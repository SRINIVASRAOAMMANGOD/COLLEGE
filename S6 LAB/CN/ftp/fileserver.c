#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int isPerfect(int n) {
    int sum = 0;
    for(int i = 1; i <= n/2; i++) {
        if(n % i == 0)
            sum += i;
    }
    return (sum == n);
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    int num;
    char buffer[1024] = {0};
    FILE *logFile;

    // Create socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);

    // Bind
    bind(server_fd, (struct sockaddr *)&address, sizeof(address));

    // Listen
    listen(server_fd, 3);
    printf("Server waiting for connection...\n");

    // Accept
    new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen);

    // Receive number
    read(new_socket, buffer, 1024);
    num = atoi(buffer);

    printf("Received number: %d\n", num);

    // Check perfect number
    char result[1024];
    if(isPerfect(num))
        sprintf(result, "%d is a Perfect Number", num);
    else
        sprintf(result, "%d is NOT a Perfect Number", num);

    // Send result
    send(new_socket, result, strlen(result), 0);

    // Logging
    logFile = fopen("server_log.txt", "a");
    fprintf(logFile, "Received: %d | Sent: %s\n", num, result);
    fclose(logFile);

    printf("Result sent to client.\n");

    close(new_socket);
    close(server_fd);

    return 0;
}