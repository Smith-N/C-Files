/* Nick Smith
Project 9
April 10, 2018
Rect header file, used for the Rectangle shape
Contains the constructor and member functions for the Rect class
Member functions defined in Rect.cpp
*/
#pragma once
#ifndef RECT.H
#define RECT_H
#include "Para.h"

class Rect : public Para {
public:
	Rect(Point p1, int length, int height); // constructor

private:
	int len;
	int height;
};
#endif // !RECT.H