#include "CRCAR.h"

CRCAR::CRCAR(string textureFileName, float x, float y, double speed, int direction) : CROBJECT(x, y, 1, direction) {
	this->speed = speed;

	texture = &CASSET::GetInstance().textureMap[textureFileName];
	setUpTexture();
}

int CRCAR::type()
{
	return Constants::CAR;
}

void CRCAR::move(float x, float y, float frac) {
	CROBJECT::move(x, y, frac);
}