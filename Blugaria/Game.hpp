#ifndef GAME_HPP_INCLUDED
#define GAME_HPP_INCLUDED

#include "Background.hpp"
#include "Character.hpp"
#include "Level.hpp"
#include "Bins.hpp"
#include "GUI.hpp"
#include "tutorial.hpp"
#include "Escape.hpp"

#include <iostream>



class game
{
private:
    sf::RenderWindow &window;
    background *Background;
    character *MainChar;
    bins *Bins;
    GUI *Interface;
    tutorial *Tutorial;
    Escape *escape;
public:
    bool show;
    game(sf::RenderWindow &window1):window(window1)
    {
        show=false;
        Background=new background(window,"foo foo");
        MainChar=new character(window);
        Tutorial=new tutorial(window);
        Bins=new bins(window,Tutorial);
        Interface=new GUI(window);
        Tutorial->setTutorialSlide(0);
        escape=new Escape(window,Background);
    }
    void Update(float delta)
    {
        Background->Update(delta);
        if(!isEscape)
            Bins->Update();
        if(isAlive)
            MainChar->Update();
        Interface->Update();
        Tutorial->Update(delta);
        //if(escape!=nullptr)
        if(isEscape && isAlive)
            escape->Update(delta);
    }
};

#endif // GAME_HPP_INCLUDED
