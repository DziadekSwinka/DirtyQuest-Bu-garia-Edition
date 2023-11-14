#ifndef GAME_HPP_INCLUDED
#define GAME_HPP_INCLUDED

#include "Background.hpp"
#include "Character.hpp"
#include "Level.hpp"
#include "Bins.hpp"
#include "GUI.hpp"
#include "tutorial.hpp"
#include "Escape.hpp"
#include "Quiz.hpp"

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
    Quiz *quiz;
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
        quiz=new Quiz(window);
    }
    void Update(float delta)
    {
        Background->Update(delta);
        if(!isEscape)
            Bins->Update();
        if(isAlive && !isQuiz)
            MainChar->Update();
        Interface->Update();
        Tutorial->Update(delta);
        //if(escape!=nullptr)
        if(isEscape && isAlive && !isQuiz)
            escape->Update(delta);
        if(isQuiz)
            quiz->Update();
    }
};

#endif // GAME_HPP_INCLUDED
