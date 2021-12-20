#include "CRGUI.h"

CRGUI::CRGUI(float width, float height)
{
	this->textTitle.loadFromFile("assets\\graphics\\TiTLE.png");
	this->textButton.loadFromFile("assets\\graphics\\PLAY.png");
	this->Title.setTexture(this->textTitle);
	this->Button.setTexture(this->textButton);
	this->Button.scale(0.5, 0.5);
	this->Title.setPosition(width, height);
	this->Button.setPosition(width + 45, height + 300);
}

bool CRGUI::isClickEnter()
{
	return this->clickEnter;
}
;
void CRGUI::draw(sf::RenderTarget* window) {
	if (this->isDelete == false)
	{
		window->draw(this->Title);
		window->draw(this->Button);
	}

}
void CRGUI::eventListener(sf::RenderWindow* window)
{
	while (window->pollEvent(this->ev))
	{
		if (this->ev.type == sf::Event::KeyReleased && this->ev.key.code == sf::Keyboard::Return)
		{
			this->clickEnter = true;
			this->isDelete = true;
		}
	}
}
;