#ifndef CROADFACTORY_

#define CROADFACTORY_


#include "CGRASS.h"
#include "CLANE.h"
#include "CRCHARACTER.h"
#include <deque>
#include <random>

enum RoadType {
	LANE, GRASS, LAST
};

class CROADFACTORY {
private:
	deque<CROAD*> roadQueue;
	CRCHARACTER* player;
	float mY;
	float mY_Origin;
	int meter;
public:

	void initRoadGame(CRCHARACTER* player);

	void shiftObject(char UorD);
	void draw(sf::RenderWindow& window);
	void update(sf::RenderWindow& window);
	CROAD* createRoad(sf::Vector2f pos, bool is_road = false);
	CROAD* createRoad(float index = 1, bool is_road = false);
	~CROADFACTORY();
};

#endif // !CROADFACTORY_
