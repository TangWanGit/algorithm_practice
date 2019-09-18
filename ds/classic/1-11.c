//
// Created by zhaoxiaoli on 2019-09-04.
//
/**
 * @desc: 
 * @author zhaoxiaoli
 * @date 2019-09-04
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode *HuffmanTree;
struct TreeNode {
    int Weight;
    HuffmanTree Left, Right;
};
typedef int ElementType;
typedef struct HeapStruct *MinHeap;
struct HeapStruct {
    ElementType *Elements; /* 存储堆元素的数组 */
    int Size; /* 堆的当前元素个数 */
    int Capacity; /* 堆的最大容量*/
};

HuffmanTree Huffman(MinHeap H);

MinHeap BuildMinHeap(MinHeap H);

ElementType DeleteMin(MinHeap H);

MinHeap Insert(MinHeap H, HuffmanTree T);

int main() {

    //Huffman();
}

HuffmanTree Huffman(MinHeap H) {
    /* 假设H->Size个权值已经存在H->Elements[]->Weight里*/
    int i;
    HuffmanTree T;
    BuildMinHeap(H); /*将H->Elements[]按权值调整为最小堆*/
    for (i = 1; i < H->Size; i++) { /*做H->Size-1次合并*/
        T = malloc(sizeof(struct TreeNode)); /*建立新结点*/

        /*从最小堆中删除一个结点，作为新T的左子结点*/
        T->Left = DeleteMin(H);

        /*从最小堆中删除一个结点，作为新T的右子结点*/
        T->Right = DeleteMin(H);

        /*计算新权值*/
        T->Weight = T->Left->Weight + T->Right->Weight;

        /*将新T插入最小堆*/
        Insert(H, T);
    }
    T = DeleteMin(H);
    return T;
}
