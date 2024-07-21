#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_M 250
#define MAX_N 250
#define MAX_QUEUE_SIZE (MAX_M * MAX_N)

typedef struct {
    int x, y, jumps;
} Node;

int bfs(int M, int N, int R[][MAX_N], int D[][MAX_N]) {
    int visited[MAX_M][MAX_N];
    memset(visited, 0, sizeof(visited));

    Node queue[MAX_QUEUE_SIZE];
    int front = 0, rear = 0;

    queue[rear].x = 0;
    queue[rear].y = 0;
    queue[rear].jumps = 0;
    rear++;

    visited[0][0] = 1;

    while (front < rear) {
        Node node = queue[front];
        front++;

        if (node.x == M - 1 && node.y == N - 1) {
            return node.jumps;
        }

        for (int i = 1; i <= R[node.x][node.y]; i++) {
            int newX = node.x;
            int newY = node.y + i;

            if (newY < N && !visited[newX][newY]) {
                queue[rear].x = newX;
                queue[rear].y = newY;
                queue[rear].jumps = node.jumps + 1;
                rear++;

                visited[newX][newY] = 1;
            }
        }

        for (int i = 1; i <= D[node.x][node.y]; i++) {
            int newX = node.x + i;
            int newY = node.y;

            if (newX < M && !visited[newX][newY]) {
                queue[rear].x = newX;
                queue[rear].y = newY;
                queue[rear].jumps = node.jumps + 1;
                rear++;

                visited[newX][newY] = 1;
            }
        }
    }

    return -1; // unreachable
}

int main() {
    int M, N;
    scanf("%d %d", &M, &N);

    int R[MAX_M][MAX_N];
    int D[MAX_M][MAX_N];

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &R[i][j]);
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &D[i][j]);
        }
    }

    int minJumps = bfs(M, N, R, D);

    printf("%d\n", minJumps);

    return 0;
}
