#include "TexturePack.h"

map<string, sf::Texture> TexturePack::textures;

void TexturePack::LoadTexture(string textureName)
{
	string path = "images/";
	path += textureName;
	path += ".png";
	textures[textureName].loadFromFile(path);
}

sf::Texture& TexturePack::GetTexture(string textureName)
{
	return textures[textureName];
}