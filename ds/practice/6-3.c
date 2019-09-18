//
// Created by zhaoxiaoli on 2019-08-27.
// 求链表的长度

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode List;

List Read(); /* 细节在此不表 */

/**
 * 链表的长度
 */
int Length(List L);

int main() {
    List L = Read();
    printf("%d\n", Length(L));
    return 0;
}

/* 你的代码将被嵌在这里 */
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

int Length(List L) {
    int length = 0;
    while (L != NULL) {
        length++;
        L = L->Next;
    }
    return length;
}
