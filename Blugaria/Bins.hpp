#ifndef BINS_HPP_INCLUDED
#define BINS_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <vector>

#include "JSON.hpp"
#include "Character.hpp"
#include "Background.hpp"

#define NumberOfBins 2

class background;
class character;

class Bin_handling
{
private:
    sf::RenderWindow &window;
    sf::Texture txt;
    sf::Sprite sprite;
    float pos;
public:
    enum type
    {
        normal_bin,
        premium_bin
    };
    Bin_handling(sf::RenderWindow &window1,std::string path,type Type):window(window1)
    {
        pos=(std::rand()%9000)-4500;
        txt.loadFromFile(path);
        sprite.setTexture(txt);
        sprite.setScale(0.3,0.3);
        sprite.setOrigin(txt.getSize().x/2,txt.getSize().y/2);
    }
    bool Update()
    {
        if((background::position-pos-window.getSize().x/2)<300
           &&(background::position-pos-window.getSize().x/2)>0)
        {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::E))
            {
                character::BinsPoints+=30;
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
    using json=nlohmann::json;
    json j;
public:
    std::vector<Bin_handling*>Bins;
    bins(sf::RenderWindow &window1):window(window1)
    {
        background::loadJSON(&j);
        Bins.resize(15);
        int *n;
        n=new int;
        for(int i=0;i<Bins.size();i++)
        {
            *n=std::rand()%NumberOfBins;
            Bins[i]=new Bin_handling(window,j["bins"][*n],static_cast<Bin_handling::type>(*n));
        }
        delete n;
        n=nullptr;
    }
    void Update()
    {
        for(int i=0;i<Bins.size();i++)
            if(Bins[i]!=nullptr)
                if(Bins[i]->Update())
                    Bins[i]=nullptr;
    }
};


#endif // BINS_HPP_INCLUDED
