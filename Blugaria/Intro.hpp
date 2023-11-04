#ifndef INTRO_HPP_INCLUDED
#define INTRO_HPP_INCLUDED

#include <SFML/Graphics.hpp>

#include "FrameTime.h"

#include "Plane.hpp"
#include "Background.hpp"
#include "Cloud.hpp"

#include "Game.hpp"

extern bool isLoaded;

class intro
{
private:
    sf::RenderWindow &window;
    plane *Plane;
    background *Background;
    cloud *Cloud;
    sf::Clock clock;
    bool timer;
public:
    bool show;
    intro(sf::RenderWindow &window1):window(window1)
    {
        show=true;
        Background=new background(window);
        Cloud=new cloud(window);
        Plane=new plane(window);
        clock.restart();
    }
    void Update(double delta)
    {
        if(isLoaded==false)
        {
            clock.restart();
            Plane->clock.restart();
            Background->clock.restart();
            return;
        }
        if(!timer)
        {
            clock.restart();
            timer=true;
            return;
        }
        if(clock.getElapsedTime().asSeconds()<9)        //9
        {
            Background->Update(delta);
            if(clock.getElapsedTime().asSeconds()<6)    //6
            {
                Plane->Update(delta);
                Cloud->Update(delta);
            }
        }
        else
        {
        show=false;
        if(Cloud!=nullptr)
            {
                delete Cloud;
                delete Plane;
                delete Background;
                Cloud=nullptr;
                Plane=nullptr;
                Background=nullptr;
            }
        }
    }
};

#endif // INTRO_HPP_INCLUDED
