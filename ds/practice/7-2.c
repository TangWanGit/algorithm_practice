//
// Created by tangwan on 2019-08-28.
// 一元多项式的乘法与加法运算（链表实现法）

#include <stdio.h>
#include <stdlib.h>

typedef struct PolyNode *Polynomial;
struct PolyNode {
    int coef; // 系数 coefficient
    int expon;// 指数 exponential
    Polynomial link;
};

/**
 * 读取多项式
 */
Polynomial Read();

/**
 * 多项式相乘
 */
Polynomial Multiply(Polynomial p1, Polynomial p2);

/**
 * 多项式相加
 */
Polynomial Add(Polynomial p1, Polynomial p2);

/**
 * 打印多项式
 */
void PrintPolynomial(Polynomial p);

/**
 * 向后追加链
 */
void Attach(int c, int e, Polynomial *pRear);

/**
 * a>b 1
 * a=b 0
 * a<b -1
 */
int Compare(int a, int b);

/**
 * 输入分2行，每行分别先给出多项式非零项的个数，再以指数递降方式输入一个多项式非零项系数和指数（绝对值均为不超过1000的整数）。数字间以空格分隔。
 * 输出分2行，分别以指数递降方式输出乘积多项式以及和多项式非零项的系数和指数。数字间以空格分隔，但结尾不能有多余空格。零多项式应输出0 0。
 *
 * 输入样例:
 * 4 3 4 -5 2  6 1  -2 0
 * 3 5 20  -7 4  3 1
 *
 * 输出样例:
 * 15 24 -25 22 30 21 -10 20 -21 8 35 6 -33 5 14 4 -15 3 18 2 -6 1
 * 5 20 -4 4 -5 2 9 1 -2 0
 */
int main() {
    Polynomial P1, P2, PP, PS;

    P1 = Read();
    P2 = Read();

    PP = Multiply(P1, P2);
    PS = Add(P1, P2);
    PrintPolynomial(PP);
    PrintPolynomial(PS);
    return 0;
}

/**
 * 读取多项式
 */
Polynomial Read() {
    Polynomial P, Rear, t;
    int c, e, N;
    scanf("%d", &N);

    /*链表头空结点*/
    P = malloc(sizeof(struct PolyNode));
    P->link = NULL;
    Rear = P;

    while (N--) {
        scanf("%d %d", &c, &e);
        /* 将当期项插入多项式尾部*/
        Attach(c, e, &Rear);
    }

    /* 删除临时生成的头结点*/
    t = P;
    P = P->link;
    free(t);
    return P;
}

/**
 * 多项式相乘
 * 逐项插入：
 *  将P1当前项乘P2当前项，并插入到结果多项式中，关键是要找到插入位置
 */
Polynomial Multiply(Polynomial P1, Polynomial P2) {
    Polynomial P, Rear, t1, t2, t;
    int c, e;

    if (!P1 || !P2)
        return NULL;

    P = malloc(sizeof(struct PolyNode));
    P->link = NULL;
    Rear = P;
    t1 = P1;
    t2 = P2;

    // 先用P1的第一项乘以P2，得到P
    while (t2) {
        Attach(t1->coef * t2->coef, t1->expon + t2->expon, &Rear);
        t2 = t2->link;
    }

    t1 = t1->link;
    while (t1) {
        t2 = P2;
        Rear = P;
        while (t2) {
            c = t1->coef * t2->coef;
            e = t1->expon + t2->expon;
            while (Rear->link && Rear->link->expon > e) {
                Rear = Rear->link;
            }

            if (Rear->link && Rear->link->expon == e) {
                if (Rear->link->coef + c) {
                    Rear->link->coef += c;
                } else {
                    t = Rear->link;
                    Rear->link = t->link;
                    free(t);
                }
            } else {
                t = malloc(sizeof(struct PolyNode));
                t->coef = c;
                t->expon = e;
                t->link = Rear->link;
                Rear->link = t;
                Rear = Rear->link;
            }
            t2 = t2->link;
        }
        t1 = t1->link;
    }

    t = P;
    P = P->link;
    free(t);
    return P;
}

/**
 * 多项式相加
 */
Polynomial Add(Polynomial P1, Polynomial P2) {
    Polynomial P, Rear, t1, t2, t;
    int sum;

    P = malloc(sizeof(struct PolyNode));
    P->link = NULL;
    Rear = P;
    t1 = P1;
    t2 = P2;

    while (t1 && t2) {
        switch (Compare(t1->expon, t2->expon)) {
            case 1:
                Attach(t1->coef, t1->expon, &Rear);
                t1 = t1->link;
                break;
            case -1:
                Attach(t2->coef, t2->expon, &Rear);
                t2 = t2->link;
                break;
            case 0:
                sum = t1->coef + t2->coef;
                if (sum) {
                    Attach(sum, t1->expon, &Rear);
                }
                t1 = t1->link;
                t2 = t2->link;
                break;
            default:
                break;
        }
    }

    for (; t1; t1 = t1->link) Attach(t1->coef, t1->expon, &Rear);
    for (; t2; t2 = t2->link) Attach(t2->coef, t2->expon, &Rear);

    t = P;
    P = P->link;
    free(t);
    return P;
}

int Compare(int a, int b) {
    return a > b ? 1 : a == b ? 0 : -1;
}

/**
 * 打印多项式
 */
void PrintPolynomial(Polynomial P) {
    int flag = 0;
    if (!P) {
        printf("0 0\n");
        return;
    }
    while (P) {
        !flag ? (flag = 1) : printf(" ");

        printf("%d %d", P->coef, P->expon);
        P = P->link;
    }
    printf("\n");
}

/**
 * 在Rear后追加数据
 */
void Attach(int c, int e, Polynomial *pRear) {
    Polynomial P = malloc(sizeof(struct PolyNode));
    P->coef = c;
    P->expon = e;
    P->link = NULL;
    (*pRear)->link = P;

    /* 修改pRear值，指向P*/
    *pRear = P;
}
