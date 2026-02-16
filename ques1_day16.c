#include <stdio.h>

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    int visited[n];

    printf("Enter the elements:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        visited[i] = 0;   // initialize visited array
    }

    printf("\nElement : Frequency\n");

    for(int i = 0; i < n; i++) {
        if(visited[i] == 1)
            continue;

        int count = 1;
        for(int j = i + 1; j < n; j++) {
            if(arr[i] == arr[j]) {
                count++;
                visited[j] = 1;
            }
        }

        printf("%d : %d\n", arr[i], count);
    }

    return 0;
}
