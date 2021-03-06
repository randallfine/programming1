/*
start
	Declarations:
		const double PI = M_PI;
		double diameter, area, r, totalSlices, sliceCounter, sliceSize = 14.125;
		int guests, slicesNeeded, pizzasNeeded = 1;
	Display: "How many inches is the diameter of the pizza?"
	diameter = input
	Display: "How many guests are you expecting?"
	guests = input
	r = diameter / 2;
	area = PI * r^2
	totalSlices = area / sliceSize;
	sliceCounter = totalSlices;
	slicesNeeded = guests * 3;
	while sliceCounter < slicesNeeded
		sliceCounter += totalSlices;
		pizzasNeeded++;
	end while
	Display: "The " {diameter} " inch pizza will make " {totalSlices} " slices"
	Display: "You will need " {pizzasNeeded} " pizzas"
end
*/

#include "pch.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	//declare variables
	const double PI = M_PI;
	double diameter, area, r, totalSlices, sliceCounter, sliceSize = 14.125;
	int guests, slicesNeeded, pizzasNeeded = 1; //assumes we will need atleat 1 pizza every time.

	//get user input and assign to variables
	cout << "How many inches is the diameter of the pizza?\n";
	cin >> diameter;
	cout << "How many guests are you expecting?\n";
	cin >> guests;

	//calculate raduis, area, and total slices the pizza will make
	r = diameter / 2;
	area = PI * pow(r, 2.0);
	totalSlices = area / sliceSize;

	//assign totalslices to the slice counter for while loop
	sliceCounter = totalSlices;

	//calculate the slices neede based on the number of guests having 3 slices each
	slicesNeeded = guests * 3;

	//while loop to count the number of pizzas needed based on the number of slices/guests
	while (sliceCounter < slicesNeeded)
	{
		sliceCounter += totalSlices;
		pizzasNeeded++;
	}
	
	//display output
	cout << " " << endl;
	cout << " " << endl;
	cout << "The " << diameter << " inch pizza will make " << setprecision(1) << fixed << totalSlices << " slices" << endl;
	cout << "You will need " << pizzasNeeded << " pizzas" << endl;
	cout << " " << endl;
	cout << " " << endl;
	
	//exit without error
	return 0;
}