#pragma warning(disable:4996)
#include <stdio.h>
#include <conio.h>

int main() {
	char signedChar = 32;				// also 'signed char'
	unsigned char unsignedChar = 32;

	printf("Please enter a single character: ");
	scanf("%c", &signedChar);

	// Both variables use the data in the byte the exact same way.
	unsignedChar = signedChar;

	// The difference in the data type causes the effective
	//   ranges of the variables to be different.
	// 1.) The signed 'char' goes from -128 to 127.
	// 2.) The 'unsigned char' goes from 0 to 255.
	// 3.) Both the 'signed char' and 'unsigned char' have
	//       8 bits of data (1 byte).
	printf("signed value  : %d\n", signedChar);
	printf("unsigned value: %d\n", unsignedChar);

	// Return to OS
	_getch();
	return 0;
}