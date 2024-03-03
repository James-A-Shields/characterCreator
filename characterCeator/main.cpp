//A character creation tool for DnD.
#include<string>
#include<map>
#include<vector>

//Structs
#include"Character.h"
#include"vectorsMapsEtc.h"

//Functions
#include"UIFunctions.h"
#include"nameFunctions.h"
#include"abilityFunctions.h"
#include"classAndRaceFunctions.h"
#include"fileFunctions.h"
#include"ageAndLevelFunctions.h"

//Main
int main()
{
    // Title
    display_title();
    dividing_line();
    
    // Name
    Character c(capitalise_words(get_char_name())); // also creates character object
    dividing_line();
    
    // Age
    age_function(c);
    dividing_line();
    
    // Level 
    level_function(c);
    dividing_line();    
    
    // Abilities
    bool abilitiesDone = false;
    std::map<std::string, int*> abilityMap = createAbilityMap(c);
    
    display_ability_menu();
    ability_menu_selection(abilityMap, abilitiesDone, abilities, standardArray, c);
    dividing_line();
    
    // Set Race
    race_function(c);
    dividing_line();
        
    // Set Class
    class_function(c);
    dividing_line();
    
    // Write to Text File
    write_character_txt(c);
    
    return 0;
}