#pragma once
#include "CGRASS.h"
#include "CLANE.h"
#include <deque>
#include <random>

enum Road {
	LANE, GRASS, LAST
};

class CROADFACTORY {
	deque<CROAD*> roadQueue;
public:

	void initRoadGame();

	void shiftObject(char UorD);
	void draw(sf::RenderWindow& window);
	void update(sf::RenderWindow& window);
	CROAD* createRoad(sf::Vector2f pos, bool is_road = false);
	CROAD* createRoad(float index = 1, bool is_road = false);
};