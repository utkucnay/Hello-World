#pragma once
#include "Hobby.h"
class Movies :
    public Hobby
{
public:
    Movies(const std::string& hobbyName) : Hobby(hobbyName) { _inherinceData = kMovies; }

public:
    void                        AddFavMovie(const std::string& movie);
    std::vector<std::string>*   GetFavMovie();
private:
    std::vector<std::string>    _FavMovies;
};

