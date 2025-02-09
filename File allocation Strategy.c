#include <stdio.h>
#include <string.h>
#define MAX_FILES 20

// Structure for linked allocation
struct file {
    char fname[10];
    int start, size, block[10];
} f[MAX_FILES];

void sequential_allocation() {
    int n, i, j, b[MAX_FILES], sb[MAX_FILES], c[MAX_FILES][MAX_FILES], x;

    printf("Enter number of files: ");
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        printf("Enter number of blocks occupied by file %d: ", i + 1);
        scanf("%d", &b[i]);
        printf("Enter the starting block of file %d: ", i + 1);
        scanf("%d", &sb[i]);
        
        for (j = 0; j < b[i]; j++) {
            c[i][j] = sb[i] + j;
        }
    }
    
    printf("Filename\tStart block\tLength\n");
    for (i = 0; i < n; i++) {
        printf("%d\t %d \t%d\n", i + 1, sb[i], b[i]);
    }

    printf("Enter file name: ");
    scanf("%d", &x);
    printf("File name is: %d\n", x);
    printf("Length is: %d\n", b[x - 1]);
    printf("Blocks occupied: ");
    for (i = 0; i < b[x - 1]; i++) {
        printf("%4d", c[x - 1][i]);
    }
    printf("\n");
}

void indexed_allocation() {
    int n, m[MAX_FILES], i, j, sb[MAX_FILES], s[MAX_FILES], b[MAX_FILES][MAX_FILES], x;

    printf("Enter number of files: ");
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        printf("Enter starting block and size of file %d: ", i + 1);
        scanf("%d%d", &sb[i], &s[i]);
        printf("Enter blocks occupied by file %d: ", i + 1);
        scanf("%d", &m[i]);
        printf("Enter blocks of file %d: ", i + 1);
        for (j = 0; j < m[i]; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    printf("\nFile\tIndex\tLength\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\n", i + 1, sb[i], m[i]);
    }

    printf("\nEnter file name: ");
    scanf("%d", &x);
    printf("File name is: %d\n", x);
    i = x - 1;
    printf("Index is: %d\n", sb[i]);
    printf("Blocks occupied are: ");
    for (j = 0; j < m[i]; j++) {
        printf("%3d", b[i][j]);
    }
    printf("\n");
}

void linked_allocation() {
    int n, i, j;

    printf("Enter number of files: ");
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        printf("Enter file name: ");
        scanf("%s", f[i].fname);
        printf("Enter starting block: ");
        scanf("%d", &f[i].start);
        f[i].block[0] = f[i].start;
        printf("Enter number of blocks: ");
        scanf("%d", &f[i].size);
        printf("Enter block numbers: ");
        for (j = 1; j <= f[i].size; j++) {
            scanf("%d", &f[i].block[j]);
        }
    }

    printf("File\tStart\tSize\tBlock\n");
    for (i = 0; i < n; i++) {
        printf("%s\t%d\t%d\t", f[i].fname, f[i].start, f[i].size);
        for (j = 1; j <= f[i].size; j++) {
            printf("%d", f[i].block[j]);
            if (j < f[i].size) printf(" --> ");
        }
        printf("\n");
    }
}

int main() {
    int choice;

    while (1) {
        printf("\nFile Allocation Methods\n");
        printf("1. Sequential Allocation\n");
        printf("2. Indexed Allocation\n");
        printf("3. Linked Allocation\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                sequential_allocation();
                break;
            case 2:
                indexed_allocation();
                break;
            case 3:
                linked_allocation();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}
