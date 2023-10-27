#ifndef GAME_HPP_INCLUDED
#define GAME_HPP_INCLUDED

#include "Background.hpp"

class game
{
private:
    sf::RenderWindow &window;
    background *Background;
public:
    bool show;
    game(sf::RenderWindow &window1):window(window1)
    {
        show=false;
        Background=new background(window,"Textures//MainBCG.png");
    }
    void Update(float delta)
    {
        Background->Update(delta);
    }
};

#endif // GAME_HPP_INCLUDED
