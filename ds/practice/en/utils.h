//
// Created by zhaoxiaoli on 2019-09-09.
//
/**
 * @desc: 
 * @author zhaoxiaoli
 * @date 2019-09-09
 */

#ifndef DS_UTILS_H
#define DS_UTILS_H
typedef enum {
    push, pop, inject, eject, end
} Operation;
#endif //DS_UTILS_H

Operation GetOp() {
    char a[11];
    scanf("%s", a);
    //push, pop, end
    if (!strcmp("Push", a))
        return push;
    if (!strcmp("Pop", a))
        return pop;
    if (!strcmp("Inject", a))
        return inject;
    if (!strcmp("Eject", a))
        return eject;
    if (!strcmp("End", a))
        return end;

    return end;
}

int Compare(int a, int b) {
    return a > b ? 1 : a < b ? -1 : 0;
}