//
// Created by zhaoxiaoli on 2019-09-09.
//
/**
 * @desc: 使用数组实现双堆栈
 * @author zhaoxiaoli
 * @date 2019-09-09
 */

#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

#define ERROR 1e8
typedef int ElementType;

typedef struct StackRecord *Stack;
struct StackRecord {
    int Capacity;       /* maximum size of the stack array 容量*/
    int Top1;           /* top pointer for Stack 1 堆栈1的Top*/
    int Top2;           /* top pointer for Stack 2 堆栈2的Top*/
    ElementType *Array; /* space for the two stacks 保存数据的数组 */
};

Stack CreateStack(int MaxElements);

int IsEmpty(Stack S, int Stacknum);

int IsFull(Stack S);

/**
 * Push is supposed to return 1 if the operation can be done successfully, or 0 if fails
 * 成功返回1，失败返回0
 */
int Push(ElementType X, Stack S, int Stacknum);

/**
 * If the stack is empty, Top_Pop must return ERROR which is defined by the judge program.
 * 成功返回数值，栈为空返回ERROR
 */
ElementType Top_Pop(Stack S, int Stacknum);

void PrintStack(Stack S, int Stacknum);

/**
 Sample Input:

5
Push 1 1
Pop 2
Push 2 11
Push 1 2
Push 2 12
Pop 1
Push 2 13
Push 2 14
Push 1 3
Pop 2
End

Sample Output:

Stack 2 is Empty!
Stack 1 is Full!
Pop from Stack 1: 1
Pop from Stack 2: 13 12 11

 */
int main() {
    int N, Sn, X;
    Stack S;
    int done = 0;

    scanf("%d", &N);
    S = CreateStack(N);
    while (!done) {
        switch (GetOp()) {
            case push:
                scanf("%d %d", &Sn, &X);
                if (!Push(X, S, Sn)) printf("Stack %d is Full!\n", Sn);
                break;
            case pop:
                scanf("%d", &Sn);
                X = Top_Pop(S, Sn);
                if (X == ERROR) printf("Stack %d is Empty!\n", Sn);
                break;
            case end:
                PrintStack(S, 1);
                PrintStack(S, 2);
                done = 1;
                break;
        }
    }
    return 0;
}

/* Your function will be put here */
Stack CreateStack(int MaxElements) {
    Stack Stack = malloc(sizeof(struct StackRecord));
    Stack->Capacity = MaxElements;
    Stack->Top1 = -1;
    Stack->Top2 = MaxElements;
    Stack->Array = (ElementType *) malloc(MaxElements * sizeof(ElementType));
    return Stack;
}

int IsEmpty(Stack S, int Stacknum) {
    if (Stacknum == 1) {
        return S->Top1 == -1 ? 1 : 0;
    } else {
        return S->Top2 == S->Capacity ? 1 : 0;
    }
}

int IsFull(Stack S) {
    return S->Top2 - S->Top1 == 1 ? 1 : 0;
}

/**
 * Push is supposed to return 1 if the operation can be done successfully, or 0 if fails
 * 成功返回1，失败返回0
 */
int Push(ElementType X, Stack S, int Stacknum) {
    if (IsFull(S)) {
        return 0;
    }
    if (Stacknum == 1) {
        S->Array[++S->Top1] = X;
    } else if (Stacknum == 2) {
        S->Array[--S->Top2] = X;
    } else {
        return 0;
    }
    return 1;
}

/**
 * If the stack is empty, Top_Pop must return ERROR which is defined by the judge program.
 * 成功返回数值，栈为空返回ERROR
 */
ElementType Top_Pop(Stack S, int Stacknum) {
    if (IsEmpty(S, Stacknum)) {
        return ERROR;
    }
    if (Stacknum == 1) {
        return S->Array[S->Top1--];
    } else if (Stacknum == 2) {
        return S->Array[S->Top2++];
    }
    return ERROR;
}

void PrintStack(Stack S, int Stacknum) {
    printf("Pop from Stack %d:", Stacknum);
    while (!IsEmpty(S, Stacknum)) {
        ElementType elementType = Top_Pop(S, Stacknum);
        printf(" %d", elementType);
    }
    printf("\n");
}