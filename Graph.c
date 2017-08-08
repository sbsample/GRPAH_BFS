# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include "List.h"
# include "Graph.h"
/*** Constructors-Destructors ***/

#define INF -2
#define NIL -1

// Defines Graph
typedef struct GraphObj
{
    List *adjLists;
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
    G -> adjLists = calloc((n + 1), sizeof(List));
    G -> parent = calloc((n + 1), sizeof(int));
    G -> color = calloc((n + 1), sizeof(int));
    G -> distance = calloc((n + 1), sizeof(int));
    for (int i = 1; i <= n; i++)
    {
        G -> adjLists[i] = newList();
        G -> distance[i] = INF;
        G -> parent[i] = NIL;
        G -> color[i] = 0;
    }
    G -> source = NIL;
    G -> order = n;
    G -> size = 0;
    return G;
}

// freeGraph()
// frees the graph in memory
void freeGraph(Graph* pG)
{
    // if (pG != NULL && *pG != NULL)
    // {
        for (int i = 1; i < (*pG) -> size; i++ )
        {
            freeList((*pG) -> adjLists);
        }
        free((*pG) -> adjLists);
        free((*pG) -> color);
        free((*pG) -> distance);
        free((*pG) -> parent);

        (*pG) -> adjLists = NULL;
        (*pG) -> color = NULL;
        (*pG) -> distance = NULL;
        (*pG) -> parent = NULL;

        free(*pG);
        *pG = NULL;
    // }
}

/*** Access functions ***/

// getOrder()
// returns the number of vertices
int getOrder(Graph G)
{
    if (G -> size == 0)
    {
        return NIL;
    }

    return G -> order;
}

//getSize()
// returns size of graph
int getSize(Graph G)
{
  
    return G -> size;
}
// getSource()
// returns the most recently used Vertex
int getSource(Graph G)
{
    if (G -> source == NIL)
    {
        return NIL;
    }
    return G -> source;
}

// getParent()
// returns the parent of of input u
int getParent(Graph G, int u)
{
    if (G -> source == NIL)
    {
        return NIL;
    }
    return G -> parent[u];
}
int getDist(Graph G, int u)
{
    return G -> distance[u];
}
void getPath(List L, Graph G, int u)
{
    if (G -> size == 0 && getParent(G, u) == NIL)
    {
        append(L, NIL);
    }
    if(u == G -> source) {
        append(L, u);
    } else if(G -> parent[u] != NIL) {
        getPath(L, G, G -> parent[u]);
        append(L, u);
    }
    // List pathList = newList();
    // for(int i = u; i != G -> source && i != NIL; i = getParent(G,i))
    // {
    //     prepend(path,i);
    // }
    // if(i == G -> source)
    // {
    //     prepend(pathList,i);
    // }
    // else
    // {
    //     append(pathList, NIL);
    // }

    // if(back(pathList) == NIL)
    // {
    //     append(L,NIL);
    // }
    // else
    // {
    //     for(moveFront(pathList); index(pathList) != -1 ; moveNext(pathList))
    //     {
    //         append(L,get(pathList));
    //     }
    // }
    // }

}
/*** Manipulation procedures ***/
void makeNull(Graph G)
{
    for (int i = 1; i < G -> size; i++)
    {
        freeList(&G -> adjLists[i]);
        G -> distance[i] = INF;
        G -> parent[i] = NIL;
        G -> color[i] = 0;
    }
}
void addEdge(Graph G, int u, int v)
{
    addArc(G,u,v);
    addArc(G,v,u);
}
void addArc(Graph G, int u, int v)
{   printf("addArc called\n");
    moveFront(G -> adjLists[u]);
    for (moveFront(G -> adjLists[u]); index(G -> adjLists[u]) != -1; moveNext(G -> adjLists[u]))
    {
        printf("addArc while loop\n");
        printf("addArc searching for %d\n", v);
        printf("addArc search get %d\n", get(G -> adjLists[u]) );
        printf("addArc search index %d\n", index(G -> adjLists[u]) );

        // moveNext(G-> adjLists[u]);
        if (G -> size == 0)
        {
            append(G -> adjLists[u], v);
            return;
        }
        else if (get(G -> adjLists[u]) > v)
        {
            insertBefore(G -> adjLists[u], v);
            return;
        }
        else
        {
            insertAfter(G -> adjLists[u], v);
            return;
        }
    }
}
void BFS(Graph G, int s)
{
    for(int i = 1; i <= getOrder(G); i++)
    {
        G -> color[i] = 0;
        G -> distance[i] = INF;
        G -> parent[i] = NIL;
    }
    G -> source = s;
    G -> color[s] = 1;
    G -> distance[s] = 0;
    G -> parent[s] = NIL;
    List L = newList();
    append(L, s);
    for (moveFront(L); index(L) >= 0; moveNext(L)) {
         int temp = get(L);
        for (moveFront(G -> adjLists[temp]); index(G -> adjLists[temp]) >= 0; moveNext(G ->adjLists[temp]))
        {
            int temp2 = get(G -> adjLists[temp]);
            if (G -> color[temp2] == 0)
            {
                G -> color[temp2] = 1;
                G -> distance[temp2] = G -> distance[temp] + 1;
                G -> parent[temp2] = temp;
                append(L, temp2);
            }
        }
        G -> color[temp] = 2; // set color to black
    }
    freeList(&L); // free the list
}
/*** Other operations ***/
void printGraph(FILE* out, Graph G);
