/*Nick Smith
Project 6
March 28, 2018
The header file for the rational commands which consists of some basic operations like add, subtract, multiply, divide, etc.
Also includes overloaded operators so that rational variables can use these operators. Member functions are defined in the Rational.cpp*/
#pragma once
#ifndef RATIONAL_H
#define RATIONAL_H
class Rational {
public:
	void add(Rational x);
	void sub(Rational x);
	void mult(Rational x);
	void div(Rational x);
	void print(); // prints both rational and float values
	void printRat();
	void printFlo();
	void negate();
	void reciprocal();
	Rational(int, int); // constructor
	Rational operator+ (Rational x);
	Rational operator- (Rational x);
	Rational operator* (Rational x);
	Rational operator/ (Rational x);
	bool operator< (Rational x);
	bool operator<= (Rational x);
	bool operator> (Rational x);
	bool operator>= (Rational x);
	bool operator== (Rational x);
	bool operator!= (Rational x);
	Rational operator!();
	Rational operator-();
private:
	int num; // numerator
	int den; // denominator
	void reduce();
	int gcd(int, int); // greatest common denominator
};
#endif // !RATIONAL_H