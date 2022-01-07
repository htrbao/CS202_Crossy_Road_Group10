#ifndef _CTRAFFIC_H_
#define _CTRAFFIC_H_

#include "CASSET.h"
#include <random>


class CTRAFFIC
{
private:
	int WIDTH = 48, HEIGHT = 213;
	float mX;
	float mY;
	float diff;
	int status;
	bool hasTraff;
	sf::Clock clc;
	sf::Texture* texture;
	sf::Sprite sprite;
	void setUpTexture();
public:
	CTRAFFIC();
	CTRAFFIC(float x, float y);
	int statusTraffic();
	void red();
	void yellow();
	void green();
	void update(sf::RenderWindow& window);
	void draw(sf::RenderWindow& window);
	void shiftObject(char UorD);
	bool hasTraffic();
};

#endif // !_CTRAFFIC_H_


