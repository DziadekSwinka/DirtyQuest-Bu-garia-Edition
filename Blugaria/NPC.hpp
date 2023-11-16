#ifndef NPC_HPP_INCLUDED
#define NPC_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <fstream>
#include <cmath>

#include "JSON.hpp"
#include "Background.hpp"

class NPC
{
private:
    float position,speed;
    bool dir;
    sf::RenderWindow &window;
    sf::Sprite sprite;
    sf::Texture txt;
    enum type
    {
        streetNPC=0,
        staticNPC=1,
        enemyNPC=2
    };
    type movement;
    using json=nlohmann::json;
    json j;
public:
    NPC(sf::RenderWindow &window1,int Type):window(window1),movement(static_cast<type>(Type))
    {
        std::fstream file;
        file.open("textures.json");
        file>>j;
        file.close();
        txt.loadFromFile(j["npc"][static_cast<int>(movement)]);
        sprite.setTexture(txt);
        if(static_cast<int>(movement)==0)
        {
            position=std::rand()%1920;
            sprite.setScale(0.1,0.1);
            dir=std::rand()%2;
            switch(std::rand()%4)
            {
                case 0: speed=1.5;  break;
                case 1: speed=2;    break;
                case 2: speed=0.5;  break;
                case 3: speed=1;    break;
            }
        }else
        if(static_cast<int>(movement)==1)
        {
            position=3500;
            sprite.setScale(0.3,0.3);
        }
        sprite.setPosition(position,750+std::rand()%200);

    }
    void Update(float delta)
    {
        if(static_cast<int>(movement)==0)
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
        }else if(static_cast<int>(movement)==1)
        {
            sprite.setPosition(background::position+position,sprite.getPosition().y);
        }
        window.draw(sprite);
    }
};

#endif // NPC_HPP_INCLUDED
