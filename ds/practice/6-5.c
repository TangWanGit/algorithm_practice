//
// Created by zhaoxiaoli on 2019-08-27.
//

#include <stdio.h>
#include <stdlib.h>

#define ERROR NULL
typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

/**
 * 返回线性表中首次出现X的位置。若找不到则返回ERROR
 */
Position Find(List L, ElementType X);

/**
 * 将X插入在位置P指向的结点之前，返回链表的表头。如果参数P指向非法位置，则打印“Wrong Position for Insertion”，返回ERROR
 */
List Insert(List L, ElementType X, Position P);

/**
 * 将位置P的元素删除并返回链表的表头。若参数P指向非法位置，则打印“Wrong Position for Deletion”并返回ERROR
 */
List Delete(List L, Position P);

/**
 * 输入样例：
 * 6
 * 12 2 4 87 10 2
 * 4
 * 2 12 87 5
 *
 * 输出样例：
 * 2 is found and deleted.
 * 12 is found and deleted.
 * 87 is found and deleted.
 * Finding Error: 5 is not in.
 * 5 is inserted as the last element.
 * Wrong Position for Insertion
 * Wrong Position for Deletion
 * 10 4 2 5
 */
int main() {
    List L;
    ElementType X;
    Position P, tmp;
    int N;

    L = NULL;
    scanf("%d", &N);
    while (N--) {
        scanf("%d", &X);
        L = Insert(L, X, L);
        if (L == ERROR) printf("Wrong Answer\n");
    }
    scanf("%d", &N);
    while (N--) {
        scanf("%d", &X);
        P = Find(L, X);
        if (P == ERROR)
            printf("Finding Error: %d is not in.\n", X);
        else {
            L = Delete(L, P);
            printf("%d is found and deleted.\n", X);
            if (L == ERROR)
                printf("Wrong Answer or Empty List.\n");
        }
    }
    L = Insert(L, X, NULL);
    if (L == ERROR) printf("Wrong Answer\n");
    else
        printf("%d is inserted as the last element.\n", X);
    P = (Position) malloc(sizeof(struct LNode));
    tmp = Insert(L, X, P);
    if (tmp != ERROR) printf("Wrong Answer\n");
    tmp = Delete(L, P);
    if (tmp != ERROR) printf("Wrong Answer\n");
    for (P = L; P; P = P->Next) printf("%d ", P->Data);
    return 0;
}

/* 你的代码将被嵌在这里 */
/**
 * 返回线性表中首次出现X的位置。若找不到则返回ERROR
 */
Position Find(List L, ElementType X) {
    Position p = L;
    while (p != NULL && p->Data != X) {
        p = p->Next;
    }
    return p ? p : ERROR;
}

/**
 * 将X插入在位置P指向的结点之前，返回链表的表头。如果参数P指向非法位置，则打印“Wrong Position for Insertion”，返回ERROR
 */
List Insert(List L, ElementType X, Position P) {
    if (P == L) {
        List Node = (List) malloc(sizeof(List));
        Node->Data = X;
        Node->Next = L;
        return Node;
    }
    List q = L;
    while (q) {
        if (q->Next == P) {
            List Node = (List) malloc(sizeof(List));
            Node->Data = X;
            Node->Next = q->Next;
            q->Next = Node;
            return L;
        }
        q = q->Next;
    }
    printf("Wrong Position for Insertion\n");
    return ERROR;
}

/**
 * 将位置P的元素删除并返回链表的表头。若参数P指向非法位置，则打印“Wrong Position for Deletion”并返回ERROR
 */
List Delete(List L, Position P) {
    if (L == P) {
        return L->Next;
    }
    List q = L;
    while (q) {
        if (q->Next == P) {
            q->Next = q->Next->Next;
            return L;
        }
        q = q->Next;
    }
    printf("Wrong Position for Deletion\n");
    return ERROR;
}