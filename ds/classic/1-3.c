//
// Created by tangwan on 2019-08-29.
//
/**
 * @desc:  堆栈实现
 * @author tangwan
 * @date 2019-08-29
 */
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef enum {
    false, true
} bool;
typedef int Position;
struct SNode {
    ElementType *Data; /* 存储元素的数组 */
    Position Top;  /* 栈顶指针 */
    int MaxSize; /* 堆栈最大容量 */
};
typedef struct SNode *Stack;

#define ERROR -1
#define MAXSIZE 10

/**
 * 初始化堆栈
 */
Stack CreateStack(int MaxSize);

/**
 * 栈满
 */
bool IsFull(Stack S);

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
    Stack S = CreateStack(MAXSIZE);
    printf("init stack is full %d \n", IsFull(S));
    printf("init stack is empty %d \n", IsEmpty(S));

    for (int i = 1; i <= MAXSIZE; ++i) {
        bool push = Push(S, i);
        printf("push %d ,result : %d \n", i, push);
    }
    printf("after push stack is full %d \n", IsFull(S));
    printf("after push stack is empty %d \n", IsEmpty(S));

    PrintStack(S);

    printf("after pop stack is full %d \n", IsFull(S));
    printf("after pop stack is empty %d \n", IsEmpty(S));
    return 0;
}


/**
 * 初始化堆栈
 */
Stack CreateStack(int MaxSize) {
    Stack S = malloc(sizeof(struct SNode));
    S->MaxSize = MaxSize;
    S->Top = -1;
    S->Data = malloc(MaxSize * sizeof(ElementType));
    return S;
}

/**
 * 栈满
 */
bool IsFull(Stack S) {
    return (S->Top == S->MaxSize - 1);
}

/**
 * 栈空
 */
bool IsEmpty(Stack S) {
    return S->Top == -1;
}

/**
 * 入栈
 */
bool Push(Stack S, ElementType X) {
    // 先判栈满
    if (IsFull(S)) {
        printf("stack full");
        return false;
    }
    S->Data[++S->Top] = X;
    return true;
}

/**
 * 出栈
 */
ElementType Pop(Stack S) {
    // 先判栈空
    if (IsEmpty(S)) {
        printf("stack empty");
        return ERROR;
    }
    return S->Data[S->Top--];
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
