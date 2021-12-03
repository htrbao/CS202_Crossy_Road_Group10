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
	void move();
	void jump();
	void draw(sf::RenderWindow& window);
};

#endif // !_CRCOIN_H_
