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
        Background=new background(window,"PFPFPFPF");
        MainChar=new character(window);
        Tutorial=new tutorial(window);
        Bins=new bins(window,Tutorial);
        Interface=new GUI(window);
        Tutorial->setTutorialSlide(0);
        escape=new Escape(window,Background);
        quiz=new Quiz(window);
        NPCs.resize(6);
        for(long long unsigned int i=0;i<NPCs.size()-1;i++)
            NPCs[i]=new NPC_animal(window);
        NPCs[NPCs.size()-1]=new NPC_static(window);
    }
    void Update(float delta)
    {
        if(1900<=-background::position && -background::position<=2100)
            Tutorial->setTutorialSlide(2);

        Background->Update(delta);
        if(!isEscape)
            Bins->Update();
        if(isAlive /*&& !isQuiz*/)
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
