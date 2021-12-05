#include "CRCAR.h"

CRCAR::CRCAR(string textureFileName, double y, double speed, int direction = 1) : CROBJECT(direction > 0 ? Constants::positionXofVehical_SE : Constants::positionXofVehical_NW, y, 1, direction) {
	this->speed = speed;

	texture = &CASSET::GetInstance().textureMap[textureFileName];

	setUpTexture();
}

CRCAR::CRCAR(string textureFileName, float x, float y, double speed, int direction) : CROBJECT(x, y, 1, direction)
{
	this->speed = speed;

	texture = &CASSET::GetInstance().textureMap[textureFileName];

	setUpTexture();
}

void CRCAR::move(double x, double y) {
	CROBJECT::move(x, y);
}

sf::Vector2f CRCAR::getPosition()
{
	return sf::Vector2f(mX, mY);
}
