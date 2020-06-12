/* Nick Smith
Project 9
April 10, 2018
Defines the functions for the point class
Point class contains two variables that would correspond to a cartesian plane
*/
#include "Point.h"
#include <iostream>
using namespace std;

Point::Point(int a, int b) // constructor
{
	x = a;
	y = b;
}

Point::Point() 
{

}

int Point::getX() // gets the value of x
{
	return x;
}

int Point::getY() // gets the value of y
{
	return y;
}
void Point::print() // prints the points
{
	cout << "(" << x << ", " << y << ") ";
}