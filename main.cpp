#include "BacktrackingAlgorithm.h"
#include "TexturePack.h"
#include "PathBlock.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
using namespace std;
int main()
{
	int mazeSize;
	cout << "Select a size for the maze: ";
	cin >> mazeSize;
	cout << "Press R to reset the maze." << endl;
	cout << "Press S to solve the maze." << endl;
	bool solved = false;
	bool reset = false;
	int** maze = new int* [mazeSize];
	for (int i = 0; i < mazeSize; i++)
		maze[i] = new int[mazeSize];
	for (int i = 0; i < mazeSize; i++)
		for (int j = 0; j < mazeSize; j++)
			maze[i][j] = 0;
	int** solution = new int* [mazeSize];
	for (int i = 0; i < mazeSize; i++)
		solution[i] = new int[mazeSize];
	for (int i = 0; i < mazeSize; i++)
		for (int j = 0; j < mazeSize; j++)
			solution[i][j] = 0;
	pathFinder(maze, solution, mazeSize);
	TexturePack::LoadTexture("tile_revealed");
	TexturePack::LoadTexture("flag");
	sf::Sprite block;
	sf::String playerInput;
	sf::Text playerText;
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "Rat in a Maze");
	string solve;
	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
			{
				
				reset = !reset;
				if (reset == true)
				{
					
					string userInput;
					cout << "Would you like to change the size of the maze? (Y/N)" << endl;
					cin >> userInput;
					while (userInput != "Y" && userInput != "N")
					{
						cout << "Please enter Y for yes or N for no" << endl;
						cin >> userInput;
					}
					if (userInput == "Y" || userInput == "N")
					{
						
						if (userInput == "Y")
						{
							do {
								cout << "Please enter a number: ";
								cin >> mazeSize;
							} while (!cin);

							for (int i = 0; i < mazeSize; i++)
								maze[i] = new int[mazeSize];
							for (int i = 0; i < mazeSize; i++)
								for (int j = 0; j < mazeSize; j++)
									maze[i][j] = 0;
							for (int i = 0; i < mazeSize; i++)
								solution[i] = new int[mazeSize];
							for (int i = 0; i < mazeSize; i++)
								for (int j = 0; j < mazeSize; j++)
									solution[i][j] = 0;
							pathFinder(maze, solution, mazeSize);
						}
						else
						{
							for (int i = 0; i < mazeSize; i++)
								maze[i] = new int[mazeSize];
							for (int i = 0; i < mazeSize; i++)
								for (int j = 0; j < mazeSize; j++)
									maze[i][j] = 0;
							for (int i = 0; i < mazeSize; i++)
								solution[i] = new int[mazeSize];
							for (int i = 0; i < mazeSize; i++)
								for (int j = 0; j < mazeSize; j++)
									solution[i][j] = 0;
							pathFinder(maze, solution, mazeSize);
						}
					}
				}
				solved = false;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			{
				solved = true;
			}
		}
		
		window.clear();
		if (solved == false)
		{
			for (int i = 0; i < mazeSize; i++)
			{

				for (int j = 0; j < mazeSize; j++)
				{
					if (maze[i][j] == 1)
					{
						PathBlock someBlock;
						someBlock.block.setPosition((j * 32.0f), (i * 32.0f));
						window.draw(someBlock.block);
					}
					else if (maze[i][j] == 0)
					{
						PathBlock someBlock;
						someBlock.block.setPosition((j * 32.0f), (i * 32.0f));
						someBlock.block.setColor(sf::Color(255, 255, 255, 128));
						window.draw(someBlock.block);
					}
				}

			}
		}
		if (solved == true)
		{
			for (int i = 0; i < mazeSize; i++)
			{

				for (int j = 0; j < mazeSize; j++)
				{
					if (solution[i][j] == 1)
					{
						PathBlock someBlock;
						someBlock.block.setPosition((j * 32.0f), (i * 32.0f));
						someBlock.block.setColor(sf::Color(0, 255, 0));
						window.draw(someBlock.block);
					}
					else if (maze[i][j] == 1 && solution[i][j] == 0)
					{
						PathBlock someBlock;
						someBlock.block.setPosition((j * 32.0f), (i * 32.0f));
						window.draw(someBlock.block);
					}
					else if (maze[i][j] == 0 && solution[i][j] == 0)
					{
						PathBlock someBlock;
						someBlock.block.setPosition((j * 32.0f), (i * 32.0f));
						someBlock.block.setColor(sf::Color(255, 255, 255, 128));
						window.draw(someBlock.block);
					}
				}

			}
		}
		window.display();
	}
	
	return 0;
}