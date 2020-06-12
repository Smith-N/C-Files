/*Nick Smith
January 29, 2018
Project 2, Excercise 5.21
The program is used for doing payroll.
It will accept user codes that tell the program what to do for calculating pay for different pay types (Weekly, Hourly, Commission, and Piecework)*/
#include <iostream>

int main() {
	//variables
	double weeklySal; // weekly salary
	int hours; // hours for the week
	int overtimeHours; // variable for the amount of hours overtime
	double hourlyWage; // variable for hourly wages
	double weeklyWage; // variable for weekly wages, also used for commission and piecework pays for the week
	int grossSales; // varaibles for gross sales
	double basePay; // variables for the base pay of commission worker
	int numProduced; // number of items produced
	double itemPay; // pay per item produced
	int userCode = 6; //user code that the user, initialized to 6 so that the while loop is guaranteed to work properly
	
	//while loop that keeps the program running until the user enters a 0 to exit
	while (userCode != 0) {
		std::cout << "Enter on of the following employee number codes to begin" << std::endl;
		std::cout << "Codes: Manager = 1, Hourly = 2, Commission = 3, Piecework = 4, Exit Function = 0" << std::endl;
		std::cin >> userCode;
		//switch statement that can do the necessary commands for the different payroll calculations
		switch (userCode) {
		case 1: // manager salary case
			std::cout << "Enter the weekly salary of a manager." << std::endl;
			std::cin >> weeklySal;
			std::cout << "The weekly salary of the manager is $" << weeklySal << std::endl;
			break;
		case 2: // hourly employee pay case
			std::cout << "Enter the number of hours logged by the employee." << std::endl;
			std::cin >> hours;
			std::cout << "Enter the hourly wage of the employee." << std::endl;
			std::cin >> hourlyWage;
			if (hours > 40) { // if statement for handling overtime
				overtimeHours = hours - 40;
				weeklyWage = (overtimeHours * (1.5 * hourlyWage)) + (40 * hourlyWage);
			}
			else { // for non-overtime hours
				weeklyWage = hours * hourlyWage;
			}
			std::cout << "The weekly wage of the hourly employee is $" << weeklyWage << std::endl;
			break;
		case 3: // commission pay case
			std::cout << "Enter the gross sales of the commission worker." << std::endl;
			std::cin >> grossSales;
			std::cout << "Enter the base pay for the commission worker." << std::endl;
			std::cin >> basePay;
			weeklyWage = (grossSales * .057) + basePay;
			std::cout << "The weekly pay of the commision worker is $" << weeklyWage << std::endl;
			break;
		case 4: // piecework pay case
			std::cout << "Enter the number of items produced by the employee this week." << std::endl;
			std::cin >> numProduced;
			std::cout << "Enter the employee's pay per item." << std::endl;
			std::cin >> itemPay;
			weeklyWage = numProduced * itemPay;
			std::cout << "The weekly pay for the piecework worker is $" << weeklyWage << std::endl;
			break;
		default: // default case for catching anything that does not match the correct codes
			std::cout << "Incorrect code, please enter a correct code." << std::endl;
			break;
		}
	}
}