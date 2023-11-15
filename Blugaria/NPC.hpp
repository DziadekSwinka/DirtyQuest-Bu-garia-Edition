#ifndef NPC_HPP_INCLUDED
#define NPC_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <fstream>

#include "JSON.hpp"

class NPC
{
private:
    //float position;
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
    }
    void Update(float delta)
    {
        window.draw(sprite);
    }
};

#endif // NPC_HPP_INCLUDED
