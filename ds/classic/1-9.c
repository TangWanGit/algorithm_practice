//
// Created by tangwan on 2019-09-02.
//
/**
 * @desc: 平衡二叉树
 * @author tangwan
 * @date 2019-09-02
 */
#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

typedef int ElementType;
typedef struct AVLNode *Position;
typedef Position AVLTree;/* AVL树类型 */

struct AVLNode {
    ElementType Data; /* 结点数据 */
    AVLTree Left; /* 指向左子树 */
    AVLTree Right;  /* 指向右子树 */
    int Height; /* 树高 */
};

AVLTree Insert(AVLTree T, ElementType X);

AVLTree Delete(AVLTree T, ElementType X);

int GetHeight(AVLTree T);

/**
 * 中序输出
 */
void InOrderTraversal(AVLTree T);

/**
 *
 */
int main() {
    int N, a;
    scanf("%d", &N);
    AVLTree T = NULL;
    while (N--) {
        scanf("%d", &a);
        T = Insert(T, a);
    }

    InOrderTraversal(T);

    scanf("%d", &a);

    AVLTree node = Delete(T, a);
    InOrderTraversal(node);
}

/**
 * 左单旋
 */
AVLTree SingleLeftRotation(AVLTree A) {
    /* 注意：A必须有一个左子结点B */
    /* 将A与B做左单旋，更新A与B的高度，返回新的根结点B */
    AVLTree B = A->Left;
    A->Left = B->Right;
    B->Right = A;
    A->Height = Max(GetHeight(A->Left), GetHeight(A->Right)) + 1;
    B->Height = Max(GetHeight(B->Left), A->Height) + 1;

    return B;
}

/**
 * 右单旋
 */
AVLTree SingleRightRotation(AVLTree A) {
    AVLTree B = A->Right;
    A->Right = B->Left;
    B->Left = A;
    A->Height = Max(GetHeight(A->Left), GetHeight(A->Right)) + 1;
    B->Height = Max(GetHeight(B->Right), A->Height) + 1;
    return B;
}

/**
 * 左-右双旋
 */
AVLTree DoubleLeftRightRotation(AVLTree A) {
/* 注意：A必须有一个左子结点B，且B必须有一个右子结点C */
    /* 将A、B与C做两次单旋，返回新的根结点C */

    /* 将B与C做右单旋，C被返回 */
    A->Left = SingleRightRotation(A->Left);
    return SingleLeftRotation(A);
}

/**
 *  右-左双旋
 */
AVLTree DoubleRightLeftRotation(AVLTree A) {
    A->Right = SingleLeftRotation(A->Right);
    return SingleRightRotation(A);
}

/*************************************/
/* 对称的右单旋与右-左双旋请自己实现 */
/*************************************/

AVLTree Insert(AVLTree T, ElementType X) {
    if (!T) {
        T = malloc(sizeof(struct AVLNode));
        T->Data = X;
        T->Left = T->Right = NULL;
        T->Height = 0;
    } else if (X < T->Data) {
        T->Left = Insert(T->Left, X);
        if (GetHeight(T->Left) - GetHeight(T->Right) == 2) {
            if (X < T->Left->Data) {
                T = SingleLeftRotation(T);
            } else {
                T = DoubleLeftRightRotation(T);
            }
        }
    } else if (X > T->Data) {
        T->Right = Insert(T->Right, X);
        if (GetHeight(T->Left) - GetHeight(T->Right) == -2) {
            if (X > T->Right->Data) {
                T = SingleRightRotation(T);
            } else {
                T = DoubleRightLeftRotation(T);
            }
        }
    }

    T->Height = Max(GetHeight(T->Left), GetHeight(T->Right)) + 1;
    return T;
}

//todo 先暂时空着
AVLTree Delete(AVLTree T, ElementType X) {
    return T;
}


int GetHeight(AVLTree T) {
    return T ? T->Height : 0;
    //if (!T) {
    //    return 0;
    //}
    //return Max(GetHeight(T->Left), GetHeight(T->Right)) + 1;
}

/**
 * 中序输出
 */
void InOrderTraversal(AVLTree T) {
    AVLTree Stack[1000];
    int top = -1;
    while (T || top > -1) {
        while (T) {
            Stack[++top] = T;
            T = T->Left;
        }

        if (top > -1) {
            T = Stack[top--];
            printf("%d %d, ", T->Data, T->Height);
            T = T->Right;
        }
    }
    printf("\n");
}