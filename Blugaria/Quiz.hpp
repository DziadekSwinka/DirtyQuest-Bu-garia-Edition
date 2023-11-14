#ifndef QUIZ_HPP_INCLUDED
#define QUIZ_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <fstream>
#include <string>

#include "JSON.hpp"

extern bool isQuiz;

class Quiz
{
private:
    sf::RenderWindow &window;
    sf::Text question,answer[3];
    sf::Font OdibeeSans_Regular;
    int correct,current,point;
    bool isDisplay;
    using json=nlohmann::json;
    const int numberOfQ=8;
    json j;
public:
    Quiz(sf::RenderWindow &window1):window(window1)
    {
        std::fstream reader;
        reader.open("quiz.json");
        reader>>j;
        reader.close();
        OdibeeSans_Regular.loadFromFile("OdibeeSans-Regular.ttf");
        question.setFont(OdibeeSans_Regular);
        question.setPosition(500,250);
        for(int i=0;i<3;i++)
        {
            answer[i].setFont(OdibeeSans_Regular);
            answer[i].setPosition(500,300+i*50);
        }
        current=0;
        point=0;
        isDisplay=false;
    }
    void Update()
    {
        if(isDisplay==false)
        {
            isDisplay=true;
            auto s=j["questions"];
            std::string answ[3]={};
            question.setString((std::string)(s[current]["question"]));
            answ[0]=s[current]["answer"];
            answ[1]=s[current]["wrong"][0];
            answ[2]=s[current]["wrong"][1];
            auto adj=std::rand()%3;
            correct=adj;
            if(correct==1)
            {
                answer[0].setString("1) "+answ[2]);
                answer[1].setString("2) "+answ[0]);
                answer[2].setString("3) "+answ[1]);
            }else
            if(correct==2)
            {
                answer[0].setString("1) "+answ[1]);
                answer[1].setString("2) "+answ[2]);
                answer[2].setString("3) "+answ[0]);
            }
            else
            {
                answer[0].setString("1) "+answ[0]);
                answer[1].setString("2) "+answ[1]);
                answer[2].setString("3) "+answ[2]);
            }
        }
        if(isDisplay)
        {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num1) && correct==0)
            {
                if(current</*numberOfQ*/8)
                    current++;
                isDisplay=false;
                correct=-1;
                point++;
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num2) && correct==1)
            {
                if(current</*numberOfQ*/8)
                    current++;
                isDisplay=false;
                correct=-1;
                point++;
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num3) && correct==2)
            {
                if(current</*numberOfQ*/8)
                    current++;
                isDisplay=false;
                correct=-1;
                point++;
            }
            if(current==numberOfQ)
            {
                isQuiz=false;
                isDisplay=false;
            }
        }
        window.draw(question);
        for(int i=0;i<3;i++)
            window.draw(answer[i]);
    }
};

#endif // QUIZ_HPP_INCLUDED
