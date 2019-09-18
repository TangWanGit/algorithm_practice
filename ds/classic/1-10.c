//
// Created by zhaoxiaoli on 2019-09-04.
//
/**
 * @desc: 最大堆的实现
 * @author zhaoxiaoli
 * @date 2019-09-04
 */
#include <stdlib.h>
#include <stdio.h>

typedef int ElementType;
typedef struct HeapStruct *MaxHeap;
struct HeapStruct {
    ElementType *Elements; /* 存储堆元素的数组 */
    int Size; /* 堆的当前元素个数 */
    int Capacity; /* 堆的最大容量*/
};

#define MaxData 1000;

MaxHeap Create(int MaxSize);

void Insert(MaxHeap H, ElementType item);

int IsFull(MaxHeap H);

int IsEmpty(MaxHeap H);

ElementType DeleteMax(MaxHeap H);

int main() {
    MaxHeap PtrH = Create(10);
    for (int i = 0; i < 10; ++i) {
        Insert(PtrH, i);
    }

    while (!IsEmpty(PtrH)) {
        ElementType i = DeleteMax(PtrH);
        printf("%d ", i);
    }
}

MaxHeap Create(int MaxSize) {
/* 创建容量为MaxSize的空的最大堆 */
    MaxHeap H = malloc(sizeof(struct HeapStruct));
    H->Elements = malloc((MaxSize + 1) * sizeof(ElementType));
    H->Size = 0;
    H->Capacity = MaxSize;
    H->Elements[0] = MaxData;
/* 定义“哨兵”为大于堆中所有可能元素的值，便于以后更快操作 */
    return H;
}

/**
 * 将元素item 插入最大堆H，其中H->Elements[0]已经定义为哨兵
 */
void Insert(MaxHeap H, ElementType item) { /* 将元素item 插入最大堆H，其中H->Elements[0]已经定义为哨兵 */
    int i;
    if (IsFull(H)) {
        printf("最大堆已满");
        return;
    }
    i = ++H->Size; /* i指向插入后堆中的最后一个元素的位置 */
    // H->Element[ 0 ] 是哨兵元素， 它不小于堆中的最大元素，控制顺环结束
    for (; H->Elements[i / 2] < item; i /= 2)
        H->Elements[i] = H->Elements[i / 2]; /* 向下过滤结点 */
    H->Elements[i] = item; /* 将item 插入 */
}

/**
 * 从最大堆H中取出键值为最大的元素，并删除一个结点
 */
ElementType DeleteMax(MaxHeap H) { /* 从最大堆H中取出键值为最大的元素，并删除一个结点 */
    int Parent, Child;
    ElementType MaxItem, temp;
    if (IsEmpty(H)) {
        printf("最大堆已为空");
        return NULL;
    }
    MaxItem = H->Elements[1]; /* 取出根结点最大值 */
    /* 用最大堆中最后一个元素从根结点开始向上过滤下层结点 */
    temp = H->Elements[H->Size--];
    /* Parent*2<=H->Size
        判断当前结点是否有左儿子，如果没有左儿子就确定没有右儿子*/
    for (Parent = 1; Parent * 2 <= H->Size; Parent = Child) {
        Child = Parent * 2;
        /*Child=H->Size代表左儿子是最后一个结点，没有右儿子*/
        if ((Child != H->Size) && (H->Elements[Child] < H->Elements[Child + 1]))
            Child++; /* Child指向左右子结点的较大者 */
        if (temp >= H->Elements[Child])
            break;
        else /* 移动temp元素到下一层 */
            H->Elements[Parent] = H->Elements[Child];
    }
    H->Elements[Parent] = temp;
    return MaxItem;
}

int IsFull(MaxHeap H) {
    return H->Size == H->Capacity ? 1 : 0;
}

int IsEmpty(MaxHeap H) {
    return H->Size == 0 ? 1 : 0;
}