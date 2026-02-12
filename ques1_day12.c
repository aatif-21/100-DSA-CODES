#include <stdio.h>

int main() {
    int n;
    int A[100][100];
    int isSymmetric = 1;

    // Input size of square matrix
    printf("Enter the order of the matrix (n x n): ");
    scanf("%d", &n);

    // Input matrix elements
    printf("Enter the elements of the matrix:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    // Check symmetry
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(A[i][j] != A[j][i]) {
                isSymmetric = 0;
                break;
            }
        }
        if(isSymmetric == 0)
            break;
    }

    // Output result
    if(isSymmetric)
        printf("The matrix is SYMMETRIC.\n");
    else
        printf("The matrix is NOT symmetric.\n");

    return 0;
}
