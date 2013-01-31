#pragma once
#include "SFML\Graphics.hpp"
#include <vector>

class Tile
{
public:
	typedef std::vector<Tile*> Walls;
	Tile(sf::Vector2f position, int x);
	~Tile();
	void update(sf::RenderWindow& window);
	bool getActive();
	void setActive();
	void setDeactive();
	sf::Vector2f getPos();
	sf::Color changeColor(sf::Color);
	Walls& getVector();
	void setOccupied(bool occupied);
	bool getOccupied();
	sf::ConvexShape getHex();
	int getNR();
private:
	sf::ConvexShape hex;
	bool mActive;
	bool mOccupied;
	sf::Vector2f mPos;
	sf::Color mTileLineColor;	
	sf::Color mTileColor;
	Walls mWalls;
	int nr;
};