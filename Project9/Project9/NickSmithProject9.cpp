/* Nick Smith
Project 9
April 10, 2018
This program allows the user to select what shape they want to create
It allows the user to enter the necessary data, and will output the points of the shape
*/
#include "Square.h"
#include <iostream>
using namespace std;

int main() {
	char shape; // shape that user chooses to make
	char userIn; // user input for whether to continue running program or not
	bool keepRunning = 1; // keeps program running until it is ended
	bool yesNo = 0; // used for yes or no option to end program
	int x = 0; // x-coordinate
	int y = 0; // y-coordinate
	int length1 = 0; // main length used for most
	int length2 = 0; // second length for trapezoid
	int height = 0; // height 
	Point p1(0, 0); // declaring first point to be used in switch statement
	Point p2(0, 0); // declaring second point to be used in switch statement
	Point p3(0, 0); // declaring third point to be used in switch statement
	Point p4(0, 0); // declaring fourth point to be used in switch statement
	Quad quad(p1, p2, p3, p4); // declaring quadrilateral to be used in switch statement
	Trap trap(p1, p2, length1, length2); // declaring trapezoid to be used in switch statement
	Para para(p1, p2, length1); // declaring parallelogram to be used in switch statement
	Rect rect(p1, length1, height); // declaring rectangle to be used in switch statement
	Square square(p1, length1); // declaring square to be used in switch statement

	while (keepRunning == 1) { // keeps program running until termination
		cout << "What shape would you like to create?" << endl << "(p = parallelogram, q = quadrilateral, r = rectangle, s = square, or t = trapezoid)" << endl;
		cin >> shape;
		switch (shape) // for user's shape selection
		{
		case'P': // Parallelogram cases
		case'p':
			cout << "Parallelogram selected." << endl << "Enter first point (two integers):" << endl;
			cin >> x >> y;
			p1 = Point(x, y);
			cout << "Enter second point (two integers):" << endl;
			cin >> x >> y;
			p2 = Point(x, y);
			cout << "Enter length: " << endl;
			cin >> length1;
			para = Para(p1, p2, length1);
			cout << "Parallelogram's points:" << endl;
			para.print();
			cout << endl;
			break;
		case'Q': // Quadrilateral cases
		case'q':
			cout << "Quadrilateral selected." << endl << "Enter first point (two integers):" << endl;
			cin >> x >> y;
			p1 = Point(x, y);
			cout << "Enter second point (two integers):" << endl;
			cin >> x >> y;
			p2 = Point(x, y);
			cout << "Enter third point (two integers):" << endl;
			cin >> x >> y;
			p3 = Point(x, y);
			cout << "Enter fourth point (two integers):" << endl;
			cin >> x >> y;
			p4 = Point(x, y);
			quad = Quad(p1, p2, p3, p4);
			cout << "Quadrilateral's points:" << endl;
			quad.print();
			cout << endl;
			break;
		case'R': // Rectangle cases
		case'r':
			cout << "Rectangle selected." << endl << "Enter first point (two integers):" << endl;
			cin >> x >> y;
			p1 = Point(x, y);
			cout << "Enter length: " << endl;
			cin >> length1;
			cout << "Enter height: " << endl;
			cin >> height;
			rect = Rect(p1, length1, height);
			cout << "Rectangle's points:" << endl;
			rect.print();
			cout << endl;
			break;
		case'S': // Square cases
		case's':
			cout << "Square selected." << endl << "Enter first point (two integers):" << endl;
			cin >> x >> y;
			p1 = Point(x, y);
			cout << "Enter length: " << endl;
			cin >> length1;
			square = Square(p1, length1);
			cout << "Square's points:" << endl;
			square.print();
			cout << endl;
			break;
		case'T': // Trapezoid cases
		case't':
			cout << "Trapezoid selected." << endl << "Enter first point (two integers):" << endl;
			cin >> x >> y;
			p1 = Point(x, y);
			cout << "Enter second point (two integers):" << endl;
			cin >> x >> y;
			p2 = Point(x, y);
			cout << "Enter length 1: " << endl;
			cin >> length1;
			cout << "Enter length 2: " << endl;
			cin >> length2;
			trap = Trap(p1, p2, length1, length2);
			cout << "Trapezoid's points:" << endl;
			trap.print();
			cout << endl;
			break;
		}
		yesNo = 0; // sets up for user's input again if said yes previously

		while (yesNo == 0) { // loop for user input, only loops if a character other than Y or N is entered
			cout << "Would you like to enter another shape? (Y/N): ";
			cin >> userIn;
			cout << endl;

			switch (userIn)
			{
			case 'Y': // yes cases if user wants to enter another shape
			case 'y':
				keepRunning = 1;
				yesNo = 1;
				break;
			case 'N': // no cases if user wants program to stop
			case 'n':
				keepRunning = 0;
				yesNo = 1;
				break;
			default: // if user enters an incorrect character
				cout << "Please enter a Y or N" << endl;
				yesNo = 0;
			}
		}
	}
}