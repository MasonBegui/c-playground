#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool judgeCircle(char *moves) { return false; }

void example_1();
void example_2();
int main(int argc, char *argv[]) {
  example_1();
  example_2();
  return EXIT_SUCCESS;
}

void example_1() {
  bool result = judgeCircle("UD");
  assert(result == true);
}

void example_2() {
  bool result = judgeCircle("LL");
  assert(result == false);
}