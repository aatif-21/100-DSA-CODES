#include <stdio.h>
#include <stdlib.h>

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
    Node **adjList; // array of pointers to linked lists
} Graph;

// ---------- Create a new adjacency list node ----------
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

// ---------- Create a graph with n vertices ----------
Graph *createGraph(int n, int directed)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->numVertices = n;
    graph->directed = directed;
    graph->adjList = (Node **)malloc(n * sizeof(Node *));

    for (int i = 0; i < n; i++)
        graph->adjList[i] = NULL; // empty list for each vertex

    return graph;
}

// ---------- Add an edge u -> v (and v -> u if undirected) ----------
void addEdge(Graph *graph, int u, int v)
{
    if (u < 0 || u >= graph->numVertices ||
        v < 0 || v >= graph->numVertices)
    {
        printf("Invalid edge (%d, %d). Skipping.\n", u, v);
        return;
    }

    // Insert at head of u's list (O(1))
    Node *newNode = createNode(v);
    newNode->next = graph->adjList[u];
    graph->adjList[u] = newNode;

    if (!graph->directed)
    {
        // Also insert v -> u
        Node *revNode = createNode(u);
        revNode->next = graph->adjList[v];
        graph->adjList[v] = revNode;
    }
}

// ---------- Print the adjacency list ----------
void printGraph(Graph *graph)
{
    printf("\nAdjacency List Representation:\n");
    printf("--------------------------------\n");
    for (int i = 0; i < graph->numVertices; i++)
    {
        printf("Vertex %2d -> ", i);
        Node *temp = graph->adjList[i];
        while (temp)
        {
            printf("%d", temp->vertex);
            if (temp->next)
                printf(" -> ");
            temp = temp->next;
        }
        printf(" NULL\n");
    }
}

// ---------- Free all allocated memory ----------
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
    int n, m, directed;

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
    freeGraph(graph);

    return 0;
}