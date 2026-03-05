#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool threeConsecutiveOdds(int *arr, int arrSize) {

  int counter = 0;

  for (int i = 0; i < arrSize; i++) {
    if (arr[i] % 2 != 0) {
      counter++;
    } else {
      counter = 0;
    }
    if (counter == 3) {
      return true;
    }
  }

  return false;
}

void example_1() {
  int arr[] = {2, 6, 4, 1};
  int arrLen = sizeof(arr) / sizeof(arr[0]);
  bool result = threeConsecutiveOdds(arr, arrLen);

  assert(result == false);
}
void example_2() {
  int arr[] = {1, 2, 34, 3, 4, 5, 7, 23, 12};
  int arrLen = sizeof(arr) / sizeof(arr[0]);
  bool result = threeConsecutiveOdds(arr, arrLen);
  assert(result == true);
}

int main(int argc, char *argv[]) {

  example_1();
  example_2();

  return 0;
}