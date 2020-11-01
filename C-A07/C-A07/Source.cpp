// INCLUDES 
#include <stdio.h> 

// DEFINES 
#ifndef __TRUE_FALSE__ 
#define __TRUE_FALSE__ 
#define TRUE 1 
#define FALSE 0 
#endif // ROWS and COLS must be between 1 and 9 
#define ROWS 7 
#define COLS 7 
#define MARKONE 'X' 
#define MARKTWO 'O' 
#define BLANK ' ' 

#define CODE_OK 0
#define CODE_OOB 1
#define CODE_COLLISION 2

// PROTOTYPES 
void InitializeBoard(char[ROWS][COLS]);
void DisplayBoard(char[ROWS][COLS]);
int PlayerMove(int, int, char[ROWS][COLS], char);
void errorHandler(char);

// MAIN 
int main() {
	// declare variables 
	char board[ROWS][COLS];
	int errorCode = CODE_OK;

	// initialize board 
	InitializeBoard(board); 
	// populate the board with moves 
	errorCode = PlayerMove(1, 1, board, MARKONE);
	errorHandler(errorCode);
	errorCode = PlayerMove(1, 2, board, MARKONE);
	errorHandler(errorCode);
	errorCode = PlayerMove(4, 3, board, MARKONE);
	errorHandler(errorCode);
	errorCode = PlayerMove(1, 1, board, MARKTWO);
	errorHandler(errorCode);
	errorCode = PlayerMove(6, 2, board, MARKTWO);
	errorHandler(errorCode);
	errorCode = PlayerMove(4, 12, board, MARKTWO);
	errorHandler(errorCode);
	// display the board 
	DisplayBoard(board);
	// exit program 
	return 0;
}

// FUNCTION IMPLEMENTATIONS 
void InitializeBoard(char board[ROWS][COLS])
{
	for (int r = 0; r < ROWS; r++) {
		for (int c = 0; c < COLS; c++) {
			board[r][c] = BLANK;
		}
	}
}

void DisplayBoard(char board[ROWS][COLS]) {
	printf("*************TIC-TAC-TOE*************\n");
	printf("\n  ");	//Ensure new line and indent first row
	for (int c = 1; c <= COLS; c++) {	//Print header
		printf("%*d", 2, c);
	}
	printf("\n");

	for (int r = 0; r < ROWS; r++) {	//Iterate rows
		printf("%*d ", 2, (r+1));	//Print row label
		for (int c = 0; c < COLS; c++) {	//Iterate columns
			printf("%c|", board[r][c]);	//Print board values
		}
		printf("\n  ");
		for (int c = 0; c <= COLS; c++) {	//Iterate columns
			printf("-+");	//Print row divider
		}
		printf("\n");
	}
}

int PlayerMove(int row, int col, char board[ROWS][COLS], char symbol) {
	row = row - 1; //Adjust English coordinates to C coordinates
	col = col - 1;

	if ((row >= ROWS) || (col >= COLS) || (row < 0) || (col < 0)) {	//Check for OOB
		return CODE_OOB;
	}
	else if (board[row][col] != BLANK) {	//Check for collision
		return CODE_COLLISION;
	}
	else {
		board[row][col] = symbol;	//Write symbol to board and confirm
		return CODE_OK;
	}
}

void errorHandler(char errorCode) {
	switch (errorCode) {
	case CODE_COLLISION:
		printf("That spot is taken!\n");
		break;
	case CODE_OOB:
		printf("That is off the board!\n");
		break;
	case CODE_OK:
	default:
		break;
	}
}