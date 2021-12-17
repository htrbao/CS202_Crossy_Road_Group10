#ifndef CRBLOCKFACTORY_

#define CRBLOCKFACTORY_

#include "CRBLOCK.h"
#include "CRCOIN.h"
#include "CRTREE.h"

#include <random>
#include <deque>

class CRBLOCKFACTORY
{
private:
	deque<CROBJECT*> objQueue;
	int numBLC;
	int numTR;
	float dif;
public:
	CRBLOCKFACTORY();
	void initObjGame(float mX, float mY, bool init = false);
	void shiftObject(char UorD);
	void draw(sf::RenderWindow& window);
	void update(sf::RenderWindow& window);
	CROBJECT* createBL(float mX, float mY, int i, bool init = false);
	CROBJECT* createTR(float mX, float mY, int i, bool init = false);
	~CRBLOCKFACTORY();
};

#endif
