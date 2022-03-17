#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Parameter.h"

#define MAX_STRING 100

//Intro menu
void menu() {
	printf("\n\tWelcome to SpaceWare!\n\n To begin please choose from the list of planets below\n\n");
	printf(" Moon\n Sun\n Mars\n\n");
}

//Distance Parameter, user chooses from 8 set destinations
double distance(int destination) {
	double distance = 0;
	switch (destination) {
		//Moon
	case 1:
		distance = 384400;
		printf("\n You have chosen the moon!\n Its just a short trip of ");
		break;
		//Sun
	case 2:
		distance = 148750000;
		printf("\n You have chosen the Sun!\n It's fairly warm there.\n It's ");
		break;
		//Mars
	case 3:
		distance = 286820000;
		printf("\n You have chosen Mars!\n I hope you find some alien life.\n It's ");
		break;
	default:
		EXIT_FAILURE;
	}
	return distance;
}

void planetSelector() {

	char planet[MAX_STRING];

	//Planet is used for when an incorrect input is entered so the user may re-enter a destination
	select:
	printf(" Planet: ");
	scanf_s("%s", &planet, MAX_STRING);

	//Null terminate string
	planet - 1;
	int choice;

	//Dereference NULL pointer
	if (planet != "\0") {
		//If user inputted string is Moon then give the distance to the Moon
		if (strcmp(planet, "Moon") == 0) {
			choice = 1;
			printf("%.2lf", distance(choice));
			printf(" kilometers!\n\n");
			moonTime();
		}
		//If user inputted string is Sun then give the distance to the Sun
		else if (strcmp(planet, "Sun") == 0) {
			choice = 2;
			printf("%.2lf", distance(choice));
			printf(" kilometers from earth!\n You're gonna be here a while...\n");
			sunTime();
		}
		//If user inputted string is Mars then give the distance to the Mars
		else if (strcmp(planet, "Mars") == 0) {
			choice = 3;
			printf("%.2lf", distance(choice));
			printf(" kilometers from earth!\n You'll spend the rest of your life waiting...\n");
			marsTime();
		}
		//If input is incorrect go back to entering a planet
		else {
			printf(" Incorrect Input please input correct planet name.\n");
			goto select;
		}
	}
}

void moonTime() {
	int irand;
	srand(time(NULL));
	irand = rand() % (230 - 60 + 1) + 60;  //  for moon 
	printf("It will take you approx %d hours.\n", irand);

}
void sunTime() {
	int srand;
	srand = rand() % (610 - 400 + 1) + 400;
	// for sun it would take 606 hours 

	printf("It will take you approx %d hours.\n", srand);
}
void marsTime() {
	int Rrand;
	Rrand = rand() % (5100 - 5000 + 1) + 5000;
	printf("It will take you approx %d hours.\n", Rrand);
}