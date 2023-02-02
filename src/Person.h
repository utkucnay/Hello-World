#pragma once

#include "Hobby.h"
#include "School.h"

template <typename T>
concept ConceptSchool = std::is_base_of<School, T>::value;

template <typename T>
concept ConceptHobby  = std::is_base_of<Hobby, T>::value;

class Person
{
public:
	Person(const std::string& name, const std::string& surName,const float& age, const DateTime& dateOfBirth);
public:
	template<ConceptHobby T>
	void									AddHobby(T&& hobby) 
	{
		_hobbies.push_back(std::make_shared<T>(hobby));
	}
	void									AddHobby(std::shared_ptr<Hobby> hobby)
	{
		_hobbies.push_back(hobby);
	}
	std::vector<std::shared_ptr<Hobby>>*	GetHobbies();

	template<ConceptSchool T>
	void									AddSchool(T&& school) 
	{
		_schools.push_back(std::make_shared<T>(school));
	}
	void									AddSchool(std::shared_ptr<School> school)
	{
		_schools.push_back(school);
	}
	std::vector<std::shared_ptr<School>>*	GetSchools();
public:
	std::string								_name;
	std::string								_surName;
	float									_age;
	DateTime								_dateOfBirth;
private:
	std::vector<std::shared_ptr<Hobby>>		_hobbies;
	std::vector<std::shared_ptr<School>>	_schools;
};

