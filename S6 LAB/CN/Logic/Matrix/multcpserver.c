// TCP MATRIX MULTIPLICATION SERVER

#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>

int main()
{
    int sockfd, newsockfd;

    struct sockaddr_in server;

    int a[2][2], b[2][2], c[2][2];

    int i, j, k;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    // IPv4
    server.sin_family = AF_INET;

    // Port number
    server.sin_port = htons(9000);

    // Any IP
    server.sin_addr.s_addr = INADDR_ANY;

    // Bind
    bind(sockfd,
         (struct sockaddr*)&server,
         sizeof(server));

    // Listen
    listen(sockfd, 5);

    printf("Waiting for client...\n");

    // Accept client
    newsockfd = accept(sockfd, NULL, NULL);

    // Receive matrices
    recv(newsockfd, a, sizeof(a), 0);
    recv(newsockfd, b, sizeof(b), 0);

    // Matrix multiplication
    for(i = 0; i < 2; i++)
    {
        for(j = 0; j < 2; j++)
        {
            c[i][j] = 0;

            for(k = 0; k < 2; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    // Send result
    send(newsockfd,
         c,
         sizeof(c),
         0);

    printf("Multiplication completed\n");

    // Close sockets
    close(newsockfd);
    close(sockfd);

    return 0;
}