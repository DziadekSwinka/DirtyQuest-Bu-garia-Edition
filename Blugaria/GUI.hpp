#ifndef GUI_HPP_INCLUDED
#define GUI_HPP_INCLUDED

#include <SFML/Graphics.hpp>

#include "Character.hpp"

class GUI
{
private:
    sf::RenderWindow &window;
    sf::Text binsPointsText;
    sf::Text moneyText;
    sf::Font OdibeeSans_Regular;
    sf::RectangleShape Back,line[3];
public:
    GUI(sf::RenderWindow &window1):window(window1)
    {
        OdibeeSans_Regular.loadFromFile("OdibeeSans-Regular.ttf");
        binsPointsText.setFont(OdibeeSans_Regular);
        binsPointsText.setColor(sf::Color(0,0,0));
        moneyText.setFont(OdibeeSans_Regular);
        moneyText.setColor(sf::Color(0,0,0));
        binsPointsText.setPosition(100,124);
        moneyText.setPosition(100,100);
        Back.setSize(sf::Vector2f(300,200));
        Back.setFillColor(sf::Color(137,138,124));
        for(int i=0;i<3;i++)
        {
            line[i].setSize(sf::Vector2f(200,48));
            line[i].setPosition(50,90+48*i);
            line[i].setFillColor(sf::Color(137,138,124));
            line[i].setOutlineThickness(1);
            line[i].setOutlineColor(sf::Color::Black);
        }
    }
    void Update()
    {
        binsPointsText.setString(std::to_string(character::BinsPoints));
        moneyText.setString(std::to_string(character::Money));

        window.draw(Back);
        for(int i=0;i<3;i++)
            window.draw(line[i]);
        window.draw(binsPointsText);
        window.draw(moneyText);
    }
};

#endif // GUI_HPP_INCLUDED
