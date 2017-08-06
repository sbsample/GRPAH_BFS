# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include "List.h"
/*** Constructors-Destructors ***/

#define INF -2
#define NIL -1

// Defines Graph
typedef struct GraphObj
{
    List *adj;
    int *color;
    int *parent;
    int *distance;
    int order;
    int size;
    int source;

}GraphObj;

//newGraph()
// creates new graph with requisite fields
Graph newGraph(int n)
{
    Graph G = malloc(sizeof(GraphObj));
    G -> adj = calloc((n + 1), sizeof(List));
    G -> parent = calloc((n + 1), sizeof(int));
    G -> color = calloc((n + 1), sizeof(int));
    G -> distance = calloc((n + 1), sizeof(int));
    for (int i = 1; i <= n; i++)
    {
        G -> adj[i] = newList();
        G -> distance[i] = INF;
        G -> parent[i] = NIL;
        G -> color[i] = 0;
    }
    G -> order = n;
    G -> size = 0;
    G -> source = NIL;
    return G;
}

// freeGraph()
// frees the graph in memory
void freeGraph(Graph* pG);

/*** Access functions ***/

// getOrder()
// returns the number of vertices
int getOrder(Graph G)
{
    return G -> order;
}

//getSize()
int getSize(Graph G)
{
    return G -> size
}
int getSource(Graph G)
{
    return G -> source;
}
int getParent(Graph G, int u)
{
    return G -> parent[u];
}
int getDist(Graph G, int u);
void getPath(List L, Graph G, int u);
/*** Manipulation procedures ***/
void makeNull(Graph G);
void addEdge(Graph G, int u, int v);
void addArc(Graph G, int u, int v);
void BFS(Graph G, int s);
/*** Other operations ***/
void printGraph(FILE* out, Graph G);