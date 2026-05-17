// UDP Palindrome Server
#include<stdio.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

int isPalindrome(int num)
{
    int rev=0,temp=num,rem;
    while(temp>0)
    {
        rem=temp%10;
        rev=rev*10+rem;
        temp=temp/10;
    }

    if(rev==num)
        return 1;
    else
        return 0;
}

int main()
{
    struct sockaddr_in client,server;
    int lfd,n,num;
    char sBuf[100];

    lfd=socket(AF_INET,SOCK_DGRAM,0);

    server.sin_family=AF_INET;
    server.sin_port=2001;
    server.sin_addr.s_addr=inet_addr("127.0.0.1");

    bind(lfd,(struct sockaddr *)&server,sizeof(server));

    printf("\nServer ready, waiting for client...\n");

    n=sizeof(client);

    recvfrom(lfd,&num,sizeof(num),0,(struct sockaddr *)&client,&n);

    printf("\nReceived number: %d",num);

    if(isPalindrome(num))
        strcpy(sBuf,"Number is PALINDROME");
    else
        strcpy(sBuf,"Number is NOT PALINDROME");

    sendto(lfd,sBuf,sizeof(sBuf),0,(struct sockaddr *)&client,n);

    close(lfd);
}
