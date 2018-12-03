/*
start
	declaratitions
		use time in srand to seed rand
		int randomNumber = rand mod 100 + 1
		int turns = 10
		int guess
		bool gameEnd = false
	display: "Let's play a guessing game!"
	do
		display "Guess a number between 1 and 100"
		display: "You have {turns}  guesses left"
	    guess = input

		if guess < 1 or guess > 100 or guess not an int
		   display "Your input was invalid
			clear input
		
		else if guess < randomNumber 
			display: "Too low, try again."
			subtract 1 from turns
		
		else if guess > randomNumber
			display "Too high, try again."
			subtract 1 from turns
		
		else 
			set gameEnd tp true;
		end if
	end do
	  while turns > 0 and gameEnd is false

	
	if turns > 5
		display "Either you know the secret or you got lucky!"
	
	else  if turns > 3
		display "You're pretty good at this!"
	
	else  if turns > 0 
		display "You'll do better next time."
	
	else 
		display "Sorry - You have taken too many guesses."
	end if

stop	
*/

#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;
int main() {

	//set seed for rand function
	srand(time(NULL));
	//declare and set variables
	int randomNumber = rand() % 100 + 1, turns = 10, guess;
	bool gameEnd = false;

	// intro
	cout << "LET'S PLAY A GUESSING GAME!!\n";
	cout << endl;


	do {
		//ask for user input
		cout << "Guess a number between 1 and 100\n";
		cout << endl;
		//show how many guesses left
		cout << "You have " << turns << " guesses left\n";
		cout << endl;
		cin >> guess;

		//validate input
		if (guess < 1 || guess > 100 || guess != int(guess)) {
			cout << "Your input was invalid\n";
			cout << endl;
			cin.clear();
			cin.ignore();
			// if inout is too high of too low, ask for input again and reduce ammount
			// of guesses left by 1
		}
		else if (guess < randomNumber) {
			cout << "Too low, try again.\n";
			cout << endl;
			turns--;
		}
		else if (guess > randomNumber) {
			cout << "Too high, try again.\n";
			cout << endl;
			turns--;
			//end game
		}
		else {
			gameEnd = true;
		}
	} while (turns > 0 && !gameEnd);

	//end game comments based on amount of guesses
	if (turns > 5) {
		cout << "Either you know the secret or you got lucky!\n";
	}
	else  if (turns > 3) {
		cout << "You're pretty good at this!\n";
	}
	else  if (turns > 0) {
		cout << "You'll do better next time.\n";
	}
	else {
		cout << "Sorry - You have taken too many guesses.\n";
	}

	//return and exit without error
	return 0;
}

