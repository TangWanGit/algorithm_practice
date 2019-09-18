//
// Created by zhaoxiaoli on 2019-08-29.
//
/**
 * @desc: 堆栈的链式存储结构实现
 * @author zhaoxiaoli
 * @date 2019-08-29
 */
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef enum {
    false, true
} bool;
typedef struct SNode *PtrToSNode;
struct SNode {
    ElementType Data;
    PtrToSNode Next;
};
typedef PtrToSNode Stack;

#define ERROR -1
#define MAXSIZE 10

/**
 * 初始化堆栈
 */
Stack CreateStack();

/**
 * 栈空
 */
bool IsEmpty(Stack S);

/**
 * 入栈
 */
bool Push(Stack S, ElementType X);

/**
 * 出栈
 */
ElementType Pop(Stack S);

/**
 * 打印栈
 */
void PrintStack(Stack S);

int main() {
    Stack S = CreateStack();
    printf("init stack is empty %d \n", IsEmpty(S));

    for (int i = 1; i <= MAXSIZE; ++i) {
        bool push = Push(S, i);
        printf("push %d ,result : %d \n", i, push);
    }
    printf("after push stack is empty %d \n", IsEmpty(S));

    PrintStack(S);

    printf("after pop stack is empty %d \n", IsEmpty(S));
    return 0;
}

/**
 * 初始化堆栈
 */
Stack CreateStack() {
    /* 构建一个堆栈的头结点，返回该结点指针 */
    Stack S = malloc(sizeof(struct SNode));
    S->Next = NULL;
    return S;
}

/**
 * 栈空
 */
bool IsEmpty(Stack S) {
    /* 判断堆栈S是否为空，若是返回true；否则返回false */
    return S->Next == NULL;
}

/**
 * 入栈
 */
bool Push(Stack S, ElementType X) {
    PtrToSNode Node = malloc(sizeof(struct SNode));
    Node->Data = X;

    Node->Next = S->Next;
    S->Next = Node;

    return true;
}

/**
 * 出栈
 */
ElementType Pop(Stack S) {
    ElementType TopElem;
    PtrToSNode TopNode;

    if (IsEmpty(S)) {
        printf("stack empty");
        return ERROR;
    }
    TopNode = S->Next;
    TopElem = TopNode->Data;
    S->Next = TopNode->Next;
    free(TopNode);
    return TopElem;
}

/**
 * 打印栈
 */
void PrintStack(Stack S) {
    while (!IsEmpty(S)) {
        printf("%d ", Pop(S));
    }
    printf("\n");
}

