// TCP File Transfer Client
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[])
{
    int sockfd, portno, n;

    struct sockaddr_in serv_addr;

    char buffer[BUF_SIZE];
    char command[50], filename[100];

    if(argc < 3)
    {
        printf("Usage: %s <IP Address> <port>\n",
               argv[0]);
        exit(1);
    }

    portno = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);

    inet_pton(AF_INET, argv[1],
              &serv_addr.sin_addr);

    connect(sockfd,
            (struct sockaddr *)&serv_addr,
            sizeof(serv_addr));

    printf("Enter \"get\" for receiving file "
           "from server\n");

    printf("Enter \"close\" for closing connection\n");

    while(1)
    {
        printf("Enter command:");
        scanf("%s", command);

        if(strcmp(command, "close") == 0)
        {
            write(sockfd, "close", 5);
            break;
        }

        if(strcmp(command, "get") == 0)
        {
            printf("Enter filename:");
            scanf("%s", filename);

            sprintf(buffer, "get %s", filename);

            write(sockfd, buffer, strlen(buffer));

            memset(buffer, 0, BUF_SIZE);

            n = read(sockfd, buffer, BUF_SIZE);

            if(strstr(buffer, "NOT FOUND"))
            {
                printf("%s", buffer);
                continue;
            }

            FILE *fp = fopen(filename, "w");

            fwrite(buffer, 1, n, fp);

            while((n = read(sockfd, buffer, BUF_SIZE)) > 0)
            {
                fwrite(buffer, 1, n, fp);

                if(n < BUF_SIZE)
                    break;
            }

            fclose(fp);
        }
    }

    close(sockfd);

    return 0;
}
