#pragma warning(disable:4996)
#include <stdio.h>
#include <conio.h>
#include <ctype.h>

#ifndef __OPERATORS__
	#define MULTIPLY 1
	#define DIVIDE 2
	#define ADD 3
	#define SUBTRACT 4
	#define MODULUS 5
	#define UNSET 6
#endif

int main() {
	//Delcare Variables
	int firstNumber = 0, secondNumber = 0, operationFlag = UNSET;
	float answer = 0;
	char operation = ' ';


	//Get User Input
	printf("Enter a number between -1000 and 1000: ");
	scanf("%d", &firstNumber);
	rewind(stdin);

	while (firstNumber > 1000 || firstNumber < -1000) { //Ensure input is in range, otherwise prompt again
		printf("That number was out of range (-1000 - 1000). Please try again: ");
		scanf("%d", &firstNumber);
		rewind(stdin);
	}

	printf("Enter another number between -1000 and 1000: ");
	scanf("%d", &secondNumber);
	rewind(stdin);

	while (secondNumber > 1000 || secondNumber < -1000) { //Ensure input is in range, otherwise prompt again
		printf("That number was out of range (-1000 - 1000). Please try again: ");
		scanf("%d", &secondNumber);
		rewind(stdin);
	}

	printf("Enter the symbol for the operation you would like to perform with the given numbers (*, /, -, +, %): ");
	scanf("%c", &operation);
	rewind(stdin);

	//Process Entered Operation
	if (operation == '+') {
		operationFlag = ADD;
	}
	else if (operation == '-') {
		operationFlag = SUBTRACT;
	}
	else if (operation == '/') {
		operationFlag = DIVIDE;
	}
	else if (operation == '*') {
		operationFlag = MULTIPLY;
	}
	else if (operation == '%') {
		operationFlag = MODULUS;
	}
	else { //Return an error if unknown operation is chosen
		printf("ERROR: Unknown Operation!"); 
		_getch();
		return 0;
	}

	//Do Maths
	switch (operationFlag) {
	case ADD:
		answer = firstNumber + secondNumber;
		break;
	case SUBTRACT:
		answer = firstNumber - secondNumber;
		break;
	case MULTIPLY:
		answer = firstNumber * secondNumber;
		break;
	case DIVIDE:
		while (secondNumber == 0) { //Check for divide by zero & repromt if necessary
			printf("ERROR: Cannot divide by zero!\n");
			printf("Enter another number between -1000 and 1000: ");
			scanf("%d", &secondNumber);
			rewind(stdin);
		}
		answer = (float)firstNumber / (float)secondNumber;
		break;
	case MODULUS:
		answer = firstNumber % secondNumber;
		break;
	}

	//Output Results
	printf("%d %c %d = %.4f\n", firstNumber, operation, secondNumber, answer);

	_getch();
	return 0;
}

//  9 %  2 =  1.00
// -9 %  2 = -1.00
//  9 % -2 = -1.00
// -9 % -2 = -1.00
// Modulus equations containing a negative will always return a negative answer. Equations containing no negatives will always return a positive answer.