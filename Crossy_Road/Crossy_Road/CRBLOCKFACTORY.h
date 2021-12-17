#include "CRBLOCKFACTORY.h"



CRBLOCKFACTORY::CRBLOCKFACTORY()
{
	numBLC = rand() % 2 + 2;
	dif = (Constants::SCREEN_WIDTH * 1.0f) / numBLC;
}

void CRBLOCKFACTORY::initObjGame(float dis, bool init)
{
	
	float i = 0;
	if (init)
	{	
		numBLC = 5;
		i = -2;
	}
	while (objQueue.size() < numBLC)
	{
		objQueue.push_back(createObj(dis, i, init));
		i+=0.7;
	}
}

void CRBLOCKFACTORY::shiftObject(char UorD)
{
	for (auto i : objQueue)
	{
		i->shiftObject(UorD);
	}
}

void CRBLOCKFACTORY::draw(sf::RenderWindow& window)
{
	for (auto i : objQueue)
	{
		i->draw(window);
	}
}

void CRBLOCKFACTORY::update(sf::RenderWindow& window)
{
	
}



CROBJECT* CRBLOCKFACTORY::createObj(float dis, float i, bool init)
{
	int type = rand() % 13;
	if (init)
		type = 10 + rand() % 3;
	dis -= 12;
	int gap = (rand() % 400 + rand() % 500 + 256);
	float mX = i * gap + Constants::SCREEN_WIDTH/2;
	float mY = mX * tan(Constants::Alpha) + dis;
	if (type > 1)
		return new CRBLOCK(Constants::BLOCKNAME[type], mX, mY);
	else
		return new CRCOIN(Constants::BLOCKNAME[type], mX, mY - 35);
}


CRBLOCKFACTORY::~CRBLOCKFACTORY()
{
	while (!objQueue.empty())
	{
		CROBJECT* tmp = objQueue.front();
		objQueue.pop_front();
		delete tmp;
	}
}
