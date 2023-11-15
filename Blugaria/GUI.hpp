#ifndef GUI_HPP_INCLUDED
#define GUI_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <map>
#include <string>

#include "Character.hpp"

class GUI
{
private:
    sf::RenderWindow &window;
    sf::Text binsPointsText;
    sf::Text moneyText;
    sf::Font OdibeeSans_Regular;
    sf::RectangleShape Back,line[3];
    std::map<short,sf::Text>Text;
public:
    GUI(sf::RenderWindow &window1):window(window1)
    {
        OdibeeSans_Regular.loadFromFile("OdibeeSans-Regular.ttf");
        for(int i=0;i<3;i++)
        {
            Text[i].setFont(OdibeeSans_Regular);
            Text[i].setColor(sf::Color(0,0,0));
            Text[i].setPosition(100,98+i*28);
            Text[i].setCharacterSize(24);

        }
        Back.setSize(sf::Vector2f(300,200));
        Back.setFillColor(sf::Color(137,138,124));
        for(int i=0;i<3;i++)
        {
            line[i].setSize(sf::Vector2f(190,26));
            line[i].setPosition(75,100+28*i);
            line[i].setFillColor(sf::Color(137,138,124));
            line[i].setOutlineThickness(1);
            line[i].setOutlineColor(sf::Color::Black);
        }
    }
    void Update()
    {
        Text[0].setString("Poziom œmieci:       "+std::to_string(character::BinsPoints));
        Text[1].setString("Poziom czystoœci:   "+std::to_string(character::CleanPoints));
        Text[2].setString("Pieni¹dze:            "+std::to_string(character::Money));

        //window.draw(Back);
        for(int i=0;i<3;i++)
        {
            window.draw(line[i]);
            window.draw(Text[i]);
        }
    }
};

#endif // GUI_HPP_INCLUDED
