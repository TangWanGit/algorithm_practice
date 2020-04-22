//
// Created by tangwan on 2019-09-16.
//
/**
 * @desc: 7-9 旅游规划
 * @author tangwan
 * @date 2019-09-16
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_VERTEX_NUM 505
#define INFINITY 65535        /* ∞设为双字节无符号整数的最大值65535*/

typedef struct GNode *PtrToNode;
struct GNode {
    int Nv;
    int Ne;
    int G[MAX_VERTEX_NUM][MAX_VERTEX_NUM][2];
};
typedef PtrToNode MGraph;

int dist[MAX_VERTEX_NUM];
int cost[MAX_VERTEX_NUM];
int collected[MAX_VERTEX_NUM];

void Dijkstra(MGraph Graph, int S);

MGraph Create(int Nv, int Ne);

int main() {
    int Nv, Ne, S, D;
    scanf("%d %d %d %d", &Nv, &Ne, &S, &D);
    MGraph Graph = Create(Nv, Ne);

    Dijkstra(Graph, S);
    if (dist[D] < INFINITY) {
        printf("%d %d", dist[D], cost[D]);
    }
    return 0;
}

MGraph Create(int Nv, int Ne) {
    //用邻接矩阵表示图
    int i, j;
    int v1, v2;
    int dn, f;  //dn表示距离，f表示费用

    MGraph Graph = malloc(sizeof(struct GNode));
    Graph->Nv = Nv;
    Graph->Ne = Ne;

    for (i = 0; i < Nv; i++) {
        for (j = 0; j < Nv; j++) {
            Graph->G[i][j][0] = INFINITY;  //初始化
            Graph->G[i][j][1] = INFINITY;  //初始化
        }
    }

    for (i = 0; i < Ne; i++)  //注意这里是读入边
    {
        scanf("%d %d %d %d", &v1, &v2, &dn, &f);
        Graph->G[v1][v2][0] = Graph->G[v2][v1][0] = dn;
        Graph->G[v1][v2][1] = Graph->G[v2][v1][1] = f;
    }
    return Graph;
}

void Dijkstra(MGraph Graph, int S) {
    //求从v结点到其他各结点的最短距离
    int i, j, k;
    int min, cost_one = 0;

    for (i = 0; i < Graph->Nv; i++) {
        collected[i] = 0;
        dist[i] = Graph->G[S][i][0];   //将与v点有连接的结点加上距离
        cost[i] = Graph->G[S][i][1];
    }

    collected[S] = 1;
    dist[S] = 0;   //V到V距离为0
    cost[S] = 0;

    for (i = 1; i < Graph->Nv; i++) {
        min = INFINITY;     //当前所知离v结点的最近距离
        for (j = 0; j < Graph->Nv; j++) {
            //寻找离v结点的最近距离
            if (!collected[j] && dist[j] < min) {
                k = j;
                min = dist[j];
                cost_one = cost[j];
            }
        }

        collected[k] = 1;
        for (j = 0; j < Graph->Nv && min < INFINITY; j++) {
            //修正最短路径和距离
            if (!collected[j] && (min + Graph->G[k][j][0] < dist[j])) {
                dist[j] = min + Graph->G[k][j][0];
                cost[j] = cost_one + Graph->G[k][j][1];

            } else if (!collected[j] && (min + Graph->G[k][j][0] == dist[j]) &&
                       (cost_one + Graph->G[k][j][1] < cost[j])) {

                cost[j] = cost_one + Graph->G[k][j][1];
            }
        }

    }
}