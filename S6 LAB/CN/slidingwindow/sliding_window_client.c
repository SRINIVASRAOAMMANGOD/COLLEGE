// Sliding Window Protocol - Client
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
    struct sockaddr_in server;
    socklen_t len;

    int window, total_packets;
    int frame_no;

    int packets[MAX];
    int ack[MAX];
    int received[MAX] = {0};

    char buffer[100];

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    len = sizeof(server);

    strcpy(buffer, "HI I AM CLIENT");

    printf("\nSending request to the server\n\n");

    sendto(sockfd, buffer, strlen(buffer)+1, 0,
           (struct sockaddr*)&server, len);

    printf("Waiting for reply\n\n");

    recvfrom(sockfd, buffer, sizeof(buffer), 0,
             (struct sockaddr*)&server, &len);

    printf("The server has to send :\t%s\n\n", buffer);

    printf("Enter the window size\n");
    scanf("%d", &window);

    printf("\nSending window size\n\n");

    sendto(sockfd, &window, sizeof(window), 0,
           (struct sockaddr*)&server, len);

    printf("Waiting for the server response\n\n");

    recvfrom(sockfd, &total_packets, sizeof(total_packets), 0,
             (struct sockaddr*)&server, &len);

    printf("Total packets to receive from SERVER : %d\n",
           total_packets);

    printf("\nStarting the process of receiving\n");

    int completed = 0;

    while(!completed)
    {
        printf("\nInitializing the received buffer\n");
        printf("Waiting for the frame\n\n");

        recvfrom(sockfd, &frame_no, sizeof(frame_no), 0,
                 (struct sockaddr*)&server, &len);

        recvfrom(sockfd, packets, sizeof(int)*window, 0,
                 (struct sockaddr*)&server, &len);

        printf("The received frame is %d with packets:", frame_no);

        int i;

        for(i = 0; i < window; i++)
            printf("\t%d", packets[i]);

        printf("\nReceived frame %d\n\n", frame_no);

        printf("Enter -1 to send negative acknowledgement "
               "for the following packets\n\n");

        for(i = 0; i < window; i++)
        {
            printf("packet:%d\n", packets[i]);
            scanf("%d", &ack[i]);

            if(ack[i] == 0)
                received[packets[i]] = 1;
        }

        sendto(sockfd, ack, sizeof(int)*window, 0,
               (struct sockaddr*)&server, len);

        completed = 1;

        for(i = 0; i < total_packets; i++)
        {
            if(received[i] == 0)
            {
                completed = 0;
                break;
            }
        }
    }

    printf("\nAll frames received successfully\n");
    printf("Closing connection with the server\n");

    close(sockfd);
}
