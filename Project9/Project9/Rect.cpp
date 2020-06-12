/* Nick Smith
Project 9
April 10, 2018
Defines the constructor for the rect class
Para takes one point, one length, and one height
*/
#include "Rect.h"
#include <iostream>
using namespace std;

Rect::Rect(Point p1, int length, int height) // constructor
	:Para(p1, Point(p1.getX(), p1.getY() + height), length){}