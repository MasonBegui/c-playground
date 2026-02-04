#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void basic_array_example();
void array_indexing_example();
void array_traversal_example();
void array_operations_example();
void array_and_functions_example();
void multidimensional_array_example();
void string_array_example();
void pointer_arithmetic_example();

int main() {
  printf("C Array Examples for Learning\n");
  printf("============================\n");

  basic_array_example();
  array_indexing_example();
  array_traversal_example();
  array_operations_example();
  array_and_functions_example();
  multidimensional_array_example();
  string_array_example();
  pointer_arithmetic_example();

  printf("\n\nAll examples completed!\n");
  return 0;
}

void basic_array_example() {
  printf("\n=== Basic Array Declaration & Initialization ===\n");

  int arr1[5] = {1, 2, 3, 4, 5};
  int arr2[] = {10, 20, 30};
  int arr3[5] = {1, 2};
  char str[6] = "Hello";

  printf("arr1: ");
  for (int i = 0; i < 5; i++) {
    printf("%d ", arr1[i]);
  }
  printf("\n");

  printf("arr2 (size inferred): ");
  for (int i = 0; i < 3; i++) {
    printf("%d ", arr2[i]);
  }
  printf("\n");

  printf("arr3 (partial init): ");
  for (int i = 0; i < 5; i++) {
    printf("%d ", arr3[i]);
  }
  printf("\n");

  printf("String: %s\n", str);
}

void array_indexing_example() {
  printf("\n=== Array Indexing & Access ===\n");

  int numbers[] = {10, 20, 30, 40, 50};
  int size = sizeof(numbers) / sizeof(numbers[0]);

  printf("First element: numbers[0] = %d\n", numbers[0]);
  printf("Last element: numbers[%d] = %d\n", size - 1, numbers[size - 1]);
  printf("Middle element: numbers[%d] = %d\n", size / 2, numbers[size / 2]);

  numbers[2] = 100;
  printf("After modification: numbers[2] = %d\n", numbers[2]);
}

void array_traversal_example() {
  printf("\n=== Array Traversal ===\n");

  int arr[] = {5, 10, 15, 20, 25, 30};
  int size = sizeof(arr) / sizeof(arr[0]);

  printf("For loop (forward): ");
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  printf("For loop (backward): ");
  for (int i = size - 1; i >= 0; i--) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  printf("While loop: ");
  int i = 0;
  while (i < size) {
    printf("%d ", arr[i]);
    i++;
  }
  printf("\n");
}

void array_operations_example() {
  printf("\n=== Common Array Operations ===\n");

  int arr[] = {45, 12, 78, 23, 67, 89, 34};
  int size = sizeof(arr) / sizeof(arr[0]);

  int sum = 0;
  for (int i = 0; i < size; i++) {
    sum += arr[i];
  }
  printf("Sum: %d\n", sum);

  double average = (double)sum / size;
  printf("Average: %.2f\n", average);

  int max = arr[0], min = arr[0];
  for (int i = 1; i < size; i++) {
    if (arr[i] > max)
      max = arr[i];
    if (arr[i] < min)
      min = arr[i];
  }
  printf("Max: %d, Min: %d\n", max, min);

  int target = 67;
  int found = -1;
  for (int i = 0; i < size; i++) {
    if (arr[i] == target) {
      found = i;
      break;
    }
  }
  if (found != -1) {
    printf("Found %d at index %d\n", target, found);
  } else {
    printf("%d not found\n", target);
  }
}

void print_array(int arr[], int size) {
  printf("Array elements: ");
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void modify_array(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    arr[i] *= 2;
  }
}

void array_and_functions_example() {
  printf("\n=== Arrays and Functions ===\n");

  int numbers[] = {1, 2, 3, 4, 5};
  int size = sizeof(numbers) / sizeof(numbers[0]);

  printf("Before modification:\n");
  print_array(numbers, size);

  modify_array(numbers, size);

  printf("After modification (doubled):\n");
  print_array(numbers, size);
}

void multidimensional_array_example() {
  printf("\n=== 2D Arrays (Matrices) ===\n");

  int matrix[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

  printf("Matrix (3x3):\n");
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      printf("%3d ", matrix[i][j]);
    }
    printf("\n");
  }

  printf("Element at [1][2]: %d\n", matrix[1][2]);

  printf("Row sums: ");
  for (int i = 0; i < 3; i++) {
    int row_sum = 0;
    for (int j = 0; j < 3; j++) {
      row_sum += matrix[i][j];
    }
    printf("%d ", row_sum);
  }
  printf("\n");

  printf("Column sums: ");
  for (int j = 0; j < 3; j++) {
    int col_sum = 0;
    for (int i = 0; i < 3; i++) {
      col_sum += matrix[i][j];
    }
    printf("%d ", col_sum);
  }
  printf("\n");
}

void string_array_example() {
  printf("\n=== String Arrays ===\n");

  char greeting[] = "Hello, World!";
  printf("String: %s\n", greeting);
  printf("Length: %zu\n", strlen(greeting));

  char *fruits[] = {"Apple", "Banana", "Cherry", "Date"};
  int num_fruits = sizeof(fruits) / sizeof(fruits[0]);

  printf("\nFruits array:\n");
  for (int i = 0; i < num_fruits; i++) {
    printf("%d. %s (length: %zu)\n", i + 1, fruits[i], strlen(fruits[i]));
  }

  char str1[20] = "Hello";
  char str2[20] = " World";
  strcat(str1, str2);
  printf("\nConcatenated string: %s\n", str1);

  char word1[] = "apple";
  char word2[] = "banana";
  int result = strcmp(word1, word2);
  printf("Comparing '%s' and '%s': %d\n", word1, word2, result);
}

void pointer_arithmetic_example() {
  printf("\n=== Pointer Arithmetic with Arrays ===\n");

  int arr[] = {10, 20, 30, 40, 50};
  int *ptr = arr;
  int size = sizeof(arr) / sizeof(arr[0]);

  printf("Using pointer arithmetic:\n");
  printf("arr[0] = %d, *ptr = %d\n", arr[0], *ptr);
  printf("arr[1] = %d, *(ptr+1) = %d\n", arr[1], *(ptr + 1));
  printf("arr[2] = %d, *(ptr+2) = %d\n", arr[2], *(ptr + 2));

  printf("\nTraversing with pointer:\n");
  for (int i = 0; i < size; i++) {
    printf("*(ptr+%d) = %d\n", i, *(ptr + i));
  }

  printf("\nModifying through pointer:\n");
  *(ptr + 2) = 100;
  printf("After *(ptr+2) = 100, arr[2] = %d\n", arr[2]);
}
