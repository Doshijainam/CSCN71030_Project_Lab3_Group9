#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Parameter.h"

#define MAX_STRING 100
#define MASS 415000

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
		break;
		//Sun
	case 2:
		distance = 148750000;
		break;
		//Mars
	case 3:
		distance = 286820000;
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

	int choice;

	//Dereference NULL pointer
	if (planet != "\0") {
		//If user inputted string is Moon then give the distance to the Moon
		if (strcmp(planet, "Moon") == 0) {
			choice = 1;
			printf("\n You have chosen the moon!\n\n Its just a short trip of ");
			printf("%.2lf", distance(choice));
			printf(" kilometers!\n\n");
			printf(" It will take you approx %d hours.\n\n", moonTime());
			moonThrust();
			moonVelocity();
		}
		//If user inputted string is Sun then give the distance to the Sun
		else if (strcmp(planet, "Sun") == 0) {
			choice = 2;
			printf("\n You have chosen the Sun!\n\n It's fairly warm there.\n It's ");
			printf("%.2lf", distance(choice));
			printf(" kilometers from earth!\n You're gonna be here a while...\n\n");
			printf(" It will take you approx %d hours.\n\n", sunThrust());
			sunThrust();
			sunVelocity();
		}
		//If user inputted string is Mars then give the distance to the Mars
		else if (strcmp(planet, "Mars") == 0) {
			choice = 3;
			printf("\n You have chosen Mars!\n\n I hope you find some alien life.\n It's ");
			printf("%.2lf", distance(choice));
			printf(" kilometers from earth!\n You'll spend the rest of your life waiting...\n\n");
			printf(" It will take you approx %d hours.\n\n", marsThrust());
			marsThrust();
			marsVelocity();
		}
		//If input is incorrect go back to entering a planet
		else {
			printf(" Incorrect Input please input correct planet name.\n\n");
			goto select;
		}
	}
}

//Moon time function
int moonTime() {
	long int irand;
	srand(time(NULL));
	irand = rand() % (230 - 60 + 1) + 60;  //  for moon 
	return irand;
}
//Sun time function
int sunTime() {
	long int srand;
	srand = rand() % (610 - 400 + 1) + 400;
	// for sun it would take 606 hours 
	return srand;
}
//Mars time function
int marsTime() {
	long int Rrand;
	Rrand = rand() % (5100 - 5000 + 1) + 5000;
	return Rrand;
}

//Thrust for moon = mass / time
double moonThrust() {
	double thrust = MASS / moonTime();
	printf(" Rocket thrust will be %.2lf Newtons\n\n", thrust);
	return thrust;
}
//Thrust for sun = mass / time
double sunThrust() {
	double thrust = MASS / sunTime();
	printf(" Rocket thrust will be %.2lf Newtons\n\n", thrust);
	return thrust;
}
//Thrust for mars = mass / time
double marsThrust() {
	double thrust = MASS / marsTime();
	printf(" Rocket thrust will be %.2lf Newtons\n\n", thrust);
	return thrust;
}

//Velocity for moon = distance / time
double moonVelocity()
{
	double velocity = distance(1) / moonTime();
	printf(" The Velocity of the rocket will be %.2lf Km/h.\n\n", velocity);
	return velocity;
}
//Velocity for sun = distance / time
double sunVelocity()
{
	double velocity = distance(2) / sunTime();
	printf(" The Velocity of the rocket will be %.2lf Km/h.\n\n", velocity);
	return velocity;
}
//Velocity for mars = distance / time
double marsVelocity()
{
	double velocity = distance(3) / marsTime();
	printf(" The Velocity of the rocket will be %.2lf Km/h.\n\n", velocity);
	return velocity;
}