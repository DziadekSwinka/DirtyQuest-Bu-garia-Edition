#ifndef BINS_HPP_INCLUDED
#define BINS_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <vector>

#include "JSON.hpp"
#include "Character.hpp"
#include "Background.hpp"
#include "tutorial.hpp"

#define NumberOfBins 2

extern bool isEscape;

class background;
class character;

class Bin_handling
{
private:
    sf::RenderWindow &window;
    sf::Texture txt;
    sf::Sprite sprite;
    float pos;
    tutorial *Tutorial;
public:
    enum type
    {
        normal_bin,
        premium_bin
    };
    Bin_handling(sf::RenderWindow &window1,std::string path,type Type,tutorial *Tut):window(window1),Tutorial(Tut)
    {
        pos=(std::rand()%9000)-4500;
        txt.loadFromFile(path);
        sprite.setTexture(txt);
        sprite.setScale(0.3,0.3);
        sprite.setOrigin(txt.getSize().x/2,txt.getSize().y/2);
    }
    bool Update()
    {
        if((background::position-pos-window.getSize().x/2)<200
           &&(background::position-pos-window.getSize().x/2)>-200)
        {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::E))
            {
                if(isEscape==false && (std::rand()%5)==0)
                {
                    isEscape=true;
                    Tutorial->setTutorialSlide(1);
                }
                character::BinsPoints+=30;
                if(std::rand()%10==0)
                    character::Money+=((std::rand()%6)+1)*5;
                return true;
            }
        }
        sprite.setPosition(background::position-pos,830);
        window.draw(sprite);
        return false;
    }

};

class bins
{
private:
    sf::RenderWindow &window;
    tutorial *Tut;
    using json=nlohmann::json;
    json j;
public:
    std::vector<Bin_handling*>Bins;
    bins(sf::RenderWindow &window1,tutorial *T):window(window1),Tut(T)
    {
        background::loadJSON(&j);
        newBins(15);
    }
    void newBins(int h)
    {
        Bins.resize(h);
        int *n;
        n=new int;
        for(long long unsigned int i=0;i<Bins.size();i++)
        {
            *n=std::rand()%NumberOfBins;
            Bins[i]=new Bin_handling(window,j["bins"][*n],static_cast<Bin_handling::type>(*n),Tut);
        }
        delete n;
        n=nullptr;
    }
    void Update()
    {
        for(long long unsigned int i=0;i<Bins.size();i++)
            if(Bins[i]!=nullptr)
                if(Bins[i]->Update())
                    Bins[i]=nullptr;
        if([](std::vector<Bin_handling*>Bins)->bool
           {
                int counter=0;
                for(long long unsigned int i=0;i<Bins.size();i++)
                    if(Bins[i]!=nullptr)
                        counter++;
                    if(counter==0)
                        return true;
                    else return false;
           }(Bins))
           {
                Bins.clear();
                newBins(15);
           }
    }
};


#endif // BINS_HPP_INCLUDED
