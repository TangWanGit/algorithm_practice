//
// Created by tangwan on 2019-09-10.
//
/**
 * @desc: 
 * @author tangwan
 * @date 2019-09-10
 */
#include <stdio.h>
#include <stdlib.h>

#define MaxSize 10*10*10*10

typedef int ElementType;            /*默认元素可以用非负整数表示*/
typedef int SetName;                /*默认用根结点的下标作为集合名称*/
typedef ElementType SetType[MaxSize];

SetName Find(SetType S, ElementType X);

void Union(SetType S, SetName Root1, SetName Root2);

void Initialization(SetType S, int N);

void Input_connection(SetType S);

void Check_connection(SetType S);

void Check_network(SetType S, int N);

/**
Sample Input 1:

5
C 3 2
I 3 2
C 1 5
I 4 5
I 2 4
C 3 5
S
Sample Output 1:

no
no
yes
There are 2 components.
Sample Input 2:

5
C 3 2
I 3 2
C 1 5
I 4 5
I 2 4
C 3 5
I 1 3
C 1 5
S
Sample Output 2:

no
no
yes
yes
The network is connected.
 */
int main() {
    int n;
    char in;
    SetType S;
    scanf("%d\n", &n);
    Initialization(S, n);
    do {
        scanf("%c", &in);
        switch (in) {
            case 'I':
                Input_connection(S);
                break;
            case 'C':
                Check_connection(S);
                break;
            case 'S':
                Check_network(S, n);
                break;
        }
    } while (in != 'S');
    return 0;
}

void Initialization(SetType S, int N) {
    S = malloc(N * sizeof(ElementType));
    for (int i = 0; i < N; ++i) {
        S[i] = -1;
    }
}

SetName Find(SetType S, ElementType X) {
    if (S[X] < 0)/*找到集合的根*/
        return X;
    else
        /*先找到根; 把根变成 X 的父结点;  再返回根。*/
        return S[X] = Find(S, S[X]);
}

void Union(SetType S, SetName Root1, SetName Root2) {
    if (S[Root2] < S[Root1]) {
        S[Root2] += S[Root1];
        S[Root1] = Root2;
    } else {
        S[Root1] += S[Root2];
        S[Root2] = Root1;
    }
}

void Input_connection(SetType S) {
    ElementType u, v;
    SetName Root1, Root2;
    scanf("%d %d \n", &u, &v);
    Root1 = Find(S, u - 1);
    Root2 = Find(S, v - 1);
    if (Root1 != Root2)
        Union(S, Root1, Root2);
}

void Check_connection(SetType S) {
    ElementType u, v;
    SetName Root1, Root2;
    scanf("%d %d \n", &u, &v);
    Root1 = Find(S, u - 1);
    Root2 = Find(S, v - 1);
    if (Root1 == Root2)
        printf("yes\n");
    else
        printf("no\n");
}

void Check_network(SetType S, int N) {
    int i, counter = 0;
    for (i = 0; i < N; i++) {
        if (S[i] < 0) counter++;
    }

    if (counter == 1)
        printf("The network is connected.\n");
    else
        printf("There are %d components.\n", counter);
}
