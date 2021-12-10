#include "CRCARFACTORY.h"

CRCARFACTORY::CRCARFACTORY()
{
	type = CarType(rand() % LASTTYPE);
	dir = CarDir(rand() % LASTDIR);
}

void CRCARFACTORY::initCarGame(float mX, float mY, int frac)
{
	float i = 0;
	while (carQueue.size() < 4)
	{
		carQueue.push_front(createCar(mX, mY, i, frac));
		i -= 0.5;
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
	if (carQueue.empty() < 4)
		initCarGame(mX, mY, frac);
	if (carQueue.front()->checkOutWindow(window))
	{
		
		CRCAR* tmp = carQueue.front();
		carQueue.push_back(createCar(mX, mY, 0, frac));
		if (carQueue.back()->checkOutWindow(window))
		{
			CRCAR* tmp1 = carQueue.back();
			carQueue.pop_back();
			delete tmp1;
		}
		carQueue.pop_front();
		delete tmp; 
	}
}

CRCAR* CRCARFACTORY::createCar(float mX, float mY, float i, int frac)
{
	float sign = 1;
	if (dir == LEFT)
	{
		sign = -1;
		while (mX < Constants::SCREEN_WIDTH)
		{
			mX += 60;
			mY += 60 * tan(Constants::Alpha);
		}
		if (!carQueue.empty())
		{
			while (mX < carQueue.back()->getPosition().x + 512/2)
			{
				mX += 10;
				mY += 10 * tan(Constants::Alpha);
			}
		}
	}
	else if (dir == RIGHT)
	{
		while (mX > 0)
		{
			mX -= 60;
			mY -= 60 * tan(Constants::Alpha);
		}
		if (!carQueue.empty())
		{
			while (mX > carQueue.back()->getPosition().x - 512/2)
			{
				mX -= 10;
				mY -= 10 * tan(Constants::Alpha);
			}
		}
	}
	return new CRCAR(Constants::CARNAME[type] + Constants::CARDIR[dir], mX - 512 * i * sign, mY - 512 * i * tan(Constants::Alpha) * sign, Constants::CARSPEED[type] * 2.5 * frac, dir * 2 - 1);
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

