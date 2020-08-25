#pragma warning(disable:4996)
#include <stdio.h>
#include <conio.h>

int main() {
	char horizontalDivider = '-', verticalDivider = '|';
	int columns = 0, rows = 0;
	int r = 0, c = 0; //Variables for use in loops
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

	for (c = 1; c <= columns; c++) { //Print Top Headings
		printf("%*d%c", columnSpace, c, verticalDivider);
	}

	printf("\n");

	for (c = 0; c <= columns; c++) { //Print Heading Divider
		for (int s = 1; s <= columnSpace; s++) {
			printf("-");
		}
		printf("%c", verticalDivider);
	}

	printf("\n");

	for (r = 1; r <= rows; r++) { //Print Rows
		printf("%*d%c", columnSpace, r, verticalDivider);
		for (c = 1; c <= columns; c++) {
			int result = r * c;
			printf("%*d%c", columnSpace, result, verticalDivider);
		}
		printf("\n");
	}

	_getch();
	return 0;
}