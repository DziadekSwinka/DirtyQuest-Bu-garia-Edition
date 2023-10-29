#ifndef BACKGROUND_HPP_INCLUDED
#define BACKGROUND_HPP_INCLUDED

#include <SFML/Graphics.hpp>

#include <string>
#include <vector>
#include <fstream>

#include "json.hpp"

#define NumberOfTextures 4

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
    float position=0;
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
    background(sf::RenderWindow &window1):window(window1)
    {
        loadJSON();
        txt.resize(2);
        type=Intro;
        clock.restart();
        txt[0].loadFromFile(j["introBack"]);
        txt[1].loadFromFile(j["introFront"]);
        Back.setTexture(txt[0]);
        Front.setTexture(txt[1]);
        Front.setColor(sf::Color(225,225,225,0));
    }
    background(sf::RenderWindow &window1,std::string s):window(window1)
    {
        loadJSON();
        txt.resize(NumberOfTextures);
        sprites.resize(8);
        type=MainGame;
        clock.restart();
        for(long long unsigned int i=0;i<txt.size();i++)
        {
            //txt[i].loadFromFile(file+std::to_string(i)+".png");
            txt[i].loadFromFile(j["houses"][i]);
        }
        for(long long unsigned int i=0;i<sprites.size();i++)
        {
            sprites[i].setTexture(txt[i%NumberOfTextures]);
            sprites[i].setScale(0.1,0.1);
        }
        position=0;
        width=[](std::vector<sf::Texture>&txt)      ///lamdba!!!
        {
            float total;
            for(long long unsigned int i=0;i<txt.size();i++)
                total+=txt[i].getSize().x;
            return total*0.1;
        }(txt);
    }
    void Update(double delta)
    {
        switch(type)
        {
        case 0:
            updateIntro(delta);
            break;
        case 1:
            updateGame(delta);
            break;
        default:
            throw;
        }
    }
};
void background::updateIntro(float delta)
{
    window.draw(Back);
    if(clock.getElapsedTime().asSeconds()>6)
    {
        Front.setColor(sf::Color(255,255,255,alpha));
        if(alpha<255)
            alpha+=3*delta;
        window.draw(Front);
    }
}
void background::updateGame(float delta)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        position-=2*delta;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        position+=2*delta;
    for(long long unsigned int i=0;i<sprites.size();i++)
    {
        //sprites[i].setPosition(position+txt[((i+3)%4)].getSize().x,700);   //txt maja rozna szerokosc wiec to bedzie trzeba uwzglednic w tej linijce
        switch(i%NumberOfTextures)
        {
        case 0:
            sprites[i].setPosition(position+int(i/NumberOfTextures)*width,600);
            break;
        case 1:
            sprites[i].setPosition(position+txt[0].getSize().x*sprites[0].getScale().x+(width*((int)i/NumberOfTextures)),670);
            break;
        case 2:
            sprites[i].setPosition(position+txt[1].getSize().x*sprites[1].getScale().x+txt[0].getSize().x*sprites[0].getScale().x+(width*((int)i/NumberOfTextures)),500);
            break;
        case 3:
            sprites[i].setPosition(position+txt[2].getSize().x*sprites[2].getScale().x+txt[1].getSize().x*sprites[1].getScale().x+txt[0].getSize().x*sprites[0].getScale().x+(width*((int)i/NumberOfTextures)),620);
            break;
        default:
            break;
        }
        window.draw(sprites[i]);
    }
}
#endif // BACKGROUND_HPP_INCLUDED
