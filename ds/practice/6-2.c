//
// Created by tangwan on 2019-08-27.
// 顺序表的操作集
//
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 5
#define ERROR -1
typedef enum {
    false, true
} bool;
typedef int ElementType;
typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};

/**
 * 创建并返回一个空的线性表
 */
List MakeEmpty();

/**
 * 返回线性表中X的位置。若找不到则返回ERROR
 */
Position Find(List L, ElementType X);

/**
 * 将X插入在位置P并返回true。若空间已满，则打印“FULL”并返回false；如果参数P指向非法位置，则打印“ILLEGAL POSITION”并返回false
 */
bool Insert(List L, ElementType X, Position P);

/**
 * 将位置P的元素删除并返回true。若参数P指向非法位置，则打印“POSITION P EMPTY”（其中P是参数值）并返回false
 */
bool Delete(List L, Position P);

/**
 * 输入样例：
 *  6
 *  1 2 3 4 5 6
 *  3
 *  6 5 1
 *  2
 *  -1 6
 * 输出样例:
 * FULL Insertion Error: 6 is not in.
 * Finding Error: 6 is not in.
 * 5 is at position 0.
 * 1 is at position 4.
 * POSITION -1 EMPTY Deletion Error.
 * FULL Insertion Error: 0 is not in.
 * POSITION 6 EMPTY Deletion Error.
 * FULL Insertion Error: 0 is not in.
 *
 */
int main() {
    List L;
    ElementType X;
    Position P;
    int N;

    L = MakeEmpty();
    scanf("%d", &N);
    // 循环插入
    while (N--) {
        scanf("%d", &X);
        if (Insert(L, X, 0) == false)
            printf(" Insertion Error: %d is not in.\n", X);
    }

    scanf("%d", &N);
    // 循环查找
    while (N--) {
        scanf("%d", &X);
        P = Find(L, X);
        if (P == ERROR)
            printf("Finding Error: %d is not in.\n", X);
        else
            printf("%d is at position %d.\n", X, P);
    }

    scanf("%d", &N);
    // 循环删除增加
    while (N--) {
        scanf("%d", &P);
        if (Delete(L, P) == false)
            printf(" Deletion Error.\n");
        if (Insert(L, 0, P) == false)
            printf(" Insertion Error: 0 is not in.\n");
    }
    return 0;
}

/* 你的代码将被嵌在这里 */

/**
 * 创建并返回一个空的线性表
 */
List MakeEmpty() {
    List L = malloc(sizeof(struct LNode));
    L->Last = -1;
    return L;
}


/**
 * 返回线性表中X的位置。若找不到则返回ERROR
 */
Position Find(List L, ElementType X) {
    Position i = 0;
    while (i <= L->Last && L->Data[i] != X) {
        i++;
    }
    return i > L->Last ? ERROR : i;
}

/**
 * 将X插入在位置P并返回true。若空间已满，则打印“FULL”并返回false；如果参数P指向非法位置，则打印“ILLEGAL POSITION”并返回false
 */
bool Insert(List L, ElementType X, Position P) {
    if (L->Last == MAXSIZE - 1) {
        printf("FULL");
        return false;
    }

    if (P < 0 || P > L->Last + 1) {
        printf("ILLEGAL POSITION");
        return false;
    }

    for (int i = L->Last; i >= P; i--)
        L->Data[i + 1] = L->Data[i]; /* 将位置P及以后的元素顺序向后移动 */

    L->Data[P] = X;
    L->Last++;
    return true;
}


/**
 * 将位置P的元素删除并返回true。若参数P指向非法位置，则打印“POSITION P EMPTY”（其中P是参数值）并返回false
 */
bool Delete(List L, Position P) {
    Position i;

    if (P < 0 || P > L->Last) { /* 检查空表及删除位置的合法性 */
        printf("POSITION %d EMPTY", P);
        return false;
    }
    for (i = P + 1; i <= L->Last; i++)
        L->Data[i - 1] = L->Data[i]; /* 将位置P+1及以后的元素顺序向前移动 */
    L->Last--; /* Last仍指向最后元素 */
    return true;
}

