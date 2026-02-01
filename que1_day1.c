//Write a C program to insert an element x at a given 1-based position pos in an array of n integers. Shift existing elements to the right to make space.

#include <stdio.h>
int arr[100], n;

void insertAtposition(int x, int pos) {
    if( pos < 1 || pos >n+1) {
        printf("Invalid position\n");
        return;
    }
    for(int i = n; i >= pos; i++) {
        arr[i] = arr[i+1];
    }
    arr[pos-1] = x;
    n++;

    printf("Array after insertion: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
        if (i != n-1)
        {
            printf(" ");
        }
    }
    printf("\n");
    
}

int main() {
    int x, pos;
    printf("Enter number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter element to insert: ");
    scanf("%d", &x);
    printf("Enter position to insert the element (1-based index): ");
    scanf("%d", &pos);
    insertAtposition(x, pos);
    return 0;
    
}
