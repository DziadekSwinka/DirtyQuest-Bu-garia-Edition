#ifndef BACKGROUND_HPP_INCLUDED
#define BACKGROUND_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <string>

class background
{
private:
    sf::RenderWindow &window;
    sf::Sprite Back,Front;
    sf::Texture txt1,txt2;
    sf::Clock clock;
    short alpha=0;
    void updateIntro(float delta);
    void updateGame(float delta);
public:
    enum
    {
        Intro,
        MainGame
    }type;
    background(sf::RenderWindow &window1):window(window1)
    {
        type=Intro;
        clock.restart();
        txt1.loadFromFile("Textures//Blugaria Intro.png");
        txt2.loadFromFile("Textures//Intro.png");
        Back.setTexture(txt1);
        Front.setTexture(txt2);
        Front.setColor(sf::Color(225,225,225,0));
    }
    background(sf::RenderWindow &window1,std::string file):window(window1)
    {
        type=MainGame;
        clock.restart();
        txt1.loadFromFile(file);
        Back.setTexture(txt1);
    }
    void Update(double delta)
    {
        switch(type)
        {
        case 0:
            updateIntro(delta);
            break;
        case 1:
            updateGame(delta);
            break;
        default:
            throw;
        }
    }
};
void background::updateIntro(float delta)
{
    window.draw(Back);
    if(clock.getElapsedTime().asSeconds()>6)
    {
        Front.setColor(sf::Color(255,255,255,alpha));
        if(alpha<255)
            alpha+=5*delta;
        window.draw(Front);
    }
}
void background::updateGame(float delta)
{
    window.draw(Back);
}
#endif // BACKGROUND_HPP_INCLUDED
