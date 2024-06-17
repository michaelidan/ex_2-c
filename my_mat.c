#include <stdio.h>
#include <limits.h>
#include "my_mat.h"
#define V 10
#define MAX_QUEUE_SIZE 100

#define MAX_CAPACITY 20
#define TOTAL_ITEMS 5


//////// for my_graph:

// for A:

int (*A())[V] {
    static int mat[V][V]; 
    int num;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &num);
            mat[i][j] = num;
            if (i == j) {
                mat[i][j] = 0;
            } else if (i > j) {
                mat[i][j] = mat[j][i];
            }
        }
    }
    return mat; 
}

// for B: 

int isReachable(int G[V][V], int i, int j) {
    if (i == j) return 1; 

    int visited[V] = {0}; 
    int queue[V]; 
    int front = 0, rear = 0;
    queue[rear++] = i;
    visited[i] = 1;

    while (front < rear) {
        int current = queue[front++];

        for (int k = 0; k < V; k++) {
            if (G[current][k] && !visited[k]) {
                if (k == j) return 1;
                queue[rear++] = k;
                visited[k] = 1;
            }
        }
    }
    return 0;
}

void B(int G[V][V]) {
    int i, j;
    scanf("%d", &i);
    scanf("%d", &j);
    if (isReachable(G, i, j) && i != j) {
        printf("True\n");
    } else {
        printf("False\n");
    }
}

// for C:
void C(int graph[V][V]) {  
    int dist[V][V];
    int next[V][V];
    int src, dest;
    scanf("%d", &src);
    scanf("%d", &dest);
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (i == j) {
                dist[i][j] = 0;
                next[i][j] = -1;
            } else if (graph[i][j] != 0) {
                dist[i][j] = graph[i][j];
                next[i][j] = j;
            } else {
                dist[i][j] = INT_MAX;
                next[i][j] = -1;
            }
        }
    }
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    next[i][j] = next[i][k];
                }
            }
        }
    }
    if (dist[src][dest] == INT_MAX || src == dest) {
        printf("%d\n", -1);
    } else {

        printf("%d\n", dist[dest][src]);
    }
}

//////// for my Knapsack:

int max(int x, int y)
{
    return (x > y) ? x : y;
}

int knapSack(int item_weights[], int item_values[], char item_names[], char selected_items[])
{
    for (int i = 0; i < TOTAL_ITEMS; i++)
    {
        selected_items[i] = '\0';
    }

    int dp[TOTAL_ITEMS + 1][MAX_CAPACITY + 1];

    int i, w;
    
    for (i = 0; i <= TOTAL_ITEMS; i++)
    {
        for (w = 0; w <= MAX_CAPACITY; w++)
        {
            
            if (i == 0 || w == 0)
            {
                dp[i][w] = 0;
            }
            else if (item_weights[i - 1] <= w) 
            {
                
                dp[i][w] = max(item_values[i - 1] + dp[i - 1][w - item_weights[i - 1]], dp[i - 1][w]);
            }
            else 
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    i = TOTAL_ITEMS;
    w = MAX_CAPACITY;
    while (i > 0 && w > 0) 
    {
        if (dp[i][w] != dp[i - 1][w]) 
        {
            selected_items[i - 1] = item_names[i - 1]; 
            w -= item_weights[i - 1];     
        }
        i--;
    }

    return dp[TOTAL_ITEMS][MAX_CAPACITY];
}




