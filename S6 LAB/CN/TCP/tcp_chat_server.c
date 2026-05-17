// TCP Chat Server
#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>

int main()
{
    struct sockaddr_in server, client;
    int lfd, cfd, len;
    char rBuf[100], sBuf[100];

    lfd = socket(AF_INET, SOCK_STREAM, 0);

    server.sin_family = AF_INET;
    server.sin_port = 2000;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    bind(lfd, (struct sockaddr*)&server, sizeof(server));
    listen(lfd, 5);

    printf("\nServer Ready...\n");

    len = sizeof(client);

    cfd = accept(lfd, (struct sockaddr*)&client, &len);

    while(1)
    {
        recv(cfd, rBuf, sizeof(rBuf), 0);
        printf("\nClient : %s\n", rBuf);

        if(strcmp(rBuf,"bye")==0)
            break;

        printf("Server : ");
        gets(sBuf);

        send(cfd, sBuf, sizeof(sBuf), 0);

        if(strcmp(sBuf,"bye")==0)
            break;
    }

    close(cfd);
    close(lfd);
}
