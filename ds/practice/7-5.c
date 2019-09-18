//
// Created by zhaoxiaoli on 2019-09-06.
//
/**
 * @desc: 7-5 堆中的路径
 * @author zhaoxiaoli
 * @date 2019-09-06
 */
#include <stdio.h>
#include <stdlib.h>

#define MAXN 1001
#define MINH -10001
// 使用完全二叉树来存储数据
int H[MAXN], size;

void Create() {
    size = 0;
    /*设置“岗哨”*/
    H[0] = MINH;
}

void Insert(int X) {
    /* 将X插入H。这里省略检查堆是否已满的代码 */
    int i;
    for (i = ++size; H[i / 2] > X; i /= 2)
        H[i] = H[i / 2];
    H[i] = X;
}

/**
输入样例:

5 3
46 23 26 24 10
5 4 3
输出样例:

24 23 10
46 23 10
26 10

 */
int main() {
    int n, m, x, i, j;
    scanf("%d %d", &n, &m);

    Create();
    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        Insert(x);
    }

    for (i = 0; i < m; i++) {
        scanf("%d", &j);
        printf("%d", H[j]);
        while (j > 1) { /*沿根方向输出各结点*/
            j /= 2;
            printf(" %d", H[j]);
        }
        printf("\n");
    }
}