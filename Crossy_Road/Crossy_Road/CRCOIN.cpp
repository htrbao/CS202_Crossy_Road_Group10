#include "CRCOIN.h"

CRCOIN::CRCOIN(string textureFileName, double x, double y) : CROBJECT(x, y, 1.8), jump_coeff(0){

	texture = &CASSET::GetInstance().textureMap[textureFileName];

	setUpTexture();
}

void CRCOIN::move() {

}


void CRCOIN::jump() {
	jump_coeff %= 400;
	jump_coeff++;
}

void CRCOIN::setVisible(bool typ) {
	this->isVisible = typ;
}

void CRCOIN::draw(sf::RenderWindow& window) {
	if (!isVisible) {
		return;
	}
	jump();
	if (checkOutWindow(window) == 0) {
		sprite.move(0, (jump_coeff < 100 ? -3 : 1) / 6.0);
		window.draw(sprite);
	}
}

int CRCOIN::type() {
	return Constants::COIN;
}
