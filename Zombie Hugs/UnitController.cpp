#include "UnitController.h"


UnitController::UnitController()
{
}


UnitController::~UnitController()
{
}

void UnitController::update()
{
	//sf::Vector2f lengthVec;
	//sf::Vector2f normal;
	//float length;

	//if(mActive == true && AbilityManager::getActiveMoveAbility() == true && (AbilityManager::getNewPos().x - mPos.x) != 0)
	//{
	//	m_Unit_is_Walking = true;
	//	for(TileVector::size_type t = 0; t < mCurrentTile->getVector().size(); t++)
	//	{
	//		if(mCurrentTile->getVector()[t]->getOccupied()==false)
	//		{
	//			mCurrentTile->getVector()[t]->setDeactive();
	//		}
	//	}

	//	lengthVec = sf::Vector2f((AbilityManager::getNewPos().x - mPos.x),(AbilityManager::getNewPos().y - mPos.y));
	//	float dx = (lengthVec.x * lengthVec.x);
	//	float dy = (lengthVec.y * lengthVec.y);
	//	float d = (dx + dy);
	//	length = sqrt(d);

	//	normal = sf::Vector2f((lengthVec.x/length),(lengthVec.y/length));

	//	mPos = mPos + normal;

	//	if(length <= 1)
	//	{
	//		length = 0;
	//		setPos(AbilityManager::getNewPos());
	//	}

	//	if(lengthVec.x > 0 && lengthVec.y < 0) { std::cout << "UPP HÖGER" << std::endl; }
	//	if(lengthVec.x > 0 && lengthVec.y == 0) { std::cout << "HÖGER" << std::endl; }
	//	if(lengthVec.x > 0 && lengthVec.y > 0) { std::cout << "NER HÖGER" << std::endl; }

	//	if(lengthVec.x < 0 && lengthVec.y > 0) { std::cout << "NER VÄNSTER" << std::endl; }
	//	if(lengthVec.x < 0 && lengthVec.y == 0) { std::cout << "VÄNSTER" << std::endl; }
	//	if(lengthVec.x < 0 && lengthVec.y < 0) { std::cout << "UPP VÄNSTER" << std::endl; }

	//if(mActive == true && mPos == AbilityManager::getNewPos())
	//{
	//	std::cout << "KLAR" << std::endl;
	//	for(TileVector::size_type t = 0; t < mCurrentTile->getVector().size(); t++)
	//	{
	//		if(mCurrentTile->getVector()[t]->getOccupied()==false)
	//		{
	//			mCurrentTile->getVector()[t]->setActive();
	//		}
	//	}
	//	m_Unit_is_Walking = false;
	//	mCurrentTile->setOccupied(true);
	//	mCurrentTile->setActive();
	//	setActive();

	//}
	//}
}


