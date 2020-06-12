/* Nick Smith
Project 9
April 10, 2018
Para header file, used for the Parallelogram shape
Contains the constructor and member functions for the Para class
Member functions defined in Para.cpp
*/
#pragma once
#ifndef PARA.H
#define PARA_H
#include "Trap.h"

class Para : public Trap {
public:
	Para(Point q1, Point q2, int len); // constructor
private:
	int len;
};
#endif // !PARA.H