
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
    m_originX = pos.x + Constants::SIZE_ROAD_X;
    m_originY = pos.y - objScale * Constants::SIZE_ROAD_Y;

    sprite.setTexture(*texture);
    sprite.setPosition(m_originX, m_originY);
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
    
    sprite.setTexture(*texture); 
    sprite.setPosition(m_originX , m_originY);
}

CLANE::~CLANE()
{
    
}

bool CLANE::is_road()
{
    return true;
}



