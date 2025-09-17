#include <stdio.h>
#include <stdlib.h>

int main()
{

	const char myname[] = "Mason";
	int myage = 12;
	float mymoney = 13.96;

	printf("Hello World\n");
	printf("My name is %s I am %d years old and I have $%f\n", myname, myage, mymoney);

	mymoney--;
	myage++;

	printf("My name is %s I am %d years old and I have $%f\n", myname, myage, mymoney);

	int age = 4;
	printf("Enter your age: ");
	scanf("%d", &age);
	printf("You are %d years old\n", age);

	
	return EXIT_SUCCESS;
}
