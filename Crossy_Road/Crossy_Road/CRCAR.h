#ifndef _CRCAR_H_

#define _CRCAR_H_

#include "CROBJECT.h"

class CRCAR : public CROBJECT {
private:
public:
	CRCAR(string textureFileName, double x, double y, double speed, int direction);
	void move(double x, double y);
	void draw(sf::RenderWindow& window);
};

#endif // !_CRCAR_H_
