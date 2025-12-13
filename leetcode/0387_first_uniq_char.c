// https://leetcode.com/problems/first-unique-character-in-a-string
#include <assert.h>
#include <stdio.h>
#include <string.h>

int firstuniqchar(char *s){
  const int N = strlen(s);
   if (N == 1) {
    // 'a' is unique
    // 'b' is unique
    // etc
    return 0;
  }
for ( int i = 0; i < N; i++) {
    int is_unique = 1;
    for (int j = 0; j < N; j++) {
      if (i != j && s[i] == s[j]) {
        is_unique = 0;
        break;
      }
    }
    if (is_unique) {
      return i;
    }
  }
 return -1;
}


int firstuniqchar_v1(char *s)
{
  const int N = strlen(s);
  // printf("%s\n", s);
  // for (int i = 0; i < strlen(s); i++) {
  //   printf("%c\n", s[i]);
  // }
  if (N == 1)
  {
    return 0;
  }
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      if (i != j)
      {
        if (s[i] == s[j])
        {
          // we know that this is not unique
          break;
        }
        else
        {
          // they are not the same.. so far it could be unique
          if (j + 1 == N)
          {
            return i;
          }
        }
      }
      else
      {
        if (i == j && j + 1 == N)
        {
          return i;
        }
      }
    }
  }

  return -1;
}

void example_1()
{
  // 0 1 2 3 4 5 6 7
  // l e e t c o d e
  char *ss = "leetcode";
  int result = firstuniqchar(ss);
  assert(0 == result);
}

void example_2()
{
  char *s = "loveleetcode";
  int result = firstuniqchar(s);
  assert(2 == result);
}

void example_3()
{
  char *s = "aabb";
  int result = firstuniqchar(s);
  assert(-1 == result);
}

void example_4()
{
  char *s = "z";
  int result = firstuniqchar(s);
  assert(0 == result);
}

void example_5()
{
  char *s = "dddccdbba";
  int result = firstuniqchar(s);
  assert(8 == result);
}

int main()
{

  example_1();
  example_2();
  example_3();
  example_4();
  example_5();

  return 0;
}
