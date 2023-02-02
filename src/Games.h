#pragma once
#include "Hobby.h"
class Games :
    public Hobby
{
public:
    Games(const std::string& hobbyName) : Hobby(hobbyName) { _inherinceData = kGames; }

public:
    void                        AddGame(const std::string& game);
    std::vector<std::string>*   GetGames();
private:
    std::vector<std::string>    _games;
};

