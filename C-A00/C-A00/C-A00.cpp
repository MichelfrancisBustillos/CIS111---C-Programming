#include <stdio.h>

int main() {
	char firstName[14] = "Michelfrancis";
	char lastName[10] = "Bustillos";
	char middleInitial = 'I';
	int age = 22;

	printf("My name is %s %c %s and I am %i years old.\n", firstName, middleInitial, lastName, age);

	return 0;
}