//CSCN71030 - LAB 3 - GROUP 9
//AFTERMATH OF STACKOVERFLOW
//MEMBERS:
//1.JAINAM DOSHI
//2.JIGNESH PATEL
//3.COLE MACGREGOR

//Hello World Program Testing

#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "Parameter.h"
#include "Files.h"
#include "Structure.h"
#include "Financials.h"
#define USE_CRT_SECURE_NO_WARNINGS

#define MAX_STRING 100

int main(int argc, char *argv[])
{
	char *n = argv[1];
	double gravity = atoi(n);

	//Check if a file exists, if not make a new file
	if (checkIfFileExists("file.txt")) {
		readOpenFile();
	}
	else {
		writeOpenFile();
	}

	//Allocate memory for the structure
	struct parameters *save = (struct parameters*)malloc(sizeof(struct parameters));

	//Function to have rocket launch animation at start
	rocketLaunch();

	//Prints intro menu
	menu();
	
	//Calls function for user to select a planet
	planetSelector();

	displaySalaryChart();

}