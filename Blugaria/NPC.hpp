#ifndef NPC_HPP_INCLUDED
#define NPC_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <fstream>
#include <cmath>

#include "JSON.hpp"
#include "Background.hpp"

class NPC
{
protected:
    float position;
    sf::RenderWindow &window;
    sf::Sprite sprite;
    sf::Texture txt;
    using json=nlohmann::json;
    json j;
public:
    NPC(sf::RenderWindow &window1):window(window1)
    {
        std::fstream file;
        file.open("textures.json");
        file>>j;
        file.close();
    }
    virtual void Update(float delta)
    {
        sprite.setPosition(background::position+position,sprite.getPosition().y);
        window.draw(sprite);
    }
};
class NPC_static
    :public NPC
{
private:

public:
    NPC_static(sf::RenderWindow &window1):NPC(window1)
    {
        txt.loadFromFile(j["npc"][1]);
        sprite.setTexture(txt);
        sprite.setScale(0.3,0.3);
        position=3500;
        sprite.setPosition(position,630);
    }
    virtual void Update(float delta)
    {
        sprite.setPosition(background::position+position,sprite.getPosition().y);
        window.draw(sprite);
    }
};

class NPC_animal
    :public NPC
{
private:
    bool dir;
    float speed;
public:
    NPC_animal(sf::RenderWindow &window1):NPC(window1)
    {
        position=std::rand()%1920;
        dir=std::rand()%2;
        switch(std::rand()%4)
        {
            case 0: speed=1.5;  break;
            case 1: speed=2;    break;
            case 2: speed=0.5;  break;
            case 3: speed=1;    break;
        }
        txt.loadFromFile(j["npc"][0]);
        sprite.setTexture(txt);
        sprite.setScale(0.1,0.1);
        sprite.setPosition(position,750+std::rand()%200);
    }
    virtual void Update(float delta)
    {
        if(position<0)
            dir=1;
        if(position>1920)
            dir=0;
        if(dir==0)
        {
            position-=speed*delta;
        }
        if(dir==1)
        {
            position+=speed*delta;
        }
        sprite.setPosition(position,sprite.getPosition().y);
        window.draw(sprite);
    }

};

#endif // NPC_HPP_INCLUDED
