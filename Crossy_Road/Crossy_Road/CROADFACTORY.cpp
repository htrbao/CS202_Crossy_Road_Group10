#include "CROADFACTORY.h"


void CROADFACTORY::processSoundQ(CROAD& it, int val)
{
	sf::Sound tmp = sf::Sound(CASSET::GetInstance().soundMap[Constants::SOUNDNAME[val]]);
	
	if (val == 3)
		tmp.setVolume(2);
	else if (val == 2)
	{
		tmp.setVolume(50);
	}
	else if (val == 1)
	{
		tmp.setVolume(50);
	}
	else
	{
		tmp.setVolume(8);
	}
	soundQueue.push(tmp);
	soundQueue.back().play();
}

void CROADFACTORY::initRoadGame(CRCHARACTER* player)
{
	this->player = player;
	bool is_road = false;
	while (CROAD::getNumRoads() <= Constants::MAX_ROAD)
	{
		roadQueue.push_front(createRoad(Constants::MAX_ROAD - CROAD::getNumRoads(),is_road));
		is_road = roadQueue.front()->is_road();
	}
	mY = 0;
	mX = 0;
	mY_Origin = Constants::HIDDEN_ROAD_Y / 1.2;
	meter = -12;
}

void CROADFACTORY::shiftObject(char UorD)
{
	if (UorD == 'U' || UorD == 'u')
	{
		mY += Constants::shiftVelocityX * tan(Constants::Beta);
		if (mY > mY_Origin)
			mY_Origin = mY;
		for (auto it : roadQueue)
		{
			it->shiftObject(UorD);
		}
		mX += Constants::shiftVelocityX/2;
	}
	else if ((UorD == 'D' || UorD == 'd') && ((mY_Origin - mY) <= Constants::HIDDEN_ROAD_Y / 1.2))
	{
		mY -= Constants::shiftVelocityX * tan(Constants::Beta);
		for (auto it : roadQueue)
		{
			it->shiftObject(UorD);
		}
		mX -= Constants::shiftVelocityX/2;
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
	playSound();
	if (mX > 1500)
	{
		cout << 1 << endl;
		roadQueue.push_front(createRoad(roadQueue.front()->getPosition() + sf::Vector2f(130,130*tan(Constants::Alpha)), roadQueue.front()->is_road()));
		roadQueue.front()->draw(window);
		mX = 0;
	}
	if (roadQueue.back()->checkOutWindow(window))
	{
		//roadQueue.push_front(createRoad(-roadQueue.front()->getScale()*2, roadQueue.front()->is_road()));
		roadQueue.push_front(createRoad(roadQueue.front()->getPosition(), roadQueue.front()->is_road()));
		roadQueue.front()->draw(window);
		
		CROAD* tmp = roadQueue.back();
		roadQueue.pop_back();
		tmp->~CROAD();
		delete tmp;
		meter++;
	}
	for (auto it : roadQueue)
	{
		it->update(window);
		if (player->isNearRoand(*it))
		{
			addSound(*it);
			//it->getObjFac(); get objDeque
			//it->getObjFac2(); if not highway, it will be nullptr
		}
		//it->setPlaying();
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

void CROADFACTORY::addSound(CROAD& it)
{
	int val = it.typeSound();
	if (val != -1)
	{
		processSoundQ(it, val);
		it.setPlaying();
		if (it.isHighway())
			processSoundQ(it, it.typeSound2());
		it.setPlaying2();
		if (soundQueue.front().getStatus() == sf::SoundSource::Stopped)
		{
			soundQueue.pop();
		}
	}
}

void CROADFACTORY::playSound()
{

}

CROADFACTORY::~CROADFACTORY()
{
	for (auto it : roadQueue)
	{
		it->~CROAD();
		delete it;
	}
		
}
