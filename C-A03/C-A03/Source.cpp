#pragma warning(disable:4996)
#include <stdio.h>
#include<conio.h>

#define ARRAY_SIZE 5

int main() {
	//Declare Variables
	char charArray[ARRAY_SIZE];
	char phantomAbsorb;

	//Fill array with Spaces
	for (int i = 0; i < ARRAY_SIZE; i++) {
		charArray[i] = ' ';
	}

	//Take User Input
	printf("Please enter a character and press enter:\n");
	scanf("%c%c", &charArray[0], &phantomAbsorb);

	printf("Please enter a character and press enter:\n");
	scanf("%c", &charArray[1]);
	rewind(stdin);

	printf("Please enter a character and press enter:\n");
	scanf("%c%c", &charArray[2], &phantomAbsorb);

	printf("Please enter a character and press enter:\n");
	scanf("%c", &charArray[3]);
	rewind(stdin);

	printf("Please enter a character and press enter:\n");
	scanf("%c%c", &charArray[4], &phantomAbsorb);

	//Display Output to Console
	printf("DEC    | ASCII | ADDRESS\n");
	for (int i = 0; i < ARRAY_SIZE; i++) {
		printf("%-8d%-8c%-8x\n", charArray[i], charArray[i], &charArray[i]);
	}
	
	_getch();
	return 0;
}