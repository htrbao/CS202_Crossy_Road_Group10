#ifndef _CROBJECT_H_

#define _CROBJECT_H_

#include "CASSET.h"

using namespace std;

class CROBJECT {
protected:
	double mX;
	double mY;

	int direction; // 1 - SE or -1 - NW

	sf::Texture texture;
	sf::Sprite sprite;


public:
	CROBJECT();
	CROBJECT(double mX, double mY);
	void shiftObject();
	bool checkOutWindow(sf::RenderWindow& window);
};

#endif // !_CROBJECT_H_
