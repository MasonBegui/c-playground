#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// https://leetcode.com/problems/to-lower-case/description/

char *toLowerCase(char *s) {

  int len = strlen(s);
//   printf("%s is of len %d\n", s, len);
  for (int i = 0; i < len; i++) {
    s[i] = tolower(s[i]);
    // printf("Before %c\n", s[i]);
    // if (s[i] >= 'A' && s[i] <= 'Z') {
    //   s[i] = s[i] + ('a' - 'A');
    // }
    // printf("After %c\n", s[i]);
  }
  return s;
}

void example_1() {
  printf("Example 1:\n");
  char val[] = "Hello";
  char *rtn = toLowerCase(val);
  assert(strcmp(rtn, "hello") == 0);
}

void example_2() {
  printf("Example 2:\n");
  char val[] = "here";
  char *rtn = toLowerCase(val);
  assert(strcmp(rtn, "here") == 0);
}

void example_3() {
  printf("Example 3:\n");
  char val[] = "LOVELY";
  char *rtn = toLowerCase(val);
  assert(strcmp(rtn, "lovely") == 0);
}

int main(int argc, char *argv[]) {

  example_1();
  example_2();
  example_3();

  return 0;
}