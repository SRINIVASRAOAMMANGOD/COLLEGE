#include <stdio.h>      // For printf(), scanf()
#include <unistd.h>     // For sleep()

int main()
{
    // bucketSize = maximum capacity of bucket
    // outgoing = packets leaving at fixed rate
    // incoming = packets entering
    // store = current packets inside bucket
    // n = number of inputs/iterations

    int bucketSize, outgoing, incoming;
    int store = 0;
    int n;

    // Input bucket size
    printf("Enter bucket size: ");
    scanf("%d", &bucketSize);

    // Input outgoing rate
    printf("Enter outgoing rate: ");
    scanf("%d", &outgoing);

    // Input number of iterations
    printf("Enter number of inputs: ");
    scanf("%d", &n);

    // Loop until all iterations finish
    while(n > 0)
    {
        // Get incoming packets
        printf("\nEnter incoming packet size: ");
        scanf("%d", &incoming);

        // Print incoming packets
        printf("Incoming packets = %d\n", incoming);

        // Check if enough space available
        if(incoming <= (bucketSize - store))
        {
            // Add packets to bucket
            store = store + incoming;

            printf("Packets stored successfully\n");
        }
        else
        {
            // Calculate packet loss
            int loss;

            loss = incoming - (bucketSize - store);

            printf("Packet loss = %d\n", loss);

            // Fill bucket completely
            store = bucketSize;
        }

        // Print current bucket status
        printf("Current bucket size = %d out of %d\n",
               store,
               bucketSize);

        // Remove outgoing packets
        store = store - outgoing;

        // Prevent negative values
        if(store < 0)
        {
            store = 0;
        }

        // Print remaining packets
        printf("After outgoing, remaining packets = %d\n",
               store);

        // Reduce loop count
        n--;

        // Delay for 1 second
        sleep(1);
    }

    return 0;
}