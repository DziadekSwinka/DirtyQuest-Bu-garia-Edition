#ifndef GUI_HPP_INCLUDED
#define GUI_HPP_INCLUDED

#include "Character.hpp"

class GUI
{
private:
    sf::RenderWindow &window;
    sf::Text binsPointsText;
    sf::Font OdibeeSans_Regular;
public:
    GUI(sf::RenderWindow &window1):window(window1)
    {
        OdibeeSans_Regular.loadFromFile("OdibeeSans-Regular.ttf");
        binsPointsText.setFont(OdibeeSans_Regular);
    }
    void Update()
    {
        binsPointsText.setString(std::to_string(character::BinsPoints));
        binsPointsText.setPosition(window.getSize().x/2,100);
        window.draw(binsPointsText);
    }
};

#endif // GUI_HPP_INCLUDED
