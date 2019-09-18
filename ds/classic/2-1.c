//
// Created by zhaoxiaoli on 2019-08-29.
//
/**
 * @desc: 最大子序列和
 * @author zhaoxiaoli
 * @date 2019-08-29
 */
#include <stdio.h>
#include <time.h>

#define MAXN 50

typedef int(*maxSubSeqSumFunction)(int A[], int N);

void MaxSubSeqSum(int functionNum, int A[], int N, maxSubSeqSumFunction function);

int MaxSubSeqSum1(int A[], int N);

int MaxSubSeqSum2(int A[], int N);

int MaxSubSeqSum3(int A[], int N);

int MaxSubSeqSum4(int A[], int N);

int main() {
    int A[MAXN] = {4, -3, 5, -2, -1, 2, 6, -2, 9, 4, 3, 5, -2, -1, 2, 6, -2, 9, 4, -3, 5, -2, -1, 2, 6, -2, 9, 4, -3,
                   5, -2, -1, 2, 6, -2, 9, 8, 3, 8, 6, 2, 18, 29, 30, -90, 2, 4, 5, 7, 9};

    MaxSubSeqSum(1, A, MAXN - 1, MaxSubSeqSum1);
    MaxSubSeqSum(2, A, MAXN - 1, MaxSubSeqSum2);
    MaxSubSeqSum(3, A, MAXN - 1, MaxSubSeqSum3);
    MaxSubSeqSum(4, A, MAXN - 1, MaxSubSeqSum4);
    return 0;
}

void MaxSubSeqSum(int functionNum, int A[], int N, maxSubSeqSumFunction function) {
    clock_t start = clock();
    int sum = function(A, N);
    clock_t stop = clock();

    double duration = ((double) (stop - start)) / CLOCKS_PER_SEC;
    printf("sum%d = %d\n", functionNum, sum);
    printf("ticks%d = %f\n", functionNum, (double) (stop - start));
    printf("duration%d = %6.2e\n", functionNum, duration);
}


/**
 * 在A数组中找到最长子列和
 *
 * O(n*n*n)
 * 暴力破解法
 * @param A 数组
 * @param N 数组的长度
 * @return
 */
int MaxSubSeqSum1(int A[], int N) {
    int ThisSum, MaxSum = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = i; j < N; ++j) {
            ThisSum = 0;
            for (int k = i; k < j; ++k) {
                ThisSum += A[k];
            }
            if (ThisSum > MaxSum) {
                MaxSum = ThisSum;
            }
        }
    }
    return MaxSum;
}

/**
 * 在A数组中找到最长子列和
 *
 * 对于相同的i，不同的j，只要在j-1次循环的基础上累加1项即可
 *
 * O(n*n)
 * @param A
 * @param N
 * @return
 */
int MaxSubSeqSum2(int A[], int N) {
    int ThisSum, MaxSum = 0;
    for (int i = 0; i < N; ++i) {
        ThisSum = 0;
        for (int j = i; j < N; ++j) {
            ThisSum += A[j];
            if (ThisSum > MaxSum) {
                MaxSum = ThisSum;
            }
        }
    }
    return MaxSum;
}

/**
 * 三者之间最大的值
 * @param A
 * @param B
 * @param C
 * @return
 */
int Max3(int A, int B, int C) {
    return A > B ? A > C ? A : C : B > C ? B : C;
}

/**
 * 分而治之
 * @param List
 * @param left
 * @param right
 * @return
 */
int DivideAndConquer(int List[], int left, int right) {
    /* 分治法求List[left]到List[right]的最大子列和 */

    int MaxLeftSum, MaxRightSum; /* 存放左右子问题的解 */
    int MaxLeftBorderSum, MaxRightBorderSum; /*存放跨分界线的结果*/

    int LeftBorderSum, RightBorderSum;
    int center, i;

    if (left == right) { /* 递归的终止条件，子列只有1个数字 */
        if (List[left] > 0) {
            return List[left];
        } else return 0;
    }

    /* 下面是"分"的过程 */
    center = (left + right) / 2; /* 找到中分点 */

    /* 递归求得两边子列的最大和 */
    MaxLeftSum = DivideAndConquer(List, left, center);
    MaxRightSum = DivideAndConquer(List, center + 1, right);

    /* 下面求跨分界线的最大子列和 */
    MaxLeftBorderSum = 0;
    LeftBorderSum = 0;
    for (i = center; i >= left; i--) { /* 从中线向左扫描 */
        LeftBorderSum += List[i];
        if (LeftBorderSum > MaxLeftBorderSum) {
            MaxLeftBorderSum = LeftBorderSum;
        }
    }/* 左边扫描结束 */


    MaxRightBorderSum = 0;
    RightBorderSum = 0;
    for (i = center + 1; i <= right; i++) { /* 从中线向右扫描 */
        RightBorderSum += List[i];
        if (RightBorderSum > MaxRightBorderSum) {
            MaxRightBorderSum = RightBorderSum;
        }
    }/* 右边扫描结束 */

    /* 下面返回"治"的结果 */
    return Max3(MaxLeftSum, MaxRightSum, MaxLeftBorderSum + MaxRightBorderSum);
}


/**
 * 在A数组中找到最长子列和
 *
 * 分而治之
 *
 * O(nlogn)
 * @param A
 * @param N
 * @return
 */
int MaxSubSeqSum3(int A[], int N) {
    return DivideAndConquer(A, 0, N - 1);
}

/**
 * 在A数组中找到最长子列和
 *
 * 在线处理
 *
 * O(n)
 *
 * @param A
 * @param N
 * @return
 */
int MaxSubSeqSum4(int A[], int N) {
    int ThisSum, MaxSum = 0;
    for (int i = 0; i < N; ++i) {
        /*向右累加*/
        ThisSum += A[i];
        if (ThisSum > MaxSum) {
            MaxSum = ThisSum;
        } else if (ThisSum < 0) { /*如果当前子列和为负*/
            ThisSum = 0; /*则不可能使后面的部分和增大，抛弃之*/
        }
    }
    return MaxSum;
}
