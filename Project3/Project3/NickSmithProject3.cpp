/*Nick Smith
Project 03
February 7, 2018
The program generates a random number that the user will guess.
The user can decide whether to play again or exit the program.*/
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
void guesses(int); // guesses functions

int main() {
	int numGuesses = 0; // number of guesses made
	srand(time(0)); // setting rand to time
	int randomNum = rand() % 1000 + 1; // random number with a range of 1 to 1000
	bool play = 1; //used for managing loop

	while (play == 1) { // loop that keeps game running
	int userGuess; //user input
	char yesNo; // for user to determines whether to play again

	cout << "Guess a number between 1 and 1,000" << endl;
	cin >> userGuess; // takes the user's guess

	if (userGuess < randomNum) // the guess is below the number
	{
		cout << "Your guess is less than the number." << endl;
		numGuesses++;
	}

	if (userGuess > randomNum) // the guess is higher than the number
	{
		cout << "Your guess is greater than the number." << endl;
		numGuesses++;
	}

	if (userGuess == randomNum) // when the guess is correct
	{
		numGuesses++;
		cout << "Your guess is right!" << endl;
		guesses(numGuesses); // calls guesses function

		while (userGuess == randomNum) {
			cout << "Would you like to play again? Y/N" << endl;
			cin >> yesNo;

			switch (yesNo) { // cases for playing again or not
			case 'Y':
			case 'y':
				numGuesses = 0;
				randomNum = rand() % 1000 + 1;
				break;
			case 'N':
			case 'n':
				userGuess = 0;
				play = 0;
				break;
			default: // if a Y, y, N, or n is not entered
				cout << "Please enter a Y or N." << endl;
			}
		}
	}
}
}

void guesses(int numGuesses) // determines what message to print
{
	if (numGuesses < 10) { cout << "Either you got lucky or you know the secret! You guessed " << numGuesses << " times." << endl; }
	else if (numGuesses == 10) { cout << "Ahah! You know the secret!" << endl; }
	else if (numGuesses > 10) { cout << "You should be able to do better!" << endl; }
}