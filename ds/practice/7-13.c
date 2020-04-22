//
// Created by tangwan on 2019-09-23.
//
/**
 * @desc: 7-13 统计工龄
 * @author tangwan
 * @date 2019-09-23
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SCORE_NUM 51
typedef int List[SCORE_NUM];

/**
 * 读入
 */
void ReadScore();

/**
 * 打印
 */
void printScore(List L);

/**
 * 输入样例:

8
10 2 0 5 7 2 5 2
输出样例:

0:1
2:3
5:2
7:1
10:1
 */
int main() {
    ReadScore();
}

void ReadScore() {
    int N, S;
    scanf("%d", &N);
    List L;
    memset(L, 0, sizeof(L));
    while (N--) {
        scanf("%d", &S);
        L[S] = L[S] + 1;
    }
    printScore(L);
}


void printScore(List L) {
    for (int i = 0; i < SCORE_NUM; ++i) {
        if (L[i]) {
            printf("%d:%d\n", i, L[i]);
        }
    }
}
