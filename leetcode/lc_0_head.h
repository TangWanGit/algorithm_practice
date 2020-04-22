//
// Created by zhaoxiaoli on 2020-04-22.
//
/**
 * @desc: 
 * @author zhaoxiaoli
 * @date 2020-04-22
 */

#ifndef ALGORITHM_PRACTICE_LC_HEAD_H
#define ALGORITHM_PRACTICE_LC_HEAD_H

void printArray(int *nums, int size) {
    int i, flag = 1;

    for (i = 0; i < size; ++i) {
        if (flag) {
            printf("%d", nums[i]);
            flag = 0;
            continue;
        }
        printf(" %d", nums[i]);
    }
    printf("\n");
}


int randomInt(int m) {
    // 随机数控制在0到m-1之间
    return rand() % m;
}

int *buildArray(int size) {
    int *nums = (int *) malloc(size * sizeof(int));
    srand(time(0));
    for (int i = 0; i < size; ++i) {
        nums[i] = randomInt(100);
    }
    return nums;
}


typedef struct Node *PtrToNode;
struct Node {
    int index;
    int value;
    PtrToNode next;
};

PtrToNode *createMap(int size) {
    PtrToNode
            *map = (PtrToNode *) malloc(size * sizeof(struct Node));
    for (int i = 0; i < size; ++i) {
        map[i] = NULL;
    }
    return map;
}

int getIndex(int value, int mapSize) {
    return value % mapSize;
}

PtrToNode getFromMap(PtrToNode *map, int mapSize, int value) {
    int index = getIndex(value, mapSize);
    PtrToNode node = map[index];
    PtrToNode tmp = node;

    while (tmp != NULL) {
        if (tmp->value == value) {
            return tmp;
        } else {
            tmp = tmp->next;
        }
    }
    return NULL;
}

PtrToNode createNode(int numIndex, int value) {
    PtrToNode node = malloc(sizeof(struct Node));
    node->index = numIndex;
    node->value = value;
    node->next = NULL;
    return node;
}

void setToMap(PtrToNode *map, int mapSize, int value, int numIndex) {
    int index = getIndex(value, mapSize);
    PtrToNode node = map[index];

    PtrToNode newNode = createNode(numIndex, value);
    if (node == NULL) {
        map[index] = newNode;
    } else {
        PtrToNode tmp = node;
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = newNode;
    }
}

struct ListNode {
    int val;
    struct ListNode *next;
};

void printListNode(struct ListNode *listNode) {
    struct ListNode *tmp = listNode;
    while (tmp != NULL) {
        printf("%d ", tmp->val);
        tmp = tmp->next;
    }
    printf("\n");
}


struct ListNode *createSingleListNode() {
    struct ListNode *listNode = (struct ListNode *) malloc(sizeof(struct ListNode));
    listNode->val = randomInt(11);
    listNode->next = NULL;
    return listNode;
}

struct ListNode *createListNode(int size) {
    struct ListNode *listNode = createSingleListNode();
    struct ListNode *next = listNode;
    for (int i = 1; i < size; ++i) {
        struct ListNode *tmp = createSingleListNode();
        next->next = tmp;
        next = tmp;
    }
    return listNode;
}

#endif //ALGORITHM_PRACTICE_LC_HEAD_H
