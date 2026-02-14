#include <stdio.h>

int main() {
    int n;
    int isIdentity = 1;

    printf("Enter the order of the matrix (n x n): ");
    scanf("%d", &n);

    int matrix[n][n];

    printf("Enter the elements of the matrix:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Check identity matrix conditions
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if (i == j) {
                if (matrix[i][j] != 1) {
                    isIdentity = 0;
                    break;
                }
            } else {
                if (matrix[i][j] != 0) {
                    isIdentity = 0;
                    break;
                }
            }
        }
        if (!isIdentity)
            break;
    }

    if (isIdentity)
        printf("The given matrix is an Identity Matrix.\n");
    else
        printf("The given matrix is NOT an Identity Matrix.\n");

    return 0;
}
