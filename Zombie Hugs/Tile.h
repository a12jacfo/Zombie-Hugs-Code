#pragma once
#include "SFML\Graphics.hpp"
#include <vector>

class Tile
{
public:
	typedef std::vector<Tile*> Walls;
	Tile(sf::Vector2f position, sf::Vector2f coordinate, sf::String home);
	~Tile();
	void update(sf::RenderWindow& window);
	bool getActive();
	void setActive();
	void setDeactive();
	void setDeactiveWalls();
	void setActiveWalls();
	bool getHomeBaseZombie();
	bool getHomeBaseHuman();
	sf::Vector2f getCoordinate();
	sf::Vector2f getPos();
	sf::Color changeColor(sf::Color);
	Walls& getVector();
	void setOccupied(bool occupied);
	bool getOccupied();
	sf::ConvexShape getHex();
private:
	sf::ConvexShape hex;
	bool mActive;
	bool mOccupied;
	bool mHumanHome;
	bool mZombieHome;
	sf::Vector2f mCoordinate;
	sf::Vector2f mPos;
	sf::Color mTileLineColor;	
	sf::Color mTileColor;
	Walls mWalls;
};