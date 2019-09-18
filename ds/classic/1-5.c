//
// Created by zhaoxiaoli on 2019-08-29.
//
/**
 * @desc: 队列的顺序存储结构实现
 * @author zhaoxiaoli
 * @date 2019-08-29
 */
#include <stdio.h>
#include <stdlib.h>

typedef enum {
    false, true
} bool;
typedef int ElementType;
typedef int Position;
struct QNode {
    ElementType *Data;     /* 存储元素的数组 */
    Position Front, Rear;  /* 队列的头、尾指针 */
    int MaxSize;           /* 队列最大容量 */
};
typedef struct QNode *Queue;

#define ERROR -1
#define MAXSIZE 10

/**
 * 创建队列
 */
Queue CreateQueue(int MaxSize);

/**
 *队满
 */
bool IsFull(Queue Q);

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
    printf("init queue is full %d \n", IsFull(Q));
    printf("init queue is empty %d \n", IsEmpty(Q));

    for (int i = 1; i <= MAXSIZE; ++i) {
        bool add = AddQ(Q, i);
        printf("AddQ %d ,result %d \n", i, add);
    }

    printf("after add queue is full %d \n", IsFull(Q));
    printf("after add queue is empty %d \n", IsEmpty(Q));

    PrintQueue(Q);

    printf("after delete queue is full %d \n", IsFull(Q));
    printf("after delete queue is empty %d \n", IsEmpty(Q));
    return 0;
}

/**
 * 创建队列
 */
Queue CreateQueue(int MaxSize) {
    Queue Q = malloc(sizeof(struct QNode));
    Q->Data = malloc(MaxSize * sizeof(ElementType));
    Q->MaxSize = MaxSize;
    Q->Front = 0;
    Q->Rear = 0;
    return Q;
}

/**
 *队满
 */
bool IsFull(Queue Q) {
    return (Q->Rear + 1) % Q->MaxSize == Q->Front;
}

/**
 * 队空
 */
bool IsEmpty(Queue Q) {
    return Q->Front == Q->Rear;
}

/**
 * 入队
 */
bool AddQ(Queue Q, ElementType X) {
    if (IsFull(Q)) {
        printf("Queue Full");
        return false;
    }
    Q->Rear = (Q->Rear + 1) % Q->MaxSize;
    Q->Data[Q->Rear] = X;
    return true;
}

/**
 * 出队
 */
ElementType DeleteQ(Queue Q) {
    if (IsEmpty(Q)) {
        printf("Queue Empty");
        return ERROR;
    }

    Q->Front = (Q->Front + 1) % Q->MaxSize;
    return Q->Data[Q->Front];
}

void PrintQueue(Queue Q) {
    while (!IsEmpty(Q)) {
        printf("%d ", DeleteQ(Q));
    }
    printf("\n");
}

