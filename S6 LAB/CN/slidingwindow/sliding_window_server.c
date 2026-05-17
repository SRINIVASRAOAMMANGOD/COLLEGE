// Sliding Window Protocol - Server
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<arpa/inet.h>
#include<unistd.h>

#define MAX 100
#define PORT 8080

int main()
{
    int sockfd;
    struct sockaddr_in server, client;
    socklen_t len;

    int window, total_packets;
    int frame_no = 0;

    int frame[MAX];
    int ack[MAX];

    int retransmit[MAX];
    int rcount = 0;

    int next_packet = 0;

    char buffer[100];

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = INADDR_ANY;

    bind(sockfd, (struct sockaddr*)&server, sizeof(server));

    len = sizeof(client);

    printf("\nWaiting for client connection\n");

    recvfrom(sockfd, buffer, sizeof(buffer), 0,
             (struct sockaddr*)&client, &len);

    printf("The client connection obtained:\t%s\n\n", buffer);

    memset(buffer, 0, sizeof(buffer));
    strcpy(buffer, "REQUEST FOR WINDOWSIZE");

    printf("Sending request for window size\n\n");

    sendto(sockfd, buffer, strlen(buffer)+1, 0,
           (struct sockaddr*)&client, len);

    printf("Waiting for the window size\n\n");

    recvfrom(sockfd, &window, sizeof(window), 0,
             (struct sockaddr*)&client, &len);

    printf("The window size obtained from Client is:\t%d\n\n", window);

    printf("Enter the total number of packets: ");
    scanf("%d", &total_packets);

    printf("\nSending total number of packets\n\n");

    sendto(sockfd, &total_packets, sizeof(total_packets), 0,
           (struct sockaddr*)&client, len);

    getchar();

    while(next_packet < total_packets || rcount > 0)
    {
        printf("\nInitializing the transmit buffer\n\n");

        int count = 0;

        printf("The frame to be send is %d with packets:", frame_no);

        int i;

        for(i = 0; i < rcount && count < window; i++)
        {
            frame[count] = retransmit[i];
            printf("\t%d", frame[count]);
            count++;
        }

        rcount = 0;

        while(count < window && next_packet < total_packets)
        {
            frame[count] = next_packet;
            printf("\t%d", frame[count]);

            next_packet++;
            count++;
        }

        printf("\nSending frame %d\n\n", frame_no);

        sendto(sockfd, &frame_no, sizeof(frame_no), 0,
               (struct sockaddr*)&client, len);

        sendto(sockfd, frame, sizeof(int)*count, 0,
               (struct sockaddr*)&client, len);

        printf("Waiting for acknowledgement\n\n");

        recvfrom(sockfd, ack, sizeof(int)*count, 0,
                 (struct sockaddr*)&client, &len);

        int neg = 0;

        for(i = 0; i < count; i++)
        {
            if(ack[i] == -1)
            {
                printf("Negative acknowledgement received for packet:%d\n\n",
                       frame[i]);

                printf("Retransmitting packet:%d\n\n", frame[i]);

                retransmit[rcount++] = frame[i];
                neg = 1;
            }
        }

        if(!neg)
            printf("Positive acknowledgement received for all packets "
                   "within the frame:%d\n\n", frame_no);

        printf("Press enter to proceed\n");
        getchar();

        frame_no++;
    }

    printf("All frames sent successfully\n");
    printf("Closing connection with the client\n");

    close(sockfd);
}
