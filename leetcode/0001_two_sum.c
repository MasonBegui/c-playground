#include <stdio.h>
#include <stdlib.h>

/*
Given an array of integers nums and an integer target,
return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution,
and you may not use the same element twice.

You can return the answer in any order.
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *twoSum(int *nums, int numsSize, const int target, int *returnSize) {
  *returnSize = 2;
  int *rtnArray = NULL;
  // casting the result of malloc to an int pointer
  rtnArray = (int *)malloc(*returnSize * sizeof(int));
  if (rtnArray == NULL) {
    printf("Could not allocate memory\n");
    exit(1);
  }
  rtnArray[0] = -1;
  rtnArray[1] = -1;
  // Implement the logic

  printf("target=%d\n", target);
  for (int i = 0; i < numsSize; i++) {
    printf("%d ", nums[i]);
  }
  printf("\n");

  for (int i = 0; i < numsSize; i++) {
    for (int j = i + 1; j < numsSize; j++) {
      printf("i=%d, j=%d\n", i, j);

      if (nums[i] + nums[j] == target) {
        rtnArray[0] = i;
        rtnArray[1] = j;
        return rtnArray;
      }
    }
  }

  return rtnArray;
}
int main() {
  // printf("hello world\n");

  {
    // Example 1
    int nums[] = {2, 7, 11, 15};
    // int numsSize = 4
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int target = 9;
    int returnSize = 0;

    //    printf("Before target=%d, returnSize=%d\n", target, returnSize);
    int *rtn = twoSum(nums, numsSize, target, &returnSize);
    //    printf("After target=%d, returnSize=%d\n", target, returnSize);

    if (rtn != NULL && rtn[0] == 0 && rtn[1] == 1) {
      printf("Example 1 Passes\n");
    }
    free(rtn);
  }

  {
    // Example 2
    int nums[] = {3, 2, 4};
    int numsSize = 3;
    int target = 6;
    int returnSize = 0;
    int *rtn = twoSum(nums, numsSize, target, &returnSize);
    if (rtn != NULL && rtn[0] == 1 && rtn[1] == 2) {
      printf("Example 2 Passes\n");
    }
    free(rtn);
  }

  {
    // Example 3
    int nums[] = {3, 3};
    int numsSize = 2;
    int target = 6;
    int returnSize = 0;
    int *rtn = twoSum(nums, numsSize, target, &returnSize);
    if (rtn != NULL && rtn[0] == 0 && rtn[1] == 1) {
      printf("Example 3 Passes\n");
    }
    free(rtn);
  }
  return 0;
}
