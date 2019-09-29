//
// Created by zhaoxiaoli on 2019-09-16.
//
/**
 * @desc: 
 * @author zhaoxiaoli
 * @date 2019-09-16
 */
#include <stdio.h>
#include <stdlib.h>

#define MaxVertexNum 1001 /* 最大顶点数设为100 */
#define INFINITY 65535   /* ∞设为双字节无符号整数的最大值65535*/

typedef int Vertex;      /* 用顶点下标表示顶点,为整型 */
typedef int WeightType;  /* 边的权值设为整型 */

typedef struct GNode *PtrToGNode;
struct GNode {
    int Nv; /*顶点数*/
    int Ne; /*边数*/
    WeightType G[MaxVertexNum][MaxVertexNum];
};
typedef PtrToGNode MGraph; /* 以邻接矩阵存储的图类型,矩阵(matrix)*/

typedef struct ENode *PtrToENode;
struct ENode {
    Vertex V1, V2;      /* 有向边<V1, V2>  */
    WeightType Weight;  /* 权重 */
};
typedef PtrToENode Edge;

int cost[MaxVertexNum];
long ret_cost = 0;

/**
 * 构建图
 */
MGraph BuildGraph();

MGraph CreateGraph(int VertexNum);

void InsertEdge(MGraph Graph, Edge E);

int Prim(MGraph Graph);

int main() {
    MGraph Graph = BuildGraph();
    printf("%d", Prim(Graph));
    return 0;
}

MGraph CreateGraph(int VertexNum) {
    Vertex V, W;/* 用顶点下标表示顶点，为整型*/
    MGraph Graph;

    Graph = malloc(sizeof(struct GNode));
    Graph->Nv = VertexNum;
    Graph->Ne = 0;

    /* 注意： 这里默认顶点编号从0开始，到（Graph->Nv -1）*/
    for (V = 1; V < Graph->Nv; V++)
        for (W = 1; W < Graph->Nv; W++)
            Graph->G[V][W] = V == W ? 0 : INFINITY;/*或INFINITY*/

    return Graph;
}

void InsertEdge(MGraph Graph, Edge E) {
    /* 插入边 <V1, V2> */
    Graph->G[E->V1][E->V2] = Graph->G[E->V2][E->V1] = E->Weight;
}

MGraph BuildGraph() {
    MGraph Graph;
    Edge E;
    int Nv, i;

    scanf("%d", &Nv); /* 读入顶点个数 */
    Graph = CreateGraph(Nv); /* 初始化有Nv个顶点但没有边的图 */

    scanf("%d", &(Graph->Ne));/* 读入边数 */
    if (Graph->Ne != 0) {/* 如果有边 */
        E = (Edge) malloc(sizeof(struct ENode));/* 建立边结点 */
        /*读入边，格式为"起点 终点 权重"，插入邻接矩阵*/
        for (i = 0; i < Graph->Ne; i++) {
            scanf("%d %d %d", &E->V1, &E->V2, &E->Weight);
            InsertEdge(Graph, E);
        }
    }

    return Graph;
}

int findMin(MGraph Graph) {
    int minCost = INFINITY;
    int k = 0, j;
    for (j = 1; j <= Graph->Nv; j++) {
        if (cost[j] != 0 && cost[j] < minCost) {
            minCost = cost[j];
            k = j;
        }
    }
    return k;
}

int Prim(MGraph Graph) {
    for (int i = 1; i <= Graph->Nv; i++) {
        cost[i] = Graph->G[1][i]; //直接和第一个节点相连的节点；这样后面找最小值才能找到
    }
    cost[1] = 0; //从序号为1的顶点出发生成最小生成树，置1表示已经在集合内了，即访问过

    for (int i = 1; i < Graph->Nv; i++) /* 生成树还需要收n-1个节点 */
    {
        int k = findMin(Graph);/* 找到到生成树距离最短的节点 */
        if (k != 0) //找到了
        {
            ret_cost += cost[k];
            cost[k] = 0; //收到集合内
            for (int j = 2; j <= Graph->Nv; j++)  /* 更新当前的最小生成树 */
            {
                if (cost[j] && Graph->G[k][j] < cost[j]) {
                    cost[j] = Graph->G[k][j];
                }
            }
        } else {
            return -1;
        }
    }
    return ret_cost;
}


