#include "CRCHARACTER.h"

int CRCHARACTER::UP = 0, CRCHARACTER::RIGHT = 1, CRCHARACTER::DOWN = 2, CRCHARACTER::LEFT = 3;
int CRCHARACTER::WIDTH = 512, CRCHARACTER::HEIGHT = 512;
float CRCHARACTER::SCALE = 1;

void CRCHARACTER::initTexture() {
	textureSheet = &CASSET::GetInstance().textureMap["CAT"];
	sprite.setTexture(*textureSheet);
	sprite.scale(SCALE, SCALE);
	side = 0;
}

CRCHARACTER::CRCHARACTER(sf::RenderWindow* window, int side, int x, int y) : window(window), side(side) {
	initTexture();
}

void CRCHARACTER::setSide(int side) {
	// Move the rectangle to the corresponding figure.
	this->side = side;
	sprite.setTextureRect(sf::IntRect(WIDTH * side, 0, WIDTH, HEIGHT));
}

void CRCHARACTER::moveDown() {
	setSide(DOWN);
}

void CRCHARACTER::moveUp() {
	//side = UP;
	setSide(UP);
}

void CRCHARACTER::moveRight() {
	//side = RIGHT;
	setSide(RIGHT);
}

void CRCHARACTER::moveLeft() {
	//side = LEFT;
	setSide(LEFT);
}

void CRCHARACTER::render() {
	//if (!isGameOver) {
		//sprite.setPosition(mX, mY);

	window->draw(sprite);
	//}
}