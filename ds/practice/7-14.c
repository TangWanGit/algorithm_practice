//
// Created by zhaoxiaoli on 2019-09-14.
//
/**
 * @desc: 7-14 电话聊天狂人
 * @author zhaoxiaoli
 * @date 2019-09-14
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* 关键词字符串的最大长度 */
#define KEY_LENGTH 11
#define MAX_D 5
#define MAX_TABLE_SIZE 1000000

/* 关键词类型用字符串 */
typedef char ElementType[1 + KEY_LENGTH];
/* 散列地址类型 */
typedef int Index;

typedef struct LNode *PtrToNode;
struct LNode {
    ElementType Data;
    PtrToNode Next;
    int Count;
};
typedef PtrToNode Position;
typedef PtrToNode List;

typedef struct TblNode *HashTable;
/* 散列表结点定义 */
struct TblNode {
    int TableSize; /* 表的最大长度 */
    List Heads;    /* 指向链表头结点的数组 */
};

/**
 * 创建hashTable
 */
HashTable CreateTable(int N);

/**
 * 插入key
 */
void Insert(HashTable H, ElementType Key);

/**
 * 扫描全表并输出电话狂人
 */
void ScanAndOutput(HashTable H);

/**
 * 销毁hashTable
 */
void DestroyTable(HashTable H);

/**
输入样例:

4
13005711862 13588625832
13505711862 13088625832
13588625832 18087925832
15005713862 13588625832
输出样例:

13588625832 3
 */
int main() {
    int N, i;
    ElementType Key;
    HashTable H;

    scanf("%d", &N);
    H = CreateTable(N * 2);
    for (i = 0; i < N; i++) {
        scanf("%s", Key);
        Insert(H, Key);
        scanf("%s", Key);
        Insert(H, Key);
    }

    ScanAndOutput(H);
    DestroyTable(H);
    return 0;
}

/**
 * 输出狂人
 */
void ScanAndOutput(HashTable H) {
    int i, MaxCnt = 0, PCnt = 0;
    ElementType MinPhone;
    List Ptr;
    MinPhone[0] = '\0';
    for (i = 0; i < H->TableSize; i++) {/* 扫描链表 */
        Ptr = H->Heads[i].Next;
        while (Ptr) {
            if (Ptr->Count > MaxCnt) { /* 更新最大通话次数 */
                MaxCnt = Ptr->Count;
                strcpy(MinPhone, Ptr->Data);
                PCnt = 1;
            } else if (Ptr->Count == MaxCnt) {
                PCnt++;/* 狂人计数 */
                if (strcmp(MinPhone, Ptr->Data) > 0) {
                    strcpy(MinPhone, Ptr->Data); /* 更新狂人的最小手机号码 */
                }
            }
            Ptr = Ptr->Next;
        }
    }
    printf("%s %d", MinPhone, MaxCnt);
    if (PCnt > 1) printf(" %d", PCnt);
    printf("\n");
}

int NextPrime(int N) {
    /* 返回大于N且不超过MAX_TABLE_SIZE的最小素数 */
    int i, p = (N % 2) ? N + 2 : N + 1;/*从大于N的下一个奇数开始 */
    while (p < MAX_TABLE_SIZE) {
        for (i = (int) sqrt(p); i > 2; i--) {
            if (!(p % i)) break; /* p不是素数 */
        }
        if (i == 2) break;  /* for正常结束，说明p是素数 */
        else p += 2;/* 否则试探下一个奇数 */
    }
    return p;
}


HashTable CreateTable(int N) {
    HashTable H;
    int i;

    H = malloc(sizeof(struct TblNode));
    H->TableSize = NextPrime(N);
    H->Heads = malloc(H->TableSize * sizeof(struct LNode));
    for (i = 0; i < H->TableSize; i++) {
        H->Heads[i].Data[0] = '\0';
        H->Heads[i].Next = NULL;
        H->Heads[i].Count = 0;
    }
    return H;
}

int Hash(int Key, int N) {
    /* 除留余数法法散列函数 */
    return Key % N;
}

Position Find(HashTable H, ElementType Key) {
    Position P;
    Index Pos;

    Pos = Hash(atoi(Key + KEY_LENGTH
                    - MAX_D), H->TableSize);

    P = H->Heads[Pos].Next; /* 从该链表的第1个结点开始 */
    /* 当未到表尾，并且Key未找到时 */
    while (P && strcmp(P->Data, Key))
        P = P->Next;

    /* 此时P或者指向找到的结点，或者为NULL */
    return P;
}

void Insert(HashTable H, ElementType Key) {
    Position P, NewCell;
    Index Pos;
    P = Find(H, Key);
    if (!P) {/* 关键词未找到，可以插入 */
        NewCell = malloc(sizeof(struct LNode));
        strcpy(NewCell->Data, Key);
        NewCell->Count = 1;
        Pos = Hash(atoi(Key + KEY_LENGTH
                        - MAX_D), H->TableSize);
        NewCell->Next = H->Heads[Pos].Next;
        H->Heads[Pos].Next = NewCell;
    } else {
        P->Count++;
    }
}

void Destroy(List L) {
    if (L->Next == NULL) {
        free(L);
    } else {
        Destroy(L->Next);
    }
}

void DestroyTable(HashTable H) {
    Destroy(H->Heads);
    free(H);
}