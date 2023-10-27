#ifndef CLOUD_HPP_INCLUDED
#define CLOUD_HPP_INCLUDED

#include <SFML/Graphics.hpp>

class cloud
{
private:
    sf::RenderWindow &window;
    sf::Sprite Clouds[3];
    sf::Texture txt;
public:
    cloud(sf::RenderWindow &window1):window(window1)
    {
        txt.loadFromFile("Textures//cloud.png");
        for(int i=0;i<3;i++)
        {
            Clouds[i].setTexture(txt);
            Clouds[i].setScale(0.3,0.3);
            Clouds[i].setPosition(std::rand()%1600,std::rand()%300);
        }
    }
    void Update(double delta)
    {
        for(int i=0;i<3;i++)
            window.draw(Clouds[i]);
    }
};

#endif // CLOUD_HPP_INCLUDED
