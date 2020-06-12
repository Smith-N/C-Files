/* Nick Smith
Project 7
3/14/18
This assignment uses the integer set class to do various different
commands dealing with sets of integers
*/
#include "IntegerSet.h"
#include <iostream>
using namespace std;

int main() {
	IntegerSet A; // first integer set
	IntegerSet B; // second integer set
	int userIn = 0; // user input for entering and deleting elements

	// SET CREATION 
	cout << "SET CREATION" << endl;
	cout << "Enter Set A one element at a time" << endl;
	cout << "The range of the set is 0 through 100" << endl;
	cout << "Enter -1 when you are done entering set A" << endl;

	while (userIn != -1) { // loop for entering Set A
		cout << "Enter an element: ";
		cin >> userIn;
		if (userIn >= 0) 
		{
			A.insertElement(userIn);
		}
	}
	cout << "Set A = ";
	A.printSet();
	cout << endl << endl;

	userIn = 0; // set up again for next loop
	cout << "Enter Set B one element at a time" << endl;
	cout << "The range of the set is 0 through 100" << endl;
	cout << "Enter -1 when you are done entering set B" << endl;

	while (userIn != -1) { // loop for entering Set B
		cout << "Enter an element: ";
		cin >> userIn;
		if (userIn >= 0) 
		{
			B.insertElement(userIn);
		}
	}
	
	cout << "Set B = ";
	B.printSet();
	cout << endl;
	cout << endl;

	// DELETION
	cout << "DELETION" << endl;
	userIn = 0; // set up again for next loop
	cout << "Enter any elements you want to delete from set A one at a time" << endl;
	cout << "Enter -1 when you are done deleting from set A" << endl;

	while (userIn != -1) { // loop for deleting elements in Set A
		A.printSet();
		cout << "Enter an element to delete: ";
		cin >> userIn;
		if (userIn >= 0)
		{
			A.deleteElement(userIn);
		}
		cout << "Set A = ";
		A.printSet();
		cout << endl;
	}
	cout << endl; 

	userIn = 0; // set up again for next loop
	cout << "Enter any elements you want to delete from set B one at a time" << endl;
	cout << "Enter -1 when you are done deleting from set B" << endl;

	while (userIn != -1) { // loop for deleting elements in Set B
		B.printSet();
		cout << "Enter an element to delete: ";
		cin >> userIn;
		if (userIn >= 0)
		{
			B.deleteElement(userIn);
		}
		cout << "Set B = ";
		B.printSet();
		cout << endl;
	}
	cout << endl;

	// DEMONSTRATION
	cout << "DEMONSTRATION" << endl;
	cout << "Set A = ";
	A.printSet();
	cout << endl;

	cout << "Set B = ";
	B.printSet();
	cout << endl;

	// Intersection
	cout << "Intersection of A and B = ";
	A.intersect(B).printSet();
	cout << endl;

	// Union
	cout << "Union of A and B = ";
	A.unionize(B).printSet();
	cout << endl;

	//Complement
	cout << "Complement of A and B = ";
	A.complement(B).printSet();
	cout << endl;

	// Difference
	cout << "Difference of A and B = ";
	A.difference(B).printSet();
	cout << endl;

	// Subsets
	if (A.subset(B)) 
	{
		cout << "A is a subset of B" << endl;
	}
	else 
	{
		cout << "A is not a subset of B" << endl;
	}

	if (B.subset(A))
	{
		cout << "B is a subset of A" << endl;
	}
	else
	{
		cout << "B is not a subset of A" << endl;
	}

	// isEmpty
	if (A.isEmpty() == true) 
	{
		cout << "A is empty" << endl;
	}
	else
	{
		cout << "A is not empty" << endl;
	}

	if (B.isEmpty() == true)
	{
		cout << "B is empty" << endl;
	}
	else
	{
		cout << "B is not empty" << endl;
	}

	// isEqualTo
	if (A.isEqualTo(B) == true) 
	{
		cout << "A and B are equal" << endl;
	}
	else 
	{
		cout << "A and B are not equal" << endl;
	}

	system("pause");
}