#include <iostream>

#include "Constants.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include "CRCAR.h"

using namespace std;

int dir = 1;

int main() {
    sf::RenderWindow window(sf::VideoMode(Constants::SCREEN_WIDTH, Constants::SCREEN_HEIGHT), "Crossy Road");
    
    sf::Texture roadTest;
    roadTest.loadFromFile("assets/graphics/road.png");
    sf::Sprite roadImageSprite;
    roadImageSprite.setTexture(roadTest);


    /*sf::Texture carTest;
    carTest.loadFromFile("assets/graphics/firetruck_SE.png");*/
    sf::Texture* texture = &CASSET::GetInstance().textureMap["firetruck_SE"];
    sf::Sprite carImageSprite;
    carImageSprite.setTexture(*texture);
    carImageSprite.scale(0.5, 0.5);
 
    sf::Texture catTest;
    catTest.loadFromFile("assets/player/CAT_1_NE.png");
    sf::Sprite catImageSprite;
    catImageSprite.setTexture(catTest);
    catImageSprite.scale(0.125, 0.125);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            carImageSprite.move(-0.0125, 0.0375);
            roadImageSprite.move(-0.0125, 0.0375);
        }
        carImageSprite.move(dir * 0.05, dir * 0.02331538291);
        window.clear();
        window.draw(roadImageSprite);
        window.draw(carImageSprite);
        window.draw(catImageSprite);
        window.display();
    }
    /*CRCAR police("firetruck_SE", 0, 0, 1, 1);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            police.shiftObject('U');
        }
        police.move(0, 0);
        police.draw(window);
        window.clear();
        window.display();
    }
	cout << "Hello";*/
	return 0;
}