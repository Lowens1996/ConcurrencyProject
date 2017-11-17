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


int main()
{
	//variables 
	char grid[20][50];//Wa-Tor World 
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
	int i = 0;
	vector<Shark>sharkTracker; //Holds all current Shark objects and their details (e.g. position)
	vector<Fish>fishTracker;  //Holds all current Shark objects and their details (e.g. position)
	vector<Shark>::iterator itS;  // declare an iterator Shark vector
	vector<Fish>::iterator itF;  // declare an iterator Shark vector

	srand(time(NULL));
	

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
		while (slot !='E')//find position in grid for new shark object
		{
			row = rand() % 19; 
			col = rand() % 49; 
			space = grid[row][col];
			if (space = '_')
			{
				grid[row][col] = 'S';
				slot ='E';//break out of while loop
			}
		}
		Shark s(starve, SharkBreed, row, col); //Create shark object 
		sharkTracker.push_back(s); //add to tracker 
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
				slot = 'E';
			}
		}
		Fish f(FishBreed, row, col);
		fishTracker.push_back(f);
		slot = ' ';
	}
	//Print grid
	for (row = 0; row < 20; row++)
	{
		for (col = 0; col < 50; col++)
		{
			cout << grid[row][col];
		}
		cout << endl;
	}
	cin.get();
    return 0;
}

