#ifndef INCLUDED_ZOMBIECATCHER
#define INCLUDED_ZOMBIECATCHER

#include "GameObject.h"
#include "Animation.h"
#include <string>
#include "SFML\System.hpp"

class Tile;

class ZombieCatcher : public GameObject
{
public:
	typedef std::vector<Tile*> TileVector;
	ZombieCatcher(Tile& tile, std::string name);
	virtual ~ZombieCatcher();
	virtual void update(sf::RenderWindow &window, bool &m_Unit_is_Walking);
private:
	Animation m_GetHealed;
	Animation m_GetDemoed;
	Animation m_GetCatched;
	Animation m_GetStunnedLeft;
	Animation m_GetStunnedRight;
	Animation m_c_GetStunnedLeft;
	Animation m_c_GetStunnedRight;

	Animation m_walkLeft;
	Animation m_walkRight;
	Animation m_walkUpLeft;
	Animation m_walkUpRight;
	Animation m_walkDownLeft;
	Animation m_walkDownRight;

	Animation m_idelLeft;
	Animation m_idelRight;
	Animation m_idelSitLeft;
	Animation m_idelSitRight;
	Animation m_idelStunnedLeft;
	Animation m_idelStunnedRight;

	Animation m_skillCatchDownLeft;
	Animation m_skillCatchDownRight;
	Animation m_skillCatchUpLeft;
	Animation m_skillCatchUpRight;

	//Human
	Animation m_c_walkLeft;
	Animation m_c_walkRight;
	Animation m_c_walkUpLeft;
	Animation m_c_walkUpRight;
	Animation m_c_walkDownLeft;
	Animation m_c_walkDownRight;

	Animation m_c_idelLeft;
	Animation m_c_idelRight;
	Animation m_c_idelSitLeft;
	Animation m_c_idelSitRight;
	Animation m_c_idelStunnedLeft;
	Animation m_c_idelStunnedRight;
};
#endif