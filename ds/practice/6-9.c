//
// Created by tangwan on 2019-08-31.
//
/**
 * @desc: 6-9 二叉树的遍历 - 使用递归
 * @author tangwan
 * @date 2019-08-31
 */
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

/**
 * 创建树
 */
BinTree CreatBinTree();

/**
 * 中序遍历
 */
void InorderTraversal(BinTree BT);

/**
 * 前序遍历
 */
void PreorderTraversal(BinTree BT);

/**
 * 后序遍历
 */
void PostorderTraversal(BinTree BT);

/**
 * 层次遍历
 */
void LevelorderTraversal(BinTree BT);

/**
 *      A
 *  B         C
 *D    F    G   I
 *    E       H
 *
 * Inorder: D B E F A G H C I
 * Preorder: A B D F E C G H I
 * Postorder: D E F B H G I C A
 * Levelorder: A B C D F G I E H
 */
int main() {
    BinTree BT = CreatBinTree();
    printf("Inorder:");
    InorderTraversal(BT);
    printf("\n");
    printf("Preorder:");
    PreorderTraversal(BT);
    printf("\n");
    printf("Postorder:");
    PostorderTraversal(BT);
    printf("\n");
    printf("Levelorder:");
    LevelorderTraversal(BT);
    printf("\n");
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
 * 中序遍历
 */
void InorderTraversal(BinTree BT) {
    if (BT) {
        InorderTraversal(BT->Left);
        printf(" %c", BT->Data);
        InorderTraversal(BT->Right);
    }
}

/**
 * 前序遍历
 */
void PreorderTraversal(BinTree BT) {
    if (BT) {
        printf(" %c", BT->Data);
        PreorderTraversal(BT->Left);
        PreorderTraversal(BT->Right);
    }
}

/**
 * 后序遍历
 */
void PostorderTraversal(BinTree BT) {
    if (BT) {
        PostorderTraversal(BT->Left);
        PostorderTraversal(BT->Right);
        printf(" %c", BT->Data);
    }
}

/**
 * 层次遍历
 */
void LevelorderTraversal(BinTree BT) {
    BinTree queue[1000];
    int front = -1;
    int rear = -1;
    if (BT)
        queue[++rear] = BT;

    while (front < rear) {
        BinTree delete = queue[++front];
        printf(" %c", delete->Data);
        if (delete->Left) {
            queue[++rear] = delete->Left;
        }
        if (delete->Right) {
            queue[++rear] = delete->Right;
        }
    }
}

