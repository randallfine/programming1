/*
start
	declarations:
		int city = 345
		int hwy = 460
		int tank = 16
		double cityMPG
		double hwyMPG
	cityMPG = city / tank
	hwyMPH = hwy / tank
	display: "The miles per gallon in the city will be {cityMPG} per gallon"
	display: "The miles per gallon on the highway will be {hwyMPG} per gallon"
stop
*/

#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	//declare variables
	double city = 345;
	double hwy = 460;
	double tank = 16;
	//calulating MPG for city
	double cityMPG = city / tank;
	//calculating MPG for hwy
	double hwyMPG = hwy / tank;
	//display mpg for city and hwy
	cout << "The miles per gallon in the city will be " << cityMPG << " per gallon\n";
	cout << "The miles per gallon on the highway will be " << hwyMPG << " per gallon\n";
	//return with code of 0
	return 0;
}