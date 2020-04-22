//
// Created by tangwan on 2019-09-02.
//
/**
 * @desc: 搜索二叉树
 * @author tangwan
 * @date 2019-09-02
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
 * 线索二叉树插入：左子树小于根结点，右子树大于根结点
 */
BinTree Insert(BinTree BST, ElementType X);

/**
 * 删除：
 * 1. 若删除的结点有左右孩子，则从右孩子中获取最小的值，替换为当前的值
 * 2. 若删除的结点有左孩子，则将左孩子的结点指向该结点
 * 3. 若删除的结点有右孩子，则将右孩子的结点指向该结点
 * 4. 若删除的结点无孩子，则直接删除
 */
BinTree Delete(BinTree BST, ElementType X);

/**
 * 获取最小结点：即最左端结点
 */
BinTree FindMin(BinTree BST);

/**
 * 获取最大结点：即最右端结点
 */
BinTree FindMax(BinTree BST);

/**
 * 中序输出
 */
void InOrderTraversal(BinTree BT);

/**
 * 依次输入5，4，3，2，1，6，7，8，9
 */
int main() {
    int N, x;
    scanf("%d", &N);
    BinTree BST = NULL;
    while (N--) {
        scanf("%d", &x);
        BST = Insert(BST, x);
    }

    InOrderTraversal(BST);

    BinTree node = Delete(BST, 6);

    InOrderTraversal(node);

    BinTree Max = FindMax(BST);
    printf("max %d \n", Max->Data);

    BinTree Min = FindMin(BST);
    printf("min %d", Min->Data);
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
            printf("%d ", BT->Data);
            BT = BT->Right;
        }
    }
    printf("\n");
}


BinTree Insert(BinTree BST, ElementType X) {
    if (!BST) {
        /* 若原树为空，生成并返回一个结点的二叉搜索树 */
        BST = malloc(sizeof(struct TNode));
        BST->Data = X;
        BST->Left = BST->Right = NULL;
    } else {
        /* 开始找要插入元素的位置 */
        if (X < BST->Data) {
            /*递归插入左子树*/
            BST->Left = Insert(BST->Left, X);
        } else if (X > BST->Data) {
            /*递归插入右子树*/
            BST->Right = Insert(BST->Right, X);
        }
        /* else X已经存在，什么都不做 */
    }
    return BST;
}

BinTree Delete(BinTree BST, ElementType X) {
    Position Tmp;

    if (!BST)
        printf("not find");
    else {
        if (X < BST->Data) {
            /* 从左子树递归删除 */
            BST->Left = Delete(BST->Left, X);
        } else if (X > BST->Data) {
            /* 从右子树递归删除 */
            BST->Right = Delete(BST->Right, X);
        } else {
            /* BST就是要删除的结点 */
            /* 如果被删除结点有左右两个子结点 */
            if (BST->Left && BST->Right) {
                /* 从右子树中找最小的元素填充删除结点 */
                Tmp = FindMin(BST->Right);
                BST->Data = Tmp->Data;
                /* 从右子树中删除最小元素 */
                BST->Right = Delete(BST->Right, BST->Data);
            } else {
                /* 被删除结点有一个或无子结点 */
                Tmp = BST;
                if (!BST->Left) {
                    /* 只有右孩子或无子结点 */
                    BST = BST->Right;
                } else {
                    /* 只有左孩子 */
                    BST = BST->Left;
                }
                free(Tmp);
            }
        }
    }
    return BST;
}

BinTree FindMin(BinTree BST) {
    while (BST && BST->Left) {
        BST = BST->Left;
    }
    return BST;
}

BinTree FindMax(BinTree BST) {
    while (BST && BST->Right) {
        BST = BST->Right;
    }
    return BST;
}