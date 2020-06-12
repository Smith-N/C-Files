/* Nick Smith
Project 9
April 10, 2018
Defines the constructor for the quad class
Para takes four points
Also includes print function that prints out the points of the shape
*/
#include "Quad.h"
#include <iostream>
using namespace std;

Quad::Quad(Point q1, Point q2, Point q3, Point q4) // constructor
{
	p1 = q1;
	p2 = q2;
	p3 = q3;
	p4 = q4;
}

void Quad::print() // prints out the points for the shape
{
	p1.print();
	p2.print();
	p3.print();
	p4.print();
}