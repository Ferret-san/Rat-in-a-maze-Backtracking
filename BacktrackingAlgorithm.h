#pragma once
#include <random>
#include <iostream>
using namespace std;
bool solutionFinder(int** maze, int mazeSize, int x, int y, int** solution);
bool validPath(int** maze, int mazeSize, int x, int y);
void printSolution(int** maze, int mazeSize);
int Random(int min, int max)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dist(min, max);
	return dist(gen);
}
bool pathFinder(int** maze, int** solution, int& mazeSize)
{
	

	for (int i = 0; i < mazeSize; i++)
	{
		for (int j = 0; j < mazeSize; j++)
		{
		
			int openPath = Random(0, (mazeSize - 1));
			maze[i][openPath] = 1;
		}
		
	}
	cout << "maze" << endl;
	printSolution(maze, mazeSize);
	for (int i = 0; i < mazeSize; i++)
		solution[i] = new int[mazeSize];
	for (int i = 0; i < mazeSize; i++)
		for (int j = 0; j < mazeSize; j++)
			solution[i][j] = 0;
	if (solutionFinder(maze, mazeSize, 0, 0, solution) == false)
	{
		printf("solution doesn't exist \n");
		return false;
	}

	cout << "solution" << endl;
	printSolution(solution, mazeSize);
	
	return true;
}
bool solutionFinder(int** maze,int mazeSize, int x, int y, int** solution)
{
	if (x == mazeSize - 1 && y == mazeSize - 1)
	{
		if(maze[x][y] == 1)
		{
			solution[x][y] = 1;
			return true;
		}
		if (maze[x][y] == 0)
		{
			solution[x][y] = 0;
			return false;
		}
		
	}

	//Check paths validity
	if (validPath(maze, mazeSize, x, y) == true)
	{
		//mark as part of the solution path
		solution[x][y] = 1;

		//move forward in x direction (horizontally)
		if (solutionFinder(maze, mazeSize, x + 1, y, solution) == true)
			return true;
		//if moving forward in x direction is not valid
		//then move down in y direction
		if (solutionFinder(maze, mazeSize, x, y + 1, solution) == true)
			return true;

		//If both moves do not work, then backtrack (unmark [x][y] from solution)
		solution[x][y] = 0;
		return false;
	}

	return false;
}
bool validPath(int** maze, int mazeSize, int x, int y)
{
	//if path is outside of the maze, return false
	if (x >= 0 && x < mazeSize && y >= 0 && y < mazeSize && maze[x][y] == 1)
		return true;

	return false;
}
void printSolution(int** maze, int mazeSize)
{
	for (int i = 0; i < mazeSize; i++)
	{
		for (int j = 0; j < mazeSize; j++)
			printf(" %d", maze[i][j]);
		printf("\n");
	}
}