#ifndef CROADFACTORY_

#define CROADFACTORY_


#include "CGRASS.h"
#include "CLANE.h"
#include "CRCHARACTER.h"
#include <deque>
#include <queue>
#include <random>

enum RoadType {
	LANE, GRASS, LAST
};

class CROADFACTORY {
private:
	friend class CGAME;
	deque<CROAD*> roadQueue;
	queue<sf::Sound> soundQueue;
	CRCHARACTER* player;
	float mY;
	float mX;
	float mY_Origin;
	int meter;
	void processSoundQ(CROAD& it, int val);
public:

	void initRoadGame(CRCHARACTER* player);

	void shiftObject(char UorD);
	void draw(sf::RenderWindow& window);
	void update(sf::RenderWindow& window);
	CROAD* createRoad(sf::Vector2f pos, bool is_road = false);
	CROAD* createRoad(float index = 1, bool is_road = false);
	void addSound(CROAD& it);
	void playSound();
	~CROADFACTORY();
};

#endif // !CROADFACTORY_
