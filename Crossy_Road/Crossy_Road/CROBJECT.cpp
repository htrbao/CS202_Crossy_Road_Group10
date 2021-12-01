#include "CROBJECT.h"

void CROBJECT::setUpTexture() {
    sprite.setTexture(*texture);
    sprite.setOrigin(texture->getSize().x / 2, texture->getSize().y / 2);
    sprite.scale(objScale, objScale);
    sprite.setPosition(mX, mY);
}

CROBJECT::CROBJECT(double mX, double mY, double objScale, int direction = 1) : mX(mX), mY(mY), objScale(objScale), direction(direction) {}

void CROBJECT::shiftObject(char UorD) {
    if (UorD == 'U' || UorD == 'u')
        sprite.move(-0.05, 0.15);
    else if (UorD == 'D' || UorD == 'd')
        sprite.move(-0.05, -0.15);
}

bool CROBJECT::checkOutWindow(sf::RenderWindow& window) {
    return (direction == 1 && (sprite.getPosition().x >= window.getSize().x + 50|| sprite.getPosition().y >= window.getSize().y + 50)) || (direction == -1 && (sprite.getPosition().x <= -50 || sprite.getPosition().y <= -50));
}

void CROBJECT::move(float x, float y) {
    sprite.move(direction * 0.05 * speed, direction * 0.02331538291 * speed);
}

void CROBJECT::draw(sf::RenderWindow& window) {
    if (checkOutWindow(window) == 0) {
        cout << "Object::drawing\n";
        window.draw(sprite);
    }
}
