/*
start
	seed rand() function with srand() using time
	declarations and assigments
		int len = rand() mod 100 + 1
		int number, avg, count = 0, sum = 0, largest = 0, smallest = 100
	declare outstream and instream for files
		ofstream outputFile
		ifstream inputfile

	open outputFile with file name "Random.txt" if exists and write over it 
	or create it if does not exist
	
	if outputFile failes to open
		display  "Failed to open file or file does not exist"
	
	else 
		for int i = 0; i < len; i++
			write to outputFile rand() mod 100 + 1 
		end for loop

		close outputFile

	end if

	
	open inputFile "Random.txt"
	
	if inputFile failed to open
		display "Failed to open file or file does not exist"
	
	else
		
		while inputFile can read the next number
			
			add 1 to {count}
			
			sum = sum + number
			
			if number < smallest
				smallest = number;
			end if

			if number > largest
				largest = number;
			end if
		end while
		
		close inputFile
	end if
	
	assignment
	avg = sum / count

	
	
	display  "There are " {count} " numbers in the file"

	display  "The largest number in the file is {largest}"
	
	display "The smallest number in the file is {smallest}"
	
	display "The average of all number in the file is {avg}";
	
	display "The sum of all the numbers in the file is {sum}"

stop
*/
#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

int main() {
	srand(time(NULL));
	//create random length to use in for loop
	//to create random length for random number list
	int len = rand() % 100 + 1;
	//declare variables
	int number, avg, count = 0, sum = 0, largest = 0, smallest = 100;
	//create output and input file variable
	ofstream outputFile;
	ifstream inputFile;

	//opens output file, removes any contant before writing to a clean file
	//if file does not exist, create the file
	outputFile.open("Random.txt", ofstream::out | ofstream::trunc);
	//check if file opened;
	if (outputFile.fail()) {
		cout << "Failed to open file or file does not exist\n";
	}
	else {
		//write random numbers to file
		for (int i = 0; i < len; i++) {
			outputFile << rand() % 100 + 1 << endl;
		}
		//close file
		outputFile.close();

	}

	//open file for reading
	inputFile.open("Random.txt");
	//check if file opened
	if (inputFile.fail()) {
		cout << "Failed to open file or file does not exist\n";
	}
	else {
		//read numbers from file to end of file
		while (inputFile >> number) {
			//count each item read
			count++;
			//sum each number in file
			sum += number;
			//find the smallest number in file
			if (number < smallest) {
				smallest = number;
			}
			//find largest number in file
			if (number > largest) {
				largest = number;
			}
		}
		//close the file
		inputFile.close();
	}
	//find the average of all number in the file
	avg = sum / count;

	// Counts how many numbers were read from the file
	cout << endl;
	cout << "There are " << count << " numbers in the file\n";
	// Determine the lowest and highest values in the file
	cout << endl;
	cout << "The largest number in the file is " << largest << endl;
	cout << endl;
	cout << "The smallest number in the file is " << smallest << endl;
	// The average of all the numbers in the file
	cout << endl;
	cout << "The average of all number in the file is " << avg << endl;
	// The sum of all the numbers in the file (a running total)
	cout << endl;
	cout << "The sum of all the numbers in the file is " << sum << endl;

	//return without error
	return 0;
}