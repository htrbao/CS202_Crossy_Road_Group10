#include "CROADFACTORY.h"

void CROADFACTORY::initRoadGame()
{
	bool is_road = false;
	while (CROAD::getNumRoads() <= Constants::MAX_ROAD)
	{
		roadQueue.push_front(createRoad(Constants::MAX_ROAD - CROAD::getNumRoads(),is_road));
		is_road = roadQueue.front()->is_road();
	}
}

void CROADFACTORY::shiftObject(char UorD)
{
	for (auto i : roadQueue)
	{
		i->shiftObject(UorD);
	}
}

void CROADFACTORY::draw(sf::RenderWindow& window)
{
	for (auto i : roadQueue)
	{
		i->draw(window);
	}
}

void CROADFACTORY::update(sf::RenderWindow& window)
{
	if (roadQueue.back()->checkOutWindow(window))
	{
		roadQueue.push_front(createRoad(roadQueue.front()->getPosition(), roadQueue.front()->is_road()));
		roadQueue.front()->draw(window);
		CROAD* tmp = roadQueue.back();
		roadQueue.pop_back();
		delete tmp;
		//cout << 1;
	}
}

CROAD* CROADFACTORY::createRoad(sf::Vector2f pos, bool is_road)
{
	Road type = Road(rand() % LAST);
	if (type == LANE)
	{
		bool oneway = rand() % 2;
		if (Constants::MAX_ROAD - CROAD::getNumRoads() == 0.5)
		{
			oneway = true;
		}
		return new CLANE(pos, oneway);
	}
	else
	{
		return new CGRASS(pos, is_road);
	}
}

CROAD* CROADFACTORY::createRoad(float index, bool is_road)
{
	
	Road type = Road(rand() % LAST);
	double diff = 0;
	if (type == LANE)
	{
		bool oneway = rand() % 2;
		if (Constants::MAX_ROAD - CROAD::getNumRoads() == 0.5)
		{
			oneway = true;
		}
		if (oneway)
			diff = 0.5;
		else
			diff = 1;
		return new CLANE(index - diff , oneway);
	}
	else
	{
		diff = 0.5;
		return new CGRASS(index - diff , is_road);
	}
}