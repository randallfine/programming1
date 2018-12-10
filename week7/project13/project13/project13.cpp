/*
start
	declare function prototypes
		collect rain data 
		calculate average
		find lowest
		find highest
	function main
		pass in nothing
		declarations
			constant int SIZE = 12
			int lowest, highest
			int array rainFall size of {SIZE}
			string array months size of {SIZE} = { "January", "Febuary", "March", "April",
												   "May", "June", "July", "August", "September",
												   "October", "November", "December" }
			call CollectRainData passing in rainFall, months, SIZE

			rainFallTotal = the return from CalculateTotalRainfall passing in rainFall, SIZE
			rainFallAvg = the return from CalculateAverage passing in rainFallTotal, SIZE
			lowestValue = the return from FindLowest passing in rainFall, SIZE, lowest
			highestValue = the return from FindHighest rainFall, SIZE, highest
			Display :
				"Total rainfall for the year:  {rainFallTotal} inches"
				"Average monthly rainfall: {rainFallAvg} inches"
				"{months[lowest]}  had the lowest amount of rainfall with {lowestValue} inches"
				"{months[highest]} had the highest ammount of rainfall with  highestValue inches"
		pass out int
	end function

	function CollectRainData
		pass in rainFall, months, SIZE
		for i = 0; i < SIZE; i++
			display: "Enter the total rainfall for the month of {months[i]}"
			rainFall[i] = input
		end for
	end function

	function CalculateTotalRainfall(double rainFall[], int SIZE) {
		passing in rainFall, SIZE
		declarations
			sum = 0
		for i = 0; i < SIZE; i++
			sum = SUM + rainFall[i];
		end for
		passing out sum;
	end function


	function CalculateAverage
		passing in total, SIZE
		passing out total / SIZE
	end function

	function FindLowest
		passing in rainFall, SIZE, reference to lowest
		declarations
		value = rainFall[0]
		lowest = 1
		for  i = 0; i < SIZE; i++
			if rainFall[i] < value
				value = rainFall[i]
				lowest = i
			end if
		end for
		passing out value;
	end function

	function FindHighest
		passing in rainFall, SIZE, reference to highest
		delcarations
		value = rainFall[0]
		highest = 1;
		for i = 0; i < SIZE; i++
			if rainFall[i] > value
				value = rainFall[i];
				highest = i;
			end if
		end for
		passing out value;
	end function
end	
*/
#include "pch.h"
#include <iostream>
#include <iomanip>
#include <string>


using namespace std;

//function prototypes
void CollectRainData(double[], string[], int);
double CalculateTotalRainfall(double[], int);
double CalculateAverage(double, int);
double FindLowest(double[], int, int&);
double FindHighest(double[], int, int&);

int main() {
	//declare variables
	const int SIZE = 12;
	int lowest, highest;
	//declare rainfall array
	double rainFall[SIZE], rainFallTotal, rainFallAvg, lowestValue, highestValue;
	//declare months array
	string months[SIZE] = { "January", "Febuary", "March", "April",
								  "May", "June", "July", "August", "September",
								  "October", "November", "December" };
	//call collect rain data
	CollectRainData(rainFall, months, SIZE);

	//call functions and asign return to vaiables for display
	rainFallTotal = CalculateTotalRainfall(rainFall, SIZE);
	rainFallAvg = CalculateAverage(rainFallTotal, SIZE);
	lowestValue = FindLowest(rainFall, SIZE, lowest);
	highestValue = FindHighest(rainFall, SIZE, highest);

	//display rainfall amoutunts formated to 2 decimal points
	cout << setprecision(2) << fixed;
	cout << endl;
	cout << "Total rainfall for the year: " << rainFallTotal << " inches" << endl;
	cout << "Average monthly rainfall: " << rainFallAvg << " inches" << endl;
	cout << months[lowest] << " had the lowest amount of rainfall with " << lowestValue << " inches" << endl;
	cout << months[highest] << " had the highest amount of rainfall with " << highestValue << " inches" << endl;
	
	//return without error
	return 0;
}

//gets inout from user an populates rainFall array
void CollectRainData(double rainFall[], string months[], int SIZE) {
	//get user input for rainfall array
	for (int i = 0; i < SIZE; i++) {
		cout << "Enter the total rainfall for the month of " << months[i] << endl;
		cin >> rainFall[i];
	}
}

//sums total rainfall from rainfall array
double CalculateTotalRainfall(double rainFall[], int SIZE) {
	double sum = 0;
	for (int i = 0; i < SIZE; i++) {
		sum += rainFall[i];
	}
	return sum;
}

//gets average rainfall from rainFall array
double CalculateAverage(double total, int SIZE) {
	return total / SIZE;
}

//finds the lowest amount of rainfall and at what index
double FindLowest(double rainFall[], int SIZE, int& lowest) {
	double value = rainFall[0];
	lowest = 1;
	for (int i = 0; i < SIZE; i++) {
		if (rainFall[i] < value) {
			value = rainFall[i];
			lowest = i;
		}
	}
	return value;
}

//finds the highest amount of rainfall and at what index
double FindHighest(double rainFall[], int SIZE, int& highest) {
	double value = rainFall[0];
	highest = 1;
	for (int i = 0; i < SIZE; i++) {
		if (rainFall[i] > value) {
			value = rainFall[i];
			highest = i;
		}
	}
	return value;
}
