#ifndef TUTORIAL_HPP_INCLUDED
#define TUTORIAL_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <queue>

#include "JSON.hpp"

#define TutorSlides 3

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
    std::queue<short>slides_q;
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
                if(!slides_q.empty())
                {
                    currentSlide=slides_q.front();
                    slides_q.pop();
                    clock.restart();
                    sprite.setPosition(50,210);
                }
                else
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
        {
            if(pastSlides[number]==false)
            {
                slides_q.push(number);
                pastSlides[number]=true;
                if(currentSlide==-1)
                {
                    currentSlide=slides_q.front();
                    slides_q.pop();
                    sprite.setPosition(50,300);
                    clock.restart();
                    return true;
                }
                return true;
            }
        return false;
        }
    }
};

#endif // TUTORIAL_HPP_INCLUDED
