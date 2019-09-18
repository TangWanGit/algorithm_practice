//
// Created by zhaoxiaoli on 2019-09-04.
//
/**
 * @desc: 双向堆栈
 * @author zhaoxiaoli
 * @date 2019-09-04
 */
#include <stdio.h>
#include <stdlib.h>

#define MaxSize 10 // 存储数据元素的最大个数
typedef int ElementType;
typedef struct DStack *TwoWayStack;
struct DStack {
    ElementType Data[MaxSize];
    int Top1; /* 堆栈1的栈顶指针 */
    int Top2; /* 堆栈2的栈顶指针 */
};

/**
 * init
 */
TwoWayStack MakeEmpty();

/**
 * push：Tag=1，左边推进，Tag = 0,右边推进
 */
void Push(TwoWayStack Stack, ElementType X, int Tag);

/**
 * pop： Tag=1，左边推出，Tag = 0,右边推出
 */
ElementType Pop(TwoWayStack Stack, int Tag);

/**
 * 是否为空
 */
int IsEmpty(TwoWayStack PtrS, int Tag);

/**
 * 打印
 */
void PrintStack(TwoWayStack Stack, int Tag);

int main() {
    TwoWayStack Stack = MakeEmpty();
    int Tag = 1;
    for (int i = 0; i < MaxSize; ++i) {
        Push(Stack, i, Tag);
        Tag = !Tag;
    }

    PrintStack(Stack, 1);
    PrintStack(Stack, 0);
}


TwoWayStack MakeEmpty() {
    TwoWayStack Stack = malloc(sizeof(struct DStack));
    Stack->Top1 = -1;
    Stack->Top2 = MaxSize;
}

void Push(TwoWayStack PtrS, ElementType X, int Tag) {
    if (PtrS->Top2 - PtrS->Top1 == 1) {
        printf("Full");
        return;
    }
    if (Tag) {
        PtrS->Data[++PtrS->Top1] = X;
    } else {
        PtrS->Data[--PtrS->Top2] = X;
    }
}

int IsEmpty(TwoWayStack PtrS, int Tag) {
    if (Tag) {
        return PtrS->Top1 == -1 ? 1 : 0;
    }
    return PtrS->Top2 == MaxSize ? 1 : 0;
}

ElementType Pop(TwoWayStack PtrS, int Tag) {
    if (IsEmpty(PtrS, Tag)) {
        printf("Empty");
        return NULL;
    }
    if (Tag) {
        return PtrS->Data[PtrS->Top1--];
    } else {
        return PtrS->Data[PtrS->Top2++];
    }
}

void PrintStack(TwoWayStack PtrS, int Tag) {
    printf("Tag: %d\nData: ", Tag);
    while (!IsEmpty(PtrS, Tag)) {
        ElementType i = Pop(PtrS, Tag);
        printf(" %d", i);
    }
    printf("\n");
}