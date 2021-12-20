#ifndef CRCARFACTORY_

#define CRCARFACTORY_

#include "CRCAR.h"
#include "CTRAFFIC.h"

#include <deque>

enum CarType {
	 CAR1, CAR2, RACE, RACE2, AMBULANCE, DELIVERY, DELIVERY2, FIRETRUCK, GARBAGETRUCK, POLICE, LASTTYPE
};

enum CarDir {
	LEFT, RIGHT, LASTDIR
};



class CRCARFACTORY
{
private:
	deque<CROBJECT*> carQueue;
	CarType type;
	CarDir dir;
	bool playing;
public:
	CRCARFACTORY();
	void initCarGame(float mX, float mY, int frac = 1);
	void shiftObject(char UorD);
	void draw(sf::RenderWindow& window);
	void update(float mX, float mY, sf::RenderWindow& window, CTRAFFIC& traffic, int frac = 1);
	CRCAR* createCar(float mX, float mY, int frac = 1);
	deque<CROBJECT*>* getObjQueue();
	int direction();
	int typeSound();
	~CRCARFACTORY();
};


#endif // !CRCARFACTORY_



