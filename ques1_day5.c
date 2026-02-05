//A system receives two separate logs of user arrival times from two different servers. Each log is already sorted in ascending order. Your task is to create a single chronological log that preserves the correct order of arrivals
#include <stdio.h>

void mergeLogs(int log1[], int size1, int log2[], int size2, int merged[]) {
    int i = 0; // index for log1
    int j = 0; // index for log2
    int k = 0; // index for merged array

    // Compare elements from both logs
    while (i < size1 && j < size2) {
        if (log1[i] <= log2[j]) {
            merged[k] = log1[i];
            i++;
        } else {
            merged[k] = log2[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements from log1 (if any)
    while (i < size1) {
        merged[k] = log1[i];
        i++;
        k++;
    }

    // Copy remaining elements from log2 (if any)
    while (j < size2) {
        merged[k] = log2[j];
        j++;
        k++;
    }
}

int main() {
    int server1[] = {1, 4, 7, 10};
    int server2[] = {2, 3, 6, 8};

    int size1 = 4;
    int size2 = 4;

    int merged[size1 + size2];

    mergeLogs(server1, size1, server2, size2, merged);

    printf("Merged log: ");
    for (int i = 0; i < size1 + size2; i++) {
        printf("%d ", merged[i]);
    }

    return 0;
}
