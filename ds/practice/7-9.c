//
// Created by zhaoxiaoli on 2019-09-16.
//
/**
 * @desc: 7-9 旅游规划
 * @author zhaoxiaoli
 * @date 2019-09-16
 */
#include <stdlib.h>
#include <stdio.h>

#define MAX_VERTEX_NUM 10
#define INFINITY 65535        /* ∞设为双字节无符号整数的最大值65535*/
#define ERROR 1e5

typedef int WeightType;
typedef int PriceType;
typedef int Vertex;

typedef struct GNode *PtrToNode;
struct GNode {
    int Nv;
    int Ne;
    WeightType G[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
    PriceType P[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
};

typedef PtrToNode MGraph;

typedef struct ENode *PtrToENode;
struct ENode {
    Vertex V1, V2;      /* 有向边<V1, V2>  */
    WeightType Weight;  /* 权重 */
    PriceType Price;
};
typedef PtrToENode Edge;

/**
 * 构建图
 */
MGraph BuildGraph();

MGraph CreateGraph(int VertexNum);

void InsertEdge(MGraph Graph, Edge E);

int Dijkstra(MGraph Graph, int dist[], int path[], int cost[], Vertex S);

int main() {
    MGraph Graph = BuildGraph();
    int dist[Graph->Nv],
    int path[Graph->Nv],
    int cost[Graph->Nv];
    Vertex S, D;
    scanf("%d %d", &S, &D);

    int result = Dijkstra(Graph, dist, path, cost, S);
    if (result) {
        printf("%d %d", dist[D], cost[D]);
    } else {
        printf("-1");
    }
    return 0;
}


MGraph CreateGraph(int VertexNum) {
    Vertex V, W;/* 用顶点下标表示顶点，为整型*/
    MGraph Graph = malloc(sizeof(struct GNode));
    Graph->Nv = VertexNum;
    Graph->Ne = 0;

    /* 注意： 这里默认顶点编号从0开始，到（Graph->Nv -1）*/
    for (V = 0; V < Graph->Nv; V++)
        for (W = 0; W < Graph->Nv; W++)
            Graph->G[V][W] = INFINITY;/*或INFINITY*/

    return Graph;
}

void InsertEdge(MGraph Graph, Edge E) {
    /* 插入边 <V1, V2> */
    Graph->G[E->V1][E->V2] = E->Weight;
    Graph->P[E->V1][E->V2] = E->Price;

    /* 若是无向图，还要插入边<V2, V1> */
    Graph->G[E->V2][E->V1] = E->Weight;
    Graph->G[E->V2][E->V1] = E->Price;
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
            scanf("%d %d %d %d", &E->V1, &E->V2, &E->Weight, &E->Price);
            E->V1--;
            E->V2--; /* 起始编号从0开始 */
            InsertEdge(Graph, E);
        }
    }

    return Graph;
}

/* 邻接矩阵存储 - 有权图的单源最短路算法 */
Vertex FindMinDist(MGraph Graph, int dist[], int collected[]) { /* 返回未被收录顶点中dist最小者 */
    Vertex MinV, V;
    int MinDist = INFINITY;

    for (V = 0; V < Graph->Nv; V++) {
        if (collected[V] == 0 && dist[V] < MinDist) {
            /* 若V未被收录，且dist[V]更小 */
            MinDist = dist[V]; /* 更新最小距离 */
            MinV = V; /* 更新对应顶点 */
        }
    }
    if (MinDist < INFINITY) /* 若找到最小dist */
        return MinV; /* 返回对应的顶点下标 */
    else return ERROR;  /* 若这样的顶点不存在，返回错误标记 */
}

int Dijkstra(MGraph Graph, int dist[], int path[], int cost[], Vertex S) {
    int collected[MAX_VERTEX_NUM];
    Vertex V, W;

    /* 初始化：此处默认邻接矩阵中不存在的边用INFINITY表示 */
    for (V = 0; V < Graph->Nv; V++) {
        dist[V] = Graph->G[S][V];
        if (dist[V] < INFINITY)
            path[V] = S;
        else
            path[V] = -1;
        collected[V] = 0;
    }
    /* 先将起点收入集合 */
    dist[S] = 0;
    collected[S] = 1;

    while (1) {
        /* V = 未被收录顶点中dist最小者 */
        V = FindMinDist(Graph, dist, collected);
        if (V == ERROR) /* 若这样的V不存在 */
            break;      /* 算法结束 */
        collected[V] = 1;  /* 收录V */
        for (W = 0; W < Graph->Nv; W++) /* 对图中的每个顶点W */
            /* 若W是V的邻接点并且未被收录 */
            if (collected[W] == 0 && Graph->G[V][W] < INFINITY) {
                if (Graph->G[V][W] < 0) /* 若有负边 */
                    return 0; /* 不能正确解决，返回错误标记 */
                /* 若收录V使得dist[W]变小 */
                if (dist[V] + Graph->G[V][W] < dist[W]) {
                    dist[W] = dist[V] + Graph->G[V][W]; /* 更新dist[W] */
                    path[W] = V; /* 更新S到W的路径 */
                    cost[W] = cost[V] + Graph->P[V, W];
                } else if ((dist[V] + Graph->G[V][W] == dist[W]) && (cost[V] + Graph->P[V, W] < cost[W])) {
                    path[W] = V; /* 更新S到W的路径 */
                    cost[W] = cost[V] + Graph->P[V, W];
                }
            }
    } /* while结束*/
    return 1; /* 算法执行完毕，返回正确标记 */
}