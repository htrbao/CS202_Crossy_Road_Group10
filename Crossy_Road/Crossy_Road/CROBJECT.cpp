#include "CROBJECT.h"

void CROBJECT::setUpTexture() {
    sprite.setTexture(*texture);
    sprite.setOrigin(texture->getSize().x / 2, texture->getSize().y / 2);
    sprite.scale(objScale, objScale);
    sprite.setPosition(mX, mY);
}

CROBJECT::CROBJECT(double mX, double mY, double scale) : mX(mX), mY(mY), objScale(scale), direction(0), speed(0) {}

CROBJECT::CROBJECT(double mX, double mY, double objScale, int direction = 1) : mX(mX), mY(mY), objScale(objScale), direction(direction), speed(0) {}

void CROBJECT::shiftObject(char UorD) {
    if (UorD == 'U' || UorD == 'u')
        sprite.move(direction * 0.0025 * speed - 0.25, direction * tan(Constants::Alpha) * 0.0025 * speed - 0.25 * tan(-Constants::Beta));
    else if (UorD == 'D' || UorD == 'd')
        sprite.move(direction * 0.0025 * speed + 0.25, direction * tan(Constants::Alpha) * 0.0025 * speed + 0.25 * tan(-Constants::Beta));
}

bool CROBJECT::checkOutWindow(sf::RenderWindow& window) {
    return (direction == 1 && (sprite.getPosition().x >= window.getSize().x + 100 || sprite.getPosition().y >= window.getSize().y + 100)) || (direction == -1 && (sprite.getPosition().x <= -100 || sprite.getPosition().y <= -100));
}

void CROBJECT::move(float x, float y) {
    sprite.move(direction * 0.0025 * speed, direction * tan(Constants::Alpha) * 0.0025 * speed);
}

void CROBJECT::draw(sf::RenderWindow& window) {
    //if (checkOutWindow(window) == 0) {
        //cout << "Object::drawing\n";
    //}
    window.draw(sprite);
}
