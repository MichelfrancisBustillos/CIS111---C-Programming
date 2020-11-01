#pragma warning(disable:4996)
// INCLUDES
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// DEFINES
#define LOWER_DIE 1 // LOWER_DIE must be at least 1
#define UPPER_DIE 10
#define TRIALS 10000

// PROTOTYPES
int genRand(int, int);
int getTwoDieSum();

// MAIN
int main() {
	int numberArray[2 * UPPER_DIE + 1]; // holds frequency of rolls
	int arraySize = 2 * UPPER_DIE + 1;

	// initialize numberArray
	for (int c = 0; c < arraySize; c++) {
		numberArray[c] = 0;
	}

	// seed the random number generator
	srand(time(0));

	// roll the dice and keep track of what was rolled in the array
	int dieSum = 0; //variable to hold incoming sums
	for (int c = 1; c <= TRIALS; c++) {
		dieSum = getTwoDieSum();
		numberArray[dieSum] = numberArray[dieSum] + 1;
	}

	// display results
	int minimumRoll = LOWER_DIE * 2; //Determine smallest possible result

	printf("After rolling the dice %d times, here are the reuslts...\n", TRIALS);
	printf("ROLL VALUE | FREQUENCY\n"); //Print table header
	for (int c = minimumRoll; c < arraySize; c++) { //Print result rows
		printf("%*d | %d\n", 10, c, numberArray[c]);
	}
	
	return 0;
}

// FUNCTION IMPLEMENTATIONS
int genRand(int lower, int upper) {
	int range = (upper - lower) + 1;
	return rand() % range + lower;
}

int getTwoDieSum() {
	// YOUR IMPLEMENTATION GOES HERE
	int dieOne = genRand(LOWER_DIE, UPPER_DIE);
	int dieTwo = genRand(LOWER_DIE, UPPER_DIE);
	int dieSum = dieOne + dieTwo;
	return dieSum;
}
