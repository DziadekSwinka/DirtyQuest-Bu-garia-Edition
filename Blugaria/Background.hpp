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

extern bool isEscape;
extern bool isAlive;

class background
{
    friend class intro;
private:
    sf::RenderWindow &window;
    sf::Sprite Back;
    sf::Sprite Front;
    sf::Sprite Background;
    std::vector<sf::Sprite>sprites;
    std::vector<sf::Sprite>tiles;
    std::vector<sf::Texture>txt;
    sf::Texture Stxt,Btxt;
    sf::Clock clock;
    using json=nlohmann::json;
    json j;
    short alpha=0;
    void updateIntro(float delta);
    void updateGame(float delta);
    float width;
    bool timer=false;
    static bool isJSONLoaded;
public:
    enum
    {
        Intro,
        MainGame
    }type;
    background(sf::RenderWindow &window1);
    background(sf::RenderWindow &window1,std::string s);
    void Update(double delta);
    void Left(float S,float delta);
    void Right(float S,float delta);
    static float position;
    static float backgroundPosition;
    static void loadJSON(nlohmann::json *jn)
    {
        /*if(!isJSONLoaded)
        {*/
            std::fstream reader;
            reader.open("config.json");
            reader>>*jn;
            reader.close();
        /*}
        else
        *jn=j;*/
    }
};

#endif // BACKGROUND_HPP_INCLUDED
