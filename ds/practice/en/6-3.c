//
// Created by tangwan on 2019-09-10.
//
/**
 * @desc: 6-3 Add Two Polynomials
 * @author tangwan
 * @date 2019-09-10
 */

#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

typedef struct Node *PtrToNode;
struct Node {
    int Coefficient;
    int Exponent;
    PtrToNode Next;
};
typedef PtrToNode Polynomial;

Polynomial Read(); /* details omitted */
void Print(Polynomial p); /* details omitted */
/**
 * 多项式相加
 */
Polynomial Add(Polynomial a, Polynomial b);

/**
 * 输入模板：
 * 多项式个数
 * 系数 指数
Sample Input:

4
3 4 -5 2 6 1 -2 0
3
5 20 -7 4 3 1

Sample Output:

5 20 -4 4 -5 2 9 1 -2 0

 */
int main() {
    Polynomial a, b, s;
    a = Read();
    b = Read();
    s = Add(a, b);
    Print(s);
    return 0;
}

/* Your function will be put here */
Polynomial Read() {
    Polynomial P, pre, tmp;
    int N;
    scanf("%d", &N);
    P = malloc(sizeof(struct Node));
    P->Next = NULL;
    pre = P;
    while (N--) {
        tmp = malloc(sizeof(struct Node));
        scanf("%d %d", &tmp->Coefficient, &tmp->Exponent);
        tmp->Next = NULL;
        pre->Next = tmp;
        pre = tmp;
    }

    tmp = P;
    P = P->Next;
    free(tmp);
    return P;
}

void Print(Polynomial p) {
    if (!p) {
        printf("0 0\n");
        return;
    }
    int flag = 0;
    while (p) {
        !flag ? (flag = 1) : printf(" ");
        printf("%d %d", p->Coefficient, p->Exponent);
        p = p->Next;
    }
}

void Attach(Polynomial *Rear, int c, int e) {
    Polynomial P = malloc(sizeof(struct Node));
    P->Coefficient = c;
    P->Exponent = e;
    P->Next = NULL;

    (*Rear)->Next = P;
    *Rear = P;
}

/**
 * 多项式相加
 */
Polynomial Add(Polynomial a, Polynomial b) {
    int sum;
    Polynomial P, rear, p1, p2;
    p1 = a->Next, p2 = b->Next;
    P = malloc(sizeof(struct Node));
    P->Next = NULL;
    rear = P;
    while (p1 && p2) {
        switch (Compare(p1->Exponent, p2->Exponent)) {
            case 1:
                Attach(&rear, p1->Coefficient, p1->Exponent);
                p1 = p1->Next;
                break;
            case -1:
                Attach(&rear, p2->Coefficient, p2->Exponent);
                p2 = p2->Next;
                break;
            case 0:
                sum = p1->Coefficient + p2->Coefficient;
                if (sum) {
                    Attach(&rear, sum, p1->Exponent);
                }
                p1 = p1->Next;
                p2 = p2->Next;
                break;
            default:
                break;
        }
    }

    for (; p1; p1 = p1->Next) Attach(&rear, p1->Coefficient, p1->Exponent);
    for (; p2; p2 = p2->Next) Attach(&rear, p2->Coefficient, p2->Exponent);

    return P;
}