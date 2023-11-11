#include "Character.hpp"

unsigned int character::CleanPoints=0;
unsigned int character::BinsPoints=50;
unsigned int character::Money=0;

void character::Update()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)||
        sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        //animacja ruchu
    }
    if(clock.getElapsedTime().asSeconds()>=1 && isEscape==false)
    {
        clock.restart();
        if(BinsPoints>=1)
            BinsPoints--;
        else isAlive=false;
    }
    window.draw(sprite);
}
