//
// Created by zhaoxiaoli on 2019-09-06.
//
/**
 * @desc: 列出连通集
 * @author zhaoxiaoli
 * @date 2019-09-06
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MaxVertexNum 10
/** 邻接矩阵表示图的结构声明 */
typedef int WeightType;
typedef char DataType;
typedef struct GNode *PtrToNode;
struct GNode {
    int Nv;                                     /* 顶点数 */
    int Ne;                                     /* 边数 */
    WeightType G[MaxVertexNum][MaxVertexNum];
};

typedef PtrToNode MGraph;
/**顶点的声明*/
typedef int Vertex;
/** 边的声明*/
typedef struct ENode *PtrToENode;
struct ENode {
    Vertex V1, V2;     /* 有向边<V1, V2>  */
    WeightType Weight; /* 权重 */
};
typedef PtrToENode Edge;

typedef void(*Traverse)(MGraph G, Vertex V, Vertex *visited);

/**
 * 构建图
 */
MGraph BuildGraph();

/**
 * 创建图
 */
MGraph CreateGraph(int VertexNum);

/**
 * 插入边
 */
void InsertEdge(MGraph Graph, Edge E);

/**
 * 列出连通集
 */
void ListComponents(MGraph Graph, Traverse traverse);

/**
 * 广度
 */
static void Traverse_BFS(MGraph G, Vertex V, Vertex *visited);

/**
 * 深度
 */
static void Traverse_DFS(MGraph G, Vertex V, Vertex *visited);

/**
输入样例:

8 6
0 7
0 1
2 0
4 1
2 4
3 5
输出样例:

{ 0 1 4 2 7 }
{ 3 5 }
{ 6 }
{ 0 1 2 7 4 }
{ 3 5 }
{ 6 }
 */
int main() {
    MGraph Graph = BuildGraph();
    ListComponents(Graph, Traverse_DFS);
    ListComponents(Graph, Traverse_BFS);
    return 0;
}

/**
 * 构建图
 */
MGraph BuildGraph() {
    int Nv;
    scanf("%d", &Nv);
    MGraph Graph = CreateGraph(Nv);
    scanf("%d", &(Graph->Ne));
    if (Graph->Ne != 0) {
        Edge E = malloc(sizeof(struct ENode));
        E->Weight = 1;
        for (int i = 0; i < Graph->Ne; i++) {
            scanf("%d %d", &E->V1, &E->V2);
            InsertEdge(Graph, E);
        }
        free(E);
    }
    return Graph;
}

/**
 * 创建图
 */
MGraph CreateGraph(int VertexNum) {
    /* 用顶点下标表示顶点，为整型*/
    Vertex V, W;

    MGraph Graph = malloc(sizeof(struct GNode));
    Graph->Nv = VertexNum;
    Graph->Ne = 0;

    for (V = 0; V < Graph->Nv; V++) {
        for (W = 0; W < Graph->Nv; W++) {
            Graph->G[V][W] = 0;
        }
    }
    return Graph;
}

/**
 * 插入边
 */
void InsertEdge(MGraph Graph, Edge E) {
    Graph->G[E->V1][E->V2] = E->Weight;
    Graph->G[E->V2][E->V1] = E->Weight;
}

void Visited(Vertex *visited, Vertex V) {
    printf(" %d", V);
    visited[V] = 1;
}

void Traverse_DFS(MGraph G, Vertex V, Vertex *visited) {
    Vertex W;
    Visited(visited, V);
    for (W = 0; W < G->Nv; W++)
        if (G->G[V][W] && !visited[W])
            Traverse_DFS(G, W, visited);
}

void Traverse_BFS(MGraph G, Vertex V, Vertex *visited) {
    Vertex W;
    Visited(visited, V);

    Vertex Queue[G->Nv];
    memset(Queue, 0, sizeof(Queue));
    Vertex Front = G->Nv - 1, Rear = Front;

    Queue[Front--] = V;

    while (Front != Rear) {
        V = Queue[Rear--];
        for (W = 0; W < G->Nv; W++) {
            if (G->G[V][W] && !visited[W]) {
                Visited(visited, W);
                Queue[Front--] = W;
            }
        }
    }
}

void ListComponents(MGraph G, Traverse traverse) {
    Vertex V;
    Vertex visited[G->Nv];
    memset(visited, 0, sizeof(visited));

    for (V = 0; V < G->Nv; V++) {
        if (!visited[V]) {
            printf("{");
            traverse(G, V, visited);// or BFS(V)
            printf(" }\n");
        }
    }
}