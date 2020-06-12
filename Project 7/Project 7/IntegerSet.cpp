/* Nick Smith
Project 7
3/14/18
Defines the member functions of IntegerSet class
*/
#include "IntegerSet.h"
#include <iostream>
using namespace std;

IntegerSet::IntegerSet() // initializes integer set to all 0's
{
	for (int i = 0; i < 101; i++) 
	{
		set[i] = 0;
	}
}

IntegerSet IntegerSet::intersect(IntegerSet x) // finds the intersection of integer sets
{
	IntegerSet temp = x; // temp integer set used to get results
	for (int i = 0; i < 101; i++) 
	{
		temp.set[i] = set[i] & x.set[i];
	}
	return temp;
}

IntegerSet IntegerSet::unionize(IntegerSet x) // finds teh union of integer sets
{
	IntegerSet temp = x; // temp integer set used to get results
	for (int i = 0; i < 101; i++)
	{
		temp.set[i] = set[i] | x.set[i];
	}
	return temp;
}

IntegerSet IntegerSet::complement(IntegerSet x) // finds the complement of integer sets
{
	IntegerSet temp = x; // temp integer set used to get results
	for (int i = 0; i < 101; i++)
	{
		temp.set[i] = !(set[i] | x.set[i]);
	}
	return temp;
}

IntegerSet IntegerSet::difference(IntegerSet x) // finds the difference of integer sets
{
	IntegerSet temp = x; // temp integer set used to get results
	for (int i = 0; i < 101; i++)
	{
		temp.set[i] = set[i] & (!(set[i] & x.set[i]));
	}
	return temp;
}

bool IntegerSet::subset(IntegerSet x) // tests to see if an integer set is a subset of another integer set
{
	bool sub = 0; // used in loop if it exits to return a true value
	for (int i = 0; i < 101; i++) 
	{
		if (set[i] == x.set[i] || set[i] == 0) 
		{
			sub = true;
		}
		else
		{
			sub = 0;
			return false;
			i = 101;
		}
	}
	if (sub == true) 
	{
		return true;
	}
}

bool IntegerSet::isEmpty() // tests to see if an integer set is empty
{
	bool empty = 0; // used in loop if it exits to return a true value
	for (int i = 0; i < 101; i++) 
	{
		if (set[i] == 0) 
		{
			empty = 1;
		}
		else 
		{
			empty = 0;
			return false;
			i = 101;
		}
	}
	if (empty == 1)
	{
		return true;
	}
}

bool IntegerSet::isEqualTo(IntegerSet x) // tests to see if two integer sets are equal to each other
{
	bool equal = 0; // used in loop if it exits to return a true value
	for (int i = 0; i < 101; i++)
	{
		if (set[i] == x.set[i]) 
		{
			equal = 1;
		}
		else 
		{
			equal = 0;
			return false;
			i = 101;
		}
	}
	if (equal == 1)
	{
		return true;
	}
}

void IntegerSet::insertElement(int a) // inserts an element into an integer set
{
	set[a] = 1;
}

void IntegerSet::deleteElement(int a) // deletes an element from an integer set
{
	set[a] = 0;
}

void IntegerSet::printSet() // prints out the integer set
{
	cout << "{ ";
	for (int i = 0; i < 101; i++) 
	{
		if (set[i] == 1) 
		{
			cout << i << " ";
		}
	}
	cout << " } ";
}
