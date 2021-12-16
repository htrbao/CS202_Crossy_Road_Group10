// character
#include "CRCHARACTER.h"

int CRCHARACTER::UP = 0, CRCHARACTER::RIGHT = 1, CRCHARACTER::DOWN = 2, CRCHARACTER::LEFT = 3;
int CRCHARACTER::WIDTH = 512, CRCHARACTER::HEIGHT = 512;
float CRCHARACTER::SCALE = 0.45;

void CRCHARACTER::initTexture() {
	textureSheet = &CASSET::GetInstance().textureMap["CAT"];
	sprite.setTexture(*textureSheet);
	sprite.setOrigin(WIDTH / 2, HEIGHT / 2);
	sprite.setPosition(mX, mY);
	sprite.scale(SCALE, SCALE);
}

CRCHARACTER::CRCHARACTER(sf::RenderWindow* window, int side, int x, int y) : window(window), side(side), mX(x), mY(y) {
	initTexture();
	setSide(side);
}

void CRCHARACTER::setSide(int side) {
	// Move the rectangle to the corresponding figure.
	this->side = side;
	sprite.setTextureRect(sf::IntRect(WIDTH * side, 0, WIDTH, HEIGHT));
}

bool CRCHARACTER::canMoveDown() {
	bool canDecreaseX = (mX >= 0);
	return false;
}

bool CRCHARACTER::canMoveUp()
{
	return false;
}

bool CRCHARACTER::canMoveRight()
{
	return false;
}

bool CRCHARACTER::canMoveLeft()
{
	return false;
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
	sprite.move(1 * 0.0025 * 250, 1 * tan(Constants::Alpha) * 0.0025 * 250);
	setSide(RIGHT);
}

void CRCHARACTER::moveLeft() {
	sprite.move(-1 * 0.0025 * 250, -1 * tan(Constants::Alpha) * 0.0025 * 250);
	//side = LEFT;
	setSide(LEFT);
}

void CRCHARACTER::update()
{
}

void CRCHARACTER::render() {
	//if (!isGameOver) {
		//sprite.setPosition(mX, mY);

	window->draw(sprite);
	//}
}

bool CRCHARACTER::isBehindRoad(CROAD& road)
{
	return mY - mX*tan(Constants::Alpha) + (WIDTH*SCALE)/2 < road.getDis();
}

bool CRCHARACTER::isNearRoand(CROAD& road)
{
	return abs((mY - mX * tan(Constants::Alpha) + (WIDTH * SCALE) / 2) - road.getDis()) <= 144.2865;
}
