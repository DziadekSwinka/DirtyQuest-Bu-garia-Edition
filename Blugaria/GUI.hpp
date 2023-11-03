#ifndef GUI_HPP_INCLUDED
#define GUI_HPP_INCLUDED

#include "Character.hpp"

class GUI
{
private:
    sf::RenderWindow &window;
    sf::Text binsPointsText;
    sf::Text moneyText;
    sf::Font OdibeeSans_Regular;
public:
    GUI(sf::RenderWindow &window1):window(window1)
    {
        OdibeeSans_Regular.loadFromFile("OdibeeSans-Regular.ttf");
        binsPointsText.setFont(OdibeeSans_Regular);
        binsPointsText.setColor(sf::Color(0,0,0));
        moneyText.setFont(OdibeeSans_Regular);
        moneyText.setColor(sf::Color(0,0,0));
    }
    void Update()
    {
        binsPointsText.setString(std::to_string(character::BinsPoints));
        moneyText.setString(std::to_string(character::Money));
        binsPointsText.setPosition(100,124);
        moneyText.setPosition(100,100);
        window.draw(binsPointsText);
        window.draw(moneyText);
    }
};

#endif // GUI_HPP_INCLUDED
