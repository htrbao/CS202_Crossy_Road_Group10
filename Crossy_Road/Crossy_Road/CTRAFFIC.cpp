#include "CTRAFFIC.h"

void CTRAFFIC::setUpTexture()
{
    sprite.setTexture(*texture);

    sprite.setOrigin(0, HEIGHT);

    sprite.setPosition(mX, mY);
}

CTRAFFIC::CTRAFFIC()
{
    hasTraff = false;
}

CTRAFFIC::CTRAFFIC(float x, float y)
{
    float tmp = (x / 512 + 1) * 50 + Constants::SCREEN_WIDTH/2;
    mX = x + tmp;
    mY = y + tmp * tan(Constants::Alpha) + 50;
    texture = &CASSET::GetInstance().textureMap[Constants::TRAFFICNAME];
    diff = rand() % 6 - 1;
    hasTraff = true;
    setUpTexture();
    green();
}


int CTRAFFIC::statusTraffic()
{
    return status;
}

void CTRAFFIC::red()
{
    status = 0;
    sprite.setTextureRect(sf::IntRect(WIDTH * status, 0, WIDTH, HEIGHT));
    clc.restart();
}

void CTRAFFIC::yellow()
{
    status = 1;
    sprite.setTextureRect(sf::IntRect(WIDTH * status, 0, WIDTH, HEIGHT));
    clc.restart();
}

void CTRAFFIC::green()
{
    status = 2;
    sprite.setTextureRect(sf::IntRect(WIDTH * status, 0, WIDTH, HEIGHT));
    clc.restart();
}

void CTRAFFIC::update(sf::RenderWindow& window)
{
    switch (status)
    {
    case 0:
        if (clc.getElapsedTime().asSeconds() >= 4 + diff)
        {
            green();
        }
        break;
    case 1:
        if (clc.getElapsedTime().asSeconds() >= 3 + diff)
        {
            red();
        }
        break;
    case 2:
        if (clc.getElapsedTime().asSeconds() >= 10 + diff)
        {
            yellow();
        }
        break;
    default:
        break;
    }
}

void CTRAFFIC::draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}

void CTRAFFIC::shiftObject(char UorD)
{
    if (UorD == 'U' || UorD == 'u')
    {
        sprite.move(-Constants::shiftVelocityX, Constants::shiftVelocityX * tan(Constants::Beta));
    }
    else if (UorD == 'D' || UorD == 'd')
    {
        sprite.move(Constants::shiftVelocityX, -Constants::shiftVelocityX * tan(Constants::Beta));
    }
    mX = sprite.getPosition().x;
    mY = sprite.getPosition().y;
}

bool CTRAFFIC::hasTraffic()
{
    return hasTraff;
}

