#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>

using namespace std;

#define SCREEN_WIDTH 473
#define SCREEN_HEIGHT 957

int main() {
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Crossy Road");
    sf::Texture imageSource;
    imageSource.loadFromFile("assets/police_SE.png");
    sf::Sprite imageSprite;
    imageSprite.setTexture(imageSource);
    imageSprite.scale(0.5, 0.5);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        imageSprite.move(0.05, 0.05);
        window.clear();
        window.draw(imageSprite);
        window.display();
    }
	cout << "Hello";
	return 0;
}