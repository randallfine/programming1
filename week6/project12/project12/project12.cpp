/*
start
	declare function prototypes
		function getuserchoice pass in nothing returns int
		function getcomputerchoice pass in nothing return int
		function determinwinner passing userchoice and compchoice return bool
		function displaychoice pass in choice return nothing

		Function Main
			declarations
				bool iswinner is false
				int userchoice, compchoice

				do
					userchoice = return from getuserchoice
					compchoice = return from getcompchoice

					display: "The user chose {return from displaychoice passing in userchoice}"
					display: "the computer chose {return from displaychoice passing in compchoice}"
					
					iswinner = return from determinwinner passing in userchoice and compchoice
				end do
				while is winner not true

				return without error
		end function

		Function get user choice
			pass in nothing
			declarations
				int userchoice
				bool isgoodchice is false

			display:
				    "Choose Your Weapon!
					"1.Rock"
					"2.Paper"
					"3.Scissors"
					"4.Lizard"
					"5.Spock"
			do
				userChoice = input
				if userChoice >= 1 and userChoice <=5 and cin is good
					isGoodChoice is true
				else 
					display "Please enter a valid number (1 - 6)"
					clear errors
					ignore input
			end do
			while isGoodChoice not true
    
			pass out userChoice;
		End function

		Function getComputerChoice
			pass in nothing 
			seed random function with time
			declaration
				int computerChoice  = random function mod 5 + 1
			pass out computerChoice;
		end function

		Function determineWinner
			pass in userchoice and compchoice
			declarations
				string message;
				bool compWins is false

			if userChoice == compChoice
				display "Tie!!"
				pass out false
			end if
			switch using userChoice
				case 1
					switch using compChoice
						case 2:
							message = "Paper covers rock"
							compWins = true
							break out of switch
						 case 3:
							message = "Rock breaks scissors"
							break out of switch
						case 4:
							message = "Rock crushes lizard";
							break out of switch
						case 5:
							message = "Spock vaporizes rock";
							compWins = true;
							break out of switch
					end compchoice switch
					break out of switch

				case 2:
					switch using compChoice
						case 1:
							message = "Paper covers rock";
							break out of switch
						 case 3:
							message = "Scissors cut paper";
							compWins = true;
							break out of switch
						case 4:
							message = "Lizard eats paper";
							compWins = true;
							break out of switch
						case 5:
							message = "Paper disproves Spock";
							break out of switch
					end compchoice switch
					break out of switch
				case 3:
					switch compChoice
						case 1:
							message = "Rock breaks scissors";
							compWins = true;
							break out of switch
						 case 2:
							message = "Scissors cut paper";
							break out of switch
						case 4:
							message = "Scissors decapitate lizard";
							break out of switch
						case 5:
							message = "Spock melts scissors";
							compWins = true;
							break out of switch
					end compchoice switch
					break out of switch
				case 4:
				   switch using compChoice
						case 1:
							message = "Rock crushes lizard";
							compWins = true;
							break out of switch
						 case 2:
							message = "Lizard eats paper";
							break out of switch
						case 3:
							message = "Scissors decapitate lizard";
							compWins = true;
							break out of switch
						case 5:
							message = "Lizard poisons Spock";
							break out of switch
					end compchoice switch
					break out of switch
				case 5:
					switch compChoice
						case 1:
							message = "Spock vaporizes rock";
							break out of switch
						 case 2:
							message = "Paper disproves Spock";
							compWins = true;
							break out of switch
						case 3:
							message = "Spock melts scissors";
							break out of switch
						case 4:
							message = "Lizard poisons Spock";
							compWins = true;
							break out of switch
					end compchoice switch
					break out of switch
			end userchoice switch

			if compWins
				display "You lose!"
			else 
				display "You win!"
			end if

			display message 

			pass out true;
		end Function


		Function displayChoice
			pass in choice
			delcaration
				string display;
			switch using choice
				case 1:
					display = "Rock";
					break out of switch
				case 2:
					display = "Paper";
					break out of switch
				case 3:
					display = "Scissors";
					break out of switch
				case 4:
					display = "Lizzard";
					break out of switch
				case 5:
					display = "Spock";
					break out of switch
				default:
					display: "Not a valid choice";
					break out of switch
			end switch

			display {display}

			pass out nothing
	end function

end
*/
#include "pch.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>  
#include <string>

using namespace std;

int getUserChoice();
int getComputerChoice();
bool determineWinner(int userChoice, int compChoice);
void displayChoice(int choice);

int main() {
	bool isWinner = false;
	int userChoice, compChoice;

	do {
		userChoice = getUserChoice();
		compChoice = getComputerChoice();
		cout << endl;
		cout << "The User chose ";
		displayChoice(userChoice);
		cout << endl;
		cout << endl;
		cout << "The computer chose ";
		displayChoice(compChoice);
		cout << endl;
		cout << endl;

		isWinner = determineWinner(userChoice, compChoice);
	} while (!isWinner);

	return 0;
}

int getUserChoice() {
	int userChoice;
	bool isGoodChoice = false;
	cout << "Choose Your Weapon!\n";
	cout << endl;
	cout << "1.Rock\n";
	cout << "2.Paper\n";
	cout << "3.Scissors\n";
	cout << "4.Lizard\n";
	cout << "5.Spock\n";

	do {
		cin >> userChoice;
		if (userChoice >= 1 && userChoice <= 5 && cin.good()) {
			isGoodChoice = true;
		}
		else {
			cout << "Please enter a valid number (1 - 6)\n";
			cin.clear();
			cin.ignore(1000, '\n');
		}
	} while (!isGoodChoice);

	return userChoice;
}

int getComputerChoice() {
	srand(time(NULL));
	int computerChoice = rand() % 5 + 1;
	return computerChoice;
}

bool determineWinner(int userChoice, int compChoice) {
	string message;
	bool compWins = false;
	if (userChoice == compChoice) {
		cout << "Tie!!\n";
		return false;
	}

	switch (userChoice) {
	case 1:
		switch (compChoice) {
		case 2:
			message = "Paper covers rock";
			compWins = true;
			break;
		case 3:
			message = "Rock breaks scissors";
			break;
		case 4:
			message = "Rock crushes lizard";
			break;
		case 5:
			message = "Spock vaporizes rock";
			compWins = true;
			break;
		}
		break;
	case 2:
		switch (compChoice) {
		case 1:
			message = "Paper covers rock";
			break;
		case 3:
			message = "Scissors cut paper";
			compWins = true;
			break;
		case 4:
			message = "Lizard eats paper";
			compWins = true;
			break;
		case 5:
			message = "Paper disproves Spock";
			break;
		}
		break;
	case 3:
		switch (compChoice) {
		case 1:
			message = "Rock breaks scissors";
			compWins = true;
			break;
		case 2:
			message = "Scissors cut paper";
			break;
		case 4:
			message = "Scissors decapitate lizard";
			break;
		case 5:
			message = "Spock melts scissors";
			compWins = true;
			break;
		}
		break;
	case 4:
		switch (compChoice) {
		case 1:
			message = "Rock crushes lizard";
			compWins = true;
			break;
		case 2:
			message = "Lizard eats paper";
			break;
		case 3:
			message = "Scissors decapitate lizard";
			compWins = true;
			break;
		case 5:
			message = "Lizard poisons Spock";
			break;
		}
		break;
	case 5:
		switch (compChoice) {
		case 1:
			message = "Spock vaporizes rock";
			break;
		case 2:
			message = "Paper disproves Spock";
			compWins = true;
			break;
		case 3:
			message = "Spock melts scissors";
			break;
		case 4:
			message = "Lizard poisons Spock";
			compWins = true;
			break;
		}
		break;
	}

	if (compWins) {
		cout << "You lose!\n";
	}
	else {
		cout << "You win!\n";
	}

	cout << message << endl;

	return true;
}


void displayChoice(int choice) {

	string display;
	switch (choice) {
	case 1:
		display = "Rock";
		break;
	case 2:
		display = "Paper";
		break;
	case 3:
		display = "Scissors";
		break;
	case 4:
		display = "Lizzard";
		break;
	case 5:
		display = "Spock";
		break;
	default:
	display: "Not a valid choice";
		break;
	}

	cout << display;

}