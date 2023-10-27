#include <SFML/Graphics.hpp>
#include <iostream>

#include "Intro.hpp"
#include "FrameTime.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1920,1080), "DirtyQuest: Blugaria Edition");
    intro Intro(window);
    double delta=0;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        if(Intro.show==true)
            Intro.Update(delta);
        window.display();
    deltaTime.PrevFrameTime=deltaTime.TimeAsSec.getElapsedTime();
    delta=deltaTime.FrameTime();
    deltaTime.TimeAsSec.restart();
    }
    return 0;
}
