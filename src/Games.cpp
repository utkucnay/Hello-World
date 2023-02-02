#include "Core.h"
#include "Games.h"

void Games::AddGame(const std::string& game)
{
	_games.push_back(game);
}

std::vector<std::string>* Games::GetGames()
{
	return &_games;
}
