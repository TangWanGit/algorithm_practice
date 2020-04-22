//
// Created by tangwan on 2019-08-28.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERROR 1e8
typedef int ElementType;
typedef enum {
    push, pop, end
} Operation;
typedef enum {
    false, true
} bool;
typedef int Position;

struct SNode {
    ElementType *Data;
    Position Top1, Top2;
    int MaxSize;
};
typedef struct SNode *Stack;

/**
 * 创建堆栈
 */
Stack CreateStack(int MaxSize);

/**
 * 如果堆栈已满，Push函数必须输出“Stack Full”并且返回false
 */
bool Push(Stack S, ElementType X, int Tag);

/**
 * 如果某堆栈是空的，则Pop函数必须输出“Stack Tag Empty”（其中Tag是该堆栈的编号），并且返回ERROR
 */
ElementType Pop(Stack S, int Tag);

Operation GetOp();  /* details omitted */
void PrintStack(Stack S, int Tag); /* details omitted */

/**
 * 输入样例：
 * 5
 * Push 1 1
 * Pop 2
 * Push 2 11
 * Push 1 2
 * Push 2 12
 * Pop 1
 * Push 2 13
 * Push 2 14
 * Push 1 3
 * Pop 2
 * End
 *
 * 输出样例：
 * Stack 2 Empty
 * Stack 2 is Empty!
 * Stack Full
 * Stack 1 is Full!
 * Pop from Stack 1: 1
 * Pop from Stack 2: 13 12 11
 */
int main() {
    int N, Tag, X;
    Stack S;
    int done = 0;

    scanf("%d", &N);
    S = CreateStack(N);
    while (!done) {
        switch (GetOp()) {
            case push:
                scanf("%d %d", &Tag, &X);
                if (!Push(S, X, Tag)) printf("Stack %d is Full!\n", Tag);
                break;
            case pop:
                scanf("%d", &Tag);
                X = Pop(S, Tag);
                if (X == ERROR) printf("Stack %d is Empty!\n", Tag);
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

/* 你的代码将被嵌在这里 */
Stack CreateStack(int MaxSize) {
    Stack stack = malloc(sizeof(Stack));
    stack->Top1 = -1;
    stack->Top2 = MaxSize;
    stack->MaxSize = MaxSize;
    stack->Data = (ElementType *) malloc(MaxSize * sizeof(ElementType));
    return stack;
}

/**
 * 如果堆栈已满，Push函数必须输出“Stack Full”并且返回false
 */
bool Push(Stack S, ElementType X, int Tag) {
    if (S == NULL)
        return false;

    if (S->Top2 - S->Top1 == 1) {
        printf("Stack Full\n");
        return false;
    }
    if (Tag == 1) {
        S->Data[++(S->Top1)] = X;
    } else {
        S->Data[--(S->Top2)] = X;
    }
    return true;
}

/**
 * 如果某堆栈是空的，则Pop函数必须输出“Stack Tag Empty”（其中Tag是该堆栈的编号），并且返回ERROR
 */
ElementType Pop(Stack S, int Tag) {
    if (Tag == 1) {
        if (S->Top1 == -1) {
            printf("Stack %d Empty\n", Tag);
            return ERROR;
        }
        return S->Data[(S->Top1)--];
    } else {
        if (S->Top2 == S->MaxSize) {
            printf("Stack %d Empty\n", Tag);
            return ERROR;
        }
        return S->Data[(S->Top2)++];
    }
}

Operation GetOp() {
    char a[11];
    scanf("%s", a);
    //push, pop, end
    if (!strcmp("Push", a))
        return push;
    if (!strcmp("Pop", a))
        return pop;
    if (!strcmp("End", a))
        return end;
    return end;
}

void PrintStack(Stack S, int Tag) {
    ElementType i = Pop(S, Tag);
    printf("%d ", i);
}
