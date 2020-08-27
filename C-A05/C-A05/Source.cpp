#pragma warning(disable:4996)
#include <stdio.h>
#include <conio.h>

int main() {
	char horizontalDivider = '-', verticalDivider = '|';
	int columns = 0, rows = 0;
	int rowCounter = 0, columnCounter = 0; //Variables for use in loops
	int columnSpace = 1; //Width of columns

	//Get user input
	printf("Please enter the horizontal divider symbol: ");
	scanf("%c", &horizontalDivider);
	rewind(stdin);
	printf("Please enter the vertical divider symbol: ");
	scanf("%c", &verticalDivider);
	rewind(stdin);
	printf("Please enter the number of columns: ");
	scanf("%d", &columns);
	rewind(stdin);
	printf("Please enter the number of rows: ");
	scanf("%d", &rows);
	rewind(stdin);
	printf("\n");

	//Find maximum column width
	int largestSum = columns * rows; //Find largest possible number on the table
	while (largestSum != 0) {
		largestSum = largestSum / 10;
		columnSpace++;
	}

	//Print Table
	printf("%*c", (columnSpace + 1), verticalDivider);

	for (columnCounter = 1; columnCounter <= columns; columnCounter++) { //Print Top Headings
		printf("%*d%c", columnSpace, columnCounter, verticalDivider);
	}

	printf("\n");

	for (columnCounter = 0; columnCounter <= columns; columnCounter++) { //Print Heading Divider
		for (int s = 1; s <= columnSpace; s++) {
			printf("-");
		}
		printf("%c", verticalDivider);
	}

	printf("\n");

	for (rowCounter = 1; rowCounter <= rows; rowCounter++) { //Print Rows
		printf("%*d%c", columnSpace, rowCounter, verticalDivider);
		for (columnCounter = 1; columnCounter <= columns; columnCounter++) {
			int result = rowCounter * columnCounter;
			printf("%*d%c", columnSpace, result, verticalDivider);
		}
		printf("\n");
	}

	_getch();
	return 0;
}