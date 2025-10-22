#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// https://www.asciitable.com/
void print_ascii(const char *str) {
  const int N = strlen(str);
  for (size_t i = 0; i < N; i++) {
    printf("Character: %c, ASCII: %d\n", str[i], (int)str[i]);
  }
  printf("\n\n");
}

void update_first_index(char *str, char val) {
    //
    *str = val; }




int main() {

  printf("Example 1\n");
  const char *myString1 = "Hello, World!";
  // Because the myString1 is const and the value is in readonly memory, we
  // cannot update it

  // update_first_index(myString1, 'Z');
  print_ascii(myString1);

  printf("Example 2\n");
  char *mystring2 = "Hello, World String 2";
  // mystring2 is pointing to a value in readonly memory

  //   update_first_index(mystring2, 'Z');
  print_ascii(mystring2);

  printf("Example 3\n");
  char mystring3[] = "hello, World String 3";
  // mystring3 is not readonly memory. I can update this
  update_first_index(mystring3, 'Z');
  print_ascii(mystring3);
  // This will update since the char *pMystr is not pointing to read only string
  char *pMystr = mystring3;
  update_first_index(pMystr, 'H');
  print_ascii(pMystr);

  return 0;
}