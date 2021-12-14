#ifndef _CRGUI_H_

#define _CRGUI_H_

#include "Constants.h"
#include "CASSET.h"
#include "CGAME.h"

class CRGUI {
private:
    friend class CGAME;
    sf::Sprite pauseButton;
    sf::Texture* pauseButtonTexture;
    sf::Font fontType;
    sf::Text SCORE_TEXT;
    sf::Text BESTSCORE_TEXT;
    sf::Text LEVEL_TEXT;
    sf::Text GAMEOVER_TEXT;

    float WIDTH, HEIGHT;
public:
    CRGUI(float width, float height);

};

#endif // !_CRGUI_H_
