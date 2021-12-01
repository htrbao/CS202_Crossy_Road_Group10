#include "CROBJECT.h"

void CROBJECT::setUpTexture() {
    sprite.setTexture(*texture);
    sprite.scale(objScale, objScale);
}

CROBJECT::CROBJECT(double mX, double mY, double objScale, int direction = 1) : mX(mX), mY(mY), objScale(objScale), direction(direction) {}

void CROBJECT::shiftObject(char UorD) {
    if (UorD == 'U' || UorD == 'u')
        sprite.move(-0.0125, 0.0375);
    else if (UorD == 'D' || UorD == 'd')
        sprite.move(-0.0125, -0.0375);
}

bool CROBJECT::checkOutWindow(sf::RenderWindow& window) {
    return (direction == 1 && (sprite.getPosition().x >= window.getSize().x || sprite.getPosition().y >= window.getSize().y)) || (direction == -1 && (sprite.getPosition().x <= 0 || sprite.getPosition().y <= 0));
}

void CROBJECT::move(float x, float y) {
    sprite.move(direction * 0.05, direction * 0.02331538291);
}

void CROBJECT::draw(sf::RenderWindow& window) {
    cout << "Object::drawing\n";
    if (checkOutWindow(window) == 0) window.draw(sprite);
}
