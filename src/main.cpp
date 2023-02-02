#include "Core.h"
#include "Person.h"
#include "Games.h"
#include "Movies.h"
#include "University.h"

int main() {
	
	Json::Value root;
	std::ifstream jsonfile(PATH_TO_JSON "mainCharacter.json");
	jsonfile >> root;
	jsonfile.close();

	Person mainCharacter;
	mainCharacter.Deserialization(root);

	std::stringstream message;

	message << "Hello," << std::endl;
	message << "My name is " << mainCharacter._name << " " << mainCharacter._surName << ". ";
	message << "I am " << mainCharacter._age << " years old. ";
	message << "I was born on " << std::format("{:02d}.{:02d}.{:04d}." ,mainCharacter._dateOfBirth._month, mainCharacter._dateOfBirth._day, mainCharacter._dateOfBirth._year);
	message << std::endl;

	message << "Hobbies:" << std::endl;
	for (auto i = 0; i < mainCharacter.GetHobbies()->size(); i++)
	{
		message << std::format("{:d}. Hobby: ", i + 1);
		message << mainCharacter.GetHobbies()->at(i)->_hobbyName;
		if (FlagHelper::IsFlag(mainCharacter.GetHobbies()->at(i).get()->_inherinceData, Hobby::kGames))
		{
			auto games = static_cast<Games*>(mainCharacter.GetHobbies()->at(i).get());
			int gamesLength = games->GetGames()->size();
			for (int FavGamesIndex = 0; FavGamesIndex < gamesLength; FavGamesIndex++)
			{
				message << std::endl << '\t' << games->GetGames()->at(FavGamesIndex);
			}
			
		}
		if (FlagHelper::IsFlag(mainCharacter.GetHobbies()->at(i).get()->_inherinceData, Hobby::kMovies))
		{
			auto movies = static_cast<Movies*>(mainCharacter.GetHobbies()->at(i).get());
			int moviesLength = movies->GetFavMovie()->size();
			for (int FavMoviesIndex = 0; FavMoviesIndex < moviesLength; FavMoviesIndex++)
			{
				message << std::endl << '\t' << movies->GetFavMovie()->at(FavMoviesIndex);
			}
		}

		message << std::endl;
	}

	message << "Schools:" << std::endl;

	for (auto i = 0; i < mainCharacter.GetSchools()->size(); i++)
	{
		message << std::format("{:d}. School: ", i + 1);
		message << mainCharacter.GetSchools()->at(i)->_name;
		if (FlagHelper::IsFlag(mainCharacter.GetSchools()->at(i).get()->_InherienceTree, School::kUniversity))
		{
			auto university = static_cast<University*>(mainCharacter.GetSchools()->at(i).get());
			message << " " << university->_degree;
			switch (university->_degreeType)
			{
			case University::kBachelorDegree:
				message << " " << "Bachelor's Degree";
				break;
			case University::kAssociateDegree:
				message << " " << "Associate's Degree";
				break;
			case University::kGraduateDegree:
				message << " " << "Graduate's Degree";
				break;
			case University::kProfessionalDegree:
				message << " " << "Professional's Degree";
				break;
			default:
				message << " " << "Undefined Degree";
				break;
			}
		}

		message << std::endl;
	}
	
	message << "Thank you for compile this project";

	std::cout << message.str();
	return 0;
}