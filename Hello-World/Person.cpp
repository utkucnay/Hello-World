#include "Core.h"

#include "Person.h"
Person::Person(const std::string& name, const std::string& surName, const float& age, const DateTime& dateOfBirth)
{
	_name = name;
	_surName = surName;
	_age = age;
	_dateOfBirth = dateOfBirth;
}

void Person::AddHobby(std::shared_ptr<Hobby> hobby)
{
	_hobbies.push_back(hobby);
}

std::vector<std::shared_ptr<Hobby>>* Person::GetHobbies()
{
	return &_hobbies;
}

void Person::AddSchool(const School& school)
{
	_schools.push_back(school);
}
