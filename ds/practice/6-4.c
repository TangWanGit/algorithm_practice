//
// Created by zhaoxiaoli on 2019-08-27.
//

#include <stdio.h>
#include <stdlib.h>

#define ERROR -1
typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode List;

List Read(); /* 细节在此不表 */

ElementType FindKth(List L, int K);

int main() {
    int N, K;
    ElementType X;
    List L = Read();
    scanf("%d", &N);
    while (N--) {
        scanf("%d", &K);
        X = FindKth(L, K);
        if (X != ERROR)
            printf("%d ", X);
        else
            printf("NA ");
    }
    return 0;
}

List Read() {
    List L = NULL;
    List pre = L;
    int a = 0;
    while (a != -1) {
        scanf("%d", &a);
        if (a == -1) continue;
        List tmp = malloc(sizeof(struct LNode));
        tmp->Data = a;
        tmp->Next = NULL;
        if (L == NULL) {
            L = tmp;
            pre = L;
        } else {
            pre->Next = tmp;
            pre = tmp;
        }
    }
    return L;
}

/**
 * L是给定单链表，函数FindKth要返回链式表的第K个元素。如果该元素不存在，则返回ERROR
 */
ElementType FindKth(List L, int K) {
    List p = L;
    int i = 0;
    while (p != NULL && i < K - 1) {
        p = p->Next;
        i++;
    }
    return (i == K - 1 && p != NULL) ? p->Data : ERROR;
}