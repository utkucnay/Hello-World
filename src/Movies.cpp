#include "Core.h"
#include "Movies.h"

void Movies::AddFavMovie(const std::string& movie)
{
	_FavMovies.push_back(movie);
}

std::vector<std::string>* Movies::GetFavMovie()
{
	return &_FavMovies;
}
