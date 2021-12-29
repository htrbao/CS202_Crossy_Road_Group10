#include "CGRASS.h"

CGRASS::CGRASS(sf::Vector2f pos, bool above):CROAD(true)
{
    m_originX = pos.x + Constants::SIZE_ROAD_X;
    m_originY = pos.y - half_scale * Constants::SIZE_ROAD_Y;
    objScale = half_scale;
    is_above = above;
    if (above)
        texture = &CASSET::GetInstance().textureMap[asset_name_grass_above];
    else
        texture = &CASSET::GetInstance().textureMap[asset_name_grass];

    dis = m_originY - m_originX * tan(Constants::Alpha);
    sprite.setTexture(*texture);
    sprite.setPosition(m_originX, m_originY);
    blcFac.initObjGame(m_originX, m_originY);
}

CGRASS::CGRASS(float index, bool above): CROAD(true)
{
    m_originX = -index * Constants::SIZE_ROAD_X + Constants::HIDDEN_ROAD_X;
    m_originY = index * (Constants::SIZE_ROAD_Y + Constants::bias) - Constants::HIDDEN_ROAD_Y;

    objScale = half_scale;
    is_above = above;

    if (above)
        texture = &CASSET::GetInstance().textureMap[asset_name_grass_above];
    else
        texture = &CASSET::GetInstance().textureMap[asset_name_grass];
    dis = m_originY - m_originX * tan(Constants::Alpha);
    sprite.setTexture(*texture);
    sprite.setPosition(m_originX, m_originY);
    blcFac.initObjGame(m_originX, m_originY,true);
}

CGRASS::CGRASS(float x, float y, bool above) : CROAD(x, y, true)
{
    objScale = half_scale;
    is_above = above;
    if (above)
        texture = &CASSET::GetInstance().textureMap[asset_name_grass_above];
    else
        texture = &CASSET::GetInstance().textureMap[asset_name_grass];
    sprite.setTexture(*texture);
    sprite.setPosition(m_originX, m_originY);
    blcFac.initObjGame(m_originX, m_originY, true);
}

CGRASS::~CGRASS()
{
    blcFac.~CRBLOCKFACTORY();
}

bool CGRASS::is_road()
{
    return false;
}

void CGRASS::drawSubObj(sf::RenderWindow& window)
{
    blcFac.draw(window);
}

void CGRASS::shiftSubObj(char UorD)
{
    blcFac.shiftObject(UorD);
}

void CGRASS::update(sf::RenderWindow& window)
{
    blcFac.update(window);
}

int CGRASS::typeSound()
{
    if (!playing)
    {
        return blcFac.typeSound();
    }
    return -1;
}

int CGRASS::typeSound2()
{
    return -1;
}

bool CGRASS::isHighway()
{
    return false;
}

deque<CROBJECT*>* CGRASS::getObjFac()
{
    return blcFac.getObjQueue();
}

deque<CROBJECT*>* CGRASS::getObjFac2()
{
    return nullptr;
}

void CGRASS::saveDerivedRoad(ofstream& of)
{
    of.write((char*)&is_above, sizeof(is_above));
}

