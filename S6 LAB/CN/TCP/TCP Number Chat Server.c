// Header file for input and output functions
#include<stdio.h>

// Header file for string handling functions
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
    // Structure to store server and client address details
    struct sockaddr_in server, client;

    // lfd -> listening socket descriptor
    // cfd -> connected socket descriptor
    // len -> size of client structure
    int lfd, cfd, len;

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

    // Convert IP address string to binary format
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Bind socket with IP address and port number
    bind(lfd, (struct sockaddr*)&server, sizeof(server));

    // Put socket in listening mode
    // 5 -> maximum waiting clients
    listen(lfd, 5);

    // Display message
    printf("\nServer Ready...\n");

    // Store size of client structure
    len = sizeof(client);

    // Accept client connection
    // Returns connected socket descriptor
    cfd = accept(lfd, (struct sockaddr*)&client, &len);

    // Infinite loop for continuous communication
    while(1)
    {
        // Receive number from client
        recv(cfd, &num, sizeof(num), 0);

        // Display received number
        printf("\nClient sent : %d\n", num);

        // If client sends 0 stop communication
        if(num == 0)
            break;

        // Ask server user to enter number
        printf("Enter number from Server : ");

        // Read number from keyboard
        scanf("%d", &num);

        // Send number to client
        send(cfd, &num, sizeof(num), 0);

        // If server sends 0 stop communication
        if(num == 0)
            break;
    }

    // Close connected socket
    close(cfd);

    // Close listening socket
    close(lfd);

    // Return success
    return 0;
}