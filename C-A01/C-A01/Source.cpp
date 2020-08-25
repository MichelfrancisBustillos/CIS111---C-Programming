#include <stdio.h>

int main() {
	//Declare Variables
	char name[30] = "Hamid";
	char dogName[30] = "Alex";
	int age = 56;
	long favNum = 34;
	double favDec = 8.90;

	//Print Output to Console
	printf("Hello, my name is %s.\n", name);
	printf("\n");
	printf("As I'm sure you already know, my best friend \nis a dog\n");
	printf("\n");
	printf("His name is \"%s\"... can you say \"%s\"?\n", dogName, dogName);
	printf("\n");
	printf("I know it's quite pathetic for a man of %i\n", age);
	printf("years to have a dog as a best friend, but I\ncan't really help it. You see, I have terrible\nhygiene and don't really have much luck with the\n");
	printf("ladies. It probably doesn't help that I insist\non \"impressing\" them with my god-given talent to\nconvert base-10 numbers to octal and hexadecimal.\n");
	printf("\n");
	printf("For instance, my favorite number %i is %o\nin octal. If I took that same number and converted it to\nhexadecimal, it would be %x.\n", favNum, favNum, favNum);
	printf("\n");
	printf("My favorite decimal is %.2f, but I can't seem to convert\nthat one into octal or hexadecimal.\n", favDec);
	printf("I'm pretty sure you can do it, but I'm not 100%% sure.\n");

	return 0;
}