#ifndef CRBLOCKFACTORY_

#define CRBLOCKFACTORY_

#include "CRBLOCK.h"
#include "CRCOIN.h"

#include <random>
#include <deque>

class CRBLOCKFACTORY
{
private:
	deque<CROBJECT*> objQueue;
	int numBLC;
	float dif;
public:
	CRBLOCKFACTORY();
	void initObjGame(float dis, bool init = false);
	void shiftObject(char UorD);
	void draw(sf::RenderWindow& window);
	void update(sf::RenderWindow& window);
	CROBJECT* createObj(float dis, float i, bool init = false);
	~CRBLOCKFACTORY();
};

#endif
