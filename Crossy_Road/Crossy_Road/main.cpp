#include "CGAME.h"

int main() {
	//sf::Texture* snowTexture = &CASSET::GetInstance().textureMap["SNOW"];
	//sf::Sprite snow;
	//snow.setTexture(*snowTexture);
	//snow.scale(2, 2);
	//sf::Sprite snowNext;
	//snowNext.setTexture(*snowTexture);
	//snowNext.scale(2, 2);
	//snowNext.setPosition(0, 0);
	//long setUpY = snowTexture->getSize().y;
	//snow.setPosition(0, -setUpY);
	CGAME game;
	game.run();
	return 0;
}