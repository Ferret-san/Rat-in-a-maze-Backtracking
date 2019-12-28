#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
using std::vector;
struct PathBlock
{
	sf::Sprite block;
	sf::Sprite flag;
	bool blocked;
	bool flagged;
	PathBlock();
	PathBlock(bool blocked);
};