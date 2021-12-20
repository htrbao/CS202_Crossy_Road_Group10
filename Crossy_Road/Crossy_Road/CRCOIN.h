#ifndef _CRCOIN_H_

#define _CRCOIN_H_

#include "CASSET.h"
#include "CROBJECT.h"

using namespace std;

class CRCOIN : public CROBJECT {
private:
	int jump_coeff;
public:
	CRCOIN(string textureFileName, double x, double y);
	void setVisible(bool typ);
	void move();
	void jump();
	int type();
	void draw(sf::RenderWindow& window);
};

#endif // !_CRCOIN_H_
