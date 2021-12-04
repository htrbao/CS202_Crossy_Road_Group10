#include "CGRASS.h"

CGRASS::CGRASS(sf::Vector2f pos, bool above)
{
    m_originX = pos.x + Constants::SIZE_ROAD_X;
    m_originY = pos.y - half_scale * Constants::SIZE_ROAD_Y;
    objScale = half_scale;
    if (above)
        texture = &CASSET::GetInstance().textureMap[asset_name_grass_above];
    else
        texture = &CASSET::GetInstance().textureMap[asset_name_grass];


    sprite.setTexture(*texture);
    sprite.setPosition(m_originX, m_originY);
}

CGRASS::CGRASS(float index, bool above): CROAD(true)
{
    m_originX = -index * Constants::SIZE_ROAD_X + Constants::HIDDEN_ROAD_X;
    m_originY = index * (Constants::SIZE_ROAD_Y + Constants::bias) - Constants::HIDDEN_ROAD_Y;
    objScale = half_scale;
    if (above)
        texture = &CASSET::GetInstance().textureMap[asset_name_grass_above];
    else
        texture = &CASSET::GetInstance().textureMap[asset_name_grass];


    sprite.setTexture(*texture);
    sprite.setPosition(m_originX, m_originY);
}

CGRASS::~CGRASS()
{
}

bool CGRASS::is_road()
{
    return false;
}
