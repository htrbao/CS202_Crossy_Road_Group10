#include "CRBLOCKFACTORY.h"



CRBLOCKFACTORY::CRBLOCKFACTORY()
{
	numBLC = rand() % 2;
	numTR = rand() % 6 + 6;
	dif = (Constants::SCREEN_WIDTH * 1.0f) / numBLC;
}

void CRBLOCKFACTORY::initObjGame(float mX, float mY, bool init)
{
	if (init)
	{
		numTR = 6;
	}
	int i = 0;
	while (i <= numTR)
	{
		objQueue.push_back(createTR(mX,mY, i, init));
		i++;
	}
	if (!init)
	{
		i = 1;
		while (i <= numBLC)
		{
			objQueue.push_back(createBL(mX, mY, i));
			i++;
		}
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

CROBJECT* CRBLOCKFACTORY::createBL(float mX, float mY, int i, bool init)
{
	int coin = rand() % 50;
	int type = rand() % 10;
	int gap = 100, gaptr = 120, dis = (mX / 512 + 1) * 40;
	if (!init)
		dis += 20;
	if (coin > 3)
	{
		type = rand() % 8 + 2;
	}
	else {
		type = rand() % 2;
	}
	if (type <= 9 && type >= 7)
	{
		gap += 20;
	}
	mX += (numTR / 2) * gaptr + dis + i * gap;
	mY += ((numTR / 2) * gaptr + dis + i * gap) * tan(Constants::Alpha);
	if (coin > 3)
	{
		return new CRBLOCK(Constants::BLOCKNAME[type], mX, mY - 10);
	}
	else
	{
		return new CRCOIN(Constants::BLOCKNAME[type], mX, mY - 42);
	}
}

CROBJECT* CRBLOCKFACTORY::createTR(float mX, float mY, int i, bool init)
{
	int type = 10 + rand() % 3;
	int gap = 120, dis = (mX / 512 + 1) * 40;
	if (!init)
		dis += 20;
	else
		dis = 130;
	if (i < numTR / 2) 
	{
		mX += i * gap + dis;
		mY += (i * gap + dis) * tan(Constants::Alpha);
	}
	else
	{
		mX += Constants::SCREEN_WIDTH + 60 + (i - numTR / 2) * gap;
		mY += (Constants::SCREEN_WIDTH + 60 + (i - numTR / 2) * gap) * tan(Constants::Alpha);
	}
	return new CRTREE(Constants::BLOCKNAME[type], mX, mY, 1);

}

int CRBLOCKFACTORY::typeSound()
{
	return 3;
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
