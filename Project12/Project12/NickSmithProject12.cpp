/* Name: Nick Smith (put your name here)
Project 12
This program allows the user to create a file that
stores a list of people, and allows for it to delete, update,
and display all records
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Person.h"

using namespace std;

char enterChoice();
void createTextFile(fstream&);
void updateRecord(fstream&);
void newRecord(fstream&);
void deleteRecord(fstream&);
void outputLine(ostream&, const Person &);
int getidNumber(const char * const);


int main()
{
	char ans;
	cout << "Do you want to create an empty file (y/n)? ";
	cin >> ans;
	if (ans == 'y' || ans == 'Y') {
		//create nameage.dat to hold 100 possible person objects
		ofstream outPerson("nameage.dat", ios::out | ios::binary);

		// exit program if ofstream could not open file
		if (!outPerson)
		{
			cerr << "File could not be opened." << endl;
			exit(1);
		}

		Person blankPerson; // constructor zeros out each data member

							// output 100 blank records to file
		for (int i = 0; i < 100; ++i)
		{
			outPerson.write(reinterpret_cast< const char * >(&blankPerson),
				sizeof(Person));
		}

		outPerson.close();
	}

	fstream inOutPerson("nameage.dat", ios::in | ios::out | ios::binary);

	char choice; // store user choice

	while ((choice = enterChoice()) != 'E' && choice != 'e')
	{
		switch (choice)
		{
		case 'P':
		case 'p':// print/display data
			createTextFile(inOutPerson);
			break;
		case 'U':
		case 'u':// update record
			updateRecord(inOutPerson);
			break;
		case 'A':
		case 'a':// add a new record
			newRecord(inOutPerson);
			break;
		case 'D':
		case 'd':// delete existing record
			deleteRecord(inOutPerson);
			break;
		default: // display error if user does not select valid choice
			cerr << "Incorrect choice" << endl;
			break;
		}

		inOutPerson.clear(); // reset
	}
}

// enable user to input menu choice
char enterChoice()
{
	// display available options
	cout << "\nEnter your choice" << endl
		<< "P - Print/Display a list of people" << endl
		<< "U - Update a person" << endl
		<< "A - Add a new person" << endl
		<< "D - Delete a person" << endl
		<< "E - End program\n> ";

	char menuChoice;
	cin >> menuChoice; // input menu selection from user
	return menuChoice;
}

// create formatted text file for printing (uses nameage.dat as input)
void createTextFile(fstream &readFromFile)
{
	// create text file
	ofstream outPrintFile("print.txt", ios::out);

	// exit program if ofstream cannot create file
	if (!outPrintFile)
	{
		cerr << "File could not be created." << endl;
		exit(1);
	}
	//display header information to file and to cout
	outPrintFile << left << setw(10) << "ID Number" << setw(16) << "Last Name" << setw(11) << "First Name" << right << setw(10) << "Age" << endl;

	// set file-position pointer to beginning of readFromFile
	readFromFile.seekg(0);
	// read first record from record file
	Person person;
	readFromFile.read(reinterpret_cast<char *>(&person), sizeof(Person));
	// copy all records from record file into text file
	while (!readFromFile.eof())
	{
		// write single record to text file
		if (person.getId() != 0)
		{
			//write to file
			outputLine(outPrintFile, person);
			//write to cout
			outputLine(cout, person);
		}

		// read next record from record file
		readFromFile.read(reinterpret_cast<char *>(&person), sizeof(Person));
	}
}

// update age in record
void updateRecord(fstream &updateFile)
{
	// obtain number of idNumber to update
	int idNumber = getidNumber("Enter Id Number to update");

	// move file-position pointer to correct record in file
	updateFile.seekg((idNumber - 1) * sizeof(Person));
	// read first record from file
	Person person;
	updateFile.read(reinterpret_cast<char *>(&person), sizeof(Person));
	//update record
	if (person.getId() != 0)
	{
		outputLine(cout, person); // display the record

								  // request user to update age
		cout << "\nEnter new age:" << endl;
		int age;
		cin >> age;

		// update age
		person.setAge(age);
		outputLine(cout, person);
		// move file-position pointer to correct record in file
		updateFile.seekg((idNumber - 1) * sizeof(Person));
		// write updated record over old record in file
		updateFile.write(reinterpret_cast<const char *>(&person), sizeof(Person));
	}
	else // display error if idNumber does not exist
	{
		cerr << "Id # " << idNumber << " has no information." << endl;
	}
}

// create and insert record
void newRecord(fstream &insertInFile)
{
	// obtain number of idNumber to create
	int idNumber = getidNumber("Enter new Id Number");

	// move file-position pointer to correct record in file
	insertInFile.seekg((idNumber - 1) * sizeof(Person));
	// read record from file
	Person person;
	insertInFile.read(reinterpret_cast<char *>(&person), sizeof(Person));
	// create record, if record does not previously exist
	if (person.getId() == 0)
	{
		string lastName;
		string firstName;
		int age;

		// user enters last name, first name and age
		cout << "Enter lastname, firstname, age\n> ";
		cin >> setw(15) >> lastName;
		cin >> setw(10) >> firstName;
		cin >> age;

		// use values to populate record
		person.setLastName(lastName);
		person.setFirstName(firstName);
		person.setAge(age);
		person.setId(idNumber);
		// move file-position pointer to correct record in file
		insertInFile.seekp((idNumber - 1) * sizeof(Person));
		// insert record in file
		insertInFile.write(reinterpret_cast<char *>(&person), sizeof(Person));
	}
	else // display error if idNumber already exists
	{
		cerr << "Id # " << idNumber
			<< " already contains information." << endl;
	}
}

// delete an existing record
void deleteRecord(fstream &deleteFromFile)
{
	// obtain number of idNumber to delete
	int idNumber;
	idNumber = getidNumber("Enter Id Number to delete");

	// move file-position pointer to correct record in file
	deleteFromFile.seekg((idNumber - 1) * sizeof(Person));
	// read record from file
	Person person;
	deleteFromFile.read(reinterpret_cast<char *>(&person), sizeof(Person));
	// delete record, if record exists in file
	if (person.getId() != 0)
	{
		Person blankPerson; // create blank record

							// move file-position pointer to correct record in file
		deleteFromFile.seekp((idNumber - 1) * sizeof(Person));
							// replace existing record with blank record
		deleteFromFile.write(reinterpret_cast<const char *>(&blankPerson), sizeof(Person));

		cout << "Id #" << idNumber << " deleted.\n";
	}
	else // display error if idNumber does not exist
	{
		cerr << "Id #" << idNumber
			<< " is empty" << endl;
	}
}

// display single record
void outputLine(ostream &output, const Person &record)
{
	output << left << setw(10) << record.getId()
		<< setw(16) << record.getLastName()
		<< setw(11) << record.getFirstName()
		<< setw(10) << right << record.getAge() << endl;
}

// obtain idNumber-number value from user
int getidNumber(const char * const prompt)
{
	int idNumber;

	//obtain idNumber-number value
	do
	{
		cout << prompt << " (1-100): ";
		cin >> idNumber;
	} while (idNumber < 1 || idNumber > 100);

	return idNumber;
}


