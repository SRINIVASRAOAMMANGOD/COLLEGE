// TCP MATRIX ADDITION CLIENT

#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>

int main()
{
    int sockfd;

    struct sockaddr_in server;

    int a[2][2], b[2][2], c[2][2];

    int i, j;

    // Create TCP socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    // IPv4
    server.sin_family = AF_INET;

    // Port number
    server.sin_port = htons(9000);

    // Server IP
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Connect to server
    connect(sockfd,
            (struct sockaddr*)&server,
            sizeof(server));

    // Input first matrix
    printf("Enter first matrix :\n");

    for(i = 0; i < 2; i++)
    {
        for(j = 0; j < 2; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    // Input second matrix
    printf("Enter second matrix :\n");

    for(i = 0; i < 2; i++)
    {
        for(j = 0; j < 2; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }

    // Send first matrix
    send(sockfd,
         a,
         sizeof(a),
         0);

    // Send second matrix
    send(sockfd,
         b,
         sizeof(b),
         0);

    // Receive result matrix
    recv(sockfd,
         c,
         sizeof(c),
         0);

    // Print result
    printf("Addition Matrix :\n");

    for(i = 0; i < 2; i++)
    {
        for(j = 0; j < 2; j++)
        {
            printf("%d ", c[i][j]);
        }

        printf("\n");
    }

    // Close socket
    close(sockfd);

    return 0;
}