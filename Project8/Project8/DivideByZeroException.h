#pragma once
#include <stdexcept>
using namespace std;
using std::runtime_error;

class DivideByZeroException : public runtime_error
{
public:
	DivideByZeroException()
		: runtime_error("Zero in the denominator.") {}
};