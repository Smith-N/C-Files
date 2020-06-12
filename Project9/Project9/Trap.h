/* Nick Smith
Project 9
April 10, 2018
Trap header file, used for the Trapezoid shape
Contains the constructor and member functions for the Trap class
Member functions defined in Trap.cpp
*/
#pragma once
#ifndef TRAP.H
#define TRAP_H
#include "Quad.h"

class Trap : public Quad {
public:
	int len1;
	int len2;
	Point p1;
	Point p2;
	Trap(Point p1, Point p2, int len1, int len2); // constructor
};
#endif // !TRAP.H