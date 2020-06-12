/* Nick Smith
Project 9
April 10, 2018
Defines the constructor for the trap class
Para takes two points and two lengths
*/
#include "Trap.h"
#include <iostream>
using namespace std;

Trap::Trap(Point q1, Point q2, int len1, int len2) // constructor
	:Quad(q1, q2, Point(q1.getX() + len1, q1.getY()), Point(q2.getX() + len2, q2.getY())) {}