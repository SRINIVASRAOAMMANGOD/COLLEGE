// TCP File Transfer Server
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[])
{
    int sockfd, newsockfd, portno;
    socklen_t clilen;

    struct sockaddr_in serv_addr, cli_addr;

    char buffer[BUF_SIZE];

    FILE *fp;

    pid_t pid = getpid();

    if(argc < 2)
    {
        printf("Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[1]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    bind(sockfd, (struct sockaddr *)&serv_addr,
         sizeof(serv_addr));

    listen(sockfd, 5);

    clilen = sizeof(cli_addr);

    newsockfd = accept(sockfd,
                       (struct sockaddr *)&cli_addr,
                       &clilen);

    while(1)
    {
        memset(buffer, 0, BUF_SIZE);

        read(newsockfd, buffer, BUF_SIZE);

        if(strncmp(buffer, "close", 5) == 0)
            break;

        char filename[100];

        sscanf(buffer, "get %s", filename);

        fp = fopen(filename, "r");

        if(fp == NULL)
        {
            sprintf(buffer,
                    "@FILE NOT FOUND PROCESS ID = %d\n",
                    pid);

            write(newsockfd, buffer, strlen(buffer));
        }
        else
        {
            while(fgets(buffer, BUF_SIZE, fp) != NULL)
            {
                write(newsockfd, buffer, strlen(buffer));
            }

            sprintf(buffer,
                    "\nFILE %s RECEIVED FROM SERVER "
                    "WITH PROCESS ID = %d\n",
                    filename, pid);

            write(newsockfd, buffer, strlen(buffer));

            fclose(fp);
        }
    }

    close(newsockfd);
    close(sockfd);

    return 0;
}
