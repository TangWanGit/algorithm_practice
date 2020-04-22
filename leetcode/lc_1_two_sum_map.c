/**
 * @desc: 给定一个整数数组，返回两个数字的索引，使它们加起来等于一个特定的目标。
 * 您可以假设每个输入将只有一个解决方案，并且不能两次使用相同的元素。
 *
 * @author tangwan
 * @date 2020-04-17
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "lc_0_head.h"

int *twoSum(int *nums, int numsSize, int target, int *returnSize);

int main() {
    int numSize = 6;
    int *nums = buildArray(numSize);
    printArray(nums, numSize);

    int *returnSize = (int *) malloc(sizeof(int));

    int first = randomInt(numSize);

    int *result = twoSum(nums, numSize, (nums[first] + nums[numSize - first]), returnSize);

    printf("predefined index: %d %d \n", first, (numSize - first));
    printArray(result, returnSize[0]);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 *
 * 返回的数组必须是malloced，假设调用者调用free()。
 */
int *twoSum(int *nums, int numsSize, int target, int *returnSize) {
    printf("target %d \n", target);
    PtrToNode *map = createMap(numsSize);

    int *result = (int *) malloc(2 * sizeof(int));
    *returnSize = 0;
    for (int i = 0; i < numsSize; ++i) {
        PtrToNode node = getFromMap(map, numsSize, target - nums[i]);
        if (node != NULL && nums[i] + node->value == target) {
            result[0] = node->index;
            result[1] = i;
            *returnSize = 2;
            return result;
        }
        setToMap(map, numsSize, nums[i], i);
    }
    return result;
}


