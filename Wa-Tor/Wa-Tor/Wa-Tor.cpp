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

char(*Move(vector<Shark>& sTracker, vector<Fish>& fTracker, char type, char grid[][50], size_t sz))[50]
{//This changes objects positions in the grid & checks for collions between positions beofre moving
	int i;
	char move;
	int sRow;
	int sCol;
	int fRow;
	int fCol;
	int movePos = 0;
	bool newPos = false;
	srand(time(NULL));

	if (type == 's')
	{
		for (i = 0; i < sTracker.size(); i++)
		{
			sRow = sTracker[i].getRow();
			sCol = sTracker[i].getCol();

			while (newPos == false)//keep trying to find a new position untill one is found 
			{
				movePos = rand() % 4;//random neumber between 0-4
				switch (movePos)
				{
				case 0:
					if (grid[sRow + 1][sCol] == '_' && sRow + 1 < 20)
					{
						move = 'D';//move down
						newPos = true;//break while loop
					}
					else { newPos = false; }
					cout << "shark down broke";
					break;
				case 1:
					if (grid[sRow - 1][sCol] == '_' && sRow - 1 >= 0)
					{
						move = 'U';
						newPos = true;
					}
					else { newPos = false; }
					cout << "shark up broke";
					break;
				case 2:
					if (grid[sRow][sCol - 1] == '_' && sCol - 1 >= 0)
					{
						move = 'L';
						newPos = true;
					}
					else { newPos = false; }
					cout << "shark left broke";
					break;
				case 3:
					if (grid[sRow][sCol + 1] == '_' && sCol + 1 > 50)
					{
						move = 'R';
						newPos = true;
					}
					else { newPos = false; }
					cout << "shark right broke";
					break;
				case 4:
					move = 'C';
					newPos = true;
					break;
				}
			}
			switch (move)
			{
			case 'D':
				grid[sRow][sCol] = '_';
				grid[sRow + 1][sCol] = 'S';
				sTracker[i].setRow(sRow + 1);
				break;
			case 'U':
				grid[sRow][sCol] = '_';
				grid[sRow - 1][sCol] = 'S';
				sTracker[i].setRow(sRow - 1);
				break;
			case 'L':
				grid[sRow][sCol] = '_';
				grid[sRow][sCol - 1] = 'S';
				sTracker[i].setCol(sCol - 1);
				break;
			case 'R':
				grid[sRow][sCol] = '_';
				grid[sRow][sCol + 1] = 'S';
				sTracker[i].setRow(sCol + 1);
				break;
			case 'C':
				break;
			}
		}
	}
	//************FISH********************
	if (type == 'f')
	{
		for (i = 0; i < fTracker.size(); i++)
		{
			fRow = fTracker[i].getRow();
			fCol = fTracker[i].getCol();

			while (newPos == false)
			{
				movePos = rand() % 5;
				switch (movePos)
				{
				case 0:
					if (grid[fRow + 1][fCol] == '_' && fRow + 1 < 20)
					{
						move = 'D';
						newPos = true;
					}
					else { newPos = false; }
					cout << "fish down broke";
					break;
				case 1:
					if (grid[fRow - 1][fCol] == '_' && fRow - 1 >= 0)
					{
						move = 'U';
						newPos = true;
					}
					else { newPos = false; }
					cout << "fish up broke";
					break;
				case 2:
					if (grid[fRow][fCol - 1] == '_' && fCol - 1 >= 0)
					{
						move = 'L';
						newPos = true;
					}
					else { newPos = false; }
					cout << "fish left broke";
					break;
				case 3:
					if (grid[fRow][fCol + 1] == '_' && fCol + 1 > 50)
					{
						move = 'R';
						newPos = true;
					}
					else { newPos = false; }
					cout << "fish right broke";
					break;
				case 4:
					move = 'C';
					newPos = true;
					break;

				}
			}
			switch (move)
			{
			case 'D':
				grid[fRow][fCol] = '_';
				grid[fRow + 1][fCol] = 'F';
				fTracker[i].setRow(fRow + 1);
				break;
			case 'U':
				grid[fRow][fCol] = '_';
				grid[fRow - 1][fCol] = 'F';
				fTracker[i].setRow(fRow - 1);
				break;
			case 'L':
				grid[fRow][fCol] = '_';
				grid[fRow][fCol - 1] = 'F';
				fTracker[i].setCol(fCol - 1);
				break;
			case 'R':
				grid[fRow][fCol] = '_';
				grid[fRow][fCol + 1] = 'F';
				fTracker[i].setRow(fCol + 1);
				break;
			case 'C':
				break;
			}
		}
	}
	return grid;
}
void Print(char grid[20][50])
{
	for (int r = 0; r < 20; r++)
	{
		for (int c = 0; c < 50; c++)
		{
			cout << grid[r][c];
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
	int NumShark = 10; //start number of sharks 
	int NumFish = 30; //start number of fish 
	int SharkBreed = 25; //Number of iterations before shark can breed 
	int FishBreed = 10; //Number of iterations before fish can breed 
	int starve = 4; //Number of iterations before shark starves and is deleted from vector 
	char slot = ' '; //Used for insertion into Grid
	char space = ' ';//Used for insertion into Grid
	int col = 0;  //Used for insertion into Grid
	int row = 0;  //Used for insertion into Grid
	char shark = 's'; //Used for sending to functions to ecxexute function on either fish or sharks 
	char fish = 'f';  //Used for sending to functions to ecxexute function on either fish or sharks 
	vector<Shark>sharkTracker; //Holds all current Shark objects and their details (e.g. position)
	vector<Fish>fishTracker;  //Holds all current Shark objects and their details (e.g. position)
	vector<Shark>::iterator itS;  // declare an iterator Shark vector
	vector<Fish>::iterator itF;  // declare an iterator Shark vector
	int fishCount = 0;
	int sharkCount = 0;

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
				grid[row][col] = 'S';
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
				grid[row][col] = 'F';
				Fish f(FishBreed, row, col); //Create shark object 
				fishTracker.push_back(f); //add to tracker 
				slot = 'E';
			}
		}
		slot = ' ';
	}
	//Life Cycle 
	for (i = 0; i < 100; i++)
	{
		system("CLS");
		char(*ptGrids)[50] = Move(sharkTracker,fishTracker,shark,grid,20);
		char(*ptGridf)[50] = Move(sharkTracker, fishTracker, fish, grid, 20);
		Print(grid);
	}
	cout << endl;
	Print(grid);

	cin.get();
    return 0;
}

