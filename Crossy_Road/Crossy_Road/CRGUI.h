#ifndef _CRGUI_H_

#define _CRGUI_H_

#include "CASSET.h"
#include "Constants.h"
#include <deque>
#include<string>

class CRGUI {
private:
	friend class CGAME;
	
	float width;
	float height;

	int choice;

	//pause then play
	sf::Texture* pauseTexture;
	sf::Texture* playTexture;
	sf::Sprite pauseButton;
	sf::Sprite playButton;

	sf::Texture* gameOverTexture;
	sf::Texture* newHighTexture;
	sf::Sprite gameOver[3];

	sf::Texture* titleTexture;
	sf::Sprite title;

	int cur;
	int position;

	sf::Font font;
	sf::Font fontScore;
	
	sf::Text scoreText;
	sf::Text highScoreText;

	sf::Event ev;

	vector<double> yText;
	deque<pair<sf::Text, int>> options;
public:
	CRGUI(float width, float height);
	void draw(sf::RenderTarget& window);
	void drawMenu();
	void drawGameOver(int score,int highScore);
	void drawPause();
	void drawSetting(sf::Sound* game, bool SFX);
	void nextChoice();
	void prevChoice();
	int getChoice();
};

#endif // !_CRGUI_H_
