#include "CRCAR.h"

CRCAR::CRCAR(string textureFileName, double y, double speed, int direction = 1) : CROBJECT(direction > 0 ? Constants::positionXofVehical_SE : Constants::positionXofVehical_NW, y, 0.5, direction) {
	this->speed = speed;

	texture = &CASSET::GetInstance().textureMap[textureFileName];

	setUpTexture();
}

void CRCAR::move(double x, double y) {
	CROBJECT::move(x, y);
}
