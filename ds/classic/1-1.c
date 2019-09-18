//
// Created by zhaoxiaoli on 2019-08-29.
//
/**
 * 线性结构的实现方式：顺序存储实现
 */
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
/* 查找 */
#define ERROR -1

typedef int Position;
typedef struct LNode *List;
typedef struct ElementType *ElementType;
/**
 * 线性结构
 */
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last;
};

/**
 *初始化
 */
List MakeEmpty();

/**
 * 从L中查找X数据，若存在则返回对应位置，否则返回ERROR
 */
Position Find(List L, ElementType X);

/**
 * 插入，需校验位置的合法性
 */
int Insert(List L, ElementType X, Position P);

/**
 * 删除
 */
int Delete(List L, Position P);

/**
 * 打印
 */
void printList(List L);

/**
 * 线性结构的实现方式：顺序存储实现
 */
int main() {
    List PtrL = MakeEmpty();
    for (int j = 0; j < MAXSIZE / 2; ++j) {
        ElementType X = (ElementType) j;
        int i = Insert(PtrL, X, j);
        printf("insert result : %d \n", i);
    }

    printf("ds size : %d \n", PtrL->Last + 1);

    printList(PtrL);

    int delete = Delete(PtrL, 0);
    printf("delete result : %d \n", delete);

    printList(PtrL);
    Position find = Find(PtrL, (ElementType) 9);
    printf("find 9 in ds,the position: %d\n", find);

    find = Find(PtrL, (ElementType) 4);
    printf("find 4 in ds,the position: %d\n", find);
}

/* 初始化 */
List MakeEmpty() {
    List L;

    L = (List) malloc(sizeof(struct LNode));
    L->Last = -1;

    return L;
}


Position Find(List L, ElementType X) {
    Position i = 0;

    while (i <= L->Last && L->Data[i] != X)
        i++;
    if (i > L->Last) return ERROR; /* 如果没找到，返回错误信息 */
    else return i;  /* 找到后返回的是存储位置 */
}

/* 插入 */
/*注意:在插入位置参数P上与课程视频有所不同，课程视频中i是序列位序（从1开始），这里P是存储下标位置（从0开始），两者差1*/
int Insert(List L, ElementType X, Position P) { /* 在L的指定位置P前插入一个新元素X */
    Position i;

    if (L->Last == MAXSIZE - 1) {
        /* 表空间已满，不能插入 */
        printf("表满");
        return 0;
    }
    if (P < 0 || P > L->Last + 1) { /* 检查插入位置的合法性 */
        printf("位置不合法");
        return 0;
    }
    for (i = L->Last; i >= P; i--)
        L->Data[i + 1] = L->Data[i]; /* 将位置P及以后的元素顺序向后移动 */
    L->Data[P] = X;  /* 新元素插入 */
    L->Last++;       /* Last仍指向最后元素 */
    return 1;
}

/* 删除 */
/*注意:在删除位置参数P上与课程视频有所不同，课程视频中i是序列位序（从1开始），这里P是存储下标位置（从0开始），两者差1*/
int Delete(List L, Position P) { /* 从L中删除指定位置P的元素 */
    Position i;

    if (P < 0 || P > L->Last) { /* 检查空表及删除位置的合法性 */
        printf("位置%d不存在元素", P);
        return 0;
    }
    for (i = P + 1; i <= L->Last; i++)
        L->Data[i - 1] = L->Data[i]; /* 将位置P+1及以后的元素顺序向前移动 */
    L->Last--; /* Last仍指向最后元素 */
    return 1;
}

void printList(List L) {
    if (L == NULL) {
        return;
    }
    if (L->Last == 0) {
        return;
    }

    Position i = 0;
    while (i <= L->Last) {
        printf("%d ", L->Data[i]);
        i++;
    }
    printf("\n");
}
