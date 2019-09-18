//
// Created by zhaoxiaoli on 2019-08-29.
//
/**
 * @desc: 线性表的链表存储实现方式，使用带头结点的链表
 * @author zhaoxiaoli
 * @date 2019-08-29
 */
#include <stdio.h>
#include <stdlib.h>

typedef enum {
    false, true
} bool;
typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

/* 查找 */
#define ERROR NULL
#define MAXSIZE 10

/**
 * 从L中查询X，返回对应位置
 */
Position Find(List L, ElementType X);

/**
 * 插入
 */
bool Insert(List L, ElementType X, Position P);

/**
 * 删除
 */
bool Delete(List L, Position P);

/**
 * 获取长度
 */
int Size(List L);

/**
 * 打印
 */
void PrintList(List L);

int main() {
    //使用带头结点的链表
    List PtrL = malloc(sizeof(struct LNode));
    PtrL->Next = NULL;

    for (int j = 0; j < MAXSIZE / 2; ++j) {
        ElementType X = (ElementType) j;
        int i = Insert(PtrL, X, PtrL->Next);
        printf("insert result : %d \n", i);
    }

    printf("ds size : %d \n", Size(PtrL));

    PrintList(PtrL);

    Position deleteNode = Find(PtrL, 2);
    bool delete = Delete(PtrL, deleteNode);
    printf("delete result : %d \n", delete);

    PrintList(PtrL);
    Position find = Find(PtrL, (ElementType) 9);
    if (find == ERROR) {
        printf("can not find 9 in ds.\n");
    } else {
        printf("find 9 in ds,the data: %d\n", find->Data);
    }

    find = Find(PtrL, (ElementType) 4);
    if (find == ERROR) {
        printf("can not find 4 in ds.\n");
    } else {
        printf("find 4 in ds,the data: %d\n", find->Data);
    }

    return 0;
}

Position Find(List L, ElementType X) {
    Position p = L; /* p指向L的第1个结点 */
    while (p && p->Data != X)
        p = p->Next;

    /* 下列语句可以用 return p; 替换 */
    if (p)
        return p;
    else
        return ERROR;
}

/* 带头结点的插入 */
/*注意:在插入位置参数P上与课程视频有所不同，课程视频中i是序列位序（从1开始），这里P是链表结点指针，在P之前插入新结点 */
bool Insert(List L, ElementType X, Position P) { /* 这里默认L有头结点 */
    Position tmp, pre;

    /* 查找P的前一个结点 */
    for (pre = L; pre && pre->Next != P; pre = pre->Next);
    if (pre == NULL) { /* P所指的结点不在L中 */
        printf("插入位置参数错误\n");
        return false;
    } else { /* 找到了P的前一个结点pre */
        /* 在P前插入新结点 */
        tmp = (Position) malloc(sizeof(struct LNode)); /* 申请、填装结点 */
        tmp->Data = X;
        tmp->Next = P;
        pre->Next = tmp;
        return true;
    }
}

/* 带头结点的删除 */
/*注意:在删除位置参数P上与课程视频有所不同，课程视频中i是序列位序（从1开始），这里P是拟删除结点指针 */
bool Delete(List L, Position P) { /* 这里默认L有头结点 */
    Position pre;

    /* 查找P的前一个结点 */
    for (pre = L; pre && pre->Next != P; pre = pre->Next);
    if (pre == NULL || P == NULL) { /* P所指的结点不在L中 */
        printf("删除位置参数错误\n");
        return false;
    } else { /* 找到了P的前一个结点pre */
        /* 将P位置的结点删除 */
        pre->Next = P->Next;
        free(P);
        return true;
    }
}

/**
 * 获取长度
 */
int Size(List L) {
    Position P = L;
    int count = 0;
    while (P) {
        count++;
        P = P->Next;
    }
    return count;
}

/**
 * 打印
 */
void PrintList(List L) {
    if (!L) {
        return;
    }
    Position P = L;
    while (P) {
        printf("%d ", P->Data);
        P = P->Next;
    }
    printf("\n");
}