//
// Created by zhaoxiaoli on 2020-04-22.
//
/**
 * @desc: 你有两个非空链表代表两个非负整数。这些数字以相反的顺序存储，每个节点包含一个数字。将这两个数字相加并以链表的形式返回。
您可以假设这两个数字不包含任何前导零，除了数字0本身。
 * @author zhaoxiaoli
 * @date 2020-04-22
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "lc_0_head.h"

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2);

int main() {
    struct ListNode *l1 = createListNode(3);
    struct ListNode *l2 = createListNode(3);
    printListNode(l1);
    printListNode(l2);

    struct ListNode *result = addTwoNumbers(l1, l2);
    printListNode(result);
    return 0;
}

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
    struct ListNode *result = malloc(sizeof(struct ListNode));
    struct ListNode *next = result;

    int plus = 0;
    while (l1 != NULL || l2 != NULL || plus != 0) {
        int l1_val = l1 == NULL ? 0 : l1->val;
        int l2_val = l2 == NULL ? 0 : l2->val;

        int x = l1_val + l2_val + plus;
        plus = 0;

        if (x >= 10) {
            plus = 1;
            x = x % 10;
        }

        struct ListNode *temp = (struct ListNode *) malloc(sizeof(struct ListNode));
        temp->val = x;
        temp->next = NULL;

        next->next = temp;
        next = temp;

        l1 = l1 == NULL ? NULL : l1->next;
        l2 = l2 == NULL ? NULL : l2->next;
    }
    return result->next;
}