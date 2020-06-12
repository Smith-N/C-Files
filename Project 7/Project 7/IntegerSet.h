/* 
Nick Smith
Project 7
3/14/18
IntegerSet class declaration
Member functions in IntegerSet.cpp
*/
#pragma once
#ifndef INTEGERSET_H
#define INTEGERSET_H
class IntegerSet {
public:
	IntegerSet(); // constructor
	IntegerSet intersect(IntegerSet x); // shows the intersection of sets
	IntegerSet unionize(IntegerSet x); // shows the union of sets
	IntegerSet complement(IntegerSet x); // shows the complement of sets
	IntegerSet difference(IntegerSet x); // shows the difference between sets
	bool subset(IntegerSet); // compares sets to see if one is a subset
	bool isEmpty(); // checks if set is empty
	bool isEqualTo(IntegerSet); // compares sets to see if they're equal
	void insertElement(int); // adds element to set
	void deleteElement(int); // removes element from set
	void printSet(); // displays set

private:
	bool set[101]; // array used for integer sets
};
#endif // !INTEGERSET_H