// How to run 
// gcc -Wall quadratic.c -lm && ./a.out

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
  //   printf("%d\n", argc);
  //   for (int i = 0; i < argc; i++) {
  //     printf("argv[%d] = %s\n", i, argv[i]);
  //   }

  double A = 0;
  double B = 0;
  double C = 0;

  printf("Please input a,b,c for y = ax^2 + bx + c: \n");
  if (scanf("%lf %lf %lf", &A, &B, &C) != 3) {
    printf("Invalid Input\n");
    return EXIT_FAILURE;
  }
  if (A == 0) {
    printf("a cannot be zero\n ");
    return EXIT_FAILURE;
  }

  const double vertexH = -B / (2 * A);
  const double vertexK = (A * vertexH * vertexH) + (B * vertexH + C);
  const double discriminant = B * B - 4 * A * C;

  printf("y = %.3f x^2 + %.3f x + %.3f\n", A, B, C);
  printf("vertex: %.3f,%.3f\n", vertexH, vertexK);
  printf("axis of symmetry: x = %.3f\n", vertexH);
  if (A > 0) {
    printf("Opens Up: positive -> min value is %.3f\n", vertexK);
  } else {
    printf("Opens down: negative -> max value is %.3f\n", vertexK);
  }
  printf("The discriminant is %.3f\n", discriminant);
  if (discriminant > 0) {
    double x1 = (-B + sqrt(discriminant)) / (2.0 * A);
    double x2 = (-B - sqrt(discriminant)) / (2.0 * A);
    printf("Two Real X intercepts: %.3f and %.3f\n", x1, x2);
  } else if (discriminant == 0) {
    double x = -B / (2.0 * A);
    printf("One Real X intercept(Double Root): %.3f\n", x);
  } else {
    printf("No Real X intercept(Complex Root)\n");
  }
  printf("y intercept is: %.3f\n", C);

  return EXIT_SUCCESS;
}