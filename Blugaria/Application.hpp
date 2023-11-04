#ifndef APPLICATION_HPP_INCLUDED
#define APPLICATION_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <thread>
#include <mutex>

#include "Intro.hpp"
#include "Game.hpp"
#include "FrameTime.h"

bool isLoaded=false;

void application()
{
    sf::RenderWindow window(sf::VideoMode(1920,1080), "DirtyQuest: Blugaria Edition");
    intro *Intro;
    game *Game;

    std::thread t1([&window,&Intro]()
    {
        Intro=new intro(window);
    });
    std::thread t2([&window,&Game]()
    {
        Game=new game(window);
    });

    double delta=0;
    t1.join();
    t2.join();
    isLoaded=true;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color(211,214,146));
        if(Intro->show==true)
            Intro->Update(delta);
        else
        {
            Game->show=true;
            /*if(Intro!=nullptr)     //zagniezdzanie If'ow moze byc skopane! ale dziala
            {
                delete Intro;
                //Intro=nullptr;
            }*/
        }
        if(Game->show==true)
        {
            Game->Update(delta);
        }
        window.display();
    deltaTime.PrevFrameTime=deltaTime.TimeAsSec.getElapsedTime();
    delta=deltaTime.FrameTime();
    deltaTime.TimeAsSec.restart();
    }
}
#endif // APPLICATION_HPP_INCLUDED
