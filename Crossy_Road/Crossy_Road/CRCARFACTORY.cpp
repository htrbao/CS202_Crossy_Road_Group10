#include "CRCARFACTORY.h"

CRCARFACTORY::CRCARFACTORY()
{
	type = CarType(rand() % LASTTYPE);
	dir = CarDir(rand() % LASTDIR);
}

void CRCARFACTORY::initCarGame(float mX, float mY, int frac)
{
	while (carQueue.size() < 25)
	{
		carQueue.push_front(createCar(mX, mY, frac));
	}

}

void CRCARFACTORY::shiftObject(char UorD)
{
	for (auto i : carQueue)
	{
		i->shiftObject(UorD);
	}
}

void CRCARFACTORY::draw(sf::RenderWindow& window)
{
	for (auto i : carQueue)
	{
		i->draw(window);
	}
}

void CRCARFACTORY::update(float mX, float mY, sf::RenderWindow& window, int frac)
{
	for (auto i : carQueue)
	{
		i->move(0, 0);
	}
	if (carQueue.empty())
		initCarGame(mX, mY, frac);

	while (!carQueue.empty() && carQueue.back()->checkOutWindow(window))
	{
		
		CRCAR* tmp = carQueue.back();
		carQueue.pop_back();
		delete tmp; 
	}
}

CRCAR* CRCARFACTORY::createCar(float mX, float mY, int frac)
{
	float sign = 1;
	if (dir == LEFT)
	{
		sign = -1;
		while (mX < Constants::SCREEN_WIDTH + 256)
		{
			mX += 10;
			mY += 10 * tan(Constants::Alpha);
		}
		if (!carQueue.empty())
		{
			while (mX  < carQueue.front()->getPosition().x + 612)
			{
				mX += 10;
				mY += 10 * tan(Constants::Alpha);
			}
		}
	}
	else if (dir == RIGHT)
	{
		while (mX  > -256)
		{
			mX -= 10;
			mY -= 10 * tan(Constants::Alpha);
		}
		if (!carQueue.empty())
		{
			while (mX  > carQueue.front()->getPosition().x - 612)
			{
				mX -= 10;
				mY -= 10 * tan(Constants::Alpha);
			}
		}
	}
	return new CRCAR(Constants::CARNAME[type] + Constants::CARDIR[dir], mX, mY , Constants::CARSPEED[type] * 2.5 * frac, dir * 2 - 1);
}

CRCARFACTORY::~CRCARFACTORY()
{
	while (!carQueue.empty())
	{
		CRCAR* tmp = carQueue.front();
		carQueue.pop_front();
		delete tmp;
	}
}
