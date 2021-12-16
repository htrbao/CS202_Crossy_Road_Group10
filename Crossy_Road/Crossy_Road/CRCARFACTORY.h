#ifndef CRCARFACTORY_

#define CRCARFACTORY_

#include "CROBJECT.h"
#include "CRCAR.h"

#include <deque>

enum CarType {
	AMBULANCE, CAR1, CAR2, DELIVERY, DELIVERY2, FIRETRUCK, GARBAGETRUCK, POLICE, RACE, RACE2, LASTTYPE
};

enum CarDir {
	LEFT, RIGHT, LASTDIR
};

class CRCARFACTORY
{
private:
	deque<CRCAR*> carQueue;
	CarType type;
	CarDir dir;
public:
	CRCARFACTORY();
	void initCarGame(float mX, float mY, int frac = 1);
	void shiftObject(char UorD);
	void draw(sf::RenderWindow& window);
	void update(float mX, float mY, sf::RenderWindow& window, int frac = 1);
	CRCAR* createCar(float mX, float mY, int frac = 1);
	~CRCARFACTORY();
};


#endif // !CRCARFACTORY_



