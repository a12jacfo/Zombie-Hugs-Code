#include "Level_One_Tiles.h"

Level_One_Tiles::Level_One_Tiles()
{
}

Level_One_Tiles::~Level_One_Tiles()
{
}

void Level_One_Tiles::insertTiles(TileVector& mTiles)
{
	//TILE 0
	int x = 0;
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	x++;

	//TILE 1
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	x++;

	//TILE 2
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	x++;

	//TILE 3
	//mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	x++;

	//TILE 4
	//mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	//mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	//mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	//mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	x++;

	//TILE 5
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	//mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	x++;

	//TILE 6
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	x++;

	//TILE 7
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	x++;

	//TILE 8
	//mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	//mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	x++;

	//TILE 9
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	//mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	x++;

	//TILE 10
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	x++;

	//TILE 11
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	//mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	x++;

	//TILE 12
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	//mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	x++;

	//TILE 13
	//mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	x++;

	//TILE 14
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	x++;

	//TILE 15
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 16
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 17
	//mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	//mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 18
	//mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	//mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	//mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	//mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 19
	//mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	//mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	//mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	//mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	//mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	//mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 20
	//mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	//mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	//mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	//mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	//mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	//mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 21
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 22
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	//mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 23
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	//mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	//mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 24
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	//mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	//mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	//mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 25
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	//mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	//mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 26
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 27
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	//mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 28	
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 29
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 30
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 31
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 32
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	//mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	//mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 33
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	//mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 34
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	//mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 35
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 36
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	//mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 37
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	//mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 38
	//mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	//mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	//mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	//mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	//mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	//mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 39
	//mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	//mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	//mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	//mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	//mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	//mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 40
	//mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	//mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	//mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 41
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 42
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	//mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	//mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 43
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	x++;

	//TILE 44
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 45
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	//mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 46
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	//mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 47
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	//mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 48
	//mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	//mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	//mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	//mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	//mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	//mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 49
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	//mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	//mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 50
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	//mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 51
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 52
	//mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 53
	//mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	//mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 54
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	//mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 55
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 56
	//mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	//mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 57
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 58
	//mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 59
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	//mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 60
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 61
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 62
	//mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 63
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	//mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 64
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	//mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	//mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	//mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 65
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	//mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	//mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	//mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 66
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	//mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;
	
	//TILE 67
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	//mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;
	
	//TILE 68
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 69
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	// TILE 70
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	//mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 71
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	//mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 72
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	x++;

	//TILE 73
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	//mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 74
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 75
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	//mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 76
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	//mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	//mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 77
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	//mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 78
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 79
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	//mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 80
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	//mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	//mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 81
	//mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	//mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	//mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	//mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	//mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	//mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 82
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	//mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 83
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	//mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 84
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	//mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 85
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 86
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 87
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	//mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 88
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 89
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	//mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	//mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	//mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 90
	//mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	//mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	//mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	//mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	//mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	//mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 91
	//mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	//mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	//mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	//mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	//mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	//mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 92
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	//mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 93
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	//mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 94
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 95
	//mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 96
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	//mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 97
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	//mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	//mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 98
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 99
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 100
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 101
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	x++;

	//TILE 102
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	//mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	//mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 103
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 104
	//mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	//mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 105
	//mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	//mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	//mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 106
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	//mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	//mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 107
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	//mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 108
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 109
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 110
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	//mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 111
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	//mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 112
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 113
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 114
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x+15)]);
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 115
	mTiles[x]->getVector().push_back(mTiles[(x+14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 116
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 117
	//mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	//mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 118
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	//mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 119
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;
	
	//TILE 120
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 121
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 122
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 123
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;
	
	//TILE 124
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 125
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 126
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	//mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;
	
	//TILE 127
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 128
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x+1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

	//TILE 129
	mTiles[x]->getVector().push_back(mTiles[(x-14)]);
	mTiles[x]->getVector().push_back(mTiles[(x-1)]);
	mTiles[x]->getVector().push_back(mTiles[(x-15)]);
	x++;

}
