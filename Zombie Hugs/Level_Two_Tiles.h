#pragma once

#include <vector>
#include "Tile.h"

class Level_Two_Tiles
{
public:
	typedef std::vector<Tile*> TileVector;
	Level_Two_Tiles();
	~Level_Two_Tiles();
	static void insertTiles(TileVector& mTiles);
};

