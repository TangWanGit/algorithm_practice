//
// Created by zhaoxiaoli on 2019-08-30.
// 6-10 二分查找
/**
 * @desc: 
 * @author zhaoxiaoli
 * @date 2019-08-30
 */
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
#define NotFound 0

typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* 保存线性表中最后一个元素的位置 */
};

List ReadInput(); /* 裁判实现，细节不表。元素从下标1开始存储 */
/**
 * 二分查找
 */
Position BinarySearch(List L, ElementType X);

/**
 * 输入样例1：
 * 5
 * 12 31 55 89 101
 * 31
 * 输出样例1：
 * 2
 *
 * 输入样例2：
 * 3
 * 26 78 233
 * 31
 * 输出样例2：
 * 0
 */
int main() {
    List L;
    ElementType X;
    Position P;

    L = ReadInput();
    scanf("%d", &X);
    P = BinarySearch(L, X);
    printf("%d\n", P);

    return 0;
}

/* 你的代码将被嵌在这里 */

/* 元素从下标1开始存储 */
List ReadInput() {
    List L;
    int N, a;
    scanf("%d", &N);

    L = malloc(sizeof(struct LNode));
    L->Last = 0;

    while (N--) {
        scanf("%d", &a);
        L->Data[++L->Last] = a;
    }
    return L;
}

/**
 * 二分查找
 */
Position BinarySearch(List L, ElementType X) {
    int left, right, mid;
    left = 1;
    right = L->Last;
    while (left <= right) {
        mid = (left + right) / 2;
        if (X < L->Data[mid]) right = mid - 1;
        else if (X > L->Data[mid]) left = mid + 1;
        else return mid;
    }
    return NotFound;
}