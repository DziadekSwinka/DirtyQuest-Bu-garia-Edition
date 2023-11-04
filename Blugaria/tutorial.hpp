#ifndef TUTORIAL_HPP_INCLUDED
#define TUTORIAL_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

#include "JSON.hpp"

#define TutorSlides 1

class tutorial
{
private:
    sf::RenderWindow &window;
    sf::Sprite sprite;
    sf::Texture txt;
    sf::Clock clock;
    using json=nlohmann::json;
    int currentSlide={-1};
    bool timer=false;
    json j;
    struct slideSturct
    {
        sf::Texture txt;
        sf::Sprite sprite;
    };
    std::vector<slideSturct>Slides;

public:
    bool pastSlides[TutorSlides]={false};
    tutorial(sf::RenderWindow &window1):window(window1)
    {
        clock.restart();
        Slides.resize(TutorSlides);
        background::loadJSON(&j);
        txt.loadFromFile(j["helper"]);
        sprite.setTexture(txt);
        sprite.setRotation(45);
        sprite.setScale(0.5,0.5);
        sprite.setPosition(50,300);
        for(long long unsigned int i=0;i<Slides.size();i++)
        {
            Slides[i].txt.loadFromFile(j["tutorial"][i]);
            Slides[i].sprite.setTexture(Slides[i].txt);
            Slides[i].sprite.setPosition(50,210);
            Slides[i].sprite.setScale(0.7,0.7);
        }
        //currentSlide=0;
    }
    void Update(float delta)
    {
        if(!timer)
        {
            clock.restart();
            timer=true;
        }
        if(currentSlide!=(-1))
        {
            window.draw(sprite);

            if(clock.getElapsedTime().asSeconds()>5)
                sprite.move(-1*delta,0);
            else
                window.draw(Slides[currentSlide].sprite);
            if(clock.getElapsedTime().asSeconds()>7)
                currentSlide=-1;
        }
    }
    bool setTutorialSlide(short number)
    {
        if(number+1>TutorSlides || number+1<0)
            return false;
        else
        if(currentSlide==-1)
           if(pastSlides[number]==false)
        {
            currentSlide=number;
            sprite.setPosition(50,300);
            pastSlides[number]=true;
            return true;
        }
        return false;
    }
};

#endif // TUTORIAL_HPP_INCLUDED
