
#include "CROAD.h"

CROAD::CROAD(bool half_scale) {
    if (half_scale)
        numOfRoad += 0.5;
    else
        numOfRoad += 1;
}

CROAD::~CROAD()
{
    numOfRoad-= objScale;
}

bool CROAD::checkOutWindow(sf::RenderWindow& window)
{
    return (sprite.getPosition().y + objScale * Constants::SIZE_ROAD_Y) >= (Constants::SCREEN_HEIGHT + Constants::HIDDEN_ROAD_Y/2);
}

bool CROAD::checkOutWindow2(sf::RenderWindow& window)
{
    return (sprite.getPosition().x  <= -Constants::SCREEN_WIDTH/2);
}


sf::Vector2f CROAD::getPosition()
{
    return sf::Vector2f(m_originX,m_originY);
}

float CROAD::getDis()
{
    return dis;
}



void CROAD::shiftObject(char UorD)
{
    if (UorD == 'U' || UorD == 'u')
    {
        sprite.move(-0.25, 0.25 * tan(Constants::Beta));
    }
    else if (UorD == 'D' || UorD == 'd')
        sprite.move(0.25, -0.25 * tan(Constants::Beta));
    m_originX = sprite.getPosition().x;
    m_originY = sprite.getPosition().y;
    dis = m_originY - m_originX * tan(Constants::Alpha);
    shiftSubObj(UorD);
    //sprite.setPosition(m_originX, m_originY);
}

void CROAD::draw(sf::RenderWindow& window)
{
   window.draw(sprite);
}

double CROAD::getNumRoads()
{
    return numOfRoad;
}
