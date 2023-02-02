#include "Core.h"

#include "Person.h"
Person::Person(const std::string& name, const std::string& surName, const float& age, const DateTime& dateOfBirth)
{
	_name = name;
	_surName = surName;
	_age = age;
	_dateOfBirth = dateOfBirth;
}

std::vector<std::shared_ptr<Hobby>>* Person::GetHobbies()
{
	return &_hobbies;
}

std::vector<std::shared_ptr<School>>* Person::GetSchools()
{
	return &_schools;
}
