#include "Core.h"
#include "Person.h"
#include "Games.h"
#include "Movies.h"
#include "University.h"
#include "json/json.h"

int main() {
	
	std::ifstream jsonfile(PATH_TO_JSON "mainCharacter.json");
	Json::Value root;
	
	jsonfile >> root;

	jsonfile.close();

	Person mainCharacter(root["name"].asString(), root["surName"].asString(), root["age"].asInt(),
		DateTime(root["DateTime"]["day"].asInt(), root["DateTime"]["month"].asInt(), root["DateTime"]["year"].asInt()));

	{
		int length = root["Hobbies"].size();
		for (int i = 0; i < length; i++)
		{
			switch (root["Hobbies"][i]["classType"].asInt())
			{
			case 1:
			{
				Hobby hobby(root["Hobbies"][i]["name"].asString());

				mainCharacter.AddHobby(std::move(hobby));
			}
				break;
			case 2:
			{
				Games games(root["Hobbies"][i]["name"].asString());

				int favHobbiesLength = root["Hobbies"][i]["favHobbies"].size();

				for (int index = 0; index < favHobbiesLength; index++)
				{
					games.AddGame(root["Hobbies"][i]["favHobbies"][index].asString());
				}
				
				mainCharacter.AddHobby(std::move(games));
			}
				break;
			case 4:
			{
				Movies movies(root["Hobbies"][i]["name"].asString());

				int favHobbiesLength = root["Hobbies"][i]["favHobbies"].size();

				for (int index = 0; index < favHobbiesLength; index++)
				{
					movies.AddFavMovie(root["Hobbies"][i]["favHobbies"][index].asString());
				}

				mainCharacter.AddHobby(std::move(movies));
			}
				break;
			default:
				std::cout << "Error not found classType at Json Deseriliaze";
				break;
			}

			
		}
	}

	{
		mainCharacter.AddSchool(University("Bakircay", "Computer Engineer", University::kBachelorDegree));
	}

	std::stringstream message;

	message << "Hello," << std::endl;
	message << "My name is " << mainCharacter._name << " " << mainCharacter._surName << ". ";
	message << "I am " << mainCharacter._age << " years old. ";
	message << "I born at " << mainCharacter._dateOfBirth._year << "/" << mainCharacter._dateOfBirth._day << "/" << mainCharacter._dateOfBirth._month;
	std::cout << message.str();

	for (auto i = 0; i < mainCharacter.GetHobbies()->size(); i++)
	{
		if (FlagHelper::IsFlag(mainCharacter.GetHobbies()->at(i).get()->_inherinceData, Hobby::kGames))
		{
			auto games = static_cast<Games*>(mainCharacter.GetHobbies()->at(i).get());
			//std::cout << games->GetGames()->at(0);
		}
		if (FlagHelper::IsFlag(mainCharacter.GetHobbies()->at(i).get()->_inherinceData, Hobby::kMovies))
		{
			auto games = static_cast<Movies*>(mainCharacter.GetHobbies()->at(i).get());
			//std::cout << games->GetFavMovie()->at(0);
		}
	}

	auto univercity = static_cast<University*>(mainCharacter.GetSchools()->at(0).get());
	//std::cout << univercity->_degree;

	return 0;
}