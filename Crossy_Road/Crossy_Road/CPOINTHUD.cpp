#include "CPOINTHUD.h"

CPOINTHUD::CPOINTHUD(string nameFont, int pxSize, float x, float y, int val)
{
	point = val;
	font = &CASSET::GetInstance().fontMap[nameFont];
	text.setFont(*font);
	text.setCharacterSize(pxSize);
	text.setFillColor(sf::Color(255, 252, 211));
	update();
	text.setPosition(x, y);
}

void CPOINTHUD::increaseP(int i)
{
	point+=i;
}

void CPOINTHUD::descreaseP(int i)
{
	point-=i;
}

void CPOINTHUD::draw(sf::RenderWindow& window)
{
	update();
	window.draw(text);
}

void CPOINTHUD::update()
{
	string display = "(Point: " + to_string(point) + ")";
	text.setString(display);
	while (text.getPosition().x + text.getLocalBounds().width >= Constants::SCREEN_WIDTH)
	{
		text.setPosition(text.getPosition().x - 10, text.getPosition().y);
	}
}

void CPOINTHUD::save(ofstream& of)
{
	of.write((char*)&point, sizeof(point));
}

void CPOINTHUD::load(ifstream& inf)
{
	inf.read((char*)&point, sizeof(point));
}

int CPOINTHUD::getPoint()
{
	return point;
}
