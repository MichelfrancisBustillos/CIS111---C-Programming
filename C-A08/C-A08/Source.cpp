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
#define MARK_ONE 'X'
#define MARK_TWO 'O'
#define BLANK   ' '

// VICTORY CODES
#define NO_WIN		0		// MARK_ONE and MARK_TWO have not produced CONSECUTIVE_MARKS_REQUIRED
					// adjacent symbols and there are moves available on the board
#define MARK_ONE_VICTORY	1	// MARK_ONE has produced CONSECUTIVE_MARKS_REQUIRED
#define MARK_TWO_VICTORY	2	// MARK_TWO has produced CONSECUTIVE_MARKS_REQUIRED
#define TIE			3	// MARK_ONE and MARK_TWO have not produced CONSECUTIVE_MARKS_REQUIRED
					// adjacent symbols and there are no moves available on the board
#define ERROR		4		// MARK_ONE and MARK_TWO have produced 
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

// MAIN
int main() {
	// declare variables
	char board[ROWS][COLS];

	// PRODUCE A NO_WIN CONDITION
	// initialize board
	InitializeBoard(board);

	// populate board
	switch (PlayerMove(1, 1, board, MARK_ONE)) {
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
	switch (PlayerMove(1, 2, board, MARK_ONE)) {
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

	// display the board
	DisplayBoard(board);
	// display victory message
	DisplayVictoryMessage(VictoryCheck(CONSECUTIVE_MARKS_REQUIRED, board));

	// PRODUCE A HORIZONTAL VICTORY
	// initialize board
	InitializeBoard(board);
	// populate board
	switch (PlayerMove(2, 1, board, MARK_ONE)) {
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
	switch (PlayerMove(2, 2, board, MARK_ONE)) {
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
	switch (PlayerMove(2, 3, board, MARK_ONE)) {
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
	// display the board
	DisplayBoard(board);
	// display victory message
	DisplayVictoryMessage(VictoryCheck(CONSECUTIVE_MARKS_REQUIRED, board));

	// PRODUCE A VERTICAL VICTORY
	// initialize board
	InitializeBoard(board);
	// populate board
	switch (PlayerMove(1, 1, board, MARK_ONE)) {
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
	switch (PlayerMove(2, 1, board, MARK_ONE)) {
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
	switch (PlayerMove(3, 1, board, MARK_ONE)) {
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
	// display the board
	DisplayBoard(board);
	// display victory message
	DisplayVictoryMessage(VictoryCheck(CONSECUTIVE_MARKS_REQUIRED, board));

	// PRODUCE A DIAGONALDOWN VICTORY
	// initialize board
	InitializeBoard(board);
	// populate board
	switch (PlayerMove(1, 1, board, MARK_ONE)) {
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
	switch (PlayerMove(2, 2, board, MARK_ONE)) {
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
	switch (PlayerMove(3, 3, board, MARK_ONE)) {
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
	// display the board
	DisplayBoard(board);
	// display victory message
	DisplayVictoryMessage(VictoryCheck(CONSECUTIVE_MARKS_REQUIRED, board));

	// PRODUCE A DIAGONALUP VICTORY
	// initialize board
	InitializeBoard(board);
	// populate board
	switch (PlayerMove(3, 1, board, MARK_ONE)) {
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
	switch (PlayerMove(2, 2, board, MARK_ONE)) {
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
	switch (PlayerMove(1, 3, board, MARK_ONE)) {
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
	// display the board
	DisplayBoard(board);
	// display victory message
	DisplayVictoryMessage(VictoryCheck(CONSECUTIVE_MARKS_REQUIRED, board));

	// PRODUCE A MULTIPLE PLAYER VICTORY
	// initialize board
	InitializeBoard(board);
	// populate board
	switch (PlayerMove(4, 1, board, MARK_TWO)) {
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
	switch (PlayerMove(4, 2, board, MARK_TWO)) {
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
	switch (PlayerMove(4, 3, board, MARK_TWO)) {
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

	switch (PlayerMove(3, 1, board, MARK_ONE)) {
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
	switch (PlayerMove(2, 2, board, MARK_ONE)) {
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
	switch (PlayerMove(1, 3, board, MARK_ONE)) {
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

	//Iterate through board, when a mark is found, sanity check to make sure it is winnable. If so, check for each type of win. If no win is detected, find next mark.
	for (int r = 0; r < ROWS; r++) {
		for (int c = 0; c < COLS; c++) {
			if (board[r][c] == MARK_ONE) {	//Find a Mark One
				markOneTally++;
				if ((c + CONSECUTIVE_MARKS_REQUIRED - 1) < COLS) {	//Ensure it is in a winnable row
					for (int x = 1; x <= (CONSECUTIVE_MARKS_REQUIRED - 1); x++) {
						if (board[r][c + x] == MARK_ONE) {	//Check row for win.
							markOneTally++;
						}
					}
				}
				if (markOneTally >= CONSECUTIVE_MARKS_REQUIRED) {
					markOneWins = TRUE;
				}
				markOneTally = 1;
				if ((r + CONSECUTIVE_MARKS_REQUIRED - 1) < ROWS) {	//Ensure it is in a winnable column
					for (int x = 1; x < CONSECUTIVE_MARKS_REQUIRED; x++) {	//Check column for win.
						if (board[r + x][c] == MARK_ONE) {
							markOneTally++;
						}
					}
				}
				if (markOneTally >= CONSECUTIVE_MARKS_REQUIRED) {
					markOneWins = TRUE;
				}
				markOneTally = 1;
				if (((c + CONSECUTIVE_MARKS_REQUIRED - 1) < COLS) && ((r + CONSECUTIVE_MARKS_REQUIRED - 1) <= ROWS)) {	//Ensure both column AND row are viable
					for (int x = 1; x < CONSECUTIVE_MARKS_REQUIRED; x++) {	//Check column & row for win.
						if (board[r + x][c + x] == MARK_ONE) {
							markOneTally++;
						}
					}
				}
				if (markOneTally >= CONSECUTIVE_MARKS_REQUIRED) {
					markOneWins = TRUE;
				}
				markOneTally = 1;
				if (((c - CONSECUTIVE_MARKS_REQUIRED + 1) >= 0) && ((r + CONSECUTIVE_MARKS_REQUIRED - 1) < ROWS)) {	//Ensure both column AND row are viable
					for (int x = 1; x < CONSECUTIVE_MARKS_REQUIRED; x++) {	//Check column & row for win.
						if (board[r + x][c - x] == MARK_ONE) {
							markOneTally++;
						}
					}
				}
				if (markOneTally >= CONSECUTIVE_MARKS_REQUIRED) {
					markOneWins = TRUE;
				}
				markOneTally = 1;
			}
			else if (board[r][c] == MARK_TWO) { //Find a Mark Two
				markTwoTally++;
				if ((c + CONSECUTIVE_MARKS_REQUIRED - 1) < COLS) {	//Ensure it is in a winnable row
					for (int x = 1; x <= (CONSECUTIVE_MARKS_REQUIRED - 1); x++) {	//Check row for win.
						if (board[r][c + x] == MARK_TWO) {
							markTwoTally++;
						}
					}
				}
				if (markTwoTally >= CONSECUTIVE_MARKS_REQUIRED) {
					markTwoWins = TRUE;
				}
				markTwoTally = 1;
				if ((c + CONSECUTIVE_MARKS_REQUIRED - 1) < COLS) {	//Ensure it is in a winnable column
					for (int x = 1; x < CONSECUTIVE_MARKS_REQUIRED; x++) {
						if (board[r + x][c] == MARK_TWO) {	//Check column for win.
							markTwoTally++;
						}
					}
				}
				if (markTwoTally >= CONSECUTIVE_MARKS_REQUIRED) {
					markTwoWins = TRUE;
				}
				markTwoTally = 1;
				if (((c + CONSECUTIVE_MARKS_REQUIRED - 1) < COLS) && ((r + CONSECUTIVE_MARKS_REQUIRED - 1) < ROWS)) {	//Ensure both column AND row are viable
					for (int x = 1; x < CONSECUTIVE_MARKS_REQUIRED; x++) {	//Check column & row for a downright win.
						if (board[r + x][c + x] == MARK_TWO) {
							markTwoTally++;
						}
					}
				}
				if (markTwoTally >= CONSECUTIVE_MARKS_REQUIRED) {
					markTwoWins = TRUE;
				}
				markTwoTally = 1;
				if (((c + CONSECUTIVE_MARKS_REQUIRED - 1) >= 0) && ((r + CONSECUTIVE_MARKS_REQUIRED - 1) < ROWS)) {	//Ensure both column AND row are viable
					for (int x = 1; x < CONSECUTIVE_MARKS_REQUIRED; x++) {	//Check column & row for downleft win.
						if (board[r + x][c - x] == MARK_TWO) {
							markTwoTally++;
						}
					}
				}
				if (markTwoTally >= CONSECUTIVE_MARKS_REQUIRED) {
					markTwoWins = TRUE;
				}
				markTwoTally = 1;
			}
			else if (board[r][c] == BLANK) {	//Check for blank space to indicate if game still able to progress
				blankSeen = TRUE;	//Set blank found to know game in progress
			}
			markOneTally = 0;	//Reset tally
			markTwoTally = 0;
		}
	}

	printf("Mark One: %d; Mark Two: %d\n", markOneWins, markTwoWins);
	if ((markOneWins == FALSE) && (markTwoWins == FALSE) && (blankSeen == TRUE)) {
		return NO_WIN;
	}
	else if ((markOneWins == FALSE) && (markTwoWins == FALSE) && (blankSeen == FALSE)) {
		return TIE;
	}
	else if ((markOneWins == TRUE) && (markTwoWins == TRUE)) {
		return ERROR;
	}
	else if (markOneWins == TRUE) {
		return MARK_ONE_VICTORY;
	}
	else if (markTwoWins == TRUE) {
		return MARK_TWO_VICTORY;
	}

	else {
		return ERROR;
	}

	return 0;
}


void DisplayVictoryMessage(int victoryCode) {
	// display the victory condition results
	switch (victoryCode) {
	case NO_WIN:
		printf("There is still no winner.\n");
		break;

	case MARK_ONE_VICTORY:
		printf("MARK_ONE has won the game.\n");
		break;

	case MARK_TWO_VICTORY:
		printf("MARK_TWO has won the game.\n");
		break;

	case TIE:
		printf("The game is a draw.\n");
		break;

	case ERROR:
		printf("Something bad happened... MARK_ONE and MARK_TWO have both won.\n");
		break;

	case EPIC_FAIL:
		printf("Something bad happened... VictoryCheck() has produced an impossible combination of return code indicators.\n");
		break;

	default:
		printf("DisplayVictoryMessage() was passed an invalid victoryCode.\n");
	}
}