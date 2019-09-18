//
// Created by sunshine on 2019-08-17.
// 传入函数作为入参
#include <stdio.h>

typedef int(*fpFunt)(int a, int b);

int Add(int a, int b, fpFunt fp);

static int fpAdd(int a, int b);

int main() {
    int a = 10;
    int b = 6;
    int c = Add(a, b, fpAdd);
    printf("c=%d\n", c);
    return 0;
}

int Add(int a, int b, fpFunt fp) {
    return fp(a, b);
}

static int fpAdd(int a, int b) {
    return a + b;
}
