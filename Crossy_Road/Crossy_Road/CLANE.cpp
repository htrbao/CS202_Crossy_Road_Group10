
#include "CLANE.h"

CLANE::CLANE()
{
    texture = &CASSET::GetInstance().textureMap[asset_name];
    objScale = scale;
    sprite.setTexture(*texture);
    sprite.scale(objScale, objScale);
    sprite.setPosition(m_originX, m_originY);
}

CLANE::CLANE(int index) : CROAD()
{
    m_originX = -index * Constants::SIZE_ROAD_X + Constants::HIDDEN_ROAD_X;
    m_originY = index * Constants::SIZE_ROAD_Y - Constants::HIDDEN_ROAD_Y;
    texture = &CASSET::GetInstance().textureMap[asset_name];
    objScale = scale;
    sprite.setTexture(*texture);
    sprite.scale(objScale, objScale);
    sprite.setPosition(m_originX , m_originY);
}

CLANE::~CLANE()
{
    
}



