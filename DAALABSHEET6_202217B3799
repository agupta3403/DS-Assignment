#include <stdio.h>

#define MAX_N 10000

int main() {
    int N;
    scanf("%d", &N);

    int a[MAX_N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }

    int best[MAX_N];
    for (int i = 0; i < N; i++) {
        best[i] = 1;
    }

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (a[i] % a[j] == 0 && best[i] < best[j] + 1) {
                best[i] = best[j] + 1;
            }
        }
    }

    int max_length = 1;
    for (int i = 0; i < N; i++) {
        if (max_length < best[i]) {
            max_length = best[i];
        }
    }

    printf("%d\n", max_length);

    return 0;
}
