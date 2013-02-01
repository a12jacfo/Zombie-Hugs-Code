#pragma once
#include <vector>

class Tile;

class Level_One_Tiles
{
public:
	typedef std::vector<Tile*> TileVector;
	Level_One_Tiles();
	~Level_One_Tiles();
	static void insertTiles(TileVector& mTiles);
};

