//
// Created by tangwan on 2019-08-28.
//

#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode {
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

BinTree CreatBinTree(); /* 实现细节忽略 */
int GetHeight(BinTree BT);

/**
 *      A
 *  B         C
 *D    F    G   I
 *    E       H
 */
int main() {
    BinTree BT = CreatBinTree();
    printf("%d\n", GetHeight(BT));
    return 0;
}

/* 你的代码将被嵌在这里 */

BinTree addBinTree(BinTree Tree, int left, ElementType X) {
    BinTree child = malloc(sizeof(struct TNode));
    child->Data = X;
    child->Right = NULL;
    child->Left = NULL;
    if (left) {
        Tree->Left = child;
    } else {
        Tree->Right = child;
    }
    return child;
}

/**
 * 创建树
 */
BinTree CreatBinTree() {
    BinTree head = malloc(sizeof(struct TNode));
    head->Data = 'A';
    BinTree left = addBinTree(head, 1, 'B');
    BinTree right = addBinTree(head, 0, 'C');

    addBinTree(left, 1, 'D');
    BinTree f = addBinTree(left, 0, 'F');
    addBinTree(f, 1, 'E');

    BinTree g = addBinTree(right, 1, 'G');
    addBinTree(g, 0, 'H');
    addBinTree(right, 0, 'I');

    return head;
}


/**
 * 获取树的高度
 */
int GetHeight(BinTree BT) {
    int right, left, max;
    if (BT) {
        left = GetHeight(BT->Left);
        right = GetHeight(BT->Right);
        max = left > right ? left : right;
        return max + 1;
    }
    return 0;
}