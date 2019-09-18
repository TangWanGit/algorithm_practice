//
// Created by sunshine on 2019-08-27.
//
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print(List L); /* 细节在此不表 */

List Reverse(List L);

int main() {
    List L1, L2;
    L1 = Read();
    L2 = Reverse(L1);
    Print(L1);
    Print(L2);
    return 0;
}

/* 你的代码将被嵌在这里 */
/**
 *单链表逆转
 */
List Reverse(List L) {
    List first = L;
    List pre = L;
    /**
     * 从第一个结点开始，每步将下一个结点放入链表的头，这样就能实现逆转
     * 例如： 1 2 3 4
     * 第一步：2 1 3 4
     * 第二步：3 2 1 4
     * 第三步：4 3 2 1
     */
    while (first != NULL && first->Next != NULL) {
        PtrToNode next = first->Next;
        PtrToNode nextNext = next->Next;

        first->Next = nextNext;
        next->Next = pre;
        pre = next;
    }
    return pre;
}

List Read() {
    int n;
    scanf("%d", &n);
    if (n < 1) {
        return NULL;
    }

    List L = NULL;
    List pre = L;
    while (n > 0) {
        int a;
        scanf("%d", &a);
        PtrToNode tmp = (PtrToNode) malloc(sizeof(struct Node)); /* 申请、填装结点 */
        tmp->Data = a;
        tmp->Next = NULL;
        if (pre == NULL) {
            L = tmp;
            pre = L;
        } else {
            pre->Next = tmp;
            pre = tmp;
        }
        n--;
    }
    return L;
}

void Print(List L) {
    while (L != NULL) {
        printf("%d ", L->Data);
        L = L->Next;
    }
    printf("\n");
}