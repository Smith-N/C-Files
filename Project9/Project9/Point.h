/* Nick Smith
Project 9
April 10, 2018
Point header file, used for points on a Cartesian Plane
Contains the constructor and member functions for the point class
Member functions defined in Point.cpp
*/
#pragma once
#ifndef POINT.H
#define POINT_H

class Point {
public:
	Point(int a, int b); // constructor
	Point();
	int getX(); // accessor for x
	int getY(); // accessor for y
	void print();
private:
	int x;
	int y;
};
#endif // !POINT.H