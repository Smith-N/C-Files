/* Nick Smith
Project 9
April 10, 2018
Defines the constructor for the square class
Para takes one point and one length
*/
#include "Square.h"
#include <iostream>
using namespace std;

Square::Square(Point p1, int len) // constructor
	:Rect(p1, len, len){}