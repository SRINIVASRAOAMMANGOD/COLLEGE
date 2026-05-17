#include <stdio.h>

int main()
{
    int bucketsize, packetsize[100], outputrate, n, i, currentbucket = 0;

    printf("Enter the Bucket Size (Bytes): ");
    scanf("%d", &bucketsize);

    printf("Enter the outgoing rate (Bytes per second): ");
    scanf("%d", &outputrate);

    printf("Enter no of packets: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("\nEnter the incoming packet size (Bytes): ");
        scanf("%d", &packetsize[i]);

        if(packetsize[i] + currentbucket <= bucketsize)
        {
            currentbucket += packetsize[i];
        }
        else
        {
            printf("Dropped %d bytes of data from packet\n",
            packetsize[i] + currentbucket - bucketsize);

            currentbucket = bucketsize;
        }

        printf("Current bucket buffer size %d out of %d\n",
        currentbucket, bucketsize);

        currentbucket -= outputrate;

        if(currentbucket < 0)
            currentbucket = 0;

        printf("After outgoing %d bytes left out of %d in buffer\n",
        currentbucket, bucketsize);
    }

    return 0;
}
