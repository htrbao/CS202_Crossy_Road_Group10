#include "CRGUI.h"

CRGUI::CRGUI(float width, float height)
{
	yText.assign(4, 0);
	yText[0] = 450;
	yText[1] = 500;
	yText[2] = 550;
	yText[3] = 600;

	cur = 0; 

	font = CASSET::GetInstance().fontMap["Flap"];
	fontScore = CASSET::GetInstance().fontMap["DIMIS___"];
	pauseTexture = &CASSET::GetInstance().textureMap["PAUSE"];
	pauseButton.setTexture(*pauseTexture);
	
	newHighTexture = &CASSET::GetInstance().textureMap["HIGH"];
	gameOverTexture = &CASSET::GetInstance().textureMap["GAMEOVER"];

	gameOver[0].setTexture(*newHighTexture);
	gameOver[0].setOrigin(newHighTexture->getSize().x / 2, newHighTexture->getSize().y / 2);
	gameOver[0].scale(0.95, 0.95);
	gameOver[0].setPosition(330, 250);

	gameOver[1].setTexture(*gameOverTexture);
	gameOver[1].setOrigin(gameOverTexture->getSize().x / 2, gameOverTexture->getSize().y / 2);
	//gameOver.scale(1.5, 1.5);
	gameOver[1].setPosition(Constants::SCREEN_WIDTH / 2, 200);

	titleTexture = &CASSET::GetInstance().textureMap["TITLE"];
	title.setTexture(*titleTexture);
	title.setOrigin(titleTexture->getSize().x / 2, titleTexture->getSize().y / 2);
	title.setPosition(Constants::SCREEN_WIDTH / 2, 200);

	choice = 0;
}

void CRGUI::draw(sf::RenderTarget& window) {
	if (cur != 3) {
		window.draw(title);
	}
	else if (cur == 3) {
		window.draw(gameOver[position]);
		window.draw(highScoreText);
		window.draw(scoreText);
	}
	for (long i = 0; i < options.size(); i++) {
		sf::FloatRect textRect = options[i].first.getLocalBounds();
		options[i].first.setOrigin(textRect.left + textRect.width / 2.0f,textRect.top + textRect.height / 2.0f);
		options[i].first.setPosition(options[i].second, yText[i]);
		window.draw(options[i].first);
	}
}

void CRGUI::drawMenu(){
	cur = 1;

	options.clear();
	options.assign(4, { sf::Text(), Constants::SCREEN_WIDTH / 2});

	options[0].first.setFont(font);
	options[0].first.setFillColor(sf::Color(244, 188, 1));
	options[0].first.setString("PLAY");

	options[1].first.setFont(font);
	options[1].first.setFillColor(sf::Color(255, 247, 182));
	options[1].first.setString("LOAD GAME");

	options[2].first.setFont(font);
	options[2].first.setFillColor(sf::Color(255, 247, 182));
	options[2].first.setString("SETTING");

	options[3].first.setFont(font);
	options[3].first.setFillColor(sf::Color(255, 247, 182));
	options[3].first.setString("QUIT");
}

void CRGUI::drawPause()
{
	cur = 2;
	options.clear();
	options.assign(4, { sf::Text(), Constants::SCREEN_WIDTH / 2 });

	options[0].first.setFont(font);
	options[0].first.setFillColor(sf::Color(244, 188, 1));
	options[0].first.setString("MENU");

	options[1].first.setFont(font);
	options[1].first.setFillColor(sf::Color(255, 247, 182));
	options[1].first.setString("RESUME");
	
	options[2].first.setFont(font);
	options[2].first.setFillColor(sf::Color(255, 247, 182));
	options[2].first.setString("SETTING");

	options[3].first.setFont(font);
	options[3].first.setFillColor(sf::Color(255, 247, 182));
	options[3].first.setString("SAVE AND EXIT");
}

void CRGUI::drawSetting(sf::Sound* game, bool SFX) {
	cur = 4;

	options.clear();
	options.assign(4, { sf::Text(), Constants::SCREEN_WIDTH / 2 });

	string typeSFX = (SFX) ? "ON" : "OFF";

	options[0].first.setFont(font);
	options[0].first.setFillColor(sf::Color(244, 188, 1));
	options[0].first.setString("SFX: " + typeSFX);

	string type = (game->getVolume() > 0.0) ? "ON" : "OFF";

	options[1].first.setFont(font);
	options[1].first.setFillColor(sf::Color(255, 247, 182));
	options[1].first.setString("MUSIC: " + type);
	
	options[2].first.setFont(font);
	options[2].first.setFillColor(sf::Color(255, 247, 182));
	options[2].first.setString("RESET");

	options[3].first.setFont(font);
	options[3].first.setFillColor(sf::Color(255, 247, 182));
	options[3].first.setString("BACK");
}

void CRGUI::drawGameOver(int score, int highScore) {
	cur = 3;
	options.clear();
	options.assign(4, { sf::Text(), Constants::SCREEN_WIDTH / 2 });

	options[0].first.setFont(font);
	options[0].first.setFillColor(sf::Color(244, 188, 1));
	options[0].first.setString("RESTART");

	options[1].first.setFont(font);
	options[1].first.setFillColor(sf::Color(255, 247, 182));
	options[1].first.setString("MENU");

	options[2].first.setFont(font);
	options[2].first.setFillColor(sf::Color(255, 247, 182));
	options[2].first.setString("SETTING");

	options[3].first.setFont(font);
	options[3].first.setFillColor(sf::Color(255, 247, 182));
	options[3].first.setString("QUIT");

	if (score == highScore) {
		position = 0;

		this->highScoreText.setFont(fontScore);
		this->highScoreText.setCharacterSize(100);
		this->highScoreText.setFillColor(sf::Color(255, 251, 255));
		this->highScoreText.setString("HIGH\nSCORE");
		this->highScoreText.setPosition(500, 160);

		this->scoreText.setFont(font);
		this->scoreText.setCharacterSize(85);
		this->scoreText.setFillColor(sf::Color(255, 251, 255));
		this->scoreText.setString(to_string(score));
		this->scoreText.setPosition(gameOver->getPosition().x - scoreText.getLocalBounds().width / 2.0, highScoreText.getLocalBounds().height / 2 + 140);

		return;
	}
	position = 1;
	this->scoreText.setFont(fontScore);
	this->scoreText.setCharacterSize(50);
	this->scoreText.setFillColor(sf::Color(255, 201, 222));
	this->scoreText.setString("SCORE : " + to_string(score));
	this->scoreText.setPosition(250, 350);

	this->highScoreText.setFont(fontScore);
	this->highScoreText.setCharacterSize(50);
	this->highScoreText.setFillColor(sf::Color(255, 181, 232));
	this->highScoreText.setString("HIGHSCORE : " + to_string(highScore));
	this->highScoreText.setPosition(500, 350);
}

void CRGUI::nextChoice() {
	options[0].first.setFillColor(sf::Color(255, 247, 182));
	options.push_back(options.front());
	options.pop_front();
	options[0].first.setFillColor(sf::Color(244, 188, 1));
	choice = (++choice) % 4;
}

void CRGUI::prevChoice() {
	options[0].first.setFillColor(sf::Color(255, 247, 182));
	options.push_front(options.back());
	options.pop_back();
	options[0].first.setFillColor(sf::Color(244, 188, 1));
	if (choice == 0)
		choice = 3;
	else
		choice--;
}

int CRGUI::getChoice()
{
	int tmp = choice;
	choice = 0;
	return tmp;
}
