#include <stdio.h>
#define MAX 20

int G[MAX][MAX];
int VISITED[MAX];
int N;

void BFS(int S) {
    int QUEUE[MAX];
    int FRONT = 0, REAR = 0;
    for (int i = 0; i < N; i++) VISITED[i] = 0;

    QUEUE[REAR++] = S;
    VISITED[S] = 1;

    printf("BFS Traversal: ");
    while (FRONT < REAR) {
        int U = QUEUE[FRONT++];
        printf("%d ", U);
        for (int V = 0; V < N; V++) {
            if (G[U][V] == 1 && VISITED[V] == 0) {
                VISITED[V] = 1;
                QUEUE[REAR++] = V;
            }
        }
    }
    printf("\n");
}

void DFS(int U) {
    VISITED[U] = 1;
    printf("%d ", U);
    for (int V = 0; V < N; V++) {
        if (G[U][V] == 1 && VISITED[V] == 0) {
            DFS(V);
        }
    }
}

int main() {
    N = 5;
    int edges[6][2] = {{0,1}, {0,2}, {1,3}, {1,4}, {2,4}, {3,4}};
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            G[i][j] = 0;

    for(int i=0; i<6; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        G[u][v] = 1;
        G[v][u] = 1;
    }

    BFS(0);

    for (int i = 0; i < N; i++) VISITED[i] = 0;
    printf("DFS Traversal: ");
    DFS(0);
    printf("\n");

    return 0;
}
