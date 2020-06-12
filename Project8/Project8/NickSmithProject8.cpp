/*Nick Smith
Project 6
March 28, 2018
The program uses a class named Rational, which accepts rational numbers as input.
The rational class can do different operations with rational numbers. Uses overloaded operators for many of the functions.*/
#include "rational.h"
#include "DivideByZeroException.h"
#include <iostream>
using namespace std;

int main() {
	int numerator1; // variable for the first numerator input
	int denominator1; // variable for the first denominator input
	int numerator2; // variable for the second numerator input
	int denominator2; // variable for the second denominator input
	bool keepRunning = 1; // used to keep program running until user stops
	bool yesNo = 0; // used for user's choice to end program or continue
	char userIn; // user input for yes or no

	Rational a(1, 1); // first rational number
	Rational b(1, 1); // second rational number

	while (keepRunning == 1) {

		do {
			try {
				cout << "Enter a rational number (seperate numerator and denominator with space): ";
				cin >> numerator1 >> denominator1; // accepts first rational number
				cout << endl;
				a = Rational(numerator1, denominator1); // first rational number
			}
			catch (DivideByZeroException)
			{
				cout << "Exception occured: Entered a zero in the denominator. Please try again." << endl;
			}
		} while (denominator1 == 0);

		do {
			try {
				cout << "Enter another rational number: ";
				cin >> numerator2 >> denominator2; // accepts second rational number
				cout << endl;
				b = Rational(numerator2, denominator2);
			}
			catch (DivideByZeroException)
			{
				cout << "Exception occured: Entered a zero in the denominator. Please try again." << endl;
			}
		} while (denominator2 == 0);

		Rational c(numerator1, denominator1); // third rational number tha holds a's value through the program

		// shows the different operations with rational numbers
		c = a + b;
		a.printRat();
		cout << " + ";
		b.printRat();
		cout << " = ";
		c.print();
		c = a - b;
		a.printRat();
		cout << " - ";
		b.printRat();
		cout << " = ";
		c.print();
		c = a * b;
		a.printRat();
		cout << " * ";
		b.printRat();
		cout << " = ";
		c.print();
		try {
			c = a / b;
			a.printRat();
			cout << " / ";
			b.printRat();
			cout << " = ";
			c.print();
		}
		catch (DivideByZeroException)
		{
			cout << "Division resulted in denominator of 0." << endl;
		}

		try {
			c = (a - b) / (a * b);
			cout << "(";
			a.printRat();
			cout << " - ";
			b.printRat();
			cout << ") / (";
			a.printRat();
			cout << " * ";
			b.printRat();
			cout << ") = ";
			c.print();
		}
		catch (DivideByZeroException)
		{
			cout << "Operation resulted in denominator of 0." << endl;
		}

		try {
			c = (a + b) / (a - b);
			cout << "(";
			a.printRat();
			cout << " + ";
			b.printRat();
			cout << ") / (";
			a.printRat();
			cout << " - ";
			b.printRat();
			cout << ") = ";
			c.print();
		}
		catch (DivideByZeroException)
		{
			cout << "Operation resulted in denominator of 0." << endl;
		}

		// shows the different relational operations
		if (a < b)
		{
			a.printRat();
			cout << " is less than ";
			b.printRat();
			cout << endl;
		}
		else if (a > b)
		{
			a.printRat();
			cout << " is greater than ";
			b.printRat();
			cout << endl;
		}

		if (a <= b)
		{
			a.printRat();
			cout << " is less than or equal to ";
			b.printRat();
			cout << endl;
		}
		else if (a >= b)
		{
			a.printRat();
			cout << " is greater than or equal to ";
			b.printRat();
			cout << endl;
		}

		if (a == b)
		{
			a.printRat();
			cout << " is equal to ";
			b.printRat();
			cout << endl;
		}
		else if (a != b)
		{
			a.printRat();
			cout << " is not equal to ";
			b.printRat();
			cout << endl;
		}

		// negations and reciprocals of the rational numbers
		c = -a;
		a.printRat();
		cout << " negated is ";
		c.printRat();
		cout << endl;

		c = -b;
		b.printRat();
		cout << " negated is ";
		c.printRat();
		cout << endl;

		try {
			c = !a;
			cout << "The reciprocal of ";
			a.printRat();
			cout << " is ";
			c.printRat();
			cout << endl;
		}
		catch (DivideByZeroException) 
		{
			cout << "Reciprocal of ";
			a.printRat();
			cout << " resulted in denominator of 0." << endl;
		}

		try {
			c = !b;
			cout << "The reciprocal of ";
			b.printRat();
			cout << " is ";
			c.printRat();
			cout << endl;
		}
		catch (DivideByZeroException)
		{
			cout << "Reciprocal of "; 
			b.printRat();
			cout << " resulted in denominator of 0." << endl;
		}

		yesNo = 0; // sets up for user's input again if said yes previously

		while (yesNo == 0) { // loop for user input, only loops if a character other than Y or N is entered
			cout << "Would you like to enter new rational numbers? (Y/N): ";
			cin >> userIn;
			cout << endl;

			switch (userIn)
			{
			case 'Y': // yes cases if users want to enter more numbers
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
