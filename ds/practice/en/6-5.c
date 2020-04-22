//
// Created by tangwan on 2019-09-12.
//
/**
 * @desc: 6-5 Evaluate Postfix Expression
 * 计算后缀表达式
 * @author tangwan
 * @date 2019-09-12
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef double ElementType;
#define Infinity 1e8
#define Max_Expr 30   /* max size of expression */

/**
 * 后缀表达式计算：
 * 1. 遇到数字push
 * 2. 遇到字符pop两个数字进行计算，将结果push
 *
 * 错误判断：
 * 1. 每次需要两个数字进行计算，所以一次性需要pop出两个数字，若不存在，则返回Infinity
 * 2. 表达式计算规则：0不能作为分母
 */
ElementType EvalPostfix(char *expr);

/**
Sample Input 1:

11 -2 5.5 * + 23 7 / -
Sample Output 1:

-3.285714
Sample Input 2:

11 -2 5.5 * + 23 0 / -
Sample Output 2:

ERROR
Sample Input 3:

11 -2 5.5 * + 23 7 / - *
Sample Output 3:

ERROR
 */
int main() {
    ElementType v;
    char expr[Max_Expr];
    gets(expr);
    v = EvalPostfix(expr);
    if (v < Infinity)
        printf("%f\n", v);
    else
        printf("ERROR\n");
    return 0;
}

/* Your function will be put here */

typedef struct Node *PtrToNode;
typedef struct Node {
    ElementType Data;
    PtrToNode Next;
} N;
typedef PtrToNode Stack;

Stack Create() {
    Stack S = malloc(sizeof(struct Node));
    S->Next = NULL;
}

void Push(Stack S, ElementType X) {
    PtrToNode Node = malloc(sizeof(struct Node));
    Node->Data = X;
    Node->Next = S->Next;
    S->Next = Node;
}

ElementType Pop(Stack S) {
    if (S->Next == NULL) {
        return Infinity;
    }
    PtrToNode Pop = S->Next;
    ElementType elementType = Pop->Data;
    free(Pop);
    return elementType;
}

int getCharEndIndex(char *expr, int index) {
    for (index; index < Max_Expr; index++) {
        if (expr[index] == ' ') {
            break;
        }
    }
    return index;
}

char *GetEval(char *src, int from, int to) {
    int length = to - from;
    char dest[length];
    strncpy(dest, src + from, length);
    return dest;
}

/**
 * 后缀表达式计算：
 * 1. 遇到数字push
 * 2. 遇到字符pop两个数字进行计算，将结果push
 *
 * 错误判断：
 * 1. 每次需要两个数字进行计算，所以一次性需要pop出两个数字，若不存在，则返回Infinity
 * 2. 表达式计算规则：0不能作为分母
 */
ElementType EvalPostfix(char *expr) {
    Stack S = Create();
    for (int i = 0; expr[i];) {
        int to = getCharEndIndex(expr, i);
        char *c = GetEval(expr, i, to);
        if ((c[0] >= '0' && c[0] <= '9') || (to - i >= 2 && c[1] == '-' && c[1] >= '0' && c[1] <= '9')) {
            Push(S, atof(c));
            i = to;
            continue;
        }

        if (!(c[0] == '+' || c[0] == '-' || c[0] == '*' || c[0] == '/')) {
            return Infinity;
        }
        ElementType e1 = Pop(S);
        ElementType e2 = Pop(S);
        if (e1 == Infinity || e2 == Infinity) {
            return Infinity;
        }
        switch (c[0]) {
            case '+':
                Push(S, e1 + e2);
                break;
            case '-':
                Push(S, e1 - e2);
                break;
            case '*':
                Push(S, e1 * e2);
                break;
            case '/':
                if (e2 == 0) {
                    return Infinity;
                }
                Push(S, e1 / e2);
                break;
        }
        i = to;
    }
    return Pop(S);
}