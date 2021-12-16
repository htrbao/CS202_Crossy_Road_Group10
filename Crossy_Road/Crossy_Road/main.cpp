#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include "Constants.h"
#include "CRCAR.h"
#include "CROADFACTORY.h"
#include "CRBLOCK.h"
#include "CRTREE.h"
#include "CRCOIN.h"
#include "CRCHARACTER.h"

using namespace std;
double CROAD::numOfRoad = 0;

int main() {
    srand((unsigned)time(0));
    sf::RenderWindow window(sf::VideoMode(Constants::SCREEN_WIDTH, Constants::SCREEN_HEIGHT), "Crossy Road");

    CROADFACTORY roadFac;
    CRCHARACTER player(&window, 0, 512, 350);
    CRCOIN bsn("COIN_2", 1000, -160);
    //CRCAR fire("firetruck_NW", 458, 50, -1);
    //CRCAR fire2("raceFuture_SE", 123, 100, 1);
    roadFac.initRoadGame(&player);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            player.moveUp();
            //fire.shiftObject('U');
            //fire2.shiftObject('U');
            roadFac.shiftObject('U');

            bsn.shiftObject('U');
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            player.moveRight();
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            player.moveDown();
            //fire.shiftObject('D');
            //fire2.shiftObject('D');
            roadFac.shiftObject('D');
            bsn.shiftObject('D');
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            player.moveLeft();
        }
        //fire.move(0, 0);
        //fire2.move(0, 0);
        roadFac.update(window);
        window.clear();
        roadFac.draw(window);
        bsn.draw(window);
        //player.render();
        //fire2.draw(window);
        //fire.draw(window);
        
        window.display();
    }
	cout << "Bye!";
	return 0;
}