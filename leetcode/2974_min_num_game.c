// https://leetcode.com/problems/minimum-number-game/description/
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXNUM 999

void example_1();
void example_2();
void print_me(int *nums, int numsSize) {

  for(int i = 0; i < numsSize; i++){
    printf("%d ", nums[i]);
  }
  printf("\n");

}

bool check_all_zeros(int *nums, int numsSize) {
  for (int i = 0; i < numsSize; i++) {
    if (nums[i] != 0) {
      return false;
    }
  }
  return true;
}
// returns smallest index or 999 if not found
int find_smallest_index(int *nums, int numsSize) {

  int smallestIndex = MAXNUM;
  int smallestValue = MAXNUM;
  for (int i = 0; i < numsSize; i++) {
    if (nums[i] > 0 && nums[i] < smallestValue) {
      smallestIndex = i;
      smallestValue = nums[i];
    }
  }
  return smallestIndex;
}

int find_smallest_number(int *nums, int numSize) {
  int smallestIndex = find_smallest_index(nums, numSize);
  if (smallestIndex != MAXNUM) {
    int smallestNum = nums[smallestIndex];
    nums[smallestIndex] = 0;
    return smallestNum;
  }

  return -1;
}

int *numberGame_old(int *nums, int numsSize, int *returnSize) {
  *returnSize = numsSize;
  int *out = (int *)malloc(sizeof(int) * numsSize);
  int outIndex = 0;

  while (!check_all_zeros(nums, numsSize)) {

    int p1SmallestNum = find_smallest_number(nums, numsSize);
    int p2SmallestNum = find_smallest_number(nums, numsSize);

    // printf("P1 %d , P2 %d\n", p1SmallestNum, p2SmallestNum);
    out[outIndex++] = p2SmallestNum;
    out[outIndex++] = p1SmallestNum;
  }

  // for (int i = 0; i < numsSize; i++) {
  //   printf("%d, %d\n", nums[i], out[i]);
  // }
  // printf("=====\n");
  return out;
}

int compare(const void *lhs, const void *rhs) {

  // a cast from void to int 
  int x = *(const int *)lhs;
  int y = *(const int *)rhs;

  if (x < y)
    return -1;
  if (x > y)
    return 1;
  return 0;
}

int *numberGame(int nums[]  , int numsSize, int *returnSize) {
  *returnSize = numsSize;
  int *out = (int *)malloc(sizeof(int) * numsSize);

  // print_me(nums, numsSize);
  qsort(nums, numsSize, sizeof(int), compare);
  // print_me(nums, numsSize);

  int gameIndex = 0;
  for(int i = 0; i < numsSize; i++){
    int p1 = nums[i];
    int p2 = nums[++i];

    out[gameIndex++] = p2;
    out[gameIndex++] = p1;
  }
  return out;
}

int main(int argc, char *argv[]) { 
  example_1();
  example_2();
  return EXIT_SUCCESS;
}



void example_1() {
  int nums[] = {5, 4, 2, 3};

  int length = sizeof(nums) / sizeof(nums[0]);

  int returnSize;
  int *out = numberGame(nums, length, &returnSize);
  // TODO: check if correct
  const int numsCheck[] = {3, 2, 5, 4};
  if (memcmp(numsCheck, out, returnSize * sizeof(int)) != 0) {
    assert(0);
  }
  if (out != NULL) {
    free(out);
  }
}

void example_2() {
  int nums[] = {2, 5};
  int length = sizeof(nums) / sizeof(nums[0]);
  int returnSize;
  int *out = numberGame(nums, length, &returnSize);
  // TODO: check if correct
  const int numsCheck[] = {5, 2};
  if (memcmp(numsCheck, out, returnSize * sizeof(int)) != 0) {
    assert(0);
  }
  if (out != NULL) {
    free(out);
  }
}