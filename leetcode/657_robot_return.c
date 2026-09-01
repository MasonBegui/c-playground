#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool judgeCircle(char *moves) { 
  int row = 0;
  int col = 0;
  for(int i = 0; i < strlen(moves); i++){
    const char dir = moves[i];
    // printf("%c \n", dir);
    if('U' == dir){
      row++;
    } else if ('D' == dir) {
      row--;
    }else if ('L' == dir) {
      col--;
    }else if('R' == dir) {
      col++;
    }else {
      // Ignore me
    } 
  }
    return (row == 0 && col == 0);
 }

void example_1();
void example_2();
void example_3();
int main(int argc, char *argv[]) {
  example_1();
  example_2();
  example_3();
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

void example_3(){
  bool result = judgeCircle("UDLR");
  assert(result == true);
}