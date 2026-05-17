// UDP Palindrome Client
#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

int main()
{
    struct sockaddr_in server;
    int lfd,n,num;
    char rBuf[100];

    lfd=socket(AF_INET,SOCK_DGRAM,0);

    server.sin_family=AF_INET;
    server.sin_port=2001;
    server.sin_addr.s_addr=inet_addr("127.0.0.1");

    n=sizeof(server);

    printf("\nEnter a number: ");
    scanf("%d",&num);

    sendto(lfd,&num,sizeof(num),0,(struct sockaddr *)&server,n);

    recvfrom(lfd,rBuf,sizeof(rBuf),0,(struct sockaddr *)&server,&n);

    printf("\nServer says: %s\n",rBuf);

    close(lfd);
}
