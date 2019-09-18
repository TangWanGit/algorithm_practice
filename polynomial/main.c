#include <stdio.h>
#include <time.h>

clock_t start, stop;

double duration;
/**
* 多项式最大项数，即多项式阶数+1
*/
#define MAXN 10

double f1(int n, double a[], double x);

double f2(int n, double a[], double x);

int main() {
    double a[MAXN];
    for (int i = 0; i < MAXN; ++i) {
        a[i] = (double) i;
    }


    start = clock();
    f1(MAXN - 1, a, 1.1);
    stop = clock();

    duration = ((double) (stop - start)) / CLOCKS_PER_SEC;
    printf("ticks1 = %f\n", (double) (stop - start));
    printf("duration1 = %6.2e\n", duration);

    start = clock();
    f2(MAXN - 1, a, 1.1);
    stop = clock();

    duration = ((double) (stop - start)) / CLOCKS_PER_SEC;
    printf("ticks2 = %f\n", (double) (stop - start));
    printf("duration2 = %6.2e\n", duration);

    return 0;
}

