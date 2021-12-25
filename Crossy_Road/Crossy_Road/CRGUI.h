#ifndef _CRGUI_H_

#define _CRGUI_H_

#include "CASSET.h"
#include "Constants.h"
#include <deque>

class CRGUI {
private:
	friend class CGAME;
	
	//
	float width;
	float height;

	//pause then play
	sf::Texture* pauseTexture;
	sf::Texture* playTexture;
	sf::Sprite pauseButton;
	sf::Sprite playButton;

	sf::Font font;

	sf::Event ev;

	vector<double> yText;
	deque<pair<sf::Text, int>> options;
public:
	CRGUI(float width, float height);
	void draw(sf::RenderTarget* window);
	void nextChoice();
	void prevChoice();
};

#endif // !_CRGUI_H_
