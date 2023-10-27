#ifndef BACKGROUND_HPP_INCLUDED
#define BACKGROUND_HPP_INCLUDED

#include <SFML/Graphics.hpp>

#include "Cloud.hpp"

class background
{
private:
    sf::RenderWindow &window;
    sf::Sprite Back,Intro;
    sf::Texture txt1,txt2;
    cloud *Cloud;
    sf::Clock clock;
    short alpha=0;
public:
    background(sf::RenderWindow &window1):window(window1)
    {
        clock.restart();
        txt1.loadFromFile("Textures//Blugaria Intro.png");
        txt2.loadFromFile("Textures//Intro.png");
        Back.setTexture(txt1);
        Intro.setTexture(txt2);
        Cloud=new cloud(window);
        Intro.setColor(sf::Color(225,225,225,0));
    }
    void Update(double delta)
    {
        window.draw(Back);
        Cloud->Update(delta);
        if(clock.getElapsedTime().asSeconds()>5)
        {
            Intro.setColor(sf::Color(255,255,255,alpha));
            if(alpha<255)
                alpha+=5*delta;
            window.draw(Intro);
        }

    }
};
#endif // BACKGROUND_HPP_INCLUDED
