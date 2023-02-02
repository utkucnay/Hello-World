#include "Core.h"

#include "Person.h"

#include "Person.h"
#include "Games.h"
#include "Movies.h"
#include "University.h"

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

void Person::Deserialization(Json::Value& root)
{
	_name = root["name"].asString();
	_surName = root["surName"].asString();
	_age =	root["age"].asInt(),
	_dateOfBirth = DateTime(root["DateTime"]["day"].asInt(), root["DateTime"]["month"].asInt(), root["DateTime"]["year"].asInt());

	{
		int hobbyLength = root["Hobbies"].size();
		for (int hobbyIndex = 0; hobbyIndex < hobbyLength; hobbyIndex++)
		{
			switch (root["Hobbies"][hobbyIndex]["classType"].asInt())
			{
			case Hobby::kNone:
			{
				Hobby hobby(root["Hobbies"][hobbyIndex]["name"].asString());

				AddHobby(std::move(hobby));
			}
			break;
			case Hobby::kGames:
			{
				Games games(root["Hobbies"][hobbyIndex]["name"].asString());

				int favHobbiesLength = root["Hobbies"][hobbyIndex]["favHobbies"].size();

				for (int favHobbyIndex = 0; favHobbyIndex < favHobbiesLength; favHobbyIndex++)
				{
					games.AddGame(root["Hobbies"][hobbyIndex]["favHobbies"][favHobbyIndex].asString());
				}

				AddHobby(std::move(games));
			}
			break;
			case Hobby::kMovies:
			{
				Movies movies(root["Hobbies"][hobbyIndex]["name"].asString());

				int favHobbiesLength = root["Hobbies"][hobbyIndex]["favHobbies"].size();

				for (int favHobbyIndex = 0; favHobbyIndex < favHobbiesLength; favHobbyIndex++)
				{
					movies.AddFavMovie(root["Hobbies"][hobbyIndex]["favHobbies"][favHobbyIndex].asString());
				}

				AddHobby(std::move(movies));
			}
			break;
			default:
				std::cout << "Error not found classType at Json Deseriliaze";
				break;
			}


		}
	}

	{
		int schoolLength = root["School"].size();
		for (int schoolIndex = 0; schoolIndex < schoolLength; schoolIndex++)
		{
			switch (root["School"][schoolIndex]["classType"].asInt())
			{
			case School::kNone:
			{
				School school(root["School"][schoolIndex]["name"].asString());

				AddSchool(std::move(school));
			}
			break;
			case School::kUniversity:
			{
				University university(root["School"][schoolIndex]["name"].asString(), root["School"][schoolIndex]["degree"].asString(),
					(University::EDegreeType)root["School"][schoolIndex]["degreeType"].asInt());

				AddSchool(std::move(university));
			}
			break;
			default:
				std::cout << "Error not found classType at Json Deseriliaze";
				break;
			}
		}
	}
}
