#pragma warning(disable:4996)
// INCLUDES
#include <stdio.h>
#include <stdlib.h>

// DEFINES
#ifndef __TRUE_FALSE__
	#define __TRUE_FALSE__
	#define TRUE 1
	#define FALSE 0
#endif


// ROWS and COLS must be between 1 and 9
#define ROWS 4

#define COLS 4

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
void errorHandler(char);
void clearScreen();

// MAIN
int main() {
	// declare variables
	char board[ROWS][COLS];
	int playerRow = 0;
	int playerCol = 0;
	int errorCatcher = BLANK;
	int victoryCatcher = NO_WIN;

	InitializeBoard(board);	//Initialize blank board
	DisplayBoard(board);	//Display blank board

	while (victoryCatcher == NO_WIN) {	//Play until win or error
		while (errorCatcher != CODE_OK) {	//Prompt unitl a valid coord is entered
			printf("Player One: Choose a space by entering the row you would like to mark: ");
			scanf("%i", &playerRow);
			printf("Enter the column you would like to mark: ");
			scanf("%i", &playerCol);
			errorCatcher = PlayerMove(playerRow, playerCol, board, MARK_ONE);
			errorHandler(errorCatcher);
		}
		clearScreen();
		DisplayBoard(board);
		victoryCatcher = VictoryCheck(CONSECUTIVE_MARKS_REQUIRED, board);	//Check for a winner
		if (victoryCatcher != NO_WIN) {	//Exit game if win or error achieved
			break;
		}

		errorCatcher = BLANK;	//Reset errorCatcher for next player
		while (errorCatcher != CODE_OK) {	//Prompt unitl a valid coord is entered
			printf("Player Two: Choose a space by entering the row you would like to mark: ");
			scanf("%i", &playerRow);
			printf("Enter the column you would like to mark: ");
			scanf("%i", &playerCol);
			errorCatcher = PlayerMove(playerRow, playerCol, board, MARK_TWO);
			errorHandler(errorCatcher);
		}
		errorCatcher = BLANK;	//Reset errorCatcher for next player
		clearScreen();
		DisplayBoard(board);
		victoryCatcher = VictoryCheck(CONSECUTIVE_MARKS_REQUIRED, board);	//Check for a winner
	}

	DisplayVictoryMessage(victoryCatcher);

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
		printf("Player One has won the game!\n");
		break;

	case MARK_TWO_VICTORY:
		printf("Player Two has won the game!\n");
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

void clearScreen() {
	#if defined(__linux__) || defined(__unix__) || defined(__APPLE__)
		system("clear");
	#endif

	#if defined(_WIN32) || defined(_WIN64)
		system("cls");
	#endif
}
