/*Nick Smith
Project 11
April 23, 2018
Defines the functions for Rational functions and the Rational variable.
Also defines the overloaded operators. These commands are called in the driver program.*/
#include "rational.h"
#include "DivideByZeroException.h"
#include <iostream>
using namespace std;

Rational::Rational(int a, int b) // rational number
{
	num = a;
	den = b;
	reduce();
}
void Rational::add(Rational x) // adds rational numbers
{
	num = (x.num * den) + (x.den * num);
	den = x.den * den;
	reduce();
}
void Rational::sub(Rational x) // subtracts rational numbers
{
	x.negate();
	add(x);
	reduce();
}
void Rational::mult(Rational x) // multiplies rational numbers
{
	num = (x.num * num);
	den = (x.den * den);
	reduce();
}
void Rational::div(Rational x) // divides rational numbers
{
	reciprocal();
	mult(x);
	reduce();
}
void Rational::printRat() // prints the rational number
{
	cout << num << "/" << den;
}
void Rational::printFlo() // prints the decimal value of the rational number
{
	float val = float(num) / float(den);
	cout << val;
}
void Rational::print() // instead of calling both seperate print commands, this calls both to print
{
	printRat();
	cout << " = ";
	printFlo();
	cout << endl;
}
void Rational::reduce() // simplifies rational numbers
{
	int temp = gcd(num, den);
	num = num / temp;
	den = den / temp;

	if (den < 0) // makes sure that numerator had the negative and not the denominator
	{
		den = -den;
		num = -num;
	}
	if (den == 0)
		throw DivideByZeroException(); // since every operation reduces, this is where it will catch 0's in the denominator for the error
}
int Rational::gcd(int a, int b) // find the greatest common denominator
{
	if (b == 0) return a;
	return gcd(b, a%b);
}
void Rational::negate() // negates the numerator
{
	num = -num;
	reduce();
}
void Rational::reciprocal() // makes rational number its reciprocal
{
	int temp = num;
	num = den;
	den = temp;
	reduce();
}
Rational Rational::operator+(Rational x) // overloaded operator that adds rational numbers
{
	Rational temp(this->num, this->den);
	temp.add(x);
	return temp;
}
Rational Rational::operator-(Rational x) // overloaded operator that subtracts rational numbers
{
	Rational temp(this->num, this->den);
	temp.sub(x);
	return temp;
}
Rational Rational::operator*(Rational x) // overloaded operator that multiplies rational numbers
{
	Rational temp(this->num, this->den);
	temp.mult(x);
	return temp;
}
Rational Rational::operator/(Rational x) // overloaded operator that divides rational numbers
{
	Rational temp(this->num, this->den);
	temp.div(x);
	return temp;
}
bool Rational::operator<(Rational x) // overloaded operator using less than relational operation
{
	int int1 = this->num * x.den;
	int int2 = x.num * this->den;
	if (int1 < int2)
		return true;
	else
		return false;
}
bool Rational::operator<=(Rational x) // overloaded operator using less than or equal to relational operation
{
	int int1 = this->num * x.den;
	int int2 = x.num * this->den;
	if (int1 <= int2)
		return true;
	else
		return false;
}
bool Rational::operator>(Rational x) // overloaded operator using greater than relational operation
{
	Rational temp(this->num, this->den);
	if (!(temp <= x))
		return true;
	else
		return false;
}
bool Rational::operator>=(Rational x) // overloaded operator using greater than or equal to relational operation
{
	Rational temp(this->num, this->den);
	if (!(temp < x))
		return true;
	else
		return false;
}
bool Rational::operator==(Rational x) // overloaded operator using equal to relational operation
{
	int int1 = this->num * x.den;
	int int2 = x.num * this->den;
	if (int1 == int2)
		return true;
	else
		return false;
}
bool Rational::operator!=(Rational x) // overloaded operator using not equal to relational operation
{
	Rational temp(this->num, this->den);
	if (!(temp == x))
		return true;
	else
		return false;
}
Rational Rational::operator!() // overloaded operator that makes number it reciprocal
{
	Rational temp(this->num, this->den);
	temp.reciprocal();
	return temp;
}
Rational Rational::operator-() // overloaded operator that negates the number
{
	Rational temp(this->num, this->den);
	temp.negate();
	return temp;
}