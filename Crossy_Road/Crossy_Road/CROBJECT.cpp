#include "CROBJECT.h"

void CROBJECT::shiftObject() {

}

bool CROBJECT::checkOutWindow(sf::RenderWindow& window) {
    return (direction && (sprite.getPosition().x >= window.getSize().x || sprite.getPosition().y >= window.getSize().y)) || (direction == -1 && (sprite.getPosition().x <= 0 || sprite.getPosition().y <= 0));
}
