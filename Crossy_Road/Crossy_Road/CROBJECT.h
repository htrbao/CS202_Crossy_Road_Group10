#ifndef _CROBJECT_H_

#define _CROBJECT_H_

#include "CASSET.h"

using namespace std;

class CROBJECT {
protected:
	friend class CGAME;
	friend class CRCHARACTER;
	double mX;
	double mY;

	bool isVisible;

	double objScale;

	int direction; // 1 - SE or -1 - NW

	int speed;

	sf::Texture* texture;
	sf::Sprite sprite;

	void setUpTexture();
public:
	friend class CROAD;
	friend class CRCHARACTER;

	CROBJECT(double mX, double mY, double scale);
	CROBJECT(double mX, double mY, double scale, int direction);
	void shiftObject(char UorD);
	bool checkOutWindow(sf::RenderWindow& window);
	virtual void setVisible(bool typ);
	virtual int type() = 0;
	virtual void move(float x, float y, float frac = 1);
	virtual void draw(sf::RenderWindow& window);
	sf::Vector2f getPos();
};

#endif // !_CROBJECT_H_
