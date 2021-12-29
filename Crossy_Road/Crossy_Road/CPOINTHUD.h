#ifndef _CPOINTHUD_H_
#define _CPOINTHUD_H_

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <fstream>
#include "Constants.h"
#include "CASSET.h"

class CPOINTHUD
{
private:
	int point;
	sf::Font* font;
	sf::Text text;

public:
	CPOINTHUD(string nameFont, int pxSize, float x, float y, int val);
	void increaseP(int i = 1);
	void descreaseP(int i = 1);
	void draw(sf::RenderWindow& window);
	void update();
	void save(ofstream& of);
	void load(ifstream& inf);
	int getPoint();
};

#endif // !_CPOINTHUD_H_


