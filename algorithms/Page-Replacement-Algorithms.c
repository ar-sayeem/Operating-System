#include <stdio.h>
#include <stdbool.h>

#define MAX_PAGES 100

bool isPageInFrame(int frames[], int frameCount, int page) {
    for (int i = 0; i < frameCount; i++) {
        if (frames[i] == page) {
            return true;
        }
    }
    return false;
}

int findLRUIndex(int frames[], int frameCount, int reference[], int refIndex) {
    int minIndex = refIndex;
    int lruPage = -1;

    for (int i = 0; i < frameCount; i++) {
        for (int j = refIndex - 1; j >= 0; j--) {
            if (reference[j] == frames[i]) {
                if (j < minIndex) {
                    minIndex = j;
                    lruPage = i;
                }
                break;
            }
        }
    }
    return lruPage;
}

int findOPTIndex(int frames[], int frameCount, int reference[], int refIndex, int refSize) {
    int farthestIndex = -1;
    int replaceIndex = -1;

    for (int i = 0; i < frameCount; i++) {
        int j;
        for (j = refIndex; j < refSize; j++) {
            if (frames[i] == reference[j]) {
                if (j > farthestIndex) {
                    farthestIndex = j;
                    replaceIndex = i;
                }
                break;
            }
        }
        if (j == refSize) {
            return i;
        }
    }
    return replaceIndex;
}

int fifo(int frames[], int frameCount, int reference[], int refSize) {
    int pageFaults = 0, index = 0;

    for (int i = 0; i < refSize; i++) {
        if (!isPageInFrame(frames, frameCount, reference[i])) {
            frames[index] = reference[i];
            index = (index + 1) % frameCount;
            pageFaults++;
        }
    }
    return pageFaults;
}

int lru(int frames[], int frameCount, int reference[], int refSize) {
    int pageFaults = 0;

    for (int i = 0; i < refSize; i++) {
        if (!isPageInFrame(frames, frameCount, reference[i])) {
            int lruIndex = findLRUIndex(frames, frameCount, reference, i);
            frames[lruIndex] = reference[i];
            pageFaults++;
        }
    }
    return pageFaults;
}

int opt(int frames[], int frameCount, int reference[], int refSize) {
    int pageFaults = 0;

    for (int i = 0; i < refSize; i++) {
        if (!isPageInFrame(frames, frameCount, reference[i])) {
            int optIndex = findOPTIndex(frames, frameCount, reference, i + 1, refSize);
            frames[optIndex] = reference[i];
            pageFaults++;
        }
    }
    return pageFaults;
}

int main() {
    int frameCount, refSize;
    int reference[MAX_PAGES];
    int fifoFrames[MAX_PAGES], lruFrames[MAX_PAGES], optFrames[MAX_PAGES];

    printf("Enter the number of page frames: ");
    scanf("%d", &frameCount);

    printf("Enter the size of the page reference string: ");
    scanf("%d", &refSize);

    printf("Enter the page reference string: ");
    for (int i = 0; i < refSize; i++) {
        scanf("%d", &reference[i]);
    }

    for (int i = 0; i < frameCount; i++) {
        fifoFrames[i] = -1;
        lruFrames[i] = -1;
        optFrames[i] = -1;
    }

    int fifoFaults = fifo(fifoFrames, frameCount, reference, refSize);
    int lruFaults = lru(lruFrames, frameCount, reference, refSize);
    int optFaults = opt(optFrames, frameCount, reference, refSize);

    int fifoHits = refSize - fifoFaults;
    int lruHits = refSize - lruFaults;
    int optHits = refSize - optFaults;

    printf("\nPage Replacement Algorithm Results:\n");
    printf("Algorithm\tPage Faults\tPage Hits\n");
    printf("FIFO\t\t%d\t\t%d\n", fifoFaults, fifoHits);
    printf("LRU\t\t%d\t\t%d\n", lruFaults, lruHits);
    printf("OPT\t\t%d\t\t%d\n", optFaults, optHits);

    return 0;
}
