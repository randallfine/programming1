/*
start
	function declarations
		void menuOptions()
		void calculateAreaOfCircle()
		void calculateAreaOfRectangle()
		void calculateAreaOfTriangle()
		void calculateAreaOfTrapezoid()
		void calculateAreaOfSphere()
	constant declaration
		const double PI = M_PI;
	call function menuOptions

	function menuOptions
		declaration
			int choice;
		display "1. Calculate the area of a circle
		display "2. Calculate the area of a rectangle
		display "3. Calculate the area of a triangle
		display "4. Calculate the area of a trapezoid
		display "5. Calculate the area of a sphere
		display "6. Exit program"
		display "Enter your choice (1-6)

		choice = input

		switch based on choice
			case 1:
				call function calculateAreaOfCircle
			case 2:
				call function calculateAreaOfRectangle
			case 3:
				call function calculateAreaOfTriangle
			case 4:
				call function calculateAreaOfTrapezoid
			case 5:
				call function calculateAreaOfSphere
			case 6:
				display "Thank you and have a wonderful day!
			default :
				display "That was not a valid choice."
		end switch
	end function

	function calculateAreaOfCircle()
		declarations
			double area, radius = 0;
		while radius <= 0
			display "Please enter the radius of the circle
			radius = input
			if radius <= 0
				display "Please enter a postive value
			end if
		end while
		area = PI * radius^2
		display "The area of the circle is {area}"
	end function

	function calculateAreaOfRectangle
		declarations
			int area, length = 0, width = 0;

		while length <= 0 or width <= 0
			display "Please enter the length of the rectangle
			length = input
			display "Please enter the width of the rectangle
			width = input
			if length <= 0 or width <= 0
				display "Please enter a postive values
			end if
		end while
		area = length * width;
		display "The area of the rectangle is {area}"
	end function

	function calculateAreaOfTriangle
		declarations
			double area, base = 0, height = 0;

		while base <= 0 or height <= 0
			display "Please enter the base of the triangle
			base = input
			display "Please enter the height of the triangle
			height = input
			if base <= 0 or height <= 0
				display "Please enter only postive values
			end if
		end while

		area = base * height * 0.5;

		display "The area of the triangle is {area}"
	end function


	funtion calculateAreaOfTrapezoid
		 declarations
			double area, base1= 0, base2 = 0,height = 0;

		while base1 <= 0 or base1 <= 0 or height <= 0
			display "Please enter the first base of the trapezoid
			base1 = input
			display "Please enter the second base of the trapezoid
			base2 = input
			display "Please enter the height of the trapezoid"
			height = input
			if base1 <= 0 or base1 <= 0 or height <= 0
				display "Please enter only postive values
			end if
		end while

		area = height/2 * (base1 + base2);

		display "The area of the trapezoid is {area}"
	end function

	function calculateAreaOfSphere
		declarations
			double area, radius = 0;

		while radius <= 0
			display "Please enter the radius of the sphere
			radius = input
			if radius <= 0
				display "Please enter a postive value
			end if
		end while

		area = 4 * PI * radius^2

	   display "The area of the sphere is {area}"
	end function
end
*/
#include "pch.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>


using namespace std;

//function declarations
void menuOptions();
void calculateAreaOfCircle();
void calculateAreaOfRectangle();
void calculateAreaOfTriangle();
void calculateAreaOfTrapezoid();
void calculateAreaOfSphere();

//const declaration
const double PI = M_PI;

int main()
{
	menuOptions();
}

//askes for user input and based on that input will run another shape function
void menuOptions()
{
	//declare variable for user input
	int choice;

	//output menu options and get user input
	cout << "1. Calculate the area of a circle\n";
	cout << "2. Calculate the area of a rectangle\n";
	cout << "3. Calculate the area of a triangle\n";
	cout << "4. Calculate the area of a trapezoid\n";
	cout << "5. Calculate the area of a sphere\n";
	cout << "6. Exit program";
	cout << "\n";
	cout << "Enter your choice (1-6)\n";
	cin >> choice;

	//based on input, run user chosen function
	switch (choice) {
	case 1:
		calculateAreaOfCircle();
		break;
	case 2:
		calculateAreaOfRectangle();
		break;
	case 3:
		calculateAreaOfTriangle();
		break;
	case 4:
		calculateAreaOfTrapezoid();
		break;
	case 5:
		calculateAreaOfSphere();
		break;
	case 6:
		cout << "\n";
		cout << "Thank you and have a wonderful day!\n";
		break;
	default:
		cout << "\n";
		cout << "That was not a valid choice\n";
	}

}

//calculate area of a circle based on user input
void calculateAreaOfCircle()
{
	//declarations
	double area, radius = 0;

	//get user input for radius, use sanity check.
	while (radius <= 0) {
		cout << "Please enter the radius of the circle\n";
		cin >> radius;
		if (radius <= 0)
		{
			cout << "Please enter a postive value\n";
			cout << "\n";
		}
	}

	//calulate area
	area = PI * pow(radius, 2.0);

	//display area
	cout << "\n";
	cout << "The area of the circle is " << area << endl;

}

//calculate area of a rectangle based on user input
void calculateAreaOfRectangle()
{
	//declare variable
	int area, length = 0, width = 0;

	//get user input for length and width, use sanity check
	while (length <= 0 || width <= 0)
	{
		cout << "Please enter the length of the rectangle\n";
		cin >> length;
		cout << "Please enter the width of the rectangle\n";
		cin >> width;
		if (length <= 0 || width <= 0)
		{
			cout << "Please enter a postive values\n";
			cout << "\n";
		}
	}

	//calculate area
	area = length * width;

	//display area
	cout << "\n";
	cout << "The area of the rectangle is " << area << endl;

}

//calculate area of a triangle based on user input
void calculateAreaOfTriangle()
{
	//declare variable
	double area, base = 0, height = 0;

	//get user input for base and height use sanity check
	while (base <= 0 || height <= 0)
	{
		cout << "Please enter the base of the triangle\n";
		cin >> base;
		cout << "Please enter the height of the triangle\n";
		cin >> height;
		if (base <= 0 || height <= 0)
		{
			cout << "Please enter only postive values\n";
			cout << "\n";
		}
	}

	//calculate area
	area = base * height * 0.5;

	//display area
	cout << "\n";
	cout << "The area of the triangle is " << area << endl;
}

//calculate area of a trapazoid based on user input
void calculateAreaOfTrapezoid()
{
	//declare variable
	double area, base1 = 0, base2 = 0, height = 0;

	//get user input for bases and height use sanity check
	while (base1 <= 0 || base1 <= 0 || height <= 0)
	{
		cout << "Please enter the first base of the trapezoid\n";
		cin >> base1;
		cout << "Please enter the second base of the trapezoid\n";
		cin >> base2;
		cout << "Please enter the height of the trapezoid\n";
		cin >> height;
		if (base1 <= 0 || base1 <= 0 || height <= 0)
		{
			cout << "Please enter only postive values\n";
			cout << "\n";
		}
	}

	//calculate area
	area = height / 2 * (base1 + base2);

	//display area
	cout << "\n";
	cout << "The area of the trapezoid is " << area << endl;
}

//calculate area of a sphere based on user input
void calculateAreaOfSphere()
{
	//declarations
	double area, radius = 0;

	//get user input for radius, use sanity check.
	while (radius <= 0) {
		cout << "Please enter the radius of the sphere\n";
		cin >> radius;
		if (radius <= 0)
		{
			cout << "Please enter a postive value\n";
			cout << "\n";
		}
	}

	//calulate area
	area = 4 * PI * pow(radius, 2.0);

	//display area
	cout << "\n";
	cout << "The area of the sphere is " << area << endl;
}

