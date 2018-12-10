
#include "pch.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
//declare global const
const int COLS = 5;
const int ROWS = 5;
//function prototypes
void getUserInput(double[][COLS], string[]);
void printTable(double[][COLS], string[]);
double CalculateTotal(double[][COLS]);
double CalculateAverage(double[][COLS]);
double CalculateRowTotal(double[][COLS], int);
double CalculateColumnTotal(double[][COLS], int);
double FindHighest(double[][COLS], int&, int&);
double FindLowest(double[][COLS], int&, int&);

int main() {
	//declarations
	double total, highest, lowest;
	string divisionNames[] = { "NORTH", "SOUTH", "EAST", "WEST" };
	int row, col;
	double salesAndTotals[ROWS][COLS];
	//call get user input to fill salesandtotals array
	getUserInput(salesAndTotals, divisionNames);
	//call calculatetotal assign to total
	total = CalculateTotal(salesAndTotals);
	//print salesand totals table to screen
	printTable(salesAndTotals, divisionNames);
	//call findhighest and assign to highest
	highest = FindHighest(salesAndTotals, row, col);
	cout << endl;
	//show division and quarter with highest sales
	cout  << setprecision(2) << fixed;
	cout << divisionNames[row] << " had the highest sales in quarter " 
		 << col + 1 << " with $" << highest << endl;
	//show division and quarter with lowest sales
	lowest = FindLowest(salesAndTotals, row, col);
	cout << divisionNames[row] << " had the lowest sales in quarter "
		<< col + 1 << " with $" << lowest << endl;

}
//get user input to fill sales an total array
void getUserInput(double salesAndTotals[][COLS], string divisionNames[]) {
	for (int i = 0; i < ROWS - 1; i++) {
		for (int j = 0; j < COLS - 1; j++) {
			cout << "Please enter the sales for " << divisionNames[i] << " division:  quarter " << j + 1 << endl;
			cin >> salesAndTotals[i][j];
		}
	}
}

//get total of all sales
double CalculateTotal(double salesAndTotals[][COLS]) {
	double sum = 0;
	for (int i = 0; i < ROWS - 1; i++) {
		for (int j = 0; j < COLS - 1; j++) {
			sum += salesAndTotals[i][j];
		}
	}
	return sum;
}

//get average of all sales
double CalculateAverage(double salesAndTotals[][COLS]) {
	double sum = 0, avg;
	for (int i = 0; i < ROWS - 1; i++) {
		for (int j = 0; j < COLS - 1; j++) {
			sum += salesAndTotals[i][j];
		}
	}
	avg = sum / ((ROWS - 1) * (COLS - 1));
	return avg;
}

//print salesandtotals to screen formated as table
void printTable(double salesAndTotals[][COLS], string divisionNames[]) {
	cout << setw(15) << "    ";
	for (int i = 0; i < COLS - 1; i++) {
		cout << setw(15) << "quarter" << i + 1;
	}
	cout << setw(15) << "  Division Totals" << endl;
	cout << setprecision(2) << fixed;
	for (int i = 0; i < ROWS - 1; i++) {
		cout << setw(15) << left << divisionNames[i];
		for (int j = 0; j < COLS - 1; j++) {
			cout << setw(15) << right << salesAndTotals[i][j] << " ";
		}
		cout << setw(15) << right << CalculateRowTotal(salesAndTotals, i) << endl;
	}
	cout << "Quarter Totals";
	for (int i = 0; i < COLS - 1; i++) {
		cout << setw(16) << right << CalculateColumnTotal(salesAndTotals, i);
	}
	cout << endl;
}

//calculate the total for each row
double CalculateRowTotal(double salesAndTotals[][COLS], int row) {
	double total = 0;
	for (int i = 0; i < COLS - 1; i++) {
		total += salesAndTotals[row][i];
	}
	return total;
}

//calculate the total for each column
double CalculateColumnTotal(double salesAndTotals[][COLS], int col) {
	double total = 0;
	for (int i = 0; i < COLS - 1; i++) {
		total += salesAndTotals[i][col];
	}
	return total;
}

//find the highest sales amount in array
double FindHighest(double salesAndTotals[][COLS], int& row, int& col) {
	row = 0, col = 0;
	double highest = salesAndTotals[0][0];
	for (int i = 0; i < ROWS - 1; i++) {
		for (int j = 0; j < COLS - 1; j++) {
			if (salesAndTotals[i][j] > highest) {
				highest = salesAndTotals[i][j];
				row = i;
				col = j;
			}
		}
		return highest;
	}
}

//find the lowest sales amount in the array
double FindLowest(double salesAndTotals[][COLS], int& row, int& col) {
	row = 0, col = 0;
	double lowest = salesAndTotals[0][0];
	for (int i = 0; i < ROWS - 1; i++) {
		for (int j = 0; j < COLS - 1; j++) {
			if (salesAndTotals[i][j] < lowest) {
				lowest = salesAndTotals[i][j];
				row = i;
				col = j;
			}
		}
		return lowest;
	}
}
