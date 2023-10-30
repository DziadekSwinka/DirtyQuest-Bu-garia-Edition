#ifndef BACKGROUND_HPP_INCLUDED
#define BACKGROUND_HPP_INCLUDED

#include <SFML/Graphics.hpp>

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

#include "json.hpp"

#define NumberOfTextures 7
#define Speed 1

class background
{
private:
    sf::RenderWindow &window;
    sf::Sprite Back;
    sf::Sprite Front;
    std::vector<sf::Sprite>sprites;
    std::vector<sf::Texture>txt;
    sf::Clock clock;
    using json=nlohmann::json;
    json j;
    short alpha=0;
    void updateIntro(float delta);
    void updateGame(float delta);
    static float position;
    static float backgroundPosition;
    float width;
    void loadJSON()
    {

        std::fstream reader;
        reader.open("config.json");
        reader>>j;
        reader.close();
    }
public:
    enum
    {
        Intro,
        MainGame
    }type;
    background(sf::RenderWindow &window1);
    background(sf::RenderWindow &window1,std::string s);
    void Update(double delta);
};

#endif // BACKGROUND_HPP_INCLUDED
