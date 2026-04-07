#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adjMatrix[MAX][MAX];
int n, m;

void initGraph()
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adjMatrix[i][j] = 0;
}

void addEdge(int u, int v, int directed)
{
    adjMatrix[u][v] = 1;
    if (!directed)
        adjMatrix[v][u] = 1;
}

void printMatrix()
{
    printf("\nAdjacency Matrix:\n");
    printf("   ");
    for (int i = 0; i < n; i++)
        printf("%2d ", i);
    printf("\n");

    for (int i = 0; i < n; i++)
    {
        printf("%2d ", i);
        for (int j = 0; j < n; j++)
            printf("%2d ", adjMatrix[i][j]);
        printf("\n");
    }
}

int main()
{
    int directed;

    printf("Enter number of vertices (n): ");
    scanf("%d", &n);

    printf("Enter number of edges (m): ");
    scanf("%d", &m);

    printf("Directed graph? (1 = Yes, 0 = No): ");
    scanf("%d", &directed);

    initGraph();

    printf("Enter %d edges (u v):\n", m);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);

        if (u < 0 || u >= n || v < 0 || v >= n)
        {
            printf("Invalid edge (%d, %d). Vertices must be in range [0, %d].\n", u, v, n - 1);
            i--;
            continue;
        }

        addEdge(u, v, directed);
    }

    printMatrix();

    return 0;
}