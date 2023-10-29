/*#ifndef H_JSON_HPP_INCLUDED
#define H_JSON_HPP_INCLUDED

#include <fstream>
#include <string>

#include "json.hpp"

class JSON_
{
public:
    using json=nlohmann::json;
    json j;
    JSON(std::string path)
    {
        std::ifstream reader(path);
        reader>>j;
        reader.close();
    }
    std::string readJSON(std::string name)
    {
        try
        {
            return j[name];
        }
        catch(...)
        {
            return "";
        }
    }
};

#endif // H_JSON_HPP_INCLUDED*/
