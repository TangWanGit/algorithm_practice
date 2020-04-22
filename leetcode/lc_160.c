//
// Created by tangwan on 2019-09-30.
//
/**
 * @desc: 160. 相交链表
 * @author tangwan
 * @date 2019-09-30
 */

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *pa = headA;
    ListNode *pb = headB;

    while (pa != pb) {
        pa = pa != nullptr ? pa->next : headB;
        pb = pb != nullptr ? pb->next : headA;
    }

    return pa;
}