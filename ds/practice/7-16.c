//
// Created by zhaoxiaoli on 2019-09-24.
//
/**
 * @desc: 7-16 一元多项式求导
 * @author zhaoxiaoli
 * @date 2019-09-24
 */

#include <stdio.h>

int main() {
    int m, n, flag = 1;
    while (scanf("%d %d", &m, &n) != EOF) {
        if (n > 0) {
            if (flag) {
                printf("%d %d", m * n, n - 1);
                flag = 0;
            } else {
                printf(" %d %d", m * n, n - 1);
            }
        }
    }
    if (flag == 1)
        printf("0 0");
    return 0;
}