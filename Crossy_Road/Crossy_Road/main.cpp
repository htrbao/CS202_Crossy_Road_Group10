#include <iostream>

#include "Constants.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include "CRCAR.h"
#include "CROADFACTORY.h"
#include "CRBLOCK.h"
#include "CRTREE.h"
#include "CRCOIN.h"

using namespace std;
double CROAD::numOfRoad = 0;
int main() {
    srand(NULL);
    sf::RenderWindow window(sf::VideoMode(Constants::SCREEN_WIDTH, Constants::SCREEN_HEIGHT), "Crossy Road");
    
    /*sf::Texture roadTest;
    roadTest.loadFromFile("assets/graphics/road.png");
    sf::Sprite roadImageSprite;
    roadImageSprite.setTexture(roadTest);


    /*sf::Texture carTest;
    carTest.loadFromFile("assets/graphics/firetruck_SE.png");
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
    }*/

    CROADFACTORY roadFac;
    CRCOIN bsn("COIN_2", 1000, -160);
    CRCAR fire("firetruck_NW", 458, 50, -1);
    CRCAR fire2("raceFuture_SE", 123, 100, 1);
    roadFac.initRoadGame();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            fire.shiftObject('U');
            fire2.shiftObject('U');
            roadFac.shiftObject('U');
            bsn.shiftObject('U');
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            fire.shiftObject('D');
            fire2.shiftObject('D');
            roadFac.shiftObject('D');
            bsn.shiftObject('D');
        }
        fire.move(0, 0);
        fire2.move(0, 0);
        roadFac.update(window);
        window.clear();
        roadFac.draw(window);
        bsn.draw(window);
        fire2.draw(window);
        fire.draw(window);
        
        window.display();
    }
	cout << "Bye!";
	return 0;
}