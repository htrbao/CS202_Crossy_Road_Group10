#ifndef _CROBJECT_H_

#define _CROBJECT_H_

#include "CASSET.h"
#include "CRCHARACTER.h"

using namespace std;

class CROBJECT {
protected:
	double mX;
	double mY;

	/*sf::SoundBuffer* buffer;
	sf::Sound sound;
	string soundFilename;*/

	double objScale;

	int direction; // 1 - SE or -1 - NW

	int speed;

	sf::Texture* texture;
	sf::Sprite sprite;

	void setUpTexture();
	//void setupSound();
public:
	CROBJECT(double mX, double mY, double scale);
	CROBJECT(double mX, double mY, double scale, int direction);
	void shiftObject(char UorD);
	bool checkOutWindow(sf::RenderWindow& window);
	//virtual bool checkCollision(CRCHARACTER*& player);
	//virtual bool checkClose(CRCHARACTER*& player);
	virtual int type() = 0;
	virtual void move(float x, float y);
	virtual void draw(sf::RenderWindow& window);
	//virtual void playSound();
};

#endif // !_CROBJECT_H_
