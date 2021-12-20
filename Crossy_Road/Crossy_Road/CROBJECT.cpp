#include "CROBJECT.h"

void CROBJECT::setUpTexture() {
    sprite.setTexture(*texture);
    sprite.setOrigin(texture->getSize().x / 2, texture->getSize().y / 2);
    sprite.scale(objScale, objScale);
    sprite.setPosition(mX, mY);
}

CROBJECT::CROBJECT(double mX, double mY, double scale) : mX(mX), mY(mY), objScale(scale), direction(0), speed(0), isVisible(true) {}

CROBJECT::CROBJECT(double mX, double mY, double objScale, int direction = 1) : mX(mX), mY(mY), objScale(objScale), direction(direction), speed(0) {}

void CROBJECT::shiftObject(char UorD) {
    if (UorD == 'U' || UorD == 'u')
        sprite.move(direction * 0.000625 * speed - Constants::shiftVelocityX, direction * tan(Constants::Alpha) * 0.000625 * speed - Constants::shiftVelocityX * tan(-Constants::Beta));
    else if (UorD == 'D' || UorD == 'd')
        sprite.move(direction * 0.000625 * speed + Constants::shiftVelocityX, direction * tan(Constants::Alpha) * 0.000625 * speed + Constants::shiftVelocityX * tan(-Constants::Beta));
}

bool CROBJECT::checkOutWindow(sf::RenderWindow& window) {
    return (direction == 1 && (sprite.getPosition().x >= window.getSize().x + 100 || sprite.getPosition().y >= window.getSize().y + 100)) || (direction == -1 && (sprite.getPosition().x <= -100 || sprite.getPosition().y <= -100));
}

void CROBJECT::setVisible(bool typ) {
    isVisible = true;
}

void CROBJECT::move(float x, float y, float frac) {
    sprite.move(direction * Constants::basicVelocityX * speed * frac, direction * tan(Constants::Alpha) * Constants::basicVelocityX * speed * frac);
}

void CROBJECT::draw(sf::RenderWindow& window) {
    if (checkOutWindow(window) == 0) {
        //cout << "Object::drawing\n";
        window.draw(sprite);
    }
}

sf::Vector2f CROBJECT::getPos()
{
    return sf::Vector2f(mX, mY);
}
