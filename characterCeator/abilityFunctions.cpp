#include"abilityFunctions.h"

std::vector<int> get_ability_scores()
{
    std::deque<int> tempAbilityRolls{};
    std::vector<int> abilityScores{};
    
    for(int i = 0; i < 6; i++) //create 6 ability scores
    {
        for(int j = 0; j<4; j++)//roll 4 d6
        {
            tempAbilityRolls.push_back(dice_roll(1,6)); //add 4d6 to tempAbility Rolls
        }
        std::sort(tempAbilityRolls.begin() ,tempAbilityRolls.end());//sort the rolls from lowest to highest
        tempAbilityRolls.pop_front(); //remove lowest roll
        int total = 0;
        for(auto num : tempAbilityRolls) //add the remaining 3 rolls to create an ability score
        {
            total += num;
        }
        abilityScores.push_back(total); //add total to ability scores vector
        tempAbilityRolls.clear();
        
    }
    return abilityScores;
}

void ability_menu_selection(std::map<std::string, int*> abilityMap, bool abilitiesDone, std::vector<std::string> abilities, std::vector<int> standardArray, Character c)
{
do{
        int choice;
        std::cin >> choice;
        std::cout << std::endl <<std::endl;
        dividing_line();
        
        switch (choice)
        {
            case 1:
            {
                std::vector<int> abilityScores = get_ability_scores();
                std::cout << "You rolled the following ability scores:" <<std::endl<<std::endl;
        
                display_vector(abilityScores);
                set_ability_scores(c, abilityScores, abilities, abilityMap); 
                abilitiesDone = true;
                break;
            }
            
            case 2:
            {
                set_ability_scores(c, standardArray, abilities, abilityMap); 
                abilitiesDone = true;
                break;
            }
            
            case 3:
            {
                manually_set_abilities(c, abilities, abilityMap);
                abilitiesDone = true;
                break;
            }
            
            default:
            {
                std::cout << "Invalid input. Please try again: ";
            }
        }

        
    }while(abilitiesDone != true);
}

void set_ability_scores(Character& c, std::vector<int> abilityScores, std::vector<std::string> abilities, std::map<std::string, int*> abilityMap)
{
    
   for(auto &ability : abilities)
   {
        bool validChoice = false;
        int abilityScoreChoice = 0;
        std::cout << "You have the following scores still available:" << std::endl;
        display_vector(abilityScores);
        do
        {
            std::cout << "Which score would you like to assign to " << ability << "?" << std::endl
                      << "Enter the score here: ";
            std::cin >> abilityScoreChoice;
            validChoice = check_if_in_vector(abilityScoreChoice, abilityScores);
            
            if(validChoice != true)
            {
                std::cout << std::endl << std::endl << "Invalid entry, please try again." << std::endl << std::endl;
            }
            
        }while (!validChoice); 
        
        *abilityMap[ability] = abilityScoreChoice;
        // Find used ability score in the vector
        auto it = std::find(abilityScores.begin(), abilityScores.end(), abilityScoreChoice);

        // Check if the number is found before erasing
        if (it != abilityScores.end()) 
        {
            // Use vector's erase to remove the first occurrence
            abilityScores.erase(it);
        }
    }
}

void manually_set_abilities(Character& c, std::vector<std::string>abilities, std::map<std::string, int*> abilityMap)
{
    for(auto &ability : abilities)
   {
        bool validScore = false;
        int abilityScoreChoice = 0;

        do
        {
            std::cout << "What score would you like to assign to " << ability << "?" << std::endl
                      << "Enter the score here [1-18]: ";
            std::cin >> abilityScoreChoice;
            if(abilityScoreChoice > 18  || abilityScoreChoice < 1)
            {
                std::cout << std::endl << "Error: Score must be in the range 1-18." << std::endl 
                          << "Please try again." << std::endl << std::endl;
            }
            
            if(abilityScoreChoice <= 18 && abilityScoreChoice >= 1)
            {
                validScore = true;
            }
            
        }while (!validScore); 
        
        *abilityMap[ability] = abilityScoreChoice;
   }
}