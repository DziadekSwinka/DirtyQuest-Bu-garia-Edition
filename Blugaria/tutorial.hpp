#ifndef TUTORIAL_HPP_INCLUDED
#define TUTORIAL_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <string>

#include "JSON.hpp"

class tutorial
{
private:
    sf::RenderWindow &window;
    sf::Sprite sprite;
    sf::Texture txt;
    using json=nlohmann::json;
    json j;
public:
    tutorial(sf::RenderWindow &window1):window(window1)
    {
        background::loadJSON(&j);
        txt.loadFromFile(j["helper"]);
        sprite.setTexture(txt);
        sprite.setRotation(45);
        sprite.setScale(0.5,0.5);
        sprite.setPosition(50,300);
    }
    void Update()
    {
        window.draw(sprite);
    }
};

#endif // TUTORIAL_HPP_INCLUDED
