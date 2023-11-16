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
#include "NPC.hpp"

#include <iostream>
#include <vector>

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
    std::vector<NPC*>NPCs;
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
        NPCs.resize(6);
        for(long long unsigned int i=0;i<NPCs.size()-1;i++)
            NPCs[i]=new NPC(window,0);
        NPCs[NPCs.size()-1]=new NPC(window,1);
    }
    void Update(float delta)
    {
        Background->Update(delta);
        if(!isEscape)
            Bins->Update();
        if(isAlive && !isQuiz)
            MainChar->Update();
        for(long long unsigned int i=0;i<NPCs.size();i++)
            NPCs[i]->Update(delta);
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
