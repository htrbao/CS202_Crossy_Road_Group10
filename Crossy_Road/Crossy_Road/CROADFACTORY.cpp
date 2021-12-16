#include "CROADFACTORY.h"

void CROADFACTORY::initRoadGame(CRCHARACTER* player)
{
	this->player = player;
	bool is_road = false;
	while (CROAD::getNumRoads() <= Constants::MAX_ROAD)
	{
		roadQueue.push_front(createRoad(Constants::MAX_ROAD - CROAD::getNumRoads(),is_road));
		is_road = roadQueue.front()->is_road();
	}
}

void CROADFACTORY::shiftObject(char UorD)
{
	for (auto it : roadQueue)
	{
		it->shiftObject(UorD);
	}
}

void CROADFACTORY::draw(sf::RenderWindow& window)
{
	for (auto it : roadQueue)
	{
		it->draw(window);
		if (!player->isBehindRoad(*it))
		{
			player->render();
		}
		it->drawSubObj(window);
	}
}

void CROADFACTORY::update(sf::RenderWindow& window)
{
	if (roadQueue.front()->checkOutWindow2(window))
	{
		roadQueue.push_front(createRoad(roadQueue.front()->getPosition() + sf::Vector2f(100,100*tan(Constants::Alpha)), roadQueue.front()->is_road()));
		roadQueue.front()->draw(window);
	}
	if (roadQueue.back()->checkOutWindow(window))
	{
		//roadQueue.push_front(createRoad(-roadQueue.front()->getScale()*2, roadQueue.front()->is_road()));
		roadQueue.push_front(createRoad(roadQueue.front()->getPosition(), roadQueue.front()->is_road()));
		roadQueue.front()->draw(window);
		
		CROAD* tmp = roadQueue.back();
		roadQueue.pop_back();
		delete tmp;
	}
	for (auto it : roadQueue)
	{
		it->update(window);
	}
}

CROAD* CROADFACTORY::createRoad(sf::Vector2f pos, bool is_road)
{
	RoadType type = RoadType(rand() % LAST);
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
	
	RoadType type = RoadType(rand() % LAST);
	double diff = 0;
	if (index > 1)
	{
		type = GRASS;
	}
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

CROADFACTORY::~CROADFACTORY()
{
	for (auto it : roadQueue)
	{
		it->~CROAD();
		delete it;
	}
		
}
