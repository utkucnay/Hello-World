#pragma once

#include "Hobby.h"
#include "School.h"

class Person
{
public:
	Person(const std::string& name, const std::string& surName,const float& age, const DateTime& dateOfBirth);
public:
	void AddHobby(std::shared_ptr<Hobby> hobby);
	std::vector<std::shared_ptr<Hobby>>* GetHobbies();
	void AddSchool(const School& school);
public:
	std::string				_name;
	std::string				_surName;
	float					_age;
	DateTime				_dateOfBirth;
private:
	std::vector<std::shared_ptr<Hobby>>		_hobbies;
	std::vector<School>		_schools;
};

