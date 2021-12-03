#include <iostream>

#include "Constants.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include "CRCAR.h"
#include "CRBLOCK.h"
#include "CRTREE.h"
#include "CRCOIN.h"
#include "CLANE.h"

using namespace std;
int CROAD::numOfRoad = 0;
int main() {
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

    CLANE lane(CROAD::getNumRoads());/*
    CLANE lane1(CROAD::getNumRoads()); 
    CLANE lane2(CROAD::getNumRoads()); 
    CLANE lane3(CROAD::getNumRoads());
    CLANE lane4(CROAD::getNumRoads());
    CLANE lane5(CROAD::getNumRoads());
    CLANE lane6(CROAD::getNumRoads());*/
    CRCOIN bsn("COIN_2", 1000, -160);
    CRCAR fire("firetruck_NW", 458, 50, -1);
    CRCAR fire2("raceFuture_SE", 123, 100, 1);


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
            lane.transposition('U');
            bsn.shiftObject('U');
            /*lane1.transposition('U');
            lane2.transposition('U');
            lane3.transposition('U');
            lane4.transposition('U');
            lane5.transposition('U');
            lane6.transposition('U');*/
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            fire.shiftObject('D');
            fire2.shiftObject('D');
            lane.transposition('D');
            bsn.shiftObject('D');
            /*lane1.transposition('D');
            lane2.transposition('D');
            lane3.transposition('D');
            lane4.transposition('D'); 
            lane5.transposition('D');
            lane6.transposition('D');*/
        }
        fire.move(0, 0);
        fire2.move(0, 0);
        window.clear();
        lane.draw(window);
        /*lane1.draw(window);
        lane2.draw(window);
        lane3.draw(window);
        lane4.draw(window);
        lane5.draw(window);
        lane6.draw(window);*/
        bsn.draw(window);
        fire2.draw(window);
        fire.draw(window);
        
        window.display();
    }
	cout << "Bye!";
	return 0;
}