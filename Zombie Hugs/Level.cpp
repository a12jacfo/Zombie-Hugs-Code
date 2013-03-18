#include "Level.h"

Level::Level(int levelnum) :
	level_id(levelnum)
{
	m_Human_Turn = true;
	m_Unit_is_Walking = false;

	m_Music.setVolume(1.5f);
	m_Music.setLoop(true);

	if(level_id == 1)
	{
		background.setTexture(ImageManager::getInstance()->get_image("Resources/Images/lvl01_grid.png"));
		m_Music.openFromFile("Resources/Audio/Music/Bana_1_Amb.wav");
	}
	else if(level_id == 2)
	{
		background.setTexture(ImageManager::getInstance()->get_image("Resources/Images/lvl01_grid.png"));
		m_Music.openFromFile("Resources/Audio/Music/Bana_1_Amb.wav");
	}
	else if(level_id == 3)
	{	
		background.setTexture(ImageManager::getInstance()->get_image("Resources/Images/lvl01_grid.png"));
		m_Music.openFromFile("Resources/Audio/Music/Bana_1_Amb.wav");
	}
	else if(level_id == 4)
	{
		background.setTexture(ImageManager::getInstance()->get_image("Resources/Images/lvl01_grid.png"));
		m_Music.openFromFile("Resources/Audio/Music/Bana_1_Amb.wav");
	}
	else if(level_id == 5)
	{
		background.setTexture(ImageManager::getInstance()->get_image("Resources/Images/lvl01_grid.png"));
		m_Music.openFromFile("Resources/Audio/Music/Bana_1_Amb.wav");
	}
	background.setPosition(background.getPosition().x+1,background.getPosition().y);

	addTile();
	addNeighbors();

	HumanHero* humanHero = new HumanHero(*mTiles[114], "HHero");
	HumanStunner* humanStunner = new HumanStunner(*mTiles[100], "HStunner");
	HumanCatcher* humanCatcher1 = new HumanCatcher(*mTiles[99], "HCatcher1");
	HumanCatcher* humanCatcher2 = new HumanCatcher(*mTiles[113], "HCatcher2");
	HumanHealer* humanHealer = new HumanHealer(*mTiles[128], "HHealer");
	mHumans.push_back(humanHero);
	mHumans.push_back(humanStunner);
	mHumans.push_back(humanCatcher1);
	mHumans.push_back(humanCatcher2);
	mHumans.push_back(humanHealer);

	ZombieHero* zombieHero = new ZombieHero(*mTiles[15], "ZHero");
	ZombieStunner* zombieStunner = new ZombieStunner(*mTiles[1], "ZStunner");
	ZombieCatcher* zombieCatcher1 = new ZombieCatcher(*mTiles[16], "ZCatcher1");
	ZombieCatcher* zombieCatcher2 = new ZombieCatcher(*mTiles[30], "ZCatcher2");
	ZombieHealer* zombieHealer = new ZombieHealer(*mTiles[29], "ZHealer");
	mZombies.push_back(zombieHero);
	mZombies.push_back(zombieStunner);
	mZombies.push_back(zombieCatcher1);
	mZombies.push_back(zombieCatcher2);
	mZombies.push_back(zombieHealer);


	sf::Vector2f lpos(0,0);
	sf::Vector2f rpos(1185,0);
	leftSide = new SideHUD(lpos, "Zombie");
	rightSide = new SideHUD(rpos, "Human");

	mActiveUnit = 0;

	m_Human_Action_Points = ConfigFile::getInstance()->getValueOfKey<int>("m_Action_Points");
	m_Zombie_Action_Points = ConfigFile::getInstance()->getValueOfKey<int>("m_Action_Points");

	m_Music.play();
}

Level::~Level()
{
	m_Music.stop();

	while(!mZombies.empty())
	{
		delete mZombies.back();
		mZombies.pop_back();
	}
	while(!mHumans.empty())
	{
		delete mHumans.back();
		mHumans.pop_back();
	}
	while(!mTiles.empty())
	{
		delete mTiles.back();
		mTiles.pop_back();
	}
}

void Level::addTile()
{
	sf::Vector2f pos(171,175);
	sf::Vector2f cord(0,0);
	for(int i = 0; i < 130; i++)
	{
		if(i == 14){ pos.x = 134; pos.y = 229; cord.x = 0; cord.y = 1;} // RAD 2
		if(i == 29){ pos.x = 170; pos.y = 283; cord.x = 0; cord.y = 2;} // RAD 3
		if(i == 43){ pos.x = 134; pos.y = 337; cord.x = 0; cord.y = 3;} // RAD 4
		if(i == 58){ pos.x = 170; pos.y = 391; cord.x = 0; cord.y = 4;} // RAD 5
		if(i == 72){ pos.x = 134; pos.y = 445; cord.x = 0; cord.y = 5;} // RAD 6
		if(i == 87){ pos.x = 170; pos.y = 499; cord.x = 0; cord.y = 6;} // RAD 7
		if(i == 101){ pos.x = 134; pos.y = 553; cord.x = 0; cord.y = 7;} // RAD 8
		if(i == 116){ pos.x = 170; pos.y = 607; cord.x = 0; cord.y = 8;} // RAD 9
		if(i == 130){ pos.x = 134; pos.y = 661; cord.x = 0; cord.y = 9;} // RAD 10
		if(i == 145){ pos.x = 170; pos.y = 715; cord.x = 0; cord.y = 10;} // RAD 11
	
		Tile* tile;
		if(i == 0 ||i == 14||i == 15)
		{
			tile = new Tile(pos,cord, "zh");
		}
		else if(i == 115 ||i == 114||i == 129)
		{
			tile = new Tile(pos,cord, "hh");
		}
		else
		{
			tile = new Tile(pos,cord, "");
		}
		mTiles.push_back(tile);
		pos.x = pos.x + 72;
		cord.x = cord.x + 1;
	}
}


void Level::rightMouseClick(sf::RenderWindow& window)
{
	if(m_Unit_is_Walking != true)
	{
		AbilityManager::setAllAbilityToFalse();
		HudManager::getInstance()->HideAbilityHud();

		if(mActiveUnit != 0)
		{
			mActiveUnit->setDeactive();
			mActiveUnit->getCurrentTile().setDeactive();
			mActiveUnit->getCurrentTile().setDeactiveWalls();
		}
		mActiveUnit = 0;
	}
}

void Level::leftMouseClick(sf::RenderWindow& window)
{
	int mPosX = sf::Mouse::getPosition(window).x;
	int mPosY = sf::Mouse::getPosition(window).y;

	if(m_Unit_is_Walking == false)
	{
 		InputManager::update(mActiveUnit,mPosX,mPosY, getHumanVector(), getZombieVector(), getStunnVector(), getHumanTurn(), get_Human_Action_Points(), get_Zombie_Action_Points());
	}
	if(m_Human_Turn == true)
	{
		if(AbilityManager::isAnyAbilityActive() == false)
		{
			for(HumanVector::size_type h = 0; h < mHumans.size(); h++)
			{	
				if(mHumans[h]->getBoundingBox().getGlobalBounds().contains(mPosX,mPosY))
				{
					if(mHumans[h] == mActiveUnit)
					{
						mActiveUnit = mHumans[h];
						HudManager::getInstance()->ShowAbilityHud(*mActiveUnit);
						mActiveUnit->setActive();
						mActiveUnit->SetActiveSound(true);
						break;
					}
					else if(mHumans[h] != mActiveUnit)
					{
						if(mActiveUnit != 0)
						{
							mActiveUnit->setDeactive();
							mActiveUnit->getCurrentTile().setDeactive();
							mActiveUnit->getCurrentTile().setDeactiveWalls();
							HudManager::getInstance()->getAbilityVector().clear();
							mActiveUnit->SetActiveSound(false);
						}

						mActiveUnit = mHumans[h];
						HudManager::getInstance()->ShowAbilityHud(*mActiveUnit);
						mActiveUnit->getCurrentTile().setActive();
						mActiveUnit->setActive();
						mActiveUnit->SetActiveSound(true);
						break;
					}
				}
			}
		} // HUMAN END
	}
	if(m_Human_Turn == false)
	{
		if(AbilityManager::isAnyAbilityActive() == false)
		{
			for(ZombieVector::size_type h = 0; h < mZombies.size(); h++)
			{
				if(mZombies[h]->getBoundingBox().getGlobalBounds().contains(mPosX,mPosY))
				{
					if(mZombies[h] == mActiveUnit)
					{
						mActiveUnit = mZombies[h];
						HudManager::getInstance()->ShowAbilityHud(*mActiveUnit);
						mActiveUnit->setActive();
						mActiveUnit->SetActiveSound(true);
						break;
					}
					else if(mZombies[h] != mActiveUnit)
					{
						if(mActiveUnit != 0)
						{
							mActiveUnit->setDeactive();
							mActiveUnit->getCurrentTile().setDeactive();
							mActiveUnit->getCurrentTile().setDeactiveWalls();
							HudManager::getInstance()->getAbilityVector().clear();
							mActiveUnit->SetActiveSound(false);
						}
						mActiveUnit = mZombies[h];
						HudManager::getInstance()->ShowAbilityHud(*mActiveUnit);
						mActiveUnit->getCurrentTile().setActive();
						mActiveUnit->setActive();
						mActiveUnit->SetActiveSound(true);
						break;
					}
				}

			}
		}
	}
}

void Level::run(sf::RenderWindow& window)
{
	window.draw(background);

	rightSide->update(window, m_Human_Action_Points, mHumans, mZombies);
	leftSide->update(window, m_Zombie_Action_Points, mHumans, mZombies);

	int humanTeamDown = 0;
	int zombieTeamDown = 0;
	for(HumanVector::size_type t = 0; t< mHumans.size(); t++)
	{
		if(mHumans[t]->getCurrentTile().getHomeBaseHuman() == true && mHumans[t]->getConverted() == true)
		{
			if(mHumans[t]->getGameObjectCategory() == GameObject::HERO)
			{
				m_Human_InGame_Score = 3;
			}
			else
			{
				m_Human_InGame_Score++;
			}
		}
		if(mHumans[t]->getMorale() == 0)
		{
			humanTeamDown++;
		}
		if(humanTeamDown == mHumans.size()-1)
		{
			m_Zombie_InGame_Score = 3;
		}
	}
	for(ZombieVector::size_type t = 0; t< mZombies.size(); t++)
	{
		if(mZombies[t]->getCurrentTile().getHomeBaseZombie() == true && mZombies[t]->getConverted() == true)
		{
			if(mZombies[t]->getGameObjectCategory() == GameObject::HERO)
			{
				m_Zombie_InGame_Score = 3;
			}
			else
			{
				m_Zombie_InGame_Score++;
			}
		}
		if(mZombies[t]->getMorale() == 0)
		{
			zombieTeamDown++;
		}
		if(zombieTeamDown == mZombies.size()-1)
		{
			m_Human_InGame_Score = 3;
		}
	}

	for(TileVector::size_type i = 0; i < mTiles.size(); i++)
	{
		mTiles[i]->update(window);
	}

	for(StunnVector::size_type i = 0; i < mStunns.size(); i++)
	{
		mStunns[i]->update(window);
	}

	for(HumanVector::size_type i = 0; i < mHumans.size(); i++) 
	{ if(mTiles[0]->getPos().y == mHumans[i]->getCurrentTile().getPos().y) { mHumans[i]->update(window, m_Unit_is_Walking);} }
	for(ZombieVector::size_type i = 0; i < mZombies.size(); i++) 
	{ if(mTiles[0]->getPos().y == mZombies[i]->getCurrentTile().getPos().y) { mZombies[i]->update(window, m_Unit_is_Walking); } }

	for(HumanVector::size_type i = 0; i < mHumans.size(); i++) 
	{ if(mTiles[14]->getPos().y == mHumans[i]->getCurrentTile().getPos().y) { mHumans[i]->update(window, m_Unit_is_Walking);} }
	for(ZombieVector::size_type i = 0; i < mZombies.size(); i++) 
	{ if(mTiles[14]->getPos().y == mZombies[i]->getCurrentTile().getPos().y) { mZombies[i]->update(window, m_Unit_is_Walking); } } 

	for(HumanVector::size_type i = 0; i < mHumans.size(); i++) 
	{ if(mTiles[29]->getPos().y == mHumans[i]->getCurrentTile().getPos().y) { mHumans[i]->update(window, m_Unit_is_Walking);} }
	for(ZombieVector::size_type i = 0; i < mZombies.size(); i++) 
	{ if(mTiles[29]->getPos().y == mZombies[i]->getCurrentTile().getPos().y) { mZombies[i]->update(window, m_Unit_is_Walking); } }

	for(HumanVector::size_type i = 0; i < mHumans.size(); i++) 
	{ if(mTiles[43]->getPos().y == mHumans[i]->getCurrentTile().getPos().y) { mHumans[i]->update(window, m_Unit_is_Walking);} }
	for(ZombieVector::size_type i = 0; i < mZombies.size(); i++) 
	{ if(mTiles[43]->getPos().y == mZombies[i]->getCurrentTile().getPos().y) { mZombies[i]->update(window, m_Unit_is_Walking); } }

	for(HumanVector::size_type i = 0; i < mHumans.size(); i++) 
	{ if(mTiles[58]->getPos().y == mHumans[i]->getCurrentTile().getPos().y) { mHumans[i]->update(window, m_Unit_is_Walking);} }
	for(ZombieVector::size_type i = 0; i < mZombies.size(); i++) 
	{ if(mTiles[58]->getPos().y == mZombies[i]->getCurrentTile().getPos().y) { mZombies[i]->update(window, m_Unit_is_Walking); } }

	for(HumanVector::size_type i = 0; i < mHumans.size(); i++) 
	{ if(mTiles[72]->getPos().y == mHumans[i]->getCurrentTile().getPos().y) { mHumans[i]->update(window, m_Unit_is_Walking);} }
	for(ZombieVector::size_type i = 0; i < mZombies.size(); i++) 
	{ if(mTiles[72]->getPos().y == mZombies[i]->getCurrentTile().getPos().y) { mZombies[i]->update(window, m_Unit_is_Walking); } }

	for(HumanVector::size_type i = 0; i < mHumans.size(); i++) 
	{ if(mTiles[87]->getPos().y == mHumans[i]->getCurrentTile().getPos().y) { mHumans[i]->update(window, m_Unit_is_Walking);} }
	for(ZombieVector::size_type i = 0; i < mZombies.size(); i++) 
	{ if(mTiles[87]->getPos().y == mZombies[i]->getCurrentTile().getPos().y) { mZombies[i]->update(window, m_Unit_is_Walking); } }

	for(HumanVector::size_type i = 0; i < mHumans.size(); i++) 
	{ if(mTiles[101]->getPos().y == mHumans[i]->getCurrentTile().getPos().y) { mHumans[i]->update(window, m_Unit_is_Walking);} }
	for(ZombieVector::size_type i = 0; i < mZombies.size(); i++) 
	{ if(mTiles[101]->getPos().y == mZombies[i]->getCurrentTile().getPos().y) { mZombies[i]->update(window, m_Unit_is_Walking); } }

	for(HumanVector::size_type i = 0; i < mHumans.size(); i++) 
	{ if(mTiles[116]->getPos().y == mHumans[i]->getCurrentTile().getPos().y) { mHumans[i]->update(window, m_Unit_is_Walking);} }
	for(ZombieVector::size_type i = 0; i < mZombies.size(); i++) 
	{ if(mTiles[116]->getPos().y == mZombies[i]->getCurrentTile().getPos().y) { mZombies[i]->update(window, m_Unit_is_Walking);} }

	HudManager::getInstance()->update(window, getHumanTurn(), get_Human_Action_Points(), get_Zombie_Action_Points(), getHumanIngameScore(), getZombieIngameScore());

	if(m_Human_InGame_Score >= 3)
	{
		sf::RectangleShape re;
		sf::Vector2f l(window.getSize().x,window.getSize().y);
		re.setSize(l);
		re.setFillColor(sf::Color::Black);
		window.draw(re);
	}
	if(m_Zombie_InGame_Score >= 3)
	{
		sf::RectangleShape re;
		sf::Vector2f l(window.getSize().x,window.getSize().y);
		re.setSize(l);
		re.setFillColor(sf::Color::Green);
		window.draw(re);
	}
	m_Zombie_InGame_Score = 0;
	m_Human_InGame_Score = 0;
}

void Level::addNeighbors()
{
	if(level_id == 1)
		Level_One_Tiles::insertTiles(getTileVector());
	if(level_id == 2)
		Level_Two_Tiles::insertTiles(getTileVector());
}

GameState* Level::switchState(GameState* state)
{
	//if(mAnyKeyPressed == true)
	//{
	//	std::cout <<"hfrj"<<std::endl;
	//	delete state;
	//	state= new MainMenu(); 
	//}
	return state;
}