#include <stdio.h>
#include <stdlib.h>

#define MAX_CANDIDATES 50000

typedef struct {
    int id;
    int count;
} Candidate;

int compareCandidates(const void *a, const void *b) {
    Candidate *candidate1 = (Candidate *)a;
    Candidate *candidate2 = (Candidate *)b;

    return candidate1->id - candidate2->id;
}

int main() {
    int N1, N2, N3, N4, N5;
    scanf("%d %d %d %d %d", &N1, &N2, &N3, &N4, &N5);

    Candidate candidates[MAX_CANDIDATES];
    int candidateCount = 0;

    // Read candidates from each zone and count their occurrences
    for (int i = 0; i < 5; i++) {
        int n;
        switch (i) {
            case 0: n = N1; break;
            case 1: n = N2; break;
            case 2: n = N3; break;
            case 3: n = N4; break;
            case 4: n = N5; break;
        }

        for (int j = 0; j < n; j++) {
            int id;
            scanf("%d", &id);

            int found = 0;
            for (int k = 0; k < candidateCount; k++) {
                if (candidates[k].id == id) {
                    candidates[k].count++;
                    found = 1;
                    break;
                }
            }

            if (!found) {
                candidates[candidateCount].id = id;
                candidates[candidateCount].count = 1;
                candidateCount++;
            }
        }
    }

    // Sort candidates by their IDs
    qsort(candidates, candidateCount, sizeof(Candidate), compareCandidates);

    // Count the number of elected candidates
    int electedCount = 0;
    for (int i = 0; i < candidateCount; i++) {
        if (candidates[i].count >= 3) {
            electedCount++;
        }
    }

    printf("%d\n", electedCount);

    return 0;
}
