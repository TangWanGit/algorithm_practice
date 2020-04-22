//
// Created by tangwan on 2019-09-09.
//
/**
 * @desc: 使用邻接矩阵来表示图
 * @author tangwan
 * @date 2019-09-09
 */
#include <stdio.h>
#include <stdlib.h>

#define MaxVertexNum 10

/** 邻接矩阵表示图的结构声明 */
typedef int WeightType;
typedef char DataType;
typedef struct GNode *PtrToNode;
struct GNode {
    int Nv;                                     /* 顶点数 */
    int Ne;                                     /* 边数 */
    WeightType G[MaxVertexNum][MaxVertexNum];   /*权重*/
    DataType Data[MaxVertexNum];                /*存顶点的数据*/
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

void printGraph(MGraph Graph);

/**
 * Nv Ne
 * V1 V2 Weight
 * ...
 *
 * Data1 Data2 ....
Sample Input:
4 4
1 2 1
1 3 2
0 2 3
2 3 9
A B C D

Sample Output:
  A B C D
A 0 0 3 0
B 0 0 1 2
C 3 1 0 9
D 0 2 9 0

 */
int main() {
    MGraph Graph = BuildGraph();
    printf("\n");

    printGraph(Graph);
}

/**
 * 构建图
 */
MGraph BuildGraph() {
    int V;
    scanf("%d", &V);
    MGraph Graph = CreateGraph(V);
    scanf("%d", &(Graph->Ne));
    if (Graph->Ne != 0) {
        Edge E = malloc(sizeof(struct ENode));
        for (int i = 0; i < Graph->Ne; i++) {
            scanf("%d %d %d", &E->V1, &E->V2, &E->Weight);
            InsertEdge(Graph, E);
        }
        free(E);
    }
    /* 如果顶点有数据的话，读入数据 */
    for (V = 0; V < Graph->Nv; V++)
        scanf(" %c", &(Graph->Data[V]));
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
    /* 插入边 <V1, V2> */
    Graph->G[E->V1][E->V2] = E->Weight;
    /* 若是无向图，还要插入边<V2, V1> */
    Graph->G[E->V2][E->V1] = E->Weight;
}

void printGraph(MGraph Graph) {
    Vertex V, W;
    printf(" ");
    for (V = 0; V < Graph->Nv; ++V) {
        printf(" %c", Graph->Data[V]);
    }
    printf("\n");
    for (V = 0; V < Graph->Nv; V++) {
        printf("%c", Graph->Data[V]);
        for (W = 0; W < Graph->Nv; W++) {
            printf(" %d", Graph->G[V][W]);
        }
        printf("\n");
    }
}

