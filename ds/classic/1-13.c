//
// Created by tangwan on 2019-09-09.
//
/**
 * @desc: 图的建立（邻接表）
 * @author tangwan
 * @date 2019-09-09
 */
#include <stdlib.h>
#include <stdio.h>

#define MaxVertexNum 10

typedef int Vertex;  /* 用顶点下标表示顶点,为整型 */
typedef int WeightType;
typedef char DataType;

/** 定义邻接表的Node*/
typedef struct AdjVNode *PtrToAdjVNode;
struct AdjVNode {
    Vertex AdjV;         /* 邻接点下标 */
    WeightType Weight;   /* 边权重 */
    PtrToAdjVNode Next;
};

/** 定义邻接表类型*/
typedef struct VNode {
    PtrToAdjVNode FirstEdge;
    DataType Data;          /* 存顶点的数据 */
} AdgList[MaxVertexNum];
/* AdjList是邻接表类型 */

/** 定义由邻接表构成的图 */
typedef struct GNode *PtrToGNode;
struct GNode {
    int Nv;    /* 顶点数 */
    int Ne;    /* 边数 */
    AdgList G; /*邻接表*/
};
/* 以邻接表方式存储的图类型 */
typedef PtrToGNode LGraph;

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
LGraph BuildGraph();

/**
 * 创建图
 */
LGraph CreateGraph(int VertexNum);

/**
 * 插入
 */
void Insert(LGraph Graph, Edge E);

void printGraph(LGraph Graph);

/**
 * Nv Ne
 * V1 V2 Weight
 * ...
 *
 * Data1 Data2 ....
 *
Sample Input:
4 4
1 2 1
1 3 2
0 2 3
2 3 9
A B C D

Sample Output:
A C-3
B D-2 C-1
C D-9 A-3 B-1
D C-9 B-2
 */
int main() {
    LGraph Graph = BuildGraph();
    printGraph(Graph);
}

/**
 * 构建图
 */
LGraph BuildGraph() {
    int V;
    scanf("%d", &V);
    LGraph Graph = CreateGraph(V);
    scanf("%d", &(Graph->Ne));
    if (Graph->Ne != 0) {
        Edge E = malloc(sizeof(struct ENode));
        for (int i = 0; i < Graph->Ne; i++) {
            scanf("%d %d %d", &E->V1, &E->V2, &E->Weight);
            Insert(Graph, E);
        }
    }
    for (V = 0; V < Graph->Nv; V++) {
        scanf(" %c", &Graph->G[V].Data);
    }
    return Graph;
}

/**
 * 创建图
 */
LGraph CreateGraph(int VertexNum) {
    Vertex V;

    LGraph Graph = malloc(sizeof(struct GNode));
    Graph->Nv = VertexNum;
    Graph->Ne = 0;

    for (V = 0; V < VertexNum; ++V) {
        Graph->G[V].FirstEdge = NULL;
    }
    return Graph;
}

/**
 * 插入
 */
void Insert(LGraph Graph, Edge E) {
    PtrToAdjVNode NewNode;
    /***************** 插入边 <V1, V2> ****************/
    /* 为V2建立新的邻接点 */
    NewNode = malloc(sizeof(struct AdjVNode));
    NewNode->AdjV = E->V2;
    NewNode->Weight = E->Weight;

    /* 将V2插入V1的表头 */
    NewNode->Next = Graph->G[E->V1].FirstEdge;
    Graph->G[E->V1].FirstEdge = NewNode;

    /********** 若是无向图，还要插入边 <V2, V1> **********/
    /* 为V1建立新的邻接点 */
    NewNode = (PtrToAdjVNode) malloc(sizeof(struct AdjVNode));
    NewNode->AdjV = E->V1;
    NewNode->Weight = E->Weight;

    /* 将V1插入V2的表头 */
    NewNode->Next = Graph->G[E->V2].FirstEdge;
    Graph->G[E->V2].FirstEdge = NewNode;

}

/**
 * 按链表显示
 */
void printGraph(LGraph Graph) {
    int V;
    PtrToAdjVNode E;
    for (V = 0; V < Graph->Nv; V++) {
        printf("%c", Graph->G[V].Data);
        E = Graph->G[V].FirstEdge;
        while (E) {
            printf(" %c-%d", Graph->G[E->AdjV].Data, E->Weight);
            E = E->Next;
        }
        printf("\n");
    }
}