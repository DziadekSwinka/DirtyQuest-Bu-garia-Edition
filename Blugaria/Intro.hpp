#ifndef INTRO_HPP_INCLUDED
#define INTRO_HPP_INCLUDED

#include <SFML/Graphics.hpp>

#include "FrameTime.h"

#include "Plane.hpp"
#include "Background.hpp"
#include "Cloud.hpp"

class intro
{
private:
    sf::RenderWindow &window;
    plane *Plane;
    background *Background;
    cloud *Cloud;
    sf::Clock clock;
public:
    bool show;
    intro(sf::RenderWindow &window1):window(window1)
    {
        show=true;
        Plane=new plane(window);
        Background=new background(window);
        Cloud=new cloud(window);
        clock.restart();
    }
    void Update(double delta)
    {
        Background->Update(delta);
        if(clock.getElapsedTime().asSeconds()<6)
        {
            Plane->Update(delta);
            Cloud->Update(delta);
        }
    }
};

#endif // INTRO_HPP_INCLUDED
