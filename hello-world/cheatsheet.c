#include <stdio.h>
#include <stdlib.h>


void calculator(){
    int num1;
    int num2;
    //This is a calculator
    printf("Enter your first number: ");
    scanf("%d", &num1);
    printf("Enter your second number: ");
    scanf("%d", &num2);

    printf("%d + %d = %d\n", num1, num2, num1 + num2);
    printf("%d - %d = %d\n", num1, num2, num1 - num2);
    printf("%d * %d = %d\n", num1, num2, num1 * num2);
}

void better_calculator(){
    double num1;
    double num2;
    char op;
 
    printf("Enter any number: ");
    scanf("%lf", &num1);
    printf("Enter an operator: ");
    scanf(" %c", &op);
    printf("Enter any number: ");
    scanf("%lf", &num2);

    if(op=='+'){
        printf("%f", num1 + num2);
    }   else if(op == '-'){
        printf("%f", num1 - num2);
    }   else if(op == '*'){
        printf("%f", num1 * num2);
    }   else if(op == '/'){
        printf("%f", num1 / num2);
    }   else {
        printf("%c is not a valid option", op);
    }
    printf("\n");
}
void cube(int num){
    printf("%d^3 = %d\n", num, num * num * num);
}

void arrays() {
    int numbers[]={8, 16, 32, 64};
    printf("%d %d %d %d\n", numbers[0],numbers[1],numbers[2],numbers[3]);


    int nu[3];
    nu[1]=120;
    printf("%d %d %d\n", nu[0],nu[1],nu[2]);
}

void arrays_and_pointers(){
    const int NUMSIZE = 5;
    // cannot use NUMSIZE to declare array size
    int numbers[] = {
        1,
        2,
        3,
        4,
        10};
    // int numbers[NUMSIZE] = {1,2,3,4,10};
    numbers[0] = 10;

    int i;
    for (i = 0; i < NUMSIZE; i++)
    {
        printf("Index[%d] = %d\n", i, numbers[i]);
    }

    int arrayexample2d[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}};

    int row;
    int col;
    for (row = 0; row < 3; row++)
    {
        for (col = 0; col < 4; col++)
        {
            printf("Row[%d] Col[%d] = %d\n", row, col, arrayexample2d[row][col]);
        }
    }

    int age = 21;   // actual variable declaration
    int height = 72;
    int *ip;        // pointer variable declaration 
    ip = &age;     // store address of var in pointer variable
    printf("Value of age variable: %d\n", age);
    printf("Value of *ip variable: %d\n", *ip); // value at
    printf("Address of age variable: %p\n", &age);
    printf("Address stored in ip variable: %p\n", ip);

    age = 22; // actual variable change
    printf("Value of age variable: %d\n", age);
    printf("Value of *ip variable: %d\n", *ip); // value at

    *ip = 23; // change value at address
    printf("Value of age variable: %d\n", age);
    printf("Value of *ip variable: %d\n", *ip); // value at

    ip = &height; // change address stored in pointer
    *ip = 73;     // change value at new address
    printf("Value of height variable: %d\n", height);
    printf("Value of *ip variable: %d\n", *ip); // value at

    const double pi = 3.14159;
    double *ppi = &pi;
    printf("Value of pi variable: %f\n", pi);
    printf("Value of *ppi variable: %f\n", *ppi); // value at
    printf("Address of pi variable: %p\n", &pi);
    printf("Address stored in ppi variable: %p\n", ppi);

    *ppi = 4.14; // change value at address
    printf("Value of pi variable: %f\n", pi);
    printf("Value of *ppi variable: %f\n", *ppi); // value at

}


int main(){

    calculator();
    better_calculator();
    cube(2);
    cube(3);
    arrays();
    arrays_and_pointers();



    return 0;
}