#include "Character.hpp"

character::CleanPoints=0;
character::BinsPoints=0;

void character::Update()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)||
        sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        //animacja ruchu
    }
    window.draw(sprite);
}
