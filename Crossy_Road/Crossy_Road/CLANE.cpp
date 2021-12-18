
#include "CLANE.h"


CLANE::CLANE(sf::Vector2f pos, bool one_way):CROAD(one_way)
{
    objScale = scale;
    is_oneway = one_way;

    if (one_way)
    {
        texture = &CASSET::GetInstance().textureMap[asset_name_road_oneway];
        objScale -= half_scale;
    }
    else
    {
        texture = &CASSET::GetInstance().textureMap[asset_name_road_twoway];
    }
    m_originX = pos.x + Constants::SIZE_ROAD_X + Constants::SIZE_ROAD_X/3;
    m_originY = pos.y - objScale * Constants::SIZE_ROAD_Y + Constants::SIZE_ROAD_X * tan(Constants::Alpha)/3;
    dis = m_originY - m_originX * tan(Constants::Alpha);
    sprite.setTexture(*texture);
    sprite.setPosition(m_originX, m_originY);
    //carFac.initCarGame(m_originX, m_originY);
}

CLANE::CLANE(float index, bool one_way) : CROAD(one_way)
{
    m_originX = -index * Constants::SIZE_ROAD_X + Constants::HIDDEN_ROAD_X;
    m_originY = index * (Constants::SIZE_ROAD_Y + Constants::bias) - Constants::HIDDEN_ROAD_Y + Constants::bias;
    objScale = scale;
    is_oneway = one_way;
 
    if (one_way)
    {
        texture = &CASSET::GetInstance().textureMap[asset_name_road_oneway];
        objScale -= half_scale;
    }
    else
    {
        texture = &CASSET::GetInstance().textureMap[asset_name_road_twoway];
    }
    dis = m_originY - m_originX * tan(Constants::Alpha);
    sprite.setTexture(*texture); 
    sprite.setPosition(m_originX , m_originY);
    //carFac.initCarGame(m_originX, m_originY);
}

CLANE::~CLANE()
{
    carFac.~CRCARFACTORY();
    if (!is_oneway)
    {
        carFac1.~CRCARFACTORY();
    }
}

bool CLANE::is_road()
{
    return true;
}

void CLANE::drawSubObj(sf::RenderWindow& window)
{
    carFac.draw(window);
    if (!is_oneway)
    {
        carFac1.draw(window);
    }
}

void CLANE::shiftSubObj(char UorD)
{
    carFac.shiftObject(UorD);
    if (!is_oneway)
    {
        carFac1.shiftObject(UorD);
    }
}

void CLANE::update(sf::RenderWindow& window)
{
    carFac.update(m_originX, m_originY, window);
    if (!is_oneway)
    {
        carFac1.update(m_originX, m_originY + (Constants::SIZE_ROAD_Y + Constants::bias) / 2, window);
    }
}

int CLANE::typeSound()
{
    if (!playing) 
    {
        playing = true;
        if (carFac.typeSound() == 2 || carFac1.typeSound() == 2)
            return 2;
        else
            return carFac.typeSound();
    }
    return -1;
}






