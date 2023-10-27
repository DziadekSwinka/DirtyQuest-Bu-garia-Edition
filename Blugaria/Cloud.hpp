#ifndef CLOUD_HPP_INCLUDED
#define CLOUD_HPP_INCLUDED

#include <SFML/Graphics.hpp>

struct
{
    float cloudPosition[3][2]={{200,100},
                                {400,200},
                                {1500,100}};
}cloudPos;

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
            Clouds[i].setPosition(cloudPos.cloudPosition[i][0],cloudPos.cloudPosition[i][1]);
        }
    }
    void Update(double delta)
    {
        for(int i=0;i<3;i++)
            window.draw(Clouds[i]);
    }
};

#endif // CLOUD_HPP_INCLUDED
