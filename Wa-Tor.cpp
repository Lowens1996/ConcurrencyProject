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
	int movePos; //used to randomise the choice of movement 
	bool newPos = false; //used to break out of while loop when a new position is found or shark or fish cant move 
	bool Down = true; //if cant move D,U,L,R set to false so it doesnt check to move down in the next iteration 
	bool Up = true;
	bool Left = true;
	bool Right = true;
	srand(time(NULL));

	if (type == 's')
	{
		for (i = 0; i < sTracker.size(); i++)
		{
			sRow = sTracker[i].getRow();
			sCol = sTracker[i].getCol();
			movePos = rand() % 3;//randomly choose movement 

			while (newPos == false)//keep trying to find a new position untill one is found 
			{
				//*************** DOWN ******************
				if (movePos == 0 && Down != false) //check randomised number and if down has been checked already
				{
					if (sRow < 19)
					{
						if (grid[sRow + 1][sCol] == '_') //check if shark can move down 
						{
							move = 'D';//move down
							newPos = true;//break while loop
						}
					}
					else if (sRow == 19)
					{
						if (grid[0][sCol] == '_') //check if shark can wrap back around 
						{
							grid[sRow][sCol] = '_';
							grid[0][sCol] = 'S';
							sTracker[i].setRow(0);
							move = '-';
							newPos = true;
						}
					}
					else { Down = false; } //If it cant do either this movement cant be made and is set to false 
				}
				//*************** UP ******************
				if (movePos == 1 && Up != false) 
				{
					if (sRow > 0)
					{
						if (grid[sRow - 1][sCol] == '_')
						{
							//cout << "move up" << endl;
							move = 'U';//move up
							newPos = true;//break while loop
						}
					}
					else if (sRow == 0)
					{
						if (grid[19][sCol] == '_')
						{
							grid[sRow][sCol] = '_';
							grid[19][sCol] = 'S';
							sTracker[i].setRow(19);
							move = '-';
							newPos = true;
						}
					}
					else { Up = false; }
				}
				//*************** LEFT ******************
				if (movePos == 2 && Left != false) 
				{
					if (sCol > 0)
					{
						if (grid[sRow][sCol - 1] == '_')
						{
							//cout << "move left" << endl;
							move = 'L';//move left
							newPos = true;//break while loop
						}
					}
					else if (sCol == 0)
					{
						if (grid[sRow][49] == '_')
						{
							grid[sRow][sCol] = '_';
							grid[sRow][49] = 'S';
							sTracker[i].setCol(49);
							move = '-';
							newPos = true;
						}
					}
					else { Left = false; }
				}
				//*************** RIGHT ******************
				if (movePos == 3 && Right != false) 
				{
					if (sCol < 49)
					{
						if (grid[sRow][sCol + 1] == '_')
						{
							//cout << "move right" << endl;
							move = 'R';//move right
							newPos = true;//break while loop
						}
					}
					else if (sCol == 49)
					{
						if (grid[sRow][0] == '_')
						{
							grid[sRow][sCol] = '_';
							grid[sRow][0] = 'S';
							sTracker[i].setCol(0);
							move = '-';
							newPos = true;
						}
					}
					else { Right = false; }
				}
				//*************** CANT MOVE ******************
				else if(Down == false && Up == false && Left == false && Right == false)
				{
					move = 'C';
					newPos = true;
				}
				movePos = rand() % 3;//randomly choose movement 
			}
			switch (move)
			{
			case 'D':
				//cout << " switch move down" << endl;
				grid[sRow][sCol] = '_';
				grid[sRow + 1][sCol] = 'S';
				sTracker[i].setRow(sRow + 1);
				break;
			case 'U':
				//cout << "switch move up" << endl;
				grid[sRow][sCol] = '_';
				grid[sRow - 1][sCol] = 'S';
				sTracker[i].setRow(sRow - 1);
				break;
			case 'L':
				//cout << "switch move left" << endl;
				grid[sRow][sCol] = '_';
				grid[sRow][sCol - 1] = 'S';
				sTracker[i].setCol(sCol - 1);
				break;
			case 'R':
				//cout << "switch move right" << endl;
				grid[sRow][sCol] = '_';
				grid[sRow][sCol + 1] = 'S';
				sTracker[i].setRow(sCol + 1);
				break;
			case 'C':
				break;
			}
			Down = true;
			Up = true;
			Left = true;
			Right = true;
			newPos = false;
		}
	}
	//************FISH********************
	if (type == 'f')
	{
		for (i = 0; i < fTracker.size(); i++)
		{
			fRow = fTracker[i].getRow();
			fCol = fTracker[i].getCol();
			movePos = rand() % 3;//randomly choose movement 

			while (newPos == false)//keep trying to find a new position untill one is found 
			{
				//*************** DOWN ******************
				if (movePos == 0 && Down != false) //check randomised number and if down has been checked already
				{
					if (fRow < 19)
					{
						if (grid[fRow + 1][fCol] == '_') //check if fish can move down 
						{
							move = 'D';//move down
							newPos = true;//break while loop
						}
					}
					else if (fRow == 19)
					{
						if (grid[0][fCol] == '_') //check if fish can wrap back around 
						{
							grid[fRow][fCol] = '_';
							grid[0][fCol] = 'F';
							fTracker[i].setRow(0);
							move = '-';
							newPos = true;
						}
					}
					else { Down = false; } //If it cant do either this movement cant be made and is set to false 
				}
				//*************** UP ******************
				if (movePos == 1 && Up != false)
				{
					if (fRow > 0)
					{
						if (grid[fRow - 1][fCol] == '_')
						{
							//cout << "move up" << endl;
							move = 'U';//move up
							newPos = true;//break while loop
						}
					}
					else if (fRow == 0)
					{
						if (grid[19][fCol] == '_')
						{
							grid[fRow][fCol] = '_';
							grid[19][fCol] = 'F';
							fTracker[i].setRow(19);
							move = '-';
							newPos = true;
						}
					}
					else { Up = false; }
				}
				//*************** LEFT ******************
				if (movePos == 2 && Left != false)
				{
					if (fCol > 0)
					{
						if (grid[fRow][fCol - 1] == '_')
						{
							move = 'L';//move left
							newPos = true;//break while loop
						}
					}
					else if (fCol == 0)
					{
						if (grid[fRow][49] == '_')
						{
							grid[fRow][fCol] = '_';
							grid[fRow][49] = 'F';
							fTracker[i].setCol(49);
							move = '-';
							newPos = true;
						}
					}
					else { Left = false; }
				}
				//*************** RIGHT ******************
				if (movePos == 3 && Right != false)
				{
					if (fCol < 49)
					{
						if (grid[fRow][fCol + 1] == '_')
						{
							move = 'R';//move right
							newPos = true;//break while loop
						}
					}
					else if (fCol == 49)
					{
						if (grid[fRow][0] == '_')
						{
							grid[fRow][fCol] = '_';
							grid[fRow][0] = 'F';
							fTracker[i].setCol(0);
							move = '-';
							newPos = true;
						}
					}
					else { Right = false; }
				}
				//*************** CANT MOVE ******************
				else if (Down == false && Up == false && Left == false && Right == false)
				{
					move = 'C';
					newPos = true;
				}
				movePos = rand() % 3;//randomly choose movement 
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
			Down = true;
			Up = true;
			Left = true;
			Right = true;
			newPos = false;
		}
	}
	//********************
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
	int NumShark = 5; //start number of sharks 
	int NumFish = 10; //start number of fish 
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
	for (i = 0; i < 50; i++)
	{
		system("CLS");
		char(*ptGrids)[50] = Move(sharkTracker,fishTracker,shark,grid,20);
		char(*ptGridf)[50] = Move(sharkTracker, fishTracker, fish, grid, 20);
		Print(grid);
	}
	cout << "FISH:" << endl;
	for (i = 0; i < fishTracker.size(); i++)
	{
		row = fishTracker[i].getRow();
		col = fishTracker[i].getCol();
		cout << row << endl;
		cout << col << endl;
	}
	cout << "SHARK:" << endl;
	for (i = 0; i < sharkTracker.size(); i++)
	{
		row = sharkTracker[i].getRow();
		col = sharkTracker[i].getCol();
		cout << row << endl;
		cout << col << endl;
	}

	cin.get();
    return 0;
}

