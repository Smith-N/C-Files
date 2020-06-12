/*Nick Smith
January 23, 2018
Project 1, Excercise 2.19
The program will accept three integers from the user.
The integers will then be used to output the sum, average, product, smallest, and largest of the integers.*/
#include <iostream>

int main() {
	//variables
	int integer1;
	int integer2;
	int integer3;
	int smallestInt;
	int largestInt;
	double intAvg;

	//asks for the three integers and assigns them to int values
	std::cout << "Enter an integer: ";
	std::cin >> integer1;
	std::cout << "Enter an integer: ";
	std::cin >> integer2;
	std::cout << "Enter an Integer: ";
	std::cin >> integer3;
	intAvg = (double)(integer1 + integer3 + integer2) / 3;

	//compares to find the smallest integer
	if (integer1 <= integer2 && integer1 <= integer3)
		smallestInt = integer1;
	else if (integer2 <= integer1 && integer2 <= integer3)
		smallestInt = integer2;
	else if (integer3 <= integer1 && integer3 <= integer2)
		smallestInt = integer3;

	//compares to find the largest integer
	if (integer1 >= integer2 && integer1 >= integer3)
		largestInt = integer1;
	else if (integer2 >= integer1 && integer2 >= integer3)
		largestInt = integer2;
	else if (integer3 >= integer1 && integer3 >= integer2)
		largestInt = integer3;

	//outputs the information
	std::cout << "Sum is " << integer1 + integer2 + integer3 << std::endl;
	std::cout << "Average is " << intAvg << std::endl;
	std::cout << "Product is " << integer1 * integer2 * integer3 << std::endl;
	std::cout << "Smallest is " << smallestInt << std::endl;
	std::cout << "Largest is " << largestInt << std::endl;
	system("pause"); //keeps window open
}