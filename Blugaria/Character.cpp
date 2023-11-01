#include "Character.hpp"

unsigned int character::CleanPoints=0;
unsigned int character::BinsPoints=0;

void character::Update()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)||
        sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        //animacja ruchu
    }
    window.draw(sprite);
}
