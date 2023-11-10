#ifndef ESCAPE_HPP_INCLUDED
#define ESCAPE_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <cmath>

#include "json.hpp"
#include "Background.hpp"

class Escape
{
private:
    sf::RenderWindow &window;
    sf::Sprite Enemy;
    sf::Texture txt;
    sf::Text KeyText;
    sf::Font OdibeeSans_Regular;
    using json=nlohmann::json;
    json j;
    int chances=3,counter=0;
    float targetXPosition;
    bool isDisplay=false;
    sf::Vector2f EnemyPosition;
    sf::Clock clock,DisplayedTime;
    float startPos;
    enum EnumKey
    {
        A = 0 , B , C ,
        D , E , F , G ,
        H , I , J , K ,
        L , M , N , O ,
        P , Q , R , S ,
        T , U , V , W ,
        X , Y , Z
    }Key;
public:
    Escape(sf::RenderWindow &window1):window(window)
    {
        background::loadJSON(&j);
        txt.loadFromFile(j["enemy"]);
        Enemy.setTexture(txt);
        Enemy.setScale(0.3,0.3);
        OdibeeSans_Regular.loadFromFile("OdibeeSans-Regular.ttf");
        KeyText.setFont(OdibeeSans_Regular);
        KeyText.setColor(sf::Color(255,0,0));
        KeyText.setPosition(1000,200);
        KeyText.setCharacterSize(58);
        startPos=background::position;
        EnemyPosition={-100.f,800.f};
    }
    void Update(float delta)
    {
        background::position-=5*delta;
        if(clock.getElapsedTime().asSeconds()>3 && isDisplay==false)
        {
            if(std::rand()%100==0)
            {
                clock.restart();
                Key=static_cast<EnumKey>(std::rand()%26);
                DisplayedTime.restart();
                isDisplay=true;
            }
        }
        if(isDisplay==true)
        {
            //KeyText.setString("Press ["+std::to_string(Key)+"] !!!");
            window.draw(KeyText);
            if(DisplayedTime.getElapsedTime().asSeconds()>2)
            {
                DisplayedTime.restart();
                isDisplay=false;
                if(chances>0)
                    chances--;
            }
        }
        if(chances==3)
            targetXPosition=200;
        else if(chances==2)
            targetXPosition=500;
        else if(chances==1)
            targetXPosition=800;
        /*if(abs(EnemyPosition.x-targetXPosition)<0.5)
        {
            EnemyPosition.x-=1*delta;
        }*/
        Enemy.setPosition(EnemyPosition);
        window.draw(Enemy);
    }
};

#endif // ESCAPE_HPP_INCLUDED
