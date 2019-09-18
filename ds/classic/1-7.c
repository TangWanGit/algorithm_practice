//
// Created by zhaoxiaoli on 2019-09-02.
//
/**
 * @desc: 
 * @author zhaoxiaoli
 * @date 2019-09-02
 */

#include <stdio.h>
#include <stdlib.h>

typedef enum {
    true, false
} bool;
typedef char ElementType;
typedef struct TNode *BinTree;
//typedef Position BinTree;
struct TNode {
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

BinTree CreateTree();

/**
 * 中序
 */
void InOrderTraversal(BinTree BT);

/**
 * 前序
 */
void PreOrderTraversal(BinTree BT);

/**
 * 后序
 */
void PostOrderTraversal(BinTree BT);

/**
 *      A
 *  B         C
 *D    F    G   I
 *    E       H
 *
 * Inorder: D B E F A G H C I
 * Preorder: A B D F E C G H I
 * Postorder: D E F B H G I C A
 */
int main() {
    BinTree BT = CreateTree();
    printf("Inorder:");
    InOrderTraversal(BT);
    printf("\n");
    printf("Preorder:");
    PreOrderTraversal(BT);
    printf("\n");
    printf("Postorder:");
    PostOrderTraversal(BT);
    printf("\n");
}

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

BinTree CreateTree() {
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

void InOrderTraversal(BinTree BT) {
    BinTree Stack[1000];
    int top = -1;
    while (BT || top > -1) {
        while (BT) {
            Stack[++top] = BT;
            BT = BT->Left;
        }
        if (top > -1) {
            BT = Stack[top--];
            printf(" %c", BT->Data);
            BT = BT->Right;
        }
    }
}

void PreOrderTraversal(BinTree BT) {
    BinTree Stack[1000];
    int top = -1;
    while (BT || top > -1) {
        while (BT) {
            printf(" %c", BT->Data);
            Stack[++top] = BT;
            BT = BT->Left;
        }
        if (top > -1) {
            BT = Stack[top--];
            BT = BT->Right;
        }
    }
}

// 有问题的版本
void PostOrderTraversal(BinTree BT) {
    BinTree Stack[1000];
    int top = -1;
    while (BT || top > -1) {
        while (BT) {
            Stack[++top] = BT;
            BT = BT->Left;
        }
        if (top > -1) {
            BT = Stack[top--];
            if (BT->Right) {
                printf(" %c", BT->Right->Data);
                printf(" %c", BT->Data);
            }

            BT = BT->Right;
        }
    }
}


void LevelOrderTraversal(BinTree BT) {
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