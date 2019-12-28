#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include <string>
using std::map;
using std::string;
class TexturePack
{

	static map<string, sf::Texture> textures;
public:
	static void LoadTexture(string textureName);
	static sf::Texture& GetTexture(string textureName);
};