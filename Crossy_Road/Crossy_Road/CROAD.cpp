
#include "CROAD.h"

CROAD::CROAD(bool half_scale) {
    if (half_scale)
        numOfRoad += 0.5;
    else
        numOfRoad += 1;
    playing = false;
}

CROAD::~CROAD()
{
    numOfRoad-= objScale;
    carFac.~CRCARFACTORY();
    carFac1.~CRCARFACTORY();
    blcFac.~CRBLOCKFACTORY();
}

bool CROAD::checkOutWindow(sf::RenderWindow& window)
{
    return (sprite.getPosition().y + objScale * Constants::SIZE_ROAD_Y) >= (Constants::SCREEN_HEIGHT + Constants::HIDDEN_ROAD_Y/1.2);
}

bool CROAD::checkOutWindow2(sf::RenderWindow& window)
{
    return (sprite.getPosition().x  <= 500);
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
        sprite.move(-Constants::shiftVelocityX, Constants::shiftVelocityX * tan(Constants::Beta));
    }
    else if (UorD == 'D' || UorD == 'd')
    {
        sprite.move(Constants::shiftVelocityX, -Constants::shiftVelocityX * tan(Constants::Beta));
    }
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


void CROAD::setPlaying()
{
    playing = false;
}

double CROAD::getNumRoads()
{
    return numOfRoad;
}
