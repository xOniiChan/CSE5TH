#include <stdio.h>
#include <stdlib.h>
#define MAX_FRAMES 3
#define MAX_PAGES 100

void fifo(int pages[], int n, int frameCount) {
    int frames[MAX_FRAMES];
    int pageFaults = 0;
    int pointer = 0;
    int i, j;

    for (i = 0; i < frameCount; i++) {
        frames[i] = -1;
    }

    printf("FIFO Page Replacement:\n");
    for (i = 0; i < n; i++) {
        int page = pages[i];
        int found = 0;

        for (j = 0; j < frameCount; j++) {
            if (frames[j] == page) {
                found = 1;
                break;
            }
        }

        if (!found) {
            frames[pointer] = page;
            pointer = (pointer + 1) % frameCount;
            pageFaults++;
            printf("Page %d caused a page fault. Frames: ", page);
            for (j = 0; j < frameCount; j++) {
                if (frames[j] != -1)
                    printf("%d ", frames[j]);
            }
            printf("\n");
        }
    }

    printf("Total Page Faults: %d\n", pageFaults);
}

int main() {
    int pages[MAX_PAGES] = {8, 5,7,8,0,2,1,5,4,2,0,1,7};
    int n = 100;
    int frameCount = MAX_FRAMES;

    fifo(pages, n, frameCount);
    return 0;
}
