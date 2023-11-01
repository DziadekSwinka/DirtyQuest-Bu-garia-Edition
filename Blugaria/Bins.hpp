#ifndef BINS_HPP_INCLUDED
#define BINS_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <vector>

#include "JSON.hpp"
#include "Background.hpp"

#define NumberOfBins 1

class background;

class Bin_handling
{
private:
    sf::RenderWindow &window;
    sf::Texture txt;
    sf::Sprite sprite;
    float pos;
public:
    Bin_handling(sf::RenderWindow &window1,std::string path):window(window1)
    {
        pos=(std::rand()%3000)-1500;
        txt.loadFromFile(path);
        sprite.setTexture(txt);
        sprite.setScale(0.3,0.3);
    }
    void Update()
    {
        sprite.setPosition(background::position+pos,700);
        window.draw(sprite);
    }
    enum
    {

    }type;
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
        for(int i=0;i<Bins.size();i++)
            Bins[i]=new Bin_handling(window,j["bins"][std::rand()%NumberOfBins]);
    }
    void Update()
    {
        for(int i=0;i<Bins.size();i++)
            Bins[i]->Update();
    }
};


#endif // BINS_HPP_INCLUDED
