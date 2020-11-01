// INCLUDES
#include <stdio.h>

// DEFINES
#ifndef __TRUE_FALSE__
#define __TRUE_FALSE__
#define TRUE 1
#define FALSE 0
#endif

// ROWS and COLS must be between 1 and 9
#define ROWS 7
#define COLS 7

// MARKER CODES
#define MARKONE 'X'
#define MARKTWO 'O'
#define BLANK   ' '

// VICTORY CODES
#define NO_WIN		0		// MARKONE and MARKTWO have not produced CONSECUTIVE_MARKS_REQUIRED
					// adjacent symbols and there are moves available on the board
#define MARK_ONE_VICTORY	1	// MARKONE has produced CONSECUTIVE_MARKS_REQUIRED
#define MARK_TWO_VICTORY	2	// MARKTWO has produced CONSECUTIVE_MARKS_REQUIRED
#define TIE			3	// MARKONE and MARKTWO have not produced CONSECUTIVE_MARKS_REQUIRED
					// adjacent symbols and there are no moves available on the board
#define ERROR		4		// MARKONE and MARKTWO have produced 
							// CONSECUTIVE_MARKS_REQUIRED adjacent symbols
#define EPIC_FAIL		5	// the logic in VictoryCheck() has produced an impossible combination of
					// return code indicators

// GAME PARAMETER CODES
#define CONSECUTIVE_MARKS_REQUIRED 3

#define CODE_OK 0
#define CODE_OOB 1
#define CODE_COLLISION 2

// PROTOTYPES
void InitializeBoard(char[ROWS][COLS]);
void DisplayBoard(char[ROWS][COLS]);
int PlayerMove(int, int, char[ROWS][COLS], char);
int VictoryCheck(int, char[ROWS][COLS]);
void DisplayVictoryMessage(int);
void errorHandler(char);

// MAIN
int main() {
	// declare variables
	char board[ROWS][COLS];

	// PRODUCE A NO_WIN CONDITION
	// initialize board
	InitializeBoard(board);
	// populate board
	PlayerMove(1, 1, board, MARKONE);
	PlayerMove(1, 2, board, MARKONE);
	// display the board
	DisplayBoard(board);
	// display victory message
	DisplayVictoryMessage(VictoryCheck(CONSECUTIVE_MARKS_REQUIRED, board));

	// PRODUCE A HORIZONTAL VICTORY
	// initialize board
	InitializeBoard(board);
	// populate board
	PlayerMove(1, 1, board, MARKONE);
	PlayerMove(1, 2, board, MARKONE);
	PlayerMove(1, 3, board, MARKONE);
	// display the board
	DisplayBoard(board);
	// display victory message
	DisplayVictoryMessage(VictoryCheck(CONSECUTIVE_MARKS_REQUIRED, board));

	// PRODUCE A VERTICAL VICTORY
	// initialize board
	InitializeBoard(board);
	// populate board
	PlayerMove(1, 1, board, MARKTWO);
	PlayerMove(2, 1, board, MARKTWO);
	PlayerMove(3, 1, board, MARKTWO);
	// display the board
	DisplayBoard(board);
	// display victory message
	DisplayVictoryMessage(VictoryCheck(CONSECUTIVE_MARKS_REQUIRED, board));

	// PRODUCE A DIAGONALDOWN VICTORY
	// initialize board
	InitializeBoard(board);
	// populate board
	PlayerMove(1, 1, board, MARKONE);
	PlayerMove(2, 2, board, MARKONE);
	PlayerMove(3, 3, board, MARKONE);
	// display the board
	DisplayBoard(board);
	// display victory message
	DisplayVictoryMessage(VictoryCheck(CONSECUTIVE_MARKS_REQUIRED, board));

	// PRODUCE A DIAGONALUP VICTORY
	// initialize board
	InitializeBoard(board);
	// populate board
	PlayerMove(3, 1, board, MARKTWO);
	PlayerMove(2, 2, board, MARKTWO);
	PlayerMove(1, 3, board, MARKTWO);
	// display the board
	DisplayBoard(board);
	// display victory message
	DisplayVictoryMessage(VictoryCheck(CONSECUTIVE_MARKS_REQUIRED, board));

	// PRODUCE A MULTIPLE PLAYER VICTORY
	// initialize board
	InitializeBoard(board);
	// populate board
	PlayerMove(4, 1, board, MARKONE);
	PlayerMove(4, 2, board, MARKONE);
	PlayerMove(4, 3, board, MARKONE);

	PlayerMove(3, 1, board, MARKTWO);
	PlayerMove(2, 2, board, MARKTWO);
	PlayerMove(1, 3, board, MARKTWO);

	// display the board
	DisplayBoard(board);
	// display victory message
	DisplayVictoryMessage(VictoryCheck(CONSECUTIVE_MARKS_REQUIRED, board));

	// exit program
	return 0;
}

// FUNCTION IMPLEMENTATIONS
void InitializeBoard(char board[ROWS][COLS]) {
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
		printf("%*d ", 2, (r + 1));	//Print row label
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

int VictoryCheck(int winRequirement, char board[ROWS][COLS]) {
	int blankSeen = FALSE;
	int markOneWins = FALSE;
	int markTwoWins = FALSE;
	int markOneTally = 0;
	int markTwoTally = 0;

	while (!(markOneTally >= CONSECUTIVE_MARKS_REQUIRED) || !(markTwoTally >= CONSECUTIVE_MARKS_REQUIRED)) { //Watch the tally for marks in a 'row' for necessary number of marks
		
		for (int r = 0; r < ROWS; r++) {	//Search for a mark
			for (int c = 0; c < COLS; c++) {
				if (board[r][c] == MARKONE) {
					markOneTally++;

					for (int d = c; d <= (c + CONSECUTIVE_MARKS_REQUIRED); d++) {

					}
				}
			}
		}
	}

}

void DisplayVictoryMessage(int victoryCode) {
	// display the victory condition results
	switch (victoryCode) {
	case NO_WIN:
		printf("There is still no winner.\n");
		break;

	case MARK_ONE_VICTORY:
		printf("MARKONE has won the game.\n");
		break;

	case MARK_TWO_VICTORY:
		printf("MARKTWO has won the game.\n");
		break;

	case TIE:
		printf("The game is a draw.\n");
		break;

	case ERROR:
		printf("Something bad happened... MARKONE and MARKTWO have both won.\n");
		break;

	case EPIC_FAIL:
		printf("Something bad happened... VictoryCheck() has produced an impossible combination of return code indicators.\n");
		break;

	default:
		printf("DisplayVictoryMessage() was passed an invalid victoryCode.\n");
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
