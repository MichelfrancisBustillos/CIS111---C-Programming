/*
Author: Mark Dencler
Description: Prints out the extended ASCII representations on the system.
Other: Extended ASCII listing:
	   http://www.cdrummond.qc.ca/cegep/informat/Professeurs/Alain/files/ascii.htm
*/

#include <stdio.h>
#include <conio.h>

int main() {
	int i = 0;

	// print title line
	printf(" DEC  | HEX  | CHAR\n");

	// print out ascii lines
	for (i = 32; i <= 255; i++) {
		printf(" %-5d| %-5x| %-5c\n", i, i, i);
	}

	_getch();
	return 0;
}