#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>

using namespace std;

#define SCREEN_WIDTH 473
#define SCREEN_HEIGHT 957

int dir = 1;

int main() {
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Crossy Road");
    sf::Texture carTest;
    carTest.loadFromFile("assets/firetruck_SE.png");
    sf::Sprite carImageSprite;
    carImageSprite.setTexture(carTest);
    carImageSprite.scale(0.5, 0.5);
 
    sf::Texture catTest;
    catTest.loadFromFile("assets/CAT_1_NE.png");
    sf::Sprite catImageSprite;
    catImageSprite.setTexture(catTest);
    catImageSprite.scale(0.25, 0.25);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            carImageSprite.move(-0.05, 0.15);
        }
        carImageSprite.move(dir * 0.05, dir * 0.05);
        window.clear();
        window.draw(carImageSprite);
        window.draw(catImageSprite);
        window.display();
    }
	cout << "Hello";
	return 0;
}