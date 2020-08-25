#pragma warning(disable:4996)
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main() {
	char horizontalDivider = '-', verticalDivider = '|';
	int columns = 0, rows = 0;

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

	//Build Grid
	int** grid;
	grid = malloc(columns * sizeof(int *));

	for (int i = 0; i <= columns; i++) {
		grid[i] = malloc(rows * sizeof(int));
	}

	//Fill Grid
	for (int x = 0; x <= columns; x++) {
		grid[0][x] = x;
	}

	for (int x = 0; x <= rows; x++) {
		grid[x + 1][0] = (x + 1);
	}

	for (int x = 1; x <= rows; x++) {
		for (int y = 1; y <= columns; y++) {
			grid[x][y] = grid[x][0] * grid[0][y];
		}
	}

	//Print Table
	for (int c = 0; c < (rows + 1); c++) {
		for (int d = 0; d < (columns + 1); d++) {
			if ((c == 0) && (d == 0)) {
				printf("%*c", 4, verticalDivider);
			}
			else {
				printf("%*d%c", 4, grid[c][d], verticalDivider);
			}
		}
		printf("\n");
		for (int e = 0; e < (columns + 1); e++) {
			printf("%c%c%c+", horizontalDivider, horizontalDivider, horizontalDivider);
		}
		printf("\n");
	}

	//Free Memory
	for (int i = 0; i < rows; i++) {
		free(grid[i]);
	}
	free(grid);

	_getch();
	return 0;
}