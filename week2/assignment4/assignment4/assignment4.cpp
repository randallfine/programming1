/*
start
	Declarations:
		int shares = 600
		double cost = 33.77
		double commitionPercent = .02
		double totalCommition
		double amountPaid
		double totalAmount
	amountPaid = shares * cost
	totalCommition = amountPaid * commitionPercent
	totalAmount = cost + totalCommition
	display: "Amount paid for stock is {amountPaid}"
	display: "The commition is {totalCommition}"
	display: "The grand total is {totalAmount}"
end
*/

#include "pch.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	int shares = 600;
	double cost = 33.77,
		commitionPercent = .02,
		totalCommition, amountPaid, totalAmount;
	amountPaid = shares * cost;
	totalCommition = amountPaid * commitionPercent;
	totalAmount = amountPaid + totalCommition;
	cout << fixed;
	cout << setprecision(2);
	cout << "Amount paid for stock is $" << amountPaid << endl;
	cout << "The commition is $" << totalCommition << endl;
	cout << "The grand total is $" << totalAmount << endl;
	return 0;
}