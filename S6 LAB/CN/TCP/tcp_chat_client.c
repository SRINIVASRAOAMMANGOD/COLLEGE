// TCP Chat Client
#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>

int main()
{
    struct sockaddr_in server;
    int lfd;
    char rBuf[100], sBuf[100];

    lfd = socket(AF_INET, SOCK_STREAM, 0);

    server.sin_family = AF_INET;
    server.sin_port = 2000;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    connect(lfd, (struct sockaddr*)&server, sizeof(server));

    printf("\nClient Ready...\n");

    while(1)
    {
        printf("\nClient : ");
        gets(sBuf);

        send(lfd, sBuf, sizeof(sBuf), 0);

        if(strcmp(sBuf,"bye")==0)
            break;

        recv(lfd, rBuf, sizeof(rBuf), 0);
        printf("Server : %s\n", rBuf);

        if(strcmp(rBuf,"bye")==0)
            break;
    }

    close(lfd);
}
