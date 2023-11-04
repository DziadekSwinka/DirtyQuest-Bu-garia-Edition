#ifndef GAME_HPP_INCLUDED
#define GAME_HPP_INCLUDED

#include "Background.hpp"
#include "Character.hpp"
#include "Level.hpp"
#include "Bins.hpp"
#include "GUI.hpp"
#include "tutorial.hpp"

class game
{
private:
    sf::RenderWindow &window;
    background *Background;
    character *MainChar;
    bins *Bins;
    GUI *Interface;
    tutorial *Tutorial;
public:
    bool show;
    game(sf::RenderWindow &window1):window(window1)
    {
        show=false;
        Background=new background(window,"foo foo");
        MainChar=new character(window);
        Bins=new bins(window);
        Tutorial=new tutorial(window);
        Interface=new GUI(window);
    }
    void Update(float delta)
    {
        Background->Update(delta);
        Bins->Update();
        MainChar->Update();
        Interface->Update();
        Tutorial->Update();
    }
};

#endif // GAME_HPP_INCLUDED
