#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[1024] = {0};
    int num;

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(8080);

    // Convert IPv4 address
    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);

    // Connect to server
    connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    printf("Enter a number: ");
    scanf("%d", &num);

    // Send number
    char msg[1024];
    sprintf(msg, "%d", num);
    send(sock, msg, strlen(msg), 0);

    // Receive result
    read(sock, buffer, 1024);
    printf("Server response: %s\n", buffer);

    close(sock);
    return 0;
}