#include "CRCAR.h"

CRCAR::CRCAR(string textureFileName, string soundFileName, float x, float y, double speed, int direction) : CROBJECT(x, y, 1, direction)
{
	this->speed = speed;

	texture = &CASSET::GetInstance().textureMap[textureFileName];
	buffer = &CASSET::GetInstance().soundMap[soundFileName];
	setUpTexture();
	setUpSound();
}

int CRCAR::type()
{
	return Constants::CAR;
}

void CRCAR::move(double x, double y) {
	CROBJECT::move(x, y);
}

sf::Vector2f CRCAR::getPosition()
{
	return sf::Vector2f(mX, mY);
}
