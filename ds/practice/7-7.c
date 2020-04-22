//
// Created by tangwan on 2019-09-16.
//
/**
 * @desc: 7-7 六度空间
 * @author tangwan
 * @date 2019-09-16
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MaxVertexNum 10*10*10*33
/* 顶点的声明 */
typedef int Vertex;
/* 权重的类型*/
typedef int WeightType;

/* 图的声明 */
typedef struct GNode *PtrToNode;
struct GNode {
    int Nv;
    int Ne;
    WeightType G[MaxVertexNum][MaxVertexNum];
};
typedef PtrToNode MGraph;

/* 边的声明 */
typedef struct ENode {
    Vertex V1, V2;
    WeightType Weight;
};
typedef struct ENode *PtrToENode;
typedef PtrToENode Edge;

/**
 * 构建图
 */
MGraph BuildGraph();

/**
 * 创建图
 *
 */
MGraph CreateGraph(int VertexNum);

/**
 * 插入
 */
void Insert(MGraph Graph, Edge E);

/**
 * 六度空间
 */
void SDS(MGraph Graph);

/**
 * 广度优先搜索
 */
int BFS(MGraph Graph, Vertex V);

/**
 * 输出
 */
void Output(double rate, Vertex V);

/**
输入样例:

10 9
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
9 10
输出样例:

1: 70.00%
2: 80.00%
3: 90.00%
4: 100.00%
5: 100.00%
6: 100.00%
7: 100.00%
8: 90.00%
9: 80.00%
10: 70.00%
 */
int main() {
    MGraph Graph = BuildGraph();
    SDS(Graph);
    return 0;
}

MGraph BuildGraph() {
    int Nv;
    scanf("%d", &Nv);
    MGraph Graph = CreateGraph(Nv);
    scanf("%d", &(Graph->Ne));
    if (Graph->Ne > 0) {
        Edge E = malloc(sizeof(struct ENode));
        E->Weight = 1;
        for (Nv = 0; Nv < Graph->Ne; ++Nv) {
            scanf("%d %d", &E->V1, &E->V2);
            E->V1--;
            E->V2--;
            Insert(Graph, E);
        }
        free(E);
    }
    return Graph;
}

MGraph CreateGraph(int VertexNum) {
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

void Insert(MGraph Graph, Edge E) {
    Graph->G[E->V1][E->V2] = E->Weight;
    Graph->G[E->V2][E->V1] = E->Weight;
}

void SDS(MGraph Graph) {
    int count;
    Vertex V;
    for (V = 0; V < Graph->Nv; V++) {
        count = BFS(Graph, V);
        Output((double) count * 100 / Graph->Nv, V);
    }
}

int BFS(MGraph Graph, Vertex V) {
    Vertex visited[Graph->Nv];
    memset(visited, 0, sizeof(visited));

    visited[V] = 1;
    int count = 1, level = 0;
    Vertex last = V, W, tail;

    Vertex Queue[Graph->Nv];
    memset(Queue, 0, sizeof(Queue));
    Vertex Front = Graph->Nv - 1, Rear = Front;

    Queue[Front--] = V;

    while (Front != Rear) {
        V = Queue[Rear--];
        for (W = 0; W < Graph->Nv; W++) {
            if (Graph->G[V][W] && !visited[W]) {
                visited[W] = 1;
                Queue[Front--] = W;
                count++;
                tail = W;
            }
        }
        if (V == last) {
            level++;
            last = tail;
        }
        if (level == 6) break;
    }
    return count;
}

void Output(double rate, Vertex V) {
    printf("%d: %.2f%%\n", V + 1, rate);
}
