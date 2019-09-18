//
// Created by zhaoxiaoli on 2019-08-31.
//
/**
 * @desc: 6-12 二叉搜索树的操作集
 * @author zhaoxiaoli
 * @date 2019-08-31
 */
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct TNode *Position;
typedef Position BinTree;
struct TNode {
    ElementType Data;
    BinTree Left;
    BinTree Right;
};

/**
 * 先序遍历
 */
void PreorderTraversal(BinTree BT);

/**
 * 中序遍历
 */
void InorderTraversal(BinTree BT);

/**
 * 插入：将X插入二叉搜索树BST并返回结果树的根结点指针
 */
BinTree Insert(BinTree BST, ElementType X);

/**
 * 删除：将X从二叉搜索树BST中删除，并返回结果树的根结点指针；如果X不在树中，则打印一行Not Found并返回原树的根结点指针
 */
BinTree Delete(BinTree BST, ElementType X);

/**
 * 查找：在二叉搜索树BST中找到X，返回该结点的指针；如果找不到则返回空指针
 */
Position Find(BinTree BST, ElementType X);

/**
 * 查找最小值：返回二叉搜索树BST中最小元结点的指针；
 */
Position FindMin(BinTree BST);

/**
 * 查找最大值：返回二叉搜索树BST中最大元结点的指针。
 */
Position FindMax(BinTree BST);

/**
 * 输入样例：
 * 10
 * 5 8 6 2 4 1 0 10 9 7
 * 5
 * 6 3 10 0 5
 * 5
 * 5 7 0 10 3
 *
 * 输出样例：
 * Preorder: 5 2 1 0 4 8 6 7 10 9
 * 6 is found
 * 3 is not found
 * 10 is found
 * 10 is the largest key
 * 0 is found
 * 0 is the smallest key
 * 5 is found
 * Not Found
 * Inorder: 1 2 4 6 8 9
 */
int main() {
    BinTree BST, MinP, MaxP, Tmp;
    ElementType X;
    int N, i;

    BST = NULL;
    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%d", &X);
        BST = Insert(BST, X);
    }
    printf("Preorder:");
    PreorderTraversal(BST);
    printf("\n");
    MinP = FindMin(BST);
    MaxP = FindMax(BST);
    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%d", &X);
        Tmp = Find(BST, X);
        if (Tmp == NULL) printf("%d is not found\n", X);
        else {
            printf("%d is found\n", Tmp->Data);
            if (Tmp == MinP) printf("%d is the smallest key\n", Tmp->Data);
            if (Tmp == MaxP) printf("%d is the largest key\n", Tmp->Data);
        }
    }
    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%d", &X);
        BST = Delete(BST, X);
    }
    printf("Inorder:");
    InorderTraversal(BST);
    printf("\n");

    return 0;
}
/* 你的代码将被嵌在这里 */

/**
 * 先序遍历
 */
void PreorderTraversal(BinTree BT) {
    if (BT) {
        printf(" %d", BT->Data);
        PreorderTraversal(BT->Left);
        PreorderTraversal(BT->Right);
    }
}

/**
 * 中序遍历
 */
void InorderTraversal(BinTree BT) {
    if (BT) {
        InorderTraversal(BT->Left);
        printf(" %d", BT->Data);
        InorderTraversal(BT->Right);
    }
}

/**
 * 插入：将X插入二叉搜索树BST并返回结果树的根结点指针
 */
BinTree Insert(BinTree BST, ElementType X) {
    if (!BST) {
        BST = malloc(sizeof(struct TNode));
        BST->Data = X;
        BST->Left = BST->Right = NULL;
    } else {
        if (BST->Data > X) {
            BST->Left = Insert(BST->Left, X);
        } else if (BST->Data < X) {
            BST->Right = Insert(BST->Right, X);
        }
    }
    return BST;
}

/**
 * 删除：将X从二叉搜索树BST中删除，并返回结果树的根结点指针；如果X不在树中，则打印一行Not Found并返回原树的根结点指针
 */
BinTree Delete(BinTree BST, ElementType X) {
    if (!BST) {
        printf("Not Found\n");
        return NULL;
    }

    if (BST->Data > X) {
        BST->Left = Delete(BST->Left, X);
    } else if (BST->Data < X) {
        BST->Right = Delete(BST->Right, X);
    } else {
        BinTree Tmp;
        /* BST就是要删除的结点 */
        /* 如果被删除结点有左右两个子结点 */
        if (BST->Left && BST->Right) {
            Tmp = FindMin(BST->Right);
            BST->Data = Tmp->Data;
            BST->Right = Delete(BST->Right, BST->Data);
        } else {
            Tmp = BST;
            if (BST->Left) {
                BST = BST->Left;
            } else {
                BST = BST->Right;
            }
            free(Tmp);
        }
    }
    return BST;
}


/**
 * 查找：在二叉搜索树BST中找到X，返回该结点的指针；如果找不到则返回空指针
 */
Position Find(BinTree BST, ElementType X) {
    if (!BST) {
        return NULL;
    }
    if (BST->Data < X) {
        return Find(BST->Right, X);
    } else if (BST->Data > X) {
        return Find(BST->Left, X);
    } else {
        return BST;
    }
}

/**
 * 查找最小值：返回二叉搜索树BST中最小元结点的指针；
 */
Position FindMin(BinTree BST) {
    while (BST && BST->Left) {
        BST = BST->Left;
    }
    return BST;
}

/**
 * 查找最大值：返回二叉搜索树BST中最大元结点的指针。
 */
Position FindMax(BinTree BST) {
    while (BST && BST->Right) {
        BST = BST->Right;
    }
    return BST;
}
