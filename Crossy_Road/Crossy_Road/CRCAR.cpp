#include "CRCAR.h"

CRCAR::CRCAR(string textureFileName, double x, double y, double speed, int direction = 1) : CROBJECT(x, y, 1, direction) {
	this->speed = speed;

	texture = &CASSET::GetInstance().textureMap[textureFileName];

	setUpTexture();
}

void CRCAR::move(double x, double y) {
	CROBJECT::move(x, y);
}

void CRCAR::draw(sf::RenderWindow& window) {
	CROBJECT::draw(window);
}
