/*Nick Smith
Project 11
April 23, 2018
This header file is for the exception that catches when there is a 0 in the denominator
*/
#pragma once
#include <stdexcept> // contains runtime error
using namespace std;
using std::runtime_error;

class DivideByZeroException : public runtime_error
{
public:
	DivideByZeroException()
		: runtime_error("Zero in the denominator.") {}
};