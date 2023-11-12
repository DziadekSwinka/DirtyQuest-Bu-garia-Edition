#ifndef QUIZ_HPP_INCLUDED
#define QUIZ_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <fstream>
#include <string>

#include "JSON.hpp"

#define numbeOfQ 8;

extern bool isQuiz;

class Quiz
{
private:
    sf::RenderWindow &window;
    sf::Text question,answer[3];
    sf::Font OdibeeSans_Regular;
    short correct,current,point;
    bool isDisplay;
    using json=nlohmann::json;
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
        for(int i=0;i<3;i++)
            answer[i].setFont(OdibeeSans_Regular);
        current=0;
        point=0;
        isDisplay=false;
    }
    void Update()
    {
        if(isDisplay==false)
        {
            auto s=j["questions"];
            std::string answ[3]={};
            questions.setString([current].question);
            answ[0]=s[current].answer;
            answ[1]=s[current].wrong[0];
            answ[2]=s[current].wrong[1];
            auto adj=std::rand()%3;
            correct=adj;
            answer[0].setString(answ[0+adj]);
            if(adj==1)
            {
                answer[1].setString(answ[2]);
                answer[2].setString(answ[0]);
            }else
            if(adj==2)
            {
                answer[1].setString(answ[0]);
                answer[2].setString(answ[1]);
            }
        }
        if(isDisplay)
        {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num1) && correct==0)
            {
                if(current<numbeOfQ)
                    current++;
                isDisplay=false;
                point++;
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num2) && correct==1)
            {
                if(current<numbeOfQ)
                    current++;
                isDisplay=false;
                point++;
            }
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Num3) && correct==2)
            {
                if(current<numbeOfQ)
                    current++;
                isDisplay=false;
                point++;
            }
        }
        window.draw(question);
        for(int i=0;i<3;i++)
            window.draw(answer[i]);
    }
};

#endif // QUIZ_HPP_INCLUDED
