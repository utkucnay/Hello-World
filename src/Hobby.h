#pragma once

class Hobby
{
public:
	enum InherinceTreeFlag : uint8_t
	{
		kNone = 1,
		kGames = 2,
		kMovies = 4
	};
public:
	Hobby(const std::string& hobbyName);
public:
	InherinceTreeFlag	_inherinceData;
	std::string			_hobbyName;
};

