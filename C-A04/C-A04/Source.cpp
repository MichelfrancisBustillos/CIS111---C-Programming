#pragma warning(disable:4996)
#include <stdio.h>
#include <conio.h>

#ifndef __CHARCODES__
#define __CHARCODES__
// Type codes...
#define LETTER       1
#define NUMBER       2
#define SYMBOL       3

// Sub-type codes...
#define VOWEL        4
#define CONSONANT    5
#define ODD          6
#define EVEN         7
#define UPPER_ASCII  8
#define LOWER_ASCII  9
#endif

#define NUM_START 48
#define NUM_STOP 57
#define UPPERCASE_START 65
#define UPPERCASE_STOP 90
#define LOWERCASE_START 97
#define LOWERCASE_STOP 122
#define TABLE_BREAK 127

int main() {
	char keyStroke = 0;
	int typeCode = -1, subTypeCode = -1;

	// GET THE KEYSTROKE (remember to clean phantoms)
	printf("Enter a single keystroke: ");
	scanf("%c", &keyStroke);
	rewind(stdin);

	// ANALYZE THE typeCode (IF, IF-ELSE, IF-ELSE-CHAIN here)
	if (keyStroke >= NUM_START && keyStroke <= NUM_STOP) {
		typeCode = NUMBER;
		if (keyStroke % 2 == 0) {
			subTypeCode = EVEN;
		}
		else {
			subTypeCode = ODD;
		}
	}
	else if ((keyStroke >= UPPERCASE_START && keyStroke <= UPPERCASE_STOP) || (keyStroke >= LOWERCASE_START && keyStroke <= LOWERCASE_STOP)) {
		typeCode = LETTER;
		if (keyStroke == 'A' || keyStroke == 'E' || keyStroke == 'I' || keyStroke == 'O' || keyStroke == 'U' || keyStroke == 'a' || keyStroke == 'e' || keyStroke == 'i' || keyStroke == 'o' || keyStroke == 'u') {
			subTypeCode = VOWEL;
		}
		else {
			subTypeCode = CONSONANT;
		}
	}
	else {
		typeCode = SYMBOL;
		if (keyStroke <= TABLE_BREAK) {
			subTypeCode = LOWER_ASCII;
		}
		else {
			subTypeCode = UPPER_ASCII;
		}
	}

	// DISPLAY RESULTS BASED ON SET CODES (SWITCH-CASE)

	printf("The character you entered was \"%c\" ... \n", keyStroke);

	switch (typeCode) {
	case LETTER:
		printf("That is a LETTER.\n");
		switch (subTypeCode) {
		case VOWEL:
			printf("The LETTER is a VOWEL.\n");
			break;
		case CONSONANT:
			printf("The LETTER is a CONSONANT.\n");
			break;
		}
		break;
	case SYMBOL:
		printf("That is a SYMBOL.\n");
		switch (subTypeCode) {
		case UPPER_ASCII:
			printf("The SYMBOL is from the UPPER_ASCII table.\n");
			break;
		case LOWER_ASCII:
			printf("The SYMBOL is from the LOWER_ASCII table.\n");
			break;
		}
		break;
	case NUMBER:
		printf("That is a NUMBER.\n");
		switch (subTypeCode) {
		case EVEN:
			printf("The NUBMER is EVEN.\n");
			break;
		case ODD:
			printf("The NUMBER is ODD.\n");
			break;
		}
		break;
	}

	_getch();
	return 0;
}
