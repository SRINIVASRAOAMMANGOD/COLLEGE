// Link State Routing using Dijkstra Algorithm

// Standard input/output header
// Used for printf() and scanf()
#include<stdio.h>

// Maximum number of routers allowed
#define MAX 10

// Infinite value used when no direct connection exists
#define INF 999

int main()
{
    // cost matrix stores distance between routers
    // Example:
    // cost[1][2] = cost from router 1 to router 2
    int cost[MAX][MAX];

    // dist[i] stores shortest distance from source to router i
    int dist[MAX];

    // visited[i] checks whether router already processed
    // 0 = not visited
    // 1 = visited
    int visited[MAX];

    // parent[i] stores previous router in shortest path
    int parent[MAX];

    // n = total routers
    int n;

    // Loop variables
    int i, j;

    // Source router
    int source;

    // count tracks visited routers
    int count;

    // min stores minimum distance
    int min;

    // next stores next nearest router
    int next;

    // Get total routers
    printf("Enter number of routers: ");
    scanf("%d", &n);

    // Input cost matrix
    printf("\nEnter Cost Matrix:\n");

    // Read matrix row by row
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            // Input cost between routers
            scanf("%d", &cost[i][j]);

            // If no direct path exists
            // and not same router
            if(cost[i][j] == 0 && i != j)
            {
                // Replace 0 with INF
                // meaning unreachable
                cost[i][j] = INF;
            }
        }
    }

    // Get source router
    printf("\nEnter source router: ");
    scanf("%d", &source);

    // Initial setup
    for(i = 1; i <= n; i++)
    {
        // Initially distance from source
        // is direct edge cost
        dist[i] = cost[source][i];

        // Initially parent is source
        parent[i] = source;

        // Mark all routers unvisited
        visited[i] = 0;
    }

    // Distance from source to itself = 0
    dist[source] = 0;

    // Mark source router visited
    visited[source] = 1;

    // One router already visited
    count = 1;

    // Main Dijkstra loop
    while(count < n)
    {
        // Assume minimum distance is INF
        min = INF;

        // Find nearest unvisited router
        for(i = 1; i <= n; i++)
        {
            // Check:
            // 1. distance smaller than current min
            // 2. router not visited
            if(dist[i] < min && !visited[i])
            {
                // Update minimum distance
                min = dist[i];

                // Store nearest router
                next = i;
            }
        }

        // Mark nearest router visited
        visited[next] = 1;

        // Update shortest distances
        for(i = 1; i <= n; i++)
        {
            // Only for unvisited routers
            if(!visited[i])
            {
                // Check if new path is shorter
                // Formula:
                // current minimum + edge cost
                if(min + cost[next][i] < dist[i])
                {
                    // Update shortest distance
                    dist[i] = min + cost[next][i];

                    // Store parent router
                    parent[i] = next;
                }
            }
        }

        // Increase visited router count
        count++;
    }

    // Print routing table
    printf("\n===== ROUTING TABLE =====\n");

    // Display shortest paths
    for(i = 1; i <= n; i++)
    {
        // Skip source router
        if(i != source)
        {
            // Print destination router
            printf("\nShortest Path from Router %d to Router %d",
                   source,
                   i);

            // Print shortest distance
            printf("\nCost = %d", dist[i]);

            // Print path
            printf("\nPath = %d", i);

            // Start from destination router
            j = i;

            // Move backwards using parent[]
            while(j != source)
            {
                // Move to previous router
                j = parent[j];

                // Print parent router
                printf(" <- %d", j);
            }

            // New line
            printf("\n");
        }
    }

    // Successful execution
    return 0;
}