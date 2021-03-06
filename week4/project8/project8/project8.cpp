/*
start
	function declarations
		double billLevel1 (double kwh);
		double billLevel2 (double kwh);
		double billLevel3 (double kwh);
		double billLevel4 (double kwh);

		constant declarations
			const double discount = 0.12, stateTax = .035, cityTax = .015;
		variable declarations
			string customerName;
			double kwh, base, discountTotal, totalCityTax, totalStateTax, total;

		display "What is the customers name?
		customerName = input
		display "What is the kWh used for this month?
		kwh = input

		if kwh <= 1000
			base = return from billLevel1(kwh)
		else if kwh <= 1300
			base  = return from billLevel2(kwh)
		else if kwh <= 2000
			base = return from billLevel3(kwh);
		else
			base = return from billLevel4(kwh);
		end if

		discountTotal = base * discount;
		totalCityTax = base * cityTax;
		totalStateTax = base * stateTax;
		total = base + totalCityTax + totalStateTax - discountTotal;

		display "Customer name: {customerName}"
		display "The billed amount before taxes and discounts: {base}"
		display "The discount applied to this bill is: {discountTotal}"
		display "The state tax amount is: {totalStateTax"
		display "The city tax amount  is: {totalCityTax}"
		display "The total amount due is: {total}"


	function double billLevel1 (double kwh)
		return kwh * .052;
	end function

	function double billLevel2 (double kwh)
		declaration
			double tmp = billLevel1(1000);
		kwh -= 1000;
		return kwh * .041 + tmp;
	end function

	function double billLevel3 (double kwh)
		delcaration
			double temp = billLevel2(1300);
		kwh -= 1300;
		return kwh * .035 + temp;
	end function

	function double billLevel4 (double kwh)
		declaration
			double tmp = billLevel3(2000);
		kwh -= 2000;
		return kwh * .03 + tmp;
	end function
end
*/

#include "pch.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//declare functions
double billLevel1(double kwh);
double billLevel2(double kwh);
double billLevel3(double kwh);
double billLevel4(double kwh);

int main() {

	//set consts
	const double discount = 0.12, stateTax = .035, cityTax = .015;
	//declare variable
	string customerName;
	double kwh, base, discountTotal, totalCityTax, totalStateTax, total;

	//get user input
	cout << "What is the customers name?\n";
	getline(cin, customerName);
	cout << "What is the kWh used for this month?\n";
	cin >> kwh;

	//calculate base ammount before tax and discount
	if (kwh <= 1000) {
		base = billLevel1(kwh);
	}
	else if (kwh <= 1300) {
		base = billLevel2(kwh);
	}
	else if (kwh <= 2000) {
		base = billLevel3(kwh);
	}
	else {
		base = billLevel4(kwh);
	}

	//calulate total discount
	discountTotal = base * discount;

	//calculate city and state tax;
	totalCityTax = base * cityTax;
	totalStateTax = base * stateTax;

	//calculate total
	total = base + totalCityTax + totalStateTax - discountTotal;

	//output bill ammount 
	cout << endl;
	cout << fixed << setprecision(2);
	cout << "Customer name: "
		<< customerName << endl;
	cout << "The billed amount before taxes and discounts: "
		<< "$" << base << endl;
	cout << "The discount applied to this bill is: "
		<< "$" << discountTotal << endl;
	cout << "The state tax amount is: "
		<< "$" << totalStateTax << endl;
	cout << "The city tax amount  is: "
		<< "$" << totalCityTax << endl;
	cout << "The total amount due is: "
		<< "$" << total << endl;
}

//function is called if kwh <= 1000
double billLevel1(double kwh) {
	return kwh * .052;
}

//function is called if kwh <= 1300 
double billLevel2(double kwh) {
	double tmp = billLevel1(1000);
	kwh -= 1000;
	return kwh * .041 + tmp;
}

// function is called if kwh <= 2000
double billLevel3(double kwh) {
	double temp = billLevel2(1300);
	kwh -= 1300;
	return kwh * .035 + temp;
}

//function is called if kwh > 2000
double billLevel4(double kwh) {
	double tmp = billLevel3(2000);
	kwh -= 2000;
	return kwh * .03 + tmp;
}
