#pragma once

class Hobby
{
public:
	enum InherinceTreeFlag : uint8_t
	{
		kNone = 1,
		kGames = 2
	};
public:
	Hobby() = delete;
	Hobby(const std::string& hobbyName);
public:
	InherinceTreeFlag _inherinceData;
	std::string _hobbyName;
};

