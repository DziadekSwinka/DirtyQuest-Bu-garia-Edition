#ifndef PLANE_HPP_INCLUDED
#define PLANE_HPP_INCLUDED

#include <SFML/Graphics.hpp>

class plane
{
private:
    sf::RenderWindow &window;
    sf::Sprite Plane;
    sf::Texture txt;
    sf::Clock clock;
public:
    plane(sf::RenderWindow &window1):window(window1)
    {
        txt.loadFromFile("Textures//plane.png");
        Plane.setPosition(0,0);
        Plane.setTexture(txt);
        Plane.setScale(0.5,0.4);
        clock.restart();
    }
    void Update(double delta)
    {
        if(clock.getElapsedTime().asSeconds()<5)
            Plane.move(0.18*delta,0.17*delta);
        window.draw(Plane);
    }
};

#endif // PLANE_HPP_INCLUDED
