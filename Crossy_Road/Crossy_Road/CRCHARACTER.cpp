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

void CRCHARACTER::initSound() {
	buffer = &CASSET::GetInstance().soundMap["JUMP"];
	sound.setBuffer(*buffer);
	sound.setVolume(100);
	sound.setLoop(false);
}

CRCHARACTER::CRCHARACTER(sf::RenderWindow* window, int side, int x, int y) : window(window), side(side), mX(x), mY(y) {
	initTexture();
	initSound();
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
	sound.play();
	if (side != DOWN) setSide(DOWN);
}

void CRCHARACTER::moveUp() {
	sound.play();
	//side = UP;
	if (side != UP) setSide(UP);
}

void CRCHARACTER::moveRight() {
	//side = RIGHT;
	sound.play();
	sprite.move(1 * 0.021875 * 250, 1 * tan(Constants::Alpha) * 0.021875 * 250);
	if (side != RIGHT) setSide(RIGHT);
}

void CRCHARACTER::moveLeft() {
	sound.play();
	sprite.move(-1 * 0.021875 * 250, -1 * tan(Constants::Alpha) * 0.021875 * 250);
	//side = LEFT;
	if(side != LEFT) setSide(LEFT);
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
	return mY - mX*tan(Constants::Alpha) + (WIDTH*SCALE)/2 <= road.getDis();
}

bool CRCHARACTER::isNearRoand(CROAD& road)
{
	int dis = 40;
	if (road.isHighway())
		dis *= 2;
	return abs((mY - mX * tan(Constants::Alpha) + (WIDTH * SCALE) / 2) - road.getDis() - dis) <= 144.2865;
}
