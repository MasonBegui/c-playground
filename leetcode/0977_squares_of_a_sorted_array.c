// https://leetcode.com/problems/squares-of-a-sorted-array/?envType=problem-list-v2&envId=prshgx6i

#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
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

int *sortedSquares(int *numsArray, int numsLength, int *rtnArrayLength) {
  int numSize = numsLength * sizeof(int);
  int *rtnArray = malloc(numSize);
  if (rtnArray == NULL) {
    printf("Error allocating\n");
    return NULL;
  }
  *rtnArrayLength = numsLength;
  //
  memset(rtnArray, 0, *rtnArrayLength);
  for (int i = 0; i < numsLength; i++) {
    rtnArray[i] = numsArray[i] * numsArray[i];
  }

  
  qsort(rtnArray, *rtnArrayLength, sizeof(int), compare);
  // for (int i = 0; i < numsLength; i++) {
  //   printf("%d ", rtnArray[i]);
  // }
  // printf(" \n");

  return rtnArray;
}

void example1();
void example2();

int main() {
  example1();
  example2();

  return 0;
}

void example1() {
  int answer[] = {0, 1, 9, 16, 100};
  int nums[] = {-4, -1, 0, 3, 10};
  int numLength = sizeof(nums) / sizeof(int);
  int resultLength;
  int *result = sortedSquares(nums, numLength, &resultLength);
  assert(result != NULL);
  int memcmprtn = memcmp(answer, result, resultLength * sizeof(int));
  assert(memcmprtn == 0);
  free(result);
}

void example2() {
  int answer[] = {4, 9, 9, 49, 121};
  int nums[] = {-7, -3, 2, 3, 11};
  int numLength = sizeof(nums) / sizeof(int);
  int resultLength;
  int *result = sortedSquares(nums, numLength, &resultLength);
  assert(result != NULL);
  int memcmprtn = memcmp(answer, result, resultLength * sizeof(int));
  assert(memcmprtn == 0);
  free(result);
}