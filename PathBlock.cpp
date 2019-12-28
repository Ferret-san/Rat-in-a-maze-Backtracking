#include "PathBlock.h"
#include "TexturePack.h"
PathBlock::PathBlock()
{
	TexturePack::LoadTexture("tile_revealed");
	TexturePack::LoadTexture("flag");
	block.setTexture(TexturePack::GetTexture("tile_revealed"));
	flag.setTexture(TexturePack::GetTexture("flag"));
	blocked = false;
	flagged = false;
}
PathBlock::PathBlock(bool isBlocked)
{
	TexturePack::LoadTexture("tile_revealed");
	TexturePack::LoadTexture("flag");
	block.setTexture(TexturePack::GetTexture("tile_revealed"));
	flag.setTexture(TexturePack::GetTexture("flag"));
	blocked = true;
	flagged = false;
}