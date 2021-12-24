#include "CPOINTHUD.h"

CPOINTHUD::CPOINTHUD(string nameFont, int pxSize, float x, float y, int val)
{
	point = val;
	font = &CASSET::GetInstance().fontMap[nameFont];
	text.setFont(*font);
	text.setCharacterSize(pxSize);
	text.setFillColor(sf::Color::Yellow);
	update();
	text.setPosition(x, y);
}

void CPOINTHUD::increaseP()
{
	point++;
}

void CPOINTHUD::descreaseP()
{
	point--;
}

void CPOINTHUD::draw(sf::RenderWindow& window)
{
	update();
	window.draw(text);
}

void CPOINTHUD::update()
{
	string display = "POINT: " + to_string(point);
	text.setString(display);
}

void CPOINTHUD::save(ofstream& of)
{
	of.write((char*)&point, sizeof(point));
}

void CPOINTHUD::load(ifstream& inf)
{
	inf.read((char*)&point, sizeof(point));
}
