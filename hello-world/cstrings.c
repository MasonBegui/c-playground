#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//https://www.asciitable.com/
void print_ascii(const char* str) {

    int N = strlen(str);

    for (size_t i = 0; i < N; i++) {
        printf("Character: %c, ASCII: %d\n", str[i], (int)str[i]);
    }
}

int main() {

    const char* myString = "Hello, World!";
    print_ascii(myString);



    return 0;
}