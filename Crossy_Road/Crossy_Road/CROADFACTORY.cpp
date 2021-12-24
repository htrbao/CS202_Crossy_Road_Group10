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

CROADFACTORY::CROADFACTORY(CRCHARACTER* player)
{
	this->player = player;
	mY = 0;
	mX = 0;
	mY_Origin = Constants::HIDDEN_ROAD_Y / 1.2;
	point = new CPOINTHUD(Constants::pointFont, 40, Constants::SCREEN_WIDTH - 200, 20, -11);
}

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
	point->draw(window);
}

void CROADFACTORY::update(sf::RenderWindow& window)
{
	playSound();
	if (mX > 1500)
	{
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
		point->increaseP();
	}
	for (auto it : roadQueue)
	{
		it->update(window);
		if (player->isNearRoad(*it))
		{
			addSound(*it);
			//it->getObjFac(); get objDeque
			//it->getObjFac2(); if not highway, it will be nullptr
		}
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

void CROADFACTORY::save(ofstream& of)
{
	of.write((char*)&mY, sizeof(mY));
	of.write((char*)&mX, sizeof(mX));
	of.write((char*)&mY_Origin, sizeof(mY_Origin));
	point->save(of);
	for (auto i : roadQueue)
	{
		i->save(of);
	}

}

void CROADFACTORY::load(ifstream& inf)
{
	inf.read((char*)&mY, sizeof(mY));
	inf.read((char*)&mX, sizeof(mX));
	inf.read((char*)&mY_Origin, sizeof(mY_Origin));
	point->load(inf);
	while (!inf.eof())
	{
		bool is_road, ishighway, special;
		float x, y;
		inf.read((char*)&is_road, sizeof(is_road));
		inf.read((char*)&ishighway, sizeof(ishighway));
		inf.read((char*)&x, sizeof(x));
		inf.read((char*)&y, sizeof(y));
		inf.read((char*)&special, sizeof(special));
		if (is_road)
		{
			roadQueue.push_back(new CLANE(x, y, !ishighway, special));
		}
		else
		{
			roadQueue.push_back(new CGRASS(x, y, special));
		}
	}
}

CROADFACTORY::~CROADFACTORY()
{
	for (auto it : roadQueue)
	{
		it->~CROAD();
		delete it;
	}
	delete point;
}
