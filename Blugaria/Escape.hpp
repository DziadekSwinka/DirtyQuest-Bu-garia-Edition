#ifndef ESCAPE_HPP_INCLUDED
#define ESCAPE_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <cmath>
#include <iostream>
#include <map>

#include "json.hpp"
#include "Background.hpp"

class Escape
{
private:
    background *Background;
    sf::RenderWindow &window;
    sf::Sprite Enemy;
    sf::Texture txt;
    sf::Text KeyText;
    sf::Font OdibeeSans_Regular;
    using json=nlohmann::json;
    json j;
    int chances,counter,correct;
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
    std::map<EnumKey,std::string>EnumToString;
public:
    Escape(sf::RenderWindow &window1,background *bcg):window(window1)
    {
        restart();
        Background=bcg;
        background::loadJSON(&j);
        txt.loadFromFile(j["enemy"]);
        Enemy.setTexture(txt);
        Enemy.setScale(0.3,0.3);
        OdibeeSans_Regular.loadFromFile("OdibeeSans-Regular.ttf");
        KeyText.setFont(OdibeeSans_Regular);
        KeyText.setColor(sf::Color(255,0,0));
        KeyText.setPosition(1000,200);
        KeyText.setCharacterSize(58);
        EnumToString[A]="A";
        EnumToString[B]="B";
        EnumToString[C]="C";
        EnumToString[D]="D";
        EnumToString[E]="E";
        EnumToString[F]="F";
        EnumToString[G]="G";
        EnumToString[H]="H";
        EnumToString[I]="I";
        EnumToString[J]="J";
        EnumToString[K]="K";
        EnumToString[L]="L";
        EnumToString[M]="M";
        EnumToString[N]="N";
        EnumToString[O]="O";
        EnumToString[P]="P";
        EnumToString[Q]="Q";
        EnumToString[R]="R";
        EnumToString[S]="S";
        EnumToString[T]="T";
        EnumToString[U]="U";
        EnumToString[V]="V";
        EnumToString[W]="W";
        EnumToString[W]="X";
        EnumToString[Y]="Y";
        EnumToString[Z]="Z";
    }
    void restart()
    {
        chances=3;
        counter=0;
        correct=0;
        startPos=background::position;
        EnemyPosition={-100.f,700.f};
    }
    void Update(float delta)
    {
        Background->Left(2,delta);
        if(clock.getElapsedTime().asSeconds()>6 && isDisplay==false)
        {
            if(std::rand()%100==0)
            {
                clock.restart();
                Key=static_cast<EnumKey>(std::rand()%sizeof(EnumKey)*sizeof(int));
                DisplayedTime.restart();
                isDisplay=true;
            }
        }
        if(isDisplay==true)
        {
            KeyText.setString("Press ["+EnumToString[Key]+"] !!!");
            window.draw(KeyText);
            if([=]
            {
                switch(Key)
                {
                case 0:
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                    return true;
                    break;
                case 1:
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::B))
                    return true;
                    break;
                case 2:
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::C))
                    return true;
                    break;
                case 3:
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                    return true;
                    break;
                case 4:
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::E))
                    return true;
                    break;
                case 5:
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::F))
                    return true;
                    break;
                case 6:
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::G))
                    return true;
                    break;
                case 7:
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::H))
                    return true;
                    break;
                case 8:
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::I))
                    return true;
                    break;
                case 9:
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::J))
                    return true;
                    break;
                case 10:
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::K))
                    return true;
                    break;
                case 11:
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::L))
                    return true;
                    break;
                case 12:
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::M))
                    return true;
                    break;
                case 13:
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::N))
                    return true;
                    break;
                case 14:
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::O))
                    return true;
                    break;
                case 15:
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::P))
                    return true;
                    break;
                case 16:
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
                    return true;
                    break;
                case 17:
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::R))
                    return true;
                    break;
                case 18:
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                    return true;
                    break;
                case 19:
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::T))
                    return true;
                    break;
                case 20:
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::U))
                    return true;
                    break;
                case 21:
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::V))
                    return true;
                    break;
                case 22:
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                    return true;
                    break;
                case 23:
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::X))
                    return true;
                    break;
                case 24:
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
                    return true;
                    break;
                case 25:
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
                    return true;
                    break;
                default:
                    return false;
                    break;
                }
                return false;
            }())
                {
                correct++;
                DisplayedTime.restart();
                isDisplay=false;
            }
            if(DisplayedTime.getElapsedTime().asSeconds()>2)
            {
                DisplayedTime.restart();
                isDisplay=false;
                if(chances>0)
                    chances--;
            }
        }
        if(correct==10)
        {
           restart();
            //delete this;
        }
        if(chances==3)
            targetXPosition=100;
        else if(chances==2)
            targetXPosition=400;
        else if(chances==1)
            targetXPosition=700;
        if(EnemyPosition.x<targetXPosition)
        {
            EnemyPosition.x+=0.2*delta;
        }
        Enemy.setPosition(EnemyPosition);
        window.draw(Enemy);
    }
};

#endif // ESCAPE_HPP_INCLUDED
