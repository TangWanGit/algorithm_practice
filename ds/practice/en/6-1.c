//
// Created by zhaoxiaoli on 2019-08-30.
// 6-1 Deque 双端队列
/**
 * @desc: 
 * @author zhaoxiaoli
 * @date 2019-08-30
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"
#define ElementType int
#define ERROR 1e5

typedef struct Node *PtrToNode;
struct Node {
    ElementType Element;
    PtrToNode Next, Last;
};
typedef struct DequeRecord *Deque;
struct DequeRecord {
    PtrToNode Front, Rear;
};

Deque CreateDeque();

/**
 * Insert item X on the front end of deque D.
 * 在前方插入X
 */
int Push(ElementType X, Deque D);
/**
 * Remove the front item from deque D and return it.
 * 从front删除
 */
ElementType Pop(Deque D);

/**
 * Insert item X on the rear end of deque D.
 * 从rear处插入x
 */
int Inject(ElementType X, Deque D);
/**
 *Remove the rear item from deque D and return it.
 * Write routines to support the deque that take O(1) time per operation.
 * 从rear处删除
 *
 */
ElementType Eject(Deque D);

Operation GetOp();

void PrintDeque(Deque D); /* details omitted */
/**
Sample Input:
Pop
Inject 1
Pop
Eject
Push 1
Push 2
Eject
Inject 3
End

Sample Output:

Deque is Empty!
Deque is Empty!
Inside Deque: 2 3
 */
int main() {
    ElementType X;
    Deque D;
    int done = 0;

    D = CreateDeque();
    while (!done) {
        switch (GetOp()) {
            case push:
                scanf("%d", &X);
                if (!Push(X, D)) printf("Memory is Full!\n");
                break;
            case pop:
                X = Pop(D);
                if (X == ERROR) printf("Deque is Empty!\n");
                break;
            case inject:
                scanf("%d", &X);
                if (!Inject(X, D)) printf("Memory is Full!\n");
                break;
            case eject:
                X = Eject(D);
                if (X == ERROR) printf("Deque is Empty!\n");
                break;
            case end:
                PrintDeque(D);
                done = 1;
                break;
        }
    }
    return 0;
}

/* Your function will be put here */

Deque CreateDeque() {
    Deque PtrQ = malloc(sizeof(struct DequeRecord));
    PtrToNode Head = malloc(sizeof(struct Node));
    Head->Last = Head->Next = NULL;
    PtrQ->Front = Head;
    PtrQ->Rear = Head;
    return PtrQ;
}

int Push(ElementType X, Deque D) {
    PtrToNode Node = malloc(sizeof(struct Node));
    if (Node == NULL) {
        return 0;
    }

    Node->Element = X;
    Node->Last = D->Front;
    Node->Next = D->Front->Next;
    if (D->Front->Next) {
        D->Front->Next->Last = Node;
    } else {
        D->Rear = Node;
    }
    D->Front->Next = Node;

    return 1;
}

int IsEmpty(Deque D) {
    if (D->Front->Next == NULL || D->Rear->Last == NULL) {
        return 1;
    }
    return 0;
}

ElementType Pop(Deque D) {
    if (IsEmpty(D)) {
        return ERROR;
    }
    ElementType element;
    PtrToNode Node = D->Front->Next;

    D->Front->Next = Node->Next;

    if (Node->Next == NULL) {
        D->Front->Next = NULL;
        D->Rear = D->Front;
    } else {
        Node->Last = D->Front;
    }

    element = Node->Element;
    free(Node);
    return element;
}

int Inject(ElementType X, Deque D) {
    PtrToNode Node = malloc(sizeof(struct Node));
    if (Node == NULL) {
        return 0;
    }
    Node->Element = X;
    Node->Next = NULL;
    Node->Last = D->Rear;
    D->Rear->Next = Node;
    D->Rear = Node;

    return 1;
}

ElementType Eject(Deque D) {
    if (IsEmpty(D)) {
        return ERROR;
    }
    ElementType element;
    PtrToNode rear = D->Rear;
    PtrToNode Last = rear->Last;
    if (Last == D->Front) {
        D->Front->Next = NULL;
        D->Rear = D->Front;
    } else {
        Last->Next = NULL;
        D->Rear = Last;
    }

    element = rear->Element;
    free(rear);
    return element;
}

void PrintDeque(Deque D) {
    printf("Inside Deque:");
    while (!IsEmpty(D)) {
        int i = Pop(D);
        printf(" %d", i);
    }
}
