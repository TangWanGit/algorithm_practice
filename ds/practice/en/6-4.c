//
// Created by tangwan on 2019-09-10.
//
/**
 * @desc:  Reverse Linked List
 * @author tangwan
 * @date 2019-09-10
 */

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
struct Node {
    ElementType Element;
    Position Next;
};

/**
 * 读入list
 */
List Read();

void Print(List L);

/**
 * 逆反
 */
List Reverse(List L);

/**
Sample Input:

5
1 3 4 5 2
Sample Output:

2 5 4 3 1
2 5 4 3 1
 */
int main() {
    List L1, L2;
    L1 = Read();
    L2 = Reverse(L1);
    Print(L1);
    Print(L2);
    return 0;
}

/* Your function will be put here */

/**
 * 读入list
 */
List Read() {
    List L, rear, tmp;

    int N;
    scanf("%d", &N);
    L = malloc(sizeof(struct Node));
    L->Next = NULL;
    rear = L;
    while (N--) {
        tmp = malloc(sizeof(struct Node));
        scanf("%d", &tmp->Element);
        rear->Next = tmp;
        tmp->Next = NULL;

        rear = tmp;
    }
    tmp = L;
    L = L->Next;
    free(tmp);
    return L;
}

void Print(List L) {
    while (L) {
        printf("%d ", L->Next);
        L = L->Next;
    }
}

Position ReverseW(Position head, int K) {
    int cnt = 1;
    Position new, old, tmp;
    new = head->Next;
    old = new->Next;
    while (cnt < K) {
        tmp = old->Next;
        old->Next = new;
        new = old;
        old = tmp;
        cnt++;
    }
    head->Next->Next = old;
    return new;
}

/**
 * 逆反
 */
List Reverse(List L) {
    return ReverseW(L, 5);
}
