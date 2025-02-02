#include <stdio.h>
#include <stdlib.h>
#define MAX_FRAMES 3
#define MAX_PAGES 100

void lru(int pages[], int n, int frameCount) {
    int frames[MAX_FRAMES];
    int pageFaults = 0;
    int recent[MAX_FRAMES];
    int i, j;

    for (i = 0; i < frameCount; i++) {
        frames[i] = -1;
        recent[i] = -1;
    }

    printf("LRU Page Replacement:\n");
    for (i = 0; i < n; i++) {
        int page = pages[i];
        int found = 0;
        for (j = 0; j < frameCount; j++) {
            if (frames[j] == page) {
                found = 1;
                recent[j] = i;
                break;
            }
        }

        if (!found) {
            int lruIndex = 0;
            for (j = 0; j < frameCount; j++) {
                if (recent[j] < recent[lruIndex]) {
                    lruIndex = j;
                }
            }

            frames[lruIndex] = page;
            recent[lruIndex] = i;
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
    int pages[MAX_PAGES] = {8,5,7,8,0,2,1,5,4,2,8,1,7};
    int n = MAX_PAGES;
    int frameCount = MAX_FRAMES;

    lru(pages, n, frameCount);
    return 0;
}
