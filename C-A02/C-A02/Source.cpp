// Preprocessor Directives
#pragma warning(disable:4996)	// To enable deprecated scanf()
#include <stdio.h>
#include <math.h>

void main() {
	// Declare Variables
	int menuOption = 0;

	// Prompts
	printf("1.) Centimeters To Inches\n");
	printf("2.) 2D Distance Formula\n");
	printf("3.) Pyramid Surface Area\n");
	printf("--------------------------\n");
	printf("Which formula would you like to run\?: ");
	scanf("%d", &menuOption);

	// Run Appropriate Formula
	if (menuOption == 1) {
		float distanceInInches = 0;
		float distanceInCM = 0;

		printf("Enter the distance in centimeters: ");
		scanf("%f", &distanceInCM);
		distanceInInches = distanceInCM / 2.54;
		printf("%.2f cm is %.2f in\n", distanceInCM, distanceInInches);
	}
	else if (menuOption == 2) {
		float x1 = 0, x2 = 0, y1 = 0, y2 = 0, distance = 0;
		printf("Enter a pair of 2D coordinates, press ENTER between each number:\n");
		printf("Point 1:\nX: ");
		scanf("%f", &x1);
		printf("Y: ");
		scanf("%f", &y1);
		printf("Point 2:\nX: ");
		scanf("%f", &x2);
		printf("Y: ");
		scanf("%f", &y2);

		distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

		printf("The distance between \(%.2f, %.2f\) and \(%.2f, %.2f\) is %.2f.\n", x1, y1, x2, y2, distance);
	}
	else if (menuOption == 3) {
		float edgeLength = 0;
		float heigth = 0;
		float surfaceArea = 0;

		printf("Enter the pyramid's edge length: ");
		scanf("%f", &edgeLength);
		printf("Enter the pyramid's heigth: ");
		scanf("%f", &heigth);

		surfaceArea = pow(edgeLength, 2) + 2 * edgeLength * sqrt((pow(edgeLength, 2) / 4) + pow(heigth, 2));

		printf("The surface area of a pyramid with an edge length of %.2f and a heigth of %.2f is %.2f.\n", edgeLength, heigth, surfaceArea);
	}
	else {
		printf("That was not a valid menu option...\n");
	}
}