#include "CRGUI.h"

CRGUI::CRGUI(float width, float height)
{
	yText.assign(3, 0);
	yText[0] = 450;
	yText[1] = 500;
	yText[2] = 550;

	font = CASSET::GetInstance().fontMap["Flap"];
	pauseTexture = &CASSET::GetInstance().textureMap["PAUSE"];
	pauseButton.setTexture(*pauseTexture);

	titleTexture = &CASSET::GetInstance().textureMap["TITLE"];
	title.setTexture(*titleTexture);
	title.setOrigin(titleTexture->getSize().x / 2, titleTexture->getSize().y / 2);
	title.setPosition(Constants::SCREEN_WIDTH / 2, 200);

	choice = 0;
}

void CRGUI::draw(sf::RenderTarget& window) {
	window.draw(title);
	for (long i = 0; i < options.size(); i++) {
		sf::FloatRect textRect = options[i].first.getLocalBounds();
		options[i].first.setOrigin(textRect.left + textRect.width / 2.0f,textRect.top + textRect.height / 2.0f);
		options[i].first.setPosition(options[i].second, yText[i]);
		window.draw(options[i].first);
	}
}

void CRGUI::drawMenu(){
	options.clear();
	options.assign(3, { sf::Text(), Constants::SCREEN_WIDTH / 2});

	options[0].first.setFont(font);
	options[0].first.setFillColor(sf::Color(244, 188, 1));
	options[0].first.setString("PLAY");

	options[1].first.setFont(font);
	options[1].first.setFillColor(sf::Color(255, 247, 182));
	options[1].first.setString("LOAD GAME");

	options[2].first.setFont(font);
	options[2].first.setFillColor(sf::Color(255, 247, 182));
	options[2].first.setString("QUIT");
}
void CRGUI::drawPause()
{
	options.clear();
	options.assign(3, { sf::Text(), Constants::SCREEN_WIDTH / 2 });

	options[0].first.setFont(font);
	options[0].first.setFillColor(sf::Color(244, 188, 1));
	options[0].first.setString("MENU");

	options[1].first.setFont(font);
	options[1].first.setFillColor(sf::Color(255, 247, 182));
	options[1].first.setString("RESUME");

	options[2].first.setFont(font);
	options[2].first.setFillColor(sf::Color(255, 247, 182));
	options[2].first.setString("SAVE AND EXIT");
	
}
void CRGUI::drawGameOver(sf::RenderTarget& window,int score, int highScore) {
	options.clear();
	options.assign(2, { sf::Text(), Constants::SCREEN_WIDTH / 2 });

	options[0].first.setFont(font);
	options[0].first.setFillColor(sf::Color(244, 188, 1));
	options[0].first.setString("RESTART");

	options[1].first.setFont(font);
	options[1].first.setFillColor(sf::Color(255, 247, 182));
	options[1].first.setString("QUIT");
	this->scoreText.setFont(font);
	this->scoreText.setFillColor(sf::Color(255, 247, 182));
	this->scoreText.setString("SCORE     : " + to_string(score));
	this->highScoreText.setFont(font);
	this->highScoreText.setFillColor(sf::Color(255, 247, 182));
	this->highScoreText.setString("HIGHSCORE: " + to_string(highScore));
	window.draw(title);
	for (long i = 0; i < options.size(); i++) {
		sf::FloatRect textRect = options[i].first.getLocalBounds();
		options[i].first.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
		options[i].first.setPosition(options[i].second, yText[i]);
		window.draw(options[i].first);
	}
	this->highScoreText.setPosition(0, 100);
	this->scoreText.setPosition(0, 150);
	window.draw(this->scoreText);
	window.draw(this->highScoreText);

}

void CRGUI::nextChoice() {
	options[0].first.setFillColor(sf::Color(255, 247, 182));
	options.push_back(options[0]);
	options.pop_front();
	options[0].first.setFillColor(sf::Color(244, 188, 1));
	if (choice == 2)
		choice = 0;
	else
		choice++;
}

void CRGUI::prevChoice() {
	options[0].first.setFillColor(sf::Color(255, 247, 182));
	options.push_front(options.back());
	options.pop_back();
	options[0].first.setFillColor(sf::Color(244, 188, 1));
	if (choice == 0)
		choice = 2;
	else
		choice--;
}

int CRGUI::getChoice()
{
	return choice;
}
