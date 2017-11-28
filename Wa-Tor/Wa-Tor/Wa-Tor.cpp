// Wa-Tor.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Shark.h"
#include "Fish.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
using namespace std;

vector<Shark> MoveShark(vector<Shark>& sTracker, vector<Fish>& fTracker)
{
	int i = 0;
	int i2 = 0;
	int sRow;
	int sCol = 0;
	int fRow = 0;
	int fCol = 0;
	bool move_up = true;
	bool move_down= true;
	bool move_right = true;
	bool move_left = true;

	for (i = 0; i < sTracker.size(); i++)
	{
		sRow = sTracker[i].getRow();
		cout << "shark row " << sRow << endl;
		sCol = sTracker[i].getCol();

		for (i2 = 0; i2 < fTracker.size(); i2++)
		{
			fRow = fTracker[i2].getRow();
			cout << "fish row " << fRow << endl;
			fCol = fTracker[i2].getCol(); 
			if (fRow = sRow + 1 && fCol = sCol)
			{
				bool move_up = false;
			}

		}
	}

	return sTracker;
}
void Print(char grid[20][50], int row, int col, vector<Shark>& sTracker, vector<Fish>& fTracker)
{
	int i = 0;
	int sRow = 0;
	int sCol = 0;
	int fRow = 0;
	int fCol = 0;
	for (row = 0; row < 20; row++)
	{
		for (col = 0; col < 50; col++)
		{
			for (i = 0; i < sTracker.size(); i++)
			{
				sRow = sTracker[i].getRow();
				sCol = sTracker[i].getCol();
				if (sRow == row && sCol == col)
				{
					grid[row][col] = 'S';
				}
			}
			for (i = 0; i < fTracker.size(); i++)
			{
				fRow = fTracker[i].getRow();
				fCol = fTracker[i].getCol();
				if (fRow == row && fCol == col)
				{
					grid[row][col] = 'F';
				}
			}
			cout << grid[row][col];
		}
		cout << endl;
	}
}
int main()
{
	//variables 
	char grid[20][50];//Wa-Tor World 
	srand(time(NULL));
	int i = 0;
	int Timer = 500;
	int NumShark = 5; //start number of sharks 
	int NumFish = 20; //start number of fish 
	int SharkBreed = 25; //Number of iterations before shark can breed 
	int FishBreed = 10; //Number of iterations before fish can breed 
	int starve = 4; //Number of iterations before shark starves and is deleted from vector 
	char slot = ' '; //Used for insertion into Grid
	char space = ' ';//Used for insertion into Grid
	int col = 0;  //Used for insertion into Grid
	int row = 0;  //Used for insertion into Grid
	string shark = "s"; //Used for sending to functions to ecxexute function on either fish or sharks 
	string fish = "f";  //Used for sending to functions to ecxexute function on either fish or sharks 
	vector<Shark>sharkTracker; //Holds all current Shark objects and their details (e.g. position)
	vector<Fish>fishTracker;  //Holds all current Shark objects and their details (e.g. position)
	vector<Shark>::iterator itS;  // declare an iterator Shark vector
	vector<Fish>::iterator itF;  // declare an iterator Shark vector

	//Intialize grid to be empty 
	for (row = 0; row < 20; row++)
	{
		for (col = 0; col < 50; col++)
		{
			grid[row][col] = '_';
		}
	}
	//insert sharks
	for (i = 0; i < NumShark; i++)
	{
		while (slot != 'E')//find position in grid for new shark object
		{
			row = rand() % 19;
			col = rand() % 49;
			space = grid[row][col];
			if (space = '_')
			{
				Shark s(starve, SharkBreed, row, col); //Create shark object 
				sharkTracker.push_back(s); //add to tracker 
				slot = 'E';
			}
		}
		slot = ' ';//reset to get back into while loop
	}
	//insert fish
	for (i = 0; i < NumFish; i++)
	{
		while (slot != 'E')//find position in grid for new fish object
		{
			row = rand() % 19;
			col = rand() % 49;
			space = grid[row][col];
			if (space = '_')
			{
				Fish f(FishBreed, row, col); //Create shark object 
				fishTracker.push_back(f); //add to tracker 
				slot = 'E';
			}
		}
		slot = ' ';
	}
	
		MoveShark(sharkTracker, fishTracker);
	
		//Print(grid, row, col, sharkTracker, fishTracker);
		//system("CLS");
	
		
	cin.get();
    return 0;
}

