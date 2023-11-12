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
    short correct,current;
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
        isDisplay=false;
    }
    void Update()
    {
        if(isDisplay==false)
            auto s=j["questions"];
        window.draw(question);
        for(int i=0;i<3;i++)
            window.draw(answer[i]);
    }
};

#endif // QUIZ_HPP_INCLUDED
