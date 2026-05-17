// link_state_routing.c
#include<stdio.h>
#include<stdlib.h>

#define MAX 10
#define INF 1000

int main()
{
    int n, cost[MAX][MAX];
    int dist[MAX], visited[MAX], parent[MAX];
    int i, j, count, min, next, source;

    printf("Enter the Number of Nodes : ");
    scanf("%d", &n);

    printf("Enter the cost between Nodes :\n");

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            if(i == j)
            {
                cost[i][j] = 0;
            }
            else
            {
                printf("Cost from %d->%d : ", i, j);
                scanf("%d", &cost[i][j]);

                if(cost[i][j] == 0)
                    cost[i][j] = INF;
            }
        }
    }

    printf("Enter the source Node : ");
    scanf("%d", &source);

    for(i = 1; i <= n; i++)
    {
        dist[i] = cost[source][i];
        visited[i] = 0;
        parent[i] = source;
    }

    dist[source] = 0;
    visited[source] = 1;
    count = 1;

    while(count < n)
    {
        min = INF;

        for(i = 1; i <= n; i++)
        {
            if(dist[i] < min && !visited[i])
            {
                min = dist[i];
                next = i;
            }
        }

        visited[next] = 1;

        for(i = 1; i <= n; i++)
        {
            if(!visited[i])
            {
                if(min + cost[next][i] < dist[i])
                {
                    dist[i] = min + cost[next][i];
                    parent[i] = next;
                }
            }
        }

        count++;
    }

    printf("\nAfter Applying Dijkstra's Algorithm\n");

    for(i = 1; i <= n; i++)
    {
        if(i != source)
        {
            printf("\nThe cost of the shortest path from router %d to %d is %d",
            source, i, dist[i]);
        }
    }

    printf("\n");

    return 0;
}
