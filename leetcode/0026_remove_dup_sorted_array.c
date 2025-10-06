#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

//https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/

int removeDuplicates(int *nums, int numsSize) {
  for (int i = 0; i < numsSize; i++) {
    printf("Index=%d, Value=%d\n", i, nums[i]);
  }

  printf("\n");

  return 0;
}

void example_1() {
  printf("Example 1\n");

  int numsArray[] = {1, 1, 2};
  int numsLength = sizeof(numsArray) / sizeof(int);
  int expectedNums[] = {1, 2, -1}; // The expected answer with correct length
  int expectedNumsLength = 2;
  int k = removeDuplicates(numsArray, numsLength); // Calls your implementation

  assert(k == expectedNumsLength);
  for (int i = 0; i < k; i++) {
    assert(numsArray[i] == expectedNums[i]);
  }
}

void example_2() {
  printf("Example 2\n");

  int numsArray[] = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
  int numsLength = sizeof(numsArray) / sizeof(int);
  int expectedNums[] = {
      0, 1, 2, 3, 4, -1, -1, -1, -1}; // The expected answer with correct length
  int expectedNumsLength = 5;
  int k = removeDuplicates(numsArray, numsLength); // Calls your implementation

  assert(k == expectedNumsLength);
  for (int i = 0; i < k; i++) {
    assert(numsArray[i] == expectedNums[i]);
  }
}

int main() {
  example_1();
  example_2();

  return 0;
}
