// Header file for input and output functions like printf(), scanf()
#include<stdio.h>

// Header file for string functions
#include<string.h>

// Header file for system data types
#include<sys/types.h>

// Header file for socket functions
#include<sys/socket.h>

// Header file for internet address structures
#include<netinet/in.h>

// Header file for inet_addr() function
#include<arpa/inet.h>

// Header file for close() function
#include<unistd.h>

// Main function starts execution
int main()
{
    // Structure to store server address details
    struct sockaddr_in server;

    // Variable to store socket descriptor
    int lfd;

    // Variable to store number
    int num;

    // Create TCP socket
    // AF_INET -> IPv4
    // SOCK_STREAM -> TCP
    // 0 -> default protocol
    lfd = socket(AF_INET, SOCK_STREAM, 0);

    // Set address family as IPv4
    server.sin_family = AF_INET;

    // Set port number as 2000
    server.sin_port = 2000;

    // Convert IP address string into binary form
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Connect client socket to server
    connect(lfd, (struct sockaddr*)&server, sizeof(server));

    // Display message
    printf("\nClient Ready...\n");

    // Infinite loop for continuous communication
    while(1)
    {
        // Ask user to enter number
        printf("\nEnter number from Client : ");

        // Read number from keyboard
        scanf("%d", &num);

        // Send number to server
        // &num -> address of number
        // sizeof(num) -> number of bytes to send
        send(lfd, &num, sizeof(num), 0);

        // If number is 0 stop communication
        if(num == 0)
            break;

        // Receive number from server
        recv(lfd, &num, sizeof(num), 0);

        // Display received number
        printf("Server sent : %d\n", num);

        // If server sends 0 stop communication
        if(num == 0)
            break;
    }

    // Close socket connection
    close(lfd);

    // Return success
    return 0;
}