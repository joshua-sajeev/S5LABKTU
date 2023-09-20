#include <stdio.h>

int findLFU(int frequencies[], int timestamps[], int numFrames) {
    int minIndex = 0;
    int minFrequency = frequencies[0];
    int minTimestamp = timestamps[0];

    for (int i = 1; i < numFrames; ++i) {
        if (frequencies[i] < minFrequency ||
            (frequencies[i] == minFrequency && timestamps[i] < minTimestamp)) {
            minIndex = i;
            minFrequency = frequencies[i];
            minTimestamp = timestamps[i];
        }
    }

    return minIndex;
}

void displayFrames(int pages[], int numFrames) {
    for (int i = 0; i < numFrames; ++i) {
        printf("%d\t", pages[i]);
    }
    printf("\n");
}

int main() {
    int numFrames;
    printf("Enter the number of frames: ");
    scanf("%d", &numFrames);

    int numReferences;
    printf("Enter the number of references: ");
    scanf("%d", &numReferences);

    int referenceString[numReferences];
    printf("Enter the reference string: ");
    for (int i = 0; i < numReferences; ++i) {
        scanf("%d", &referenceString[i]);
    }

    int pages[numFrames];
    int frequencies[numFrames];
    int timestamps[numFrames];

    for (int i = 0; i < numFrames; ++i) {
        pages[i] = -1;
        frequencies[i] = 0;
        timestamps[i] = 0;
    }

    int pageFaults = 0;
    int timestampCounter = 1;

    printf("Ref String  ");
    for (int i = 0; i < numFrames; ++i) {
        printf("Frame %d  ", i + 1);
    }
    printf("\n");

    for (int i = 0; i < numReferences; ++i) {
        int page = referenceString[i];
        int frameIndex = -1;

        for (int j = 0; j < numFrames; ++j) {
            if (pages[j] == page) {
                frameIndex = j;
                break;
            }
        }

        if (frameIndex == -1) {
            ++pageFaults;

            int lfuIndex = findLFU(frequencies, timestamps, numFrames);
            pages[lfuIndex] = page;
            frequencies[lfuIndex] = 1;
            timestamps[lfuIndex] = timestampCounter++;
        } else {
            ++frequencies[frameIndex];
        }

        printf(" %d\t\t", page);
        displayFrames(pages, numFrames);
    }

    printf("Total Page Faults: %d\n", pageFaults);

    return 0;
}
