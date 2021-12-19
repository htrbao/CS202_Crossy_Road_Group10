#ifndef _CRGUI_H_

#define _CRGUI_H_

#include "CASSET.h"
#include "Constants.h"
//#include "CGame.h"
class CRGUI {
private:
	friend class CGAME;
	sf::Sprite Title;
	sf::Sprite Button;
	sf::Texture textTitle;
	sf::Texture textButton;
	sf::Event ev;
	bool clickEnter = false;
	bool isDelete = false;
public:
	CRGUI(float width, float height);
	bool isClickEnter();
	void draw(sf::RenderTarget* window);
	void eventListener(sf::RenderWindow* window);
};

#endif // !_CRGUI_H_
