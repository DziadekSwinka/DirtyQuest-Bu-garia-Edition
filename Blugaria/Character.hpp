#ifndef CHARACTER_HPP_INCLUDED
#define CHARACTER_HPP_INCLUDED

#include <SFML/Graphics.hpp>

#include "json.hpp"
#include "FrameTime.h"

#include "Background.hpp"

extern bool isEscape;
extern bool isAlive;

class character
{
private:
    sf::RenderWindow &window;
    sf::Sprite sprite;
    sf::Texture txt;
    sf::Clock clock;
    using json=nlohmann::json;
    json j;
public:
    static unsigned int BinsPoints;
    static unsigned int CleanPoints;
    static unsigned int Money;
    character(sf::RenderWindow &window1):window(window1)
    {
        background::loadJSON(&j);
        txt.loadFromFile(j["character"]);
        sprite.setTexture(txt);
        sprite.setScale(0.3,0.3);
        sprite.setOrigin(txt.getSize().x/2,txt.getSize().y/2);
        sprite.setPosition(window.getSize().x/2,800);
        clock.restart();
    }
    void Update();
};

#endif // CHARACTER_HPP_INCLUDED
