#pragma once

class School
{
public:
	enum InherinceTreeFlag : uint8_t
	{
		kNone = 1,
		kUniversity = 2
	};
public:
	School(const std::string& name);

public:
	std::string			_name;
	InherinceTreeFlag	_InherienceTree;
};

