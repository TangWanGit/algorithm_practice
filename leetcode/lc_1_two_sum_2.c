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
    int numSize = 3;

    int *nums = buildArray(numSize);
    nums[0] = 3;
    nums[1] = 2;
    nums[2] = 3;
    //nums[3] = 70;
    //nums[4] = 16;
    //nums[5] = 38;

    //[3,2,3]
    //6
    printArray(nums, numSize);

    int *returnSize = (int *) malloc(sizeof(int));

    int first = randomInt(numSize - 1);

    int *result = twoSum(nums, numSize, 6, returnSize);

    printf("predefined index: %d %d \n", first, (numSize - first));
    printArray(result, returnSize[0]);
    return 0;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 *
 * 返回的数组必须是malloced，假设调用者调用free()。
 */
int *twoSum(int *nums, int numsSize, int target, int *returnSize) {
    int i, max, min;

    max = min = nums[0];

    for (i = 0; i < numsSize; i++) {
        if (nums[i] > max) max = nums[i];
        if (nums[i] < min) min = nums[i];
    }

    int *map = (int *) calloc((max - min + 1), sizeof(int));

    int *result = (int *) malloc(2 * sizeof(int));

    for (i = 0; i < numsSize; i++) {
        int lookIndex = target - nums[i];
        if (lookIndex < min || lookIndex > max) continue;

        int dis = lookIndex - min;
        if (map[dis]) {
            result[0] = i;
            result[1] = map[dis] - 1;
            *returnSize = 2;
            return result;
        } else {
            map[nums[i] - min] = i + 1;
        }
    }

    *returnSize = 0;
    return result;

}
