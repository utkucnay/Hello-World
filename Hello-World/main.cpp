#include "Core.h"
#include "Person.h"
#include "Games.h"
#include "University.h"

int main() {
	Person mainCharacter("Utkucan","Ay", 23, DateTime(07,06,2000));

	mainCharacter.AddHobby(std::make_shared<Hobby>(Hobby("Roleplay")));
	mainCharacter.AddHobby(std::make_shared<Hobby>(Hobby("Baseball")));
	
	std::shared_ptr<Games> TCG(new Games("Trading Card Game"));
	TCG.get()->AddGame("Yu-Gi-Oh!");
	TCG.get()->AddGame("MTG Arena");
	mainCharacter.AddHobby(TCG);
	
	mainCharacter.AddHobby(std::make_shared<Hobby>(Hobby("Computer Games")));

	mainCharacter.AddSchool(University("Bakircay", "Computer Engineer", University::kBachelorDegree));

	std::cout << mainCharacter._name;

	for (auto i = 0; i < mainCharacter.GetHobbies()->size(); i++)
	{
		if (FlagHelper::IsFlag(mainCharacter.GetHobbies()->at(i).get()->_inherinceData, Hobby::kGames))
		{
			auto games = static_cast<Games*>(mainCharacter.GetHobbies()->at(i).get());
			games->GetGames();
		}
	}

	return 0;
}