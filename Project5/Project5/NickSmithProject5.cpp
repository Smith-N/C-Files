/*Nick Smith
Project 5
February 19, 2018
This program demonstrates pointer manipulation actions
*/
#include <iostream>
using namespace std;

int main() {
	unsigned int values[5] = {2,4,6,8,10}; // unsigned int array (from 8.9 part a.)
	unsigned int *vptr; // array pointer (from 8.9 part b.)
	vptr = values; // one way of assigning the starting address of array values (From 8.9 part d.)
	vptr = &values[0]; // another way to assign the starting address (From 8.9 part d.)

	// Array subscript notation (from 8.9 part c.)
	cout << endl << "Array Subscript Notation" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << "values[" << i << "] = " << values[i] << endl;
	}

	// Pointer/offset pointer name (from 8.9 part e.)
	cout << endl << "Pointer/offset Notation using pointer name" << endl;
	for (int offset1 = 0; offset1 < 5; offset1++)
	{
		cout << "*(vptr + " << offset1 << ") = " << *(vptr + offset1) << endl;
	}


	// Pointer/offset array name (from 8.9 part f.)
	cout << endl << "Pointer/offset Notation using array name" << endl;
	for (int offset2 = 0; offset2 < 5; offset2++)
	{
		cout << "*(b + " << offset2 << ") = " << *(values + offset2) << endl;
	}

	// Display with subscripting the pointer (from 8.9 part g.)
	cout << endl << "Display array with subscripting the pointer" << endl;
	for (int j = 0; j < 5; j++) 
	{
		cout << "vptr[" << j << "] = " << vptr[j] << endl;
	}

	cout << endl << "Array Subscript Notation: " << values[4] << endl; // Refers to fifth element using Array Subscript Notation (from 8.9 part h.)
	cout << endl << "Pointer/Offset Notation Using Array Name: " << *(values + 4) << endl; // Refers to fifth element using Pointer/Offset with array name (from 8.9 part h.)
	cout << endl << "Pointer Subscript Notation: " << vptr[4] << endl; // Refers to fifth element using Pointer Subscript Notation (from 8.9 part h.)
	cout << endl << "Pointer/Offset Notation: " << *(vptr + 4) << endl; // Refers to fifth element using Pointer/Offset (from 8.9 part h.)
	cout << endl << "Address referenced at vptr+3: " << vptr + 3 << endl; // Shows the address of element 4 (from 8.9 part i.)
	cout << endl << vptr[3] << " is found at " << vptr + 3 << endl; // Shows the value of element 4 (from 8.9 part i.)
	vptr = &values[4]; // Sets pointer to fifth element (from 8.9 part j.)
	vptr -= 4; // Subtracts four, which would make to pointer point to vptr[0] or values[0] (from 8.9 part j.)
	cout << endl << "The address after vptr -= 4 is: " << vptr << endl; // Shows address after vptr -= 4 (from 8.9 part j.)
	cout << endl << "The value after vptr -= 4 is: " << *vptr << endl; // Shows value after vptr -= 4 (from 8.9 part j.)

	system("pause");
}