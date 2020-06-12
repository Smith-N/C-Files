/* Nick Smith
Project 9
April 10, 2018
Square header file, used for the Square shape
Contains the constructor and member functions for the Square class
Member functions defined in Square.cpp
*/
#pragma once
#ifndef SQUARE.H
#define SQUARE_H
#include "Rect.h"

class Square : public Rect {
public:
	Square(Point p1, int len); // constructor
};
#endif // !SQAURE.H