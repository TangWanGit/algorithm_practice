//
// Created by tangwan on 2019-08-29.
//
/**
 * @desc: 队列的链式存储结构实现
 * @author tangwan
 * @date 2019-08-29
 */
#include <stdio.h>
#include <stdlib.h>

typedef enum {
    false, true
} bool;
typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {/* 队列中的结点 */
    ElementType Data;
    PtrToNode Next;
};
typedef PtrToNode Position;

struct QNode {
    Position Front, Rear;  /* 队列的头、尾指针 */
    //int MaxSize;           /* 队列最大容量 */
};

typedef struct QNode *Queue;

#define ERROR -1
#define MAXSIZE 10

/**
 * 创建队列
 */
Queue CreateQueue();

/**
 * 队空
 */
bool IsEmpty(Queue Q);

/**
 * 入队
 */
bool AddQ(Queue Q, ElementType X);

/**
 * 出队
 */
ElementType DeleteQ(Queue Q);

void PrintQueue(Queue Q);

int main() {
    Queue Q = CreateQueue(MAXSIZE);
    printf("init queue is empty %d \n", IsEmpty(Q));

    for (int i = 1; i <= MAXSIZE; ++i) {
        bool add = AddQ(Q, i);
        printf("AddQ %d ,result %d \n", i, add);
    }

    printf("after add queue is empty %d \n", IsEmpty(Q));

    PrintQueue(Q);

    printf("after delete queue is empty %d \n", IsEmpty(Q));

    return 0;
}

/**
 * 创建队列
 */
Queue CreateQueue() {
    Queue Q = malloc(sizeof(struct QNode));

    Position Front = malloc(sizeof(struct Node));
    Front->Next = NULL;
    Q->Front = Front;
    Q->Rear = Front;
    return Q;
}

/**
 * 队空
 */
bool IsEmpty(Queue Q) {
    return Q->Front == NULL;
}

/**
 * 入队
 */
bool AddQ(Queue Q, ElementType X) {
    PtrToNode Node = malloc(sizeof(struct Node));
    Node->Data = X;
    Node->Next = NULL;

    Q->Rear->Next = Node;
    Q->Rear = Node;
    return true;
}

/**
 * 出队
 */
ElementType DeleteQ(Queue Q) {
    Position FrontCell;
    ElementType FrontElem;

    if (IsEmpty(Q)) {
        printf("Queue Empty");
        return ERROR;
    }

    FrontCell = Q->Front;
    if (Q->Front == Q->Rear) {
        Q->Front = Q->Rear = NULL;
    } else {
        Q->Front = Q->Front->Next;
    }
    FrontElem = FrontCell->Data;
    free(FrontCell);
    return FrontElem;
}

void PrintQueue(Queue Q) {
    while (!IsEmpty(Q)) {
        printf("%d ", DeleteQ(Q));
    }
    printf("\n");
}
