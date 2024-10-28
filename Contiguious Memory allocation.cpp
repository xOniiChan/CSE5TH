#include <stdio.h>
#include <stdlib.h>
#define MAX 50

struct Block {
    int size;
    int allocated;  // 1 if allocated, 0 if free
};

// Function for First Fit
void firstFit(struct Block blocks[], int n, int process[], int m) {
    printf("\nFirst Fit Allocation:\n");
    int i;
    for (i = 0; i < m; i++) {
        int allocated = 0;
        int j;
        for ( j = 0; j < n; j++) {
            if (!blocks[j].allocated && blocks[j].size >= process[i]) {
                blocks[j].allocated = 1;
                printf("Process %d allocated to Block %d\n", i + 1, j + 1);
                allocated = 1;
                break;
            }
        }
        if (!allocated) {
            printf("Process %d not allocated\n", i + 1);
        }
    }
}

// Function for Best Fit
void bestFit(struct Block blocks[], int n, int process[], int m) {
    printf("\nBest Fit Allocation:\n");
    int i;
    for (i = 0; i < m; i++) {
        int bestIdx = -1;
        int j;
        for (j = 0; j < n; j++) {
            if (!blocks[j].allocated && blocks[j].size >= process[i]) {
                if (bestIdx == -1 || blocks[j].size < blocks[bestIdx].size) {
                    bestIdx = j;
                }
            }
        }
        if (bestIdx != -1) {
            blocks[bestIdx].allocated = 1;
            printf("Process %d allocated to Block %d\n", i + 1, bestIdx + 1);
        } else {
            printf("Process %d not allocated\n", i + 1);
        }
    }
}

// Function for Worst Fit
void worstFit(struct Block blocks[], int n, int process[], int m) {
    printf("\nWorst Fit Allocation:\n");
    int i;
    for (i = 0; i < m; i++) {
        int worstIdx = -1;
        int j;
        for (j = 0; j < n; j++) {
            if (!blocks[j].allocated && blocks[j].size >= process[i]) {
                if (worstIdx == -1 || blocks[j].size > blocks[worstIdx].size) {
                    worstIdx = j;
                }
            }
        }
        if (worstIdx != -1) {
            blocks[worstIdx].allocated = 1;
            printf("Process %d allocated to Block %d\n", i + 1, worstIdx + 1);
        } else {
            printf("Process %d not allocated\n", i + 1);
        }
    }
}

int main() {
    int i, n, m;

    printf("Enter number of memory blocks: ");
    scanf("%d", &n);
    struct Block blocks[MAX];

    for (i = 0; i < n; i++) {
        printf("Enter size of block %d: ", i + 1);
        scanf("%d", &blocks[i].size);
        blocks[i].allocated = 0;
    }

    printf("Enter number of processes: ");
    scanf("%d", &m);
    int process[MAX];

    for (i = 0; i < m; i++) {
        printf("Enter size of process %d: ", i + 1);
        scanf("%d", &process[i]);
    }

    firstFit(blocks, n, process, m);

    // Reset allocation status for Best Fit and Worst Fit
    for (i = 0; i < n; i++) {
        blocks[i].allocated = 0;
    }
    bestFit(blocks, n, process, m);

    for (i = 0; i < n; i++) {
        blocks[i].allocated = 0;
    }
    worstFit(blocks, n, process, m);

    return 0;
}

