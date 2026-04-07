#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// ---------- Node structure for adjacency list ----------
typedef struct Node
{
    int vertex;
    struct Node *next;
} Node;

// ---------- Graph structure ----------
typedef struct Graph
{
    int numVertices;
    int directed;
    Node **adjList;
} Graph;

// ---------- Visited array ----------
int visited[MAX];

// ---------- Create a new node ----------
Node *createNode(int v)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// ---------- Create graph ----------
Graph *createGraph(int n, int directed)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = n;
    graph->directed = directed;
    graph->adjList = (Node **)malloc(n * sizeof(Node *));
    for (int i = 0; i < n; i++)
        graph->adjList[i] = NULL;
    return graph;
}

// ---------- Add edge ----------
void addEdge(Graph *graph, int u, int v)
{
    if (u < 0 || u >= graph->numVertices ||
        v < 0 || v >= graph->numVertices)
    {
        printf("Invalid edge (%d, %d). Skipping.\n", u, v);
        return;
    }
    Node *newNode = createNode(v);
    newNode->next = graph->adjList[u];
    graph->adjList[u] = newNode;

    if (!graph->directed)
    {
        Node *revNode = createNode(u);
        revNode->next = graph->adjList[v];
        graph->adjList[v] = revNode;
    }
}

// ---------- Recursive DFS ----------
void dfs(Graph *graph, int vertex)
{
    // Mark current vertex as visited and print it
    visited[vertex] = 1;
    printf("%d ", vertex);

    // Recurse on all unvisited neighbours
    Node *temp = graph->adjList[vertex];
    while (temp)
    {
        if (!visited[temp->vertex])
            dfs(graph, temp->vertex);
        temp = temp->next;
    }
}

// ---------- Print adjacency list ----------
void printGraph(Graph *graph)
{
    printf("\nAdjacency List:\n");
    for (int i = 0; i < graph->numVertices; i++)
    {
        printf("  %2d -> ", i);
        Node *temp = graph->adjList[i];
        while (temp)
        {
            printf("%d ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// ---------- Free graph ----------
void freeGraph(Graph *graph)
{
    for (int i = 0; i < graph->numVertices; i++)
    {
        Node *curr = graph->adjList[i];
        while (curr)
        {
            Node *tmp = curr;
            curr = curr->next;
            free(tmp);
        }
    }
    free(graph->adjList);
    free(graph);
}

// ---------- Main ----------
int main()
{
    int n, m, directed, source;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    printf("Directed graph? (1 = Yes, 0 = No): ");
    scanf("%d", &directed);

    Graph *graph = createGraph(n, directed);

    printf("Enter %d edges (u v):\n", m);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }

    printGraph(graph);

    printf("\nEnter source vertex for DFS: ");
    scanf("%d", &source);

    // Initialise visited array
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    printf("\nDFS Traversal from vertex %d:\n  ", source);
    dfs(graph, source);

    // Handle disconnected components
    printf("\n\nChecking for unvisited vertices (disconnected graph):\n");
    int found = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            printf("  Starting DFS from unvisited vertex %d:\n  ", i);
            dfs(graph, i);
            printf("\n");
            found = 1;
        }
    }
    if (!found)
        printf("  All vertices visited. Graph is connected.\n");

    freeGraph(graph);
    return 0;
}