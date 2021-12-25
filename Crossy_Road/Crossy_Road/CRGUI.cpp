#include "CRGUI.h"

CRGUI::CRGUI(float width, float height)
{
	font = CASSET::GetInstance().fontMap["Flap"];
	pauseTexture = &CASSET::GetInstance().textureMap["PAUSE"];
}

void CRGUI::draw(sf::RenderTarget* window) {
	
}

void CRGUI::nextChoice() {
	options[0].first.setFillColor(sf::Color(255, 247, 182));
	options.push_back(options[0]);
	options.pop_front();
	options[0].first.setFillColor(sf::Color(244, 188, 1));
}

void CRGUI::prevChoice() {
	options[0].first.setFillColor(sf::Color(255, 247, 182));
	options.push_front(options.back());
	options.pop_back();
	options[0].first.setFillColor(sf::Color(244, 188, 1));
}
