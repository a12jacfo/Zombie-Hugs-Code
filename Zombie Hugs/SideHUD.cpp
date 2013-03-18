#include "SideHUD.h"
#include <sstream>
#include <iostream>
#include "ImageManager.h"


SideHUD::SideHUD(sf::Vector2f pos, std::string typ) :
mPos(pos), mSize(95,720), mTyp(typ)
{
	ap_Count.setCharacterSize(15);
	ap_Count.setPosition(mPos.x+15,mPos.y+10);
	ap_Count.setColor(sf::Color::Black);
	for(int i = 0; i<10;i++)
	{
		mUnits.push_back(mUnit);
		int ypos = (((i+1)*35)+10);
		mUnits[i].setPosition(mPos.x+15,mPos.y+ypos);
		mUnits[i].setCharacterSize(15);
	}
		hmorale.setTexture(ImageManager::getInstance()->get_image("Resources/Images/H_moral_bar.png"));
		zmorale.setTexture(ImageManager::getInstance()->get_image("Resources/Images/Z_moral_bar.png"));
		sf::Vector2f s(80,12);
		cont.setSize(s);
		cont.setFillColor(sf::Color::Black);
}
SideHUD::~SideHUD()
{
	

}

void SideHUD::update(sf::RenderWindow &window, int &ap, HumanVector &humans, ZombieVector &zombies)
{
	std::stringstream ss;
    ss << ap;
    ap_Count.setString("AP Left\n\t" + ss.str());
	rect.setSize(mSize);
	rect.setPosition(mPos);
	rect.setFillColor(sf::Color::White);
	window.draw(rect);
	window.draw(ap_Count);
	for(UnitVector::size_type c = 0; c<mUnits.size(); c++)
	{
		mUnits[c].setString("");
	}
	if(mTyp == "Human")
	{
		for(HumanVector::size_type i = 0; i< humans.size();i++)
		{
			if(humans[i]->getName()== "HHero")
			{
				ss.clear();
				ss.str("");
				ss<<humans[i]->getMorale();
				mUnits[0].setString(humans[i]->getName());
				
				cont.setPosition(mUnits[0].getPosition().x-12,mUnits[0].getPosition().y+18);
				hmorale.setPosition(mUnits[0].getPosition().x-10,mUnits[0].getPosition().y+20);
				
				float scalefactor = ((float)humans[i]->getMorale()/100);
				hmorale.setScale(scalefactor,1);
				window.draw(cont);
				window.draw(hmorale);
				if(humans[i]->getActive() == true)
				{
					mUnits[0].setColor(sf::Color::Green);
				}
				else
				{
					mUnits[0].setColor(sf::Color::Black);
				}
			}
			else if(humans[i]->getName()== "HCatcher1")
			{
				ss.clear();
				ss.str("");
				ss<<humans[i]->getMorale();
				mUnits[1].setString(humans[i]->getName());
				cont.setPosition(mUnits[1].getPosition().x-12,mUnits[1].getPosition().y+18);
				hmorale.setPosition(mUnits[1].getPosition().x-10,mUnits[1].getPosition().y+20);
				float scalefactor = ((float)humans[i]->getMorale()/100);
				hmorale.setScale(scalefactor,1);
				window.draw(cont);
				window.draw(hmorale);
				if(humans[i]->getActive() == true)
				{
					mUnits[1].setColor(sf::Color::Green);
				}
				else
				{
					mUnits[1].setColor(sf::Color::Black);
				}
			}
			else if(humans[i]->getName()== "HCatcher2")
			{
				ss.clear();
				ss.str("");
				ss<<humans[i]->getMorale();
				mUnits[2].setString(humans[i]->getName());
				cont.setPosition(mUnits[2].getPosition().x-12,mUnits[2].getPosition().y+18);
				hmorale.setPosition(mUnits[2].getPosition().x-10,mUnits[2].getPosition().y+20);
				float scalefactor = ((float)humans[i]->getMorale()/100);
				hmorale.setScale(scalefactor,1);
				window.draw(cont);
				window.draw(hmorale);
				if(humans[i]->getActive() == true)
				{
					mUnits[2].setColor(sf::Color::Green);
				}
				else
				{
					mUnits[2].setColor(sf::Color::Black);
				}
			}
			else if(humans[i]->getName()== "HHealer")
			{
				ss.clear();
				ss.str("");
				ss<<humans[i]->getMorale();
				mUnits[3].setString(humans[i]->getName());
				cont.setPosition(mUnits[3].getPosition().x-12,mUnits[3].getPosition().y+18);
				hmorale.setPosition(mUnits[3].getPosition().x-10,mUnits[3].getPosition().y+20);
				float scalefactor = ((float)humans[i]->getMorale()/100);
				hmorale.setScale(scalefactor,1);
				window.draw(cont);
				window.draw(hmorale);
				if(humans[i]->getActive() == true)
				{
					mUnits[3].setColor(sf::Color::Green);
				}
				else
				{
					mUnits[3].setColor(sf::Color::Black);
				}
			}
			else if(humans[i]->getName()== "HStunner")
			{
				ss.clear();
				ss.str("");
				ss<<humans[i]->getMorale();
				mUnits[4].setString(humans[i]->getName());
				cont.setPosition(mUnits[4].getPosition().x-12,mUnits[4].getPosition().y+18);
				hmorale.setPosition(mUnits[4].getPosition().x-10,mUnits[4].getPosition().y+20);
				float scalefactor = ((float)humans[i]->getMorale()/100);
				hmorale.setScale(scalefactor,1);
				window.draw(cont);
				window.draw(hmorale);
				if(humans[i]->getActive() == true)
				{
					mUnits[4].setColor(sf::Color::Green);
				}
				else
				{
					mUnits[4].setColor(sf::Color::Black);
				}
			}
			else if(humans[i]->getName()== "ZHero")
			{
				ss.clear();
				ss.str("");
				ss<<humans[i]->getMorale();
				mUnits[5].setString(humans[i]->getName());
				cont.setPosition(mUnits[5].getPosition().x-12,mUnits[5].getPosition().y+18);
				hmorale.setPosition(mUnits[5].getPosition().x-10,mUnits[5].getPosition().y+20);
				float scalefactor = ((float)humans[i]->getMorale()/100);
				hmorale.setScale(scalefactor,1);
				window.draw(cont);
				window.draw(hmorale);
				if(humans[i]->getActive() == true)
				{
					mUnits[5].setColor(sf::Color::Green);
				}
				else
				{
					mUnits[5].setColor(sf::Color::Black);
				}
			}
			else if(humans[i]->getName()== "ZCatcher1")
			{
				ss.clear();
				ss.str("");
				ss<<humans[i]->getMorale();
				mUnits[6].setString(humans[i]->getName());
				cont.setPosition(mUnits[6].getPosition().x-12,mUnits[6].getPosition().y+18);
				hmorale.setPosition(mUnits[6].getPosition().x-10,mUnits[6].getPosition().y+20);
				float scalefactor = ((float)humans[i]->getMorale()/100);
				hmorale.setScale(scalefactor,1);
				window.draw(cont);
				window.draw(hmorale);
				if(humans[i]->getActive() == true)
				{
					mUnits[6].setColor(sf::Color::Green);
				}
				else
				{
					mUnits[6].setColor(sf::Color::Black);
				}
			}
			else if(humans[i]->getName()== "ZCatcher2")
			{
				ss.clear();
				ss.str("");
				ss<<humans[i]->getMorale();
				mUnits[7].setString(humans[i]->getName());
				cont.setPosition(mUnits[7].getPosition().x-12,mUnits[7].getPosition().y+18);
				hmorale.setPosition(mUnits[7].getPosition().x-10,mUnits[7].getPosition().y+20);
				float scalefactor = ((float)humans[i]->getMorale()/100);
				hmorale.setScale(scalefactor,1);
				window.draw(cont);
				window.draw(hmorale);
				if(humans[i]->getActive() == true)
				{
					mUnits[7].setColor(sf::Color::Green);
				}
				else
				{
					mUnits[7].setColor(sf::Color::Black);
				}
			}
			else if(humans[i]->getName()== "ZHealer")
			{
				ss.clear();
				ss.str("");
				ss<<humans[i]->getMorale();
				mUnits[8].setString(humans[i]->getName());
				cont.setPosition(mUnits[9].getPosition().x-12,mUnits[9].getPosition().y+18);
				hmorale.setPosition(mUnits[9].getPosition().x-10,mUnits[9].getPosition().y+20);
				float scalefactor = ((float)humans[i]->getMorale()/100);
				hmorale.setScale(scalefactor,1);
				window.draw(cont);
				window.draw(hmorale);
				if(humans[i]->getActive() == true)
				{
					mUnits[8].setColor(sf::Color::Green);
				}
				else
				{
					mUnits[8].setColor(sf::Color::Black);
				}
			}
			else if(humans[i]->getName()== "ZStunner")
			{
				ss.clear();
				ss.str("");
				ss<<humans[i]->getMorale();
				mUnits[9].setString(humans[i]->getName());
				cont.setPosition(mUnits[9].getPosition().x-12,mUnits[9].getPosition().y+18);
				hmorale.setPosition(mUnits[9].getPosition().x-10,mUnits[9].getPosition().y+20);
				float scalefactor = ((float)humans[i]->getMorale()/100);
				hmorale.setScale(scalefactor,1);
				window.draw(cont);
				window.draw(hmorale);
				if(humans[i]->getActive() == true)
				{
					mUnits[9].setColor(sf::Color::Green);
				}
				else
				{
					mUnits[9].setColor(sf::Color::Black);
				}

			}		
		}
	}
	else
	{

		for(ZombieVector::size_type i = 0; i< zombies.size();i++)
		{
			if(zombies[i]->getName()== "ZHero")
			{
				ss.clear();
				ss.str("");
				ss<<zombies[i]->getMorale();
				mUnits[0].setString(zombies[i]->getName());
				cont.setPosition(mUnits[0].getPosition().x-12,mUnits[0].getPosition().y+18);
				zmorale.setPosition(mUnits[0].getPosition().x-10,mUnits[0].getPosition().y+20);
				float scalefactor = ((float)zombies[i]->getMorale()/100);
				zmorale.setScale(scalefactor,1);
				window.draw(cont);
				window.draw(zmorale);
				if(zombies[i]->getActive() == true)
				{
					mUnits[0].setColor(sf::Color::Green);
				}
				else
				{
					mUnits[0].setColor(sf::Color::Black);
				}
			}
			else if(zombies[i]->getName()== "ZCatcher1")
			{
				ss.clear();
				ss.str("");
				ss<<zombies[i]->getMorale();
				mUnits[1].setString(zombies[i]->getName());
				cont.setPosition(mUnits[1].getPosition().x-12,mUnits[1].getPosition().y+18);
				zmorale.setPosition(mUnits[1].getPosition().x-10,mUnits[1].getPosition().y+20);
				float scalefactor = ((float)zombies[i]->getMorale()/100);
				zmorale.setScale(scalefactor,1);
				window.draw(cont);
				window.draw(zmorale);
				if(zombies[i]->getActive() == true)
				{
					mUnits[1].setColor(sf::Color::Green);
				}
				else
				{
					mUnits[1].setColor(sf::Color::Black);
				}
			}
			else if(zombies[i]->getName()== "ZCatcher2")
			{
				ss.clear();
				ss.str("");
				ss<<zombies[i]->getMorale();
				mUnits[2].setString(zombies[i]->getName());
				cont.setPosition(mUnits[2].getPosition().x-12,mUnits[2].getPosition().y+18);
				zmorale.setPosition(mUnits[2].getPosition().x-10,mUnits[2].getPosition().y+20);
				float scalefactor = ((float)zombies[i]->getMorale()/100);
				zmorale.setScale(scalefactor,1);
				window.draw(cont);
				window.draw(zmorale);
				if(zombies[i]->getActive() == true)
				{
					mUnits[2].setColor(sf::Color::Green);
				}
				else
				{
					mUnits[2].setColor(sf::Color::Black);
				}
			}
			else if(zombies[i]->getName()== "ZHealer")
			{
				ss.clear();
				ss.str("");
				ss<<zombies[i]->getMorale();
				mUnits[3].setString(zombies[i]->getName());
				cont.setPosition(mUnits[3].getPosition().x-12,mUnits[3].getPosition().y+18);
				zmorale.setPosition(mUnits[3].getPosition().x-10,mUnits[3].getPosition().y+20);
				float scalefactor = ((float)zombies[i]->getMorale()/100);
				zmorale.setScale(scalefactor,1);
				window.draw(cont);
				window.draw(zmorale);
				if(zombies[i]->getActive() == true)
				{
					mUnits[3].setColor(sf::Color::Green);
				}
				else
				{
					mUnits[3].setColor(sf::Color::Black);
				}
			}
			else if(zombies[i]->getName()== "ZStunner")
			{
				ss.clear();
				ss.str("");
				ss<<zombies[i]->getMorale();
				mUnits[4].setString(zombies[i]->getName());
				cont.setPosition(mUnits[4].getPosition().x-12,mUnits[4].getPosition().y+18);
				zmorale.setPosition(mUnits[4].getPosition().x-10,mUnits[4].getPosition().y+20);
				float scalefactor = ((float)zombies[i]->getMorale()/100);
				zmorale.setScale(scalefactor,1);
				window.draw(cont);
				window.draw(zmorale);
				if(zombies[i]->getActive() == true)
				{
					mUnits[4].setColor(sf::Color::Green);
				}
				else
				{
					mUnits[4].setColor(sf::Color::Black);
				}
			}
			else if(zombies[i]->getName()== "HHero")
			{
				ss.clear();
				ss.str("");
				ss<<zombies[i]->getMorale();
				mUnits[5].setString(zombies[i]->getName());
				cont.setPosition(mUnits[5].getPosition().x-12,mUnits[5].getPosition().y+18);
				zmorale.setPosition(mUnits[5].getPosition().x-10,mUnits[5].getPosition().y+20);
				float scalefactor = ((float)zombies[i]->getMorale()/100);
				zmorale.setScale(scalefactor,1);
				window.draw(cont);
				window.draw(zmorale);
				if(zombies[i]->getActive() == true)
				{
					mUnits[5].setColor(sf::Color::Green);
				}
				else
				{
					mUnits[5].setColor(sf::Color::Black);
				}
			}
			else if(zombies[i]->getName()== "HCatcher1")
			{
				ss.clear();
				ss.str("");
				ss<<zombies[i]->getMorale();
				mUnits[6].setString(zombies[i]->getName());
				cont.setPosition(mUnits[6].getPosition().x-12,mUnits[6].getPosition().y+18);
				zmorale.setPosition(mUnits[6].getPosition().x-10,mUnits[6].getPosition().y+20);
				float scalefactor = ((float)zombies[i]->getMorale()/100);
				zmorale.setScale(scalefactor,1);
				window.draw(cont);
				window.draw(zmorale);
				if(zombies[i]->getActive() == true)
				{
					mUnits[6].setColor(sf::Color::Green);
				}
				else
				{
					mUnits[6].setColor(sf::Color::Black);
				}
			}
			else if(zombies[i]->getName()== "HCatcher2")
			{
				ss.clear();
				ss.str("");
				ss<<zombies[i]->getMorale();
				mUnits[7].setString(zombies[i]->getName());
				cont.setPosition(mUnits[7].getPosition().x-12,mUnits[7].getPosition().y+18);
				zmorale.setPosition(mUnits[7].getPosition().x-10,mUnits[7].getPosition().y+20);
				float scalefactor = ((float)zombies[i]->getMorale()/100);
				zmorale.setScale(scalefactor,1);
				window.draw(cont);
				window.draw(zmorale);
				if(zombies[i]->getActive() == true)
				{
					mUnits[7].setColor(sf::Color::Green);
				}
				else
				{
					mUnits[7].setColor(sf::Color::Black);
				}
			}
			else if(zombies[i]->getName()== "HHealer")
			{
				ss.clear();
				ss.str("");
				ss<<zombies[i]->getMorale();
				mUnits[8].setString(zombies[i]->getName());
				cont.setPosition(mUnits[8].getPosition().x-12,mUnits[8].getPosition().y+18);
				zmorale.setPosition(mUnits[8].getPosition().x-10,mUnits[8].getPosition().y+20);
				float scalefactor = ((float)zombies[i]->getMorale()/100);
				zmorale.setScale(scalefactor,1);
				window.draw(cont);
				window.draw(zmorale);
				if(zombies[i]->getActive() == true)
				{
					mUnits[8].setColor(sf::Color::Green);
				}
				else
				{
					mUnits[8].setColor(sf::Color::Black);
				}
			}
			else if(zombies[i]->getName()== "HStunner")
			{
				ss.clear();
				ss.str("");
				ss<<zombies[i]->getMorale();
				mUnits[9].setString(zombies[i]->getName());
				cont.setPosition(mUnits[9].getPosition().x-12,mUnits[9].getPosition().y+18);
				zmorale.setPosition(mUnits[9].getPosition().x-10,mUnits[9].getPosition().y+20);
				float scalefactor = ((float)zombies[i]->getMorale()/100);
				zmorale.setScale(scalefactor,1);
				window.draw(cont);
				window.draw(zmorale);
				if(zombies[i]->getActive() == true)
				{
					mUnits[9].setColor(sf::Color::Green);
				}
				else
				{
					mUnits[9].setColor(sf::Color::Black);
				}
			}
		}
	}

	
	for(int i = 0; i < mUnits.size();i++)
	{
		window.draw(mUnits[i]);
	}
}