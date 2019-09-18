//
// Created by zhaoxiaoli on 2019-08-28.
// 最大子列和问题

#include <stdio.h>

/**
 * 在线处理办法
 */
int MaxSeqSum(int A[], int N);
/**
 * 6
 * -2 11 -4 13 -5 -2
 *
 * 20
 */
int main() {
    int N = 0;
    scanf("%d", &N);
    int A[N];
    for (int i = 0; i < N; ++i) {
        int b;
        scanf("%d", &b);
        A[i] = b;
    }
    printf("%d", MaxSeqSum(A, N));
    return 0;
}

int MaxSeqSum(int A[], int N) {
    int ThisSum = 0, MaxSum = 0;
    for (int i = 0; i < N; ++i) {
        ThisSum += A[i];
        if (ThisSum > MaxSum) {
            MaxSum = ThisSum;
        }
        if (ThisSum < 0) {
            ThisSum = 0;
        }
    }
    return MaxSum;
}
