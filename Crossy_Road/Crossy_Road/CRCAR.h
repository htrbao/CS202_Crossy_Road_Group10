#ifndef _CRCAR_H_

#define _CRCAR_H_

#include "CROBJECT.h"

class CRCAR : public CROBJECT {
private:
public:
	CRCAR(string textureFileName, double y, double speed, int direction);
	CRCAR(string textureFileName, float x, float y, double speed, int direction);
	void move(double x, double y);
	sf::Vector2f getPosition();
};

#endif // !_CRCAR_H_
