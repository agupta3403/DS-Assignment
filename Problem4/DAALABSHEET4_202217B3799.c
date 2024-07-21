#include <stdio.h>
#include <stdlib.h>

#define INF 1000000

typedef struct Edge {
    int to, weight;
    struct Edge* next;
} Edge;

typedef struct Node {
    Edge* head;
} Node;

Node graph[2001];

void addEdge(int from, int to, int weight) {
    Edge* e = (Edge*)malloc(sizeof(Edge));
    e->to = to;
    e->weight = weight;
    e->next = graph[from].head;
    graph[from].head = e;
}

void dijkstra(int start, int dist[]) {
    for (int i = 0; i <= 2000; i++) {
        dist[i] = INF;
    }
    dist[start] = 0;

    int queue[2001];
    int front = 0, rear = 0;
    queue[rear++] = start;

    while (front < rear) {
        int u = queue[front++];
        for (Edge* e = graph[u].head; e != NULL; e = e->next) {
            int v = e->to;
            int w = e->weight;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                queue[rear++] = v;
            }
        }
    }
}

int main() {
    int M, A, B;
    scanf("%d %d %d", &M, &A, &B);

    for (int i = 0; i <= 2000; i++) {
        graph[i].head = NULL;
    }

    for (int i = 0; i < M; i++) {
        int X, Y, Z;
        scanf("%d %d %d", &X, &Y, &Z);
        addEdge(X, Y, Z);
        addEdge(Y, X, Z);
    }

    int dist[2001];
    dijkstra(A, dist);

    if (dist[B] == INF) {
        printf("NO\n");
    } else {
        printf("YES\n");
        printf("%d\n", dist[B]);
    }

    return 0;
}
