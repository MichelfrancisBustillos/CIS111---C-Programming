#define _CRT_SECURE_NO_WARNINGS
// INCLUDES AND DEFINES
#include <stdio.h>
#include <string.h>

#ifndef __TRUE_FALSE__
#define __TRUE_FALSE__
#define TRUE 1
#define FALSE 0
#endif

#define BUFFER_SIZE 10000
#define ASCII_UPPER_LOWER_OFFSET 32

// PROTOTYPES
int ReadStringFromFile(char*, char*);
int WriteStringToFile(char*, char*);
int CleanString(char*);

// MAIN
int main() {
	char INPUT_FILE[] = "D:\\College\\CIS111\\C-A09\\input.txt";	//Note: Using direct path as VS appears to have issue with using working directory
	char OUTPUT_FILE[] = "D:\\College\\CIS111\\C-A09\\output.txt";
	char buffer[BUFFER_SIZE] = "";

	ReadStringFromFile(INPUT_FILE, buffer);
	CleanString(buffer);
	WriteStringToFile(OUTPUT_FILE, buffer);

	return 0;
}

int ReadStringFromFile(char* fileName, char* buffer) {
	FILE* file;	//Create obj of type FILE

	if ((file = fopen(fileName, "r")) == NULL) {	//Ensure a file has been opened (fopen will return NULL if no file opened) in read mode
		printf("Error Opening File!\n");
		return false;
	}

	fscanf(file, "%s", buffer);	//Read file contents into buffer

	fclose(file);	//Close file
	return TRUE;
}

int WriteStringToFile(char* filename, char* buffer) {
	FILE* file;	//Create obj of type FILE

	if ((file = fopen(filename, "w")) == NULL) {	//Ensure a file has been opened in write mode
		printf("Error Opening File!\n");
		return false;
	}

	fputs(buffer, file);	//Write buffer to file

	fclose(file);	//Close file
	return TRUE;
}

int CleanString(char* buffer) {
	int read = 0, write = 0;

	while (buffer[read]) {	//While buffer[read] is NOT empty
		if ((buffer[read] >= 97) && (buffer[read] <= 122)) {	//Check if buffer[read] is in spec (i.e. a lower case English letter with corresponding ASCII value between 97 & 122)
			buffer[write++] = buffer[read];	//If in spec copy, else drop
		}
		read++;	//Move read head to next index
	}
	buffer[write] = 0;	//Reset write head

	return TRUE;
}