/* Nick Smith
Project 9
April 10, 2018
Quad header file, used for the Quadrilateral shape
Contains the constructor and member functions for the Quad class
Member functions defined in Quad.cpp
*/
#pragma once
#ifndef QUAD.H
#define QUAD_H
#include "Point.h"

class Quad {
public:
	Point p1;
	Point p2;
	Point p3;
	Point p4;
	Quad(Point q1, Point q2, Point q3, Point q4); // constructor
	void print();
};
#endif // !QUAD.H