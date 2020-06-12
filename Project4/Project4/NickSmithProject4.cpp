/*Nick Smith
Project 04
February 14, 2018
This program will solve mazes
A rat will go through the maze, marking its path with *'s and -'s depending on if it backtracks*/

#include <iostream>
#include "mazelayout1.h"
using namespace std;

int main() {
	int rat = 'E'; // what moves through the maze
	int row = startRow; // used for the cases that check where to move
	int col = startCol; // used for the cases that check where to move
	int mazeRowSize = 12; // row size for printing array later
	int mazeColSize = 12; // column size for printing array later

	maze[row][col] = 'X'; // marks the beginning of maze

		while (row != endRow || col != endCol){
		switch (rat) {
		case 'E':
			if (maze[row + 1][col] != '#') // right
			{
				rat = 'S';
				row++;

				if (maze[row][col] == '*') {
					maze[row][col] = '-';
				}
				else 
				{ 
					maze[row][col] = '*'; 
				}

			}
			else if (maze[row][col + 1] != '#') // forward
			{
				rat = 'E';
				col++;

				if (maze[row][col] == '*') {
					maze[row][col] = '-';
				}
				else
				{
					maze[row][col] = '*';
				}

			}
			else if (maze[row - 1][col] != '#') // left
			{
				rat = 'N';
				row--;
				if (maze[row][col] == '*') {
					maze[row][col] = '-';
				}
				else
				{
					maze[row][col] = '*';
				}

			}
			else // back
			{
				rat = 'W';
				col--;
				if (maze[row][col] == '*') {
					maze[row][col] = '-';
				}
				else
				{
					maze[row][col] = '*';
				}
			}
			break;

		case 'S':
			if (maze[row][col-1] != '#') { // right
				rat = 'W';
				col--;
				if (maze[row][col] == '*') {
					maze[row][col] = '-';
				}
				else
				{
					maze[row][col] = '*';
				}
			}
			else if (maze[row+1][col] != '#') { // forward
				rat = 'S';
				row++;
				if (maze[row][col] == '*') {
					maze[row][col] = '-';
				}
				else
				{
					maze[row][col] = '*';
				}
			}
			else if (maze[row][col+1] != '#') { // left
				rat = 'E';
				col++;
				if (maze[row][col] == '*') {
					maze[row][col] = '-';
				}
				else
				{
					maze[row][col] = '*';
				}
			}
			else //back
			{ 
				rat = 'N';
				row--;
				if (maze[row][col] == '*') {
					maze[row][col] = '-';
				}
				else
				{
					maze[row][col] = '*';
				}
			}
			break;

		case 'N':
			if (maze[row][col+1] != '#') { // right
				rat = 'E';
				col++;
				if (maze[row][col] == '*') {
					maze[row][col] = '-';
				}
				else
				{
					maze[row][col] = '*';
				}
			}
			else if (maze[row - 1][col] != '#') { // forward
				rat = 'N';
				row--;
				if (maze[row][col] == '*') {
					maze[row][col] = '-';
				}
				else
				{
					maze[row][col] = '*';
				}
			}
			else if (maze[row][col-1] != '#') { // left
				rat = 'W';
				col--;
				if (maze[row][col] == '*') {
					maze[row][col] = '-';
				}
				else
				{
					maze[row][col] = '*';
				}
			}
			else { // back
				rat = 'S';
				row++;
				if (maze[row][col] == '*') {
					maze[row][col] = '-';
				}
				else
				{
					maze[row][col] = '*';
				}
			}
			break;

		case 'W':
			if (maze[row - 1][col] != '#') // right
			{
				rat = 'N';
				row--;
				if (maze[row][col] == '*') {
					maze[row][col] = '-';
				}
				else
				{
					maze[row][col] = '*';
				}
			}
			else if (maze[row][col-1] != '#') // forward
			{
				rat = 'W';
				col--;
				if (maze[row][col] == '*') {
					maze[row][col] = '-';
				}
				else
				{
					maze[row][col] = '*';
				}
			}
			else if (maze[row+1][col] != '#') // left
			{
				rat = 'S';
				row++;
				if (maze[row][col] == '*') {
					maze[row][col] = '-';
				}
				else
				{
					maze[row][col] = '*';
				}
			}
			else // back
			{
				rat = 'E';
				col++;
				if (maze[row][col] == '*') {
					maze[row][col] = '-';
				}
				else
				{
					maze[row][col] = '*';
				}
			}
			break;
		}
		for (int i = 0; i < mazeRowSize; i++) { //prints out the maze
			for (int j = 0; j < mazeColSize; j++) {
				cout << maze[i][j];
			}
			cout << endl;
		}
	cout << endl; //adds extra space between mazes
	}
	system("pause");
}