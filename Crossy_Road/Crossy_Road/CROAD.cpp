
#include "CROAD.h"

CROAD::CROAD() {
    m_originX = 0;
    m_originY = 0;
    numOfRoad++;
}

CROAD::~CROAD()
{
    numOfRoad--;
}

bool CROAD::checkOutWindow(sf::RenderWindow& window)
{
    return sprite.getPosition().y >= (window.getSize().y + size_road);
}

void CROAD::transposition(char UorD)
{
    if (UorD == 'U' || UorD == 'u')
        sprite.move(-0.25, 0.25 * tan(Constants::Beta));
    else if (UorD == 'D' || UorD == 'd')
        sprite.move(0.25, -0.25 * tan(Constants::Beta));
    m_originX = sprite.getPosition().x;
    m_originY = sprite.getPosition().y;
}

void CROAD::draw(sf::RenderWindow& window)
{
    if (!checkOutWindow(window)) window.draw(sprite);
}

int CROAD::getNumRoads()
{
    return numOfRoad;
}
