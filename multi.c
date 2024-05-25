#include <stdio.h>
#include <limits.h>

#define V 6 

int minDistance(int dist[], int sptSet[]) {
    int min = INT_MAX;
    int min_index = -1;
    int v;  // Declared outside the for-loop
    for (v = 0; v < V; v++) {
        if (sptSet[v] == 0 && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void printSolution(int dist[]) {
    int i;  // Declared outside the for-loop
    printf("Vertex   Distance from Source\n");
    for (i = 0; i < V; i++) {
        printf("%d \t\t %d\n", i, dist[i]);
    }
}

void dijkstra(int graph[V][V], int src) {
    int dist[V]; 
    int sptSet[V];
    int i;  // Declared outside the for-loop
    int u;  // Declared outside the for-loop
    int count;  // Declared outside the for-loop
    
    for (i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = 0;
    }

    dist[src] = 0;

    for (count = 0; count < V - 1; count++) {
        u = minDistance(dist, sptSet);
        sptSet[u] = 1;

        for (i = 0; i < V; i++) {  // Reuse declared variable
            if (!sptSet[i] && graph[u][i] && dist[u] != INT_MAX && dist[u] + graph[u][i] < dist[i]) {
                dist[i] = dist[u] + graph[u][i];
            }
        }
    }

    printSolution(dist);
}

int main() {
    int graph[V][V] = {
        {0, 2, 0, 1, 0, 0},
        {2, 0, 3, 2, 0, 0},
        {0, 3, 0, 0, 1, 0},
        {1, 2, 0, 0, 4, 3},
        {0, 0, 1, 4, 0, 2},
        {0, 0, 0, 3, 2, 0}
    };
    
    int src = 0;

    dijkstra(graph, src);

    return 0;
}

