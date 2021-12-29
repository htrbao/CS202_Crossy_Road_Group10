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
	radius = WIDTH / 16;
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

int CRCHARACTER::checkCollision(CROBJECT*& obj) {
	if (obj) {
		float hRadius = obj->sprite.getLocalBounds().width / 16;
		float vRadius = obj->sprite.getLocalBounds().height / 32;
		double xX = (sprite.getPosition().x + radius) - (obj->sprite.getPosition().x + hRadius);
		double yY = (sprite.getPosition().y + radius) - (obj->sprite.getPosition().y + vRadius + 25);
		double dis = sqrt(xX * xX + yY * yY);
		//cout << dis << endl;
		switch (obj->type()) {
		case Constants::BLOCK:
			if (dis < radius + sqrt(hRadius * hRadius + vRadius * vRadius)) return 1;
			break;
		case Constants::CAR:
			if (dis < radius + sqrt(hRadius * hRadius + vRadius * vRadius)) return 2;
			break;
		case Constants::COIN:
			if (obj->isVisible && dis < radius + sqrt(hRadius * hRadius + vRadius * vRadius)) {
				obj->setVisible(false);
				return 3;
			}
			break;
		}
	}
	return 0;
}

void CRCHARACTER::setSide(int side) {
	// Move the rectangle to the corresponding figure.
	this->side = side;
	sprite.setTextureRect(sf::IntRect(WIDTH * side, 0, WIDTH, HEIGHT));
}

bool CRCHARACTER::canMoveDown() {
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
	if(sprite.getPosition().x > Constants::SCREEN_WIDTH || sprite.getPosition().y > Constants::SCREEN_HEIGHT)
		sprite.move(-1 * 0.021875 * 250, -1 * tan(Constants::Alpha) * 0.021875 * 250);
	if (side != RIGHT) setSide(RIGHT);
}

void CRCHARACTER::moveLeft() {
	sound.play();
	sprite.move(-1 * 0.021875 * 250, -1 * tan(Constants::Alpha) * 0.021875 * 250);
	if (sprite.getPosition().x < 0 || sprite.getPosition().y < 0)
		sprite.move(1 * 0.021875 * 250, 1 * tan(Constants::Alpha) * 0.021875 * 250);
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

void CRCHARACTER::save(ofstream& of)
{
	float x = sprite.getPosition().x;
	float y = sprite.getPosition().y;

	of.write((char*)&x, sizeof(x));
	of.write((char*)&y, sizeof(y));
	of.write((char*)&side, sizeof(side));
}

void CRCHARACTER::load(ifstream& inf)
{
	float x;
	float y;
	inf.read((char*)&x, sizeof(x));
	inf.read((char*)&y, sizeof(y));
	inf.read((char*)&side, sizeof(side));
	setSide(side);
	sprite.setPosition(x, y);
}

bool CRCHARACTER::isBehindRoad(CROAD& road) {
	return mY - mX*tan(Constants::Alpha) + (WIDTH*SCALE)/2 <= road.getDis();
}

bool CRCHARACTER::isNearRoad(CROAD& road)
{
	int dis = 40;
	if (road.isHighway())
		dis *= 2;
	return abs((mY - mX * tan(Constants::Alpha) + (WIDTH * SCALE) / 2) - road.getDis() - dis) <= 144.2865;
}
