/*
start
 declarations:
  double interestRate, timesCompounded, principal, interest, amountInSavings
 display: "what is the investment amount?"
 principal = input
 display: "what is the intrest rate in decimal form?"
 intrestRate = input;
 display: "How many times per year is the intrest compounded? (4 for quaterly, 12 for monthly)"
 timesCompounded = input
 amountInSavings = principal * 1 + (interestRate / 100) / timesCompounded^ timesCompounded
 interest = amountInSavings - principal
 Display: "Interest Rate:"  interestRate
 Display: "Times Compounded:" timesCompounded
 Display: "Principal:" principal
 Display: "Interest:"  interest 
 Display: "Amount is Savings:"  amountInSavings
End
*/
#include "pch.h"
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
	//declare variables
	double interestRate, timesCompounded, principal, interest, amountInSavings;

	//get user input and save to variables
	cout << "what is the investment amount?\n";
	cin >> principal;
	cout << "what is the intrest rate?\n";
	cin >> interestRate;
	cout << "How many times per year is the intrest compounded? (4 for quaterly, 12 for monthly)\n";
	cin >> timesCompounded;

	//calculate amount in savings
	amountInSavings = principal * pow(1 + (interestRate / 100) / timesCompounded, timesCompounded);

	//calulate interest amount;
	interest = amountInSavings - principal;

	//show fomated outpput
	cout << setprecision(2) << fixed;
	cout << endl;
	cout << endl;
	cout << left << setw(30) << "Interest Rate:"
		<< right << setw(9) << interestRate << "%" << endl;
	cout << left << setw(30) << "Times Compounded:"
		 << right << setprecision(0) << fixed << setw(10) << timesCompounded  << endl;
	cout << left << setw(30) << "Principal:"
		 << right << setprecision(2) << fixed << setw(3) << "$"  << principal  << endl;
	cout << left << setw(30) << "Interest:"
		 << right << setw(5) << "$" <<  interest  << endl;
	cout << left << setw(30) << "Amount is Savings:"
		 << right << setw(3) << "$" << amountInSavings  << endl;
	cout << endl;
	cout << endl;
	//exit program without error
	return 0;
}
