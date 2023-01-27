#pragma once

#include "Core.h"

class Person
{
public:
	Person() = delete;
	Person(Person&&) = delete;
	Person(std::string name, std::string surName, float age);


public:
	std::string _name;
	std::string _surName;
	float _age;
};

