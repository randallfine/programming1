/*
start
	function prototype declarations
		Fucntion getscore passing in reference to score
		Function Calcaverage passing in score1 through score6
		Function Findlowest passing in score1 through score6
		
		Function main
			Pass In: nothing
			declarations
				score1 through score6
			call getscore for each score variable (score1 - score6)
			
			call calcaverage

			Pass Out: 0 for no errors
		Endfunction

		Function get score
			Pass In: reference to score
			declare bool variable isGoodScore and set to false
			display: "Please enter a score"
			do
				score = input

				if input is valid 
					isGoodValue = true
				else
					dipsplay: "Please enter a valid number from 0 to 100"
					clear error and ignore input
			end do 
			while isGoodscore is false
			Pass Out: nothing
		Endfunction

		Function calcaverage
			Pass In: score1 through score6
			declarations
				avg, sum set to 0, lowest set to the return of find lowest function
				array of scores from score1 through score6

			for each score in scores array
				sum is sum + score;
			end for
			sum is sum - lowest
			avg is sum / 5

			display "The average score is {avg}" set to fixed 2 decimal points
			Pass Out: nothing
		Endfunction

		Function find lowest score
			Pass In: score1 through score6

			declare array with score1 through score6
			declare lowest set to 100

			for each score in scores
				if score < lowest
					lowest = score
				end if
			end for

			Pass Out: lowest
		Endfunction
*/
#include "pch.h"
#include <iostream>
#include <iomanip>

//declare function prototypes
void GetScore(double &score);
void CalcAverage(double score1, double score2, double score3, double score4, double score5, double score6);
double FindLowest(double score1, double score2, double score3, double score4, double score5, double score6);

using namespace std;
int main() {
	//declare variables
	double score1, score2, score3, score4, score5, score6;
	//call getscore for each score variable
	GetScore(score1);
	GetScore(score2);
	GetScore(score3);
	GetScore(score4);
	GetScore(score5);
	GetScore(score6);
	//calculate average of top 5 scores
	CalcAverage(score1, score2, score3, score4, score5, score6);
	//exit without error
	return 0;

}

void GetScore(double &score) {
	//declare variable
	bool isGoodScore = false;


	cout << "Please enter a score\n";

	//get user input
	do {
		//get input while input is valis
		cin >> score;
		if (score > 0 && score < 100 && cin.good()) {
			isGoodScore = true;
		}
		else {
			//ask for input again if invalid, clear invalid input and errors
			cout << "Please enter a valid number from 0 to 100\n";
			cin.clear();
			cin.ignore(1000, '\n');
		}
	} while (!isGoodScore);
}

void CalcAverage(double score1, double score2, double score3, double score4, double score5, double score6) {
	//declare variables, call findLowest to get lowest score
	double avg, sum = 0, lowest = FindLowest(score1, score2, score3, score4, score5, score6);
	//make array of scores
	double scores[]{ score1, score2, score3, score4, score5, score6 };

	//loop through and sum scores
	for (double &score : scores) {
		sum += score;
	}

	//sutract lowest score
	sum -= lowest;

	//find the average score
	avg = sum / 5;

	//output the average score formated
	cout << setprecision(2) << fixed;
	cout << endl;
	cout << "The average score is: " << avg << endl;
}

double FindLowest(double score1, double score2, double score3, double score4, double score5, double score6) {
	//make array of scores
	double scores[]{ score1, score2, score3, score4, score5, score6 };
	//declare variable
	double lowest = 100;

	//loop through scores and find lowest
	for (double &score : scores) {
		if (score < lowest) {
			lowest = score;
		}
	}

	//retern lowest score
	return lowest;
}
