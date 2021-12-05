#include "CRCARFACTORY.h"

CRCARFACTORY::CRCARFACTORY()
{
	type = CarType(rand() % LASTTYPE);
	dir = CarDir(rand() % LASTDIR);
}

void CRCARFACTORY::initCarGame(float mX, float mY, int frac)
{
	float i = 0;
	while (carQueue.size() < 2)
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
	if (carQueue.empty())
		initCarGame(mX, mY, frac);
	
	if (carQueue.front()->checkOutWindow(window))
	{
		
		CRCAR* tmp = carQueue.front();
		carQueue.push_back(createCar(mX, mY, 0.5, frac));
		carQueue.pop_front();
		delete tmp; 
	}
}

CRCAR* CRCARFACTORY::createCar(float mX, float mY, float i, int frac)
{
	float sign = 1;
	if (dir == LEFT)
	{
		mX += 1024;
		mY += 1024 * tan(Constants::Alpha);
		sign = -1;
	}
	return new CRCAR(Constants::CARNAME[type] + Constants::CARDIR[dir], mX - Constants::CARSPEED[type] * 9.5 * i * sign, mY - Constants::CARSPEED[type] * 9.5 * i * tan(Constants::Alpha) * sign, Constants::CARSPEED[type] * 2 * frac, dir*2 - 1);
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

