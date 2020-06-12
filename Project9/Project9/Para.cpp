/* Nick Smith
Project 9
April 10, 2018
Defines the constructor for the para class
Para takes two points and one length
*/
#include "Para.h"
#include <iostream>
using namespace std;

Para::Para(Point q1, Point q2, int len) // constructor
	:Trap(q1, q2, len, len) {}