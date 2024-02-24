//A character creation tool for DnD.
#include<iostream>
#include<fstream>
#include<filesystem>
#include<string>
#include<sstream>
#include<cctype>
#include<array>
#include<algorithm>
#include<map>
#include<random>
#include<deque>
#include<vector>

//Libraries
#include"pugixml.hpp" //XML reader library

//Classes
#include"Character.h"

//Functions
#include"generalFunctions.h"
#include"UIFunctions.h"
#include"nameFunctions.h"
#include"abilityFunctions.h"
#include"classAndRaceFunctions.h"
#include"fileFunctions.h"
#include"ageAndLevelFunctions.h"

//Main
int main(){
    //Vectors, Variables etc.
    std::vector<std::string> abilities{"Strength", "Dexterity", "Constitution", "Intelligence", "Wisdom", "Charisma"};
    
    std::vector<int> standardArray {15, 14, 13, 12, 10, 8};
    
    //Title
    display_title();
    dividing_line();
    
    //Name
    Character c(capitalise_words(get_char_name())); // also creates character object
    dividing_line();
    
    //PROBABLY MAKE TEHSE TWO INTO FUNCTIONS RATHER THAN HAVE THEM IN MAIN
    //Age
    age_function(c);

    dividing_line();
    
    //Level 
    level_function(c);

    dividing_line();    
    
    //Abilities
    bool abilitiesDone = false;
    std::map<std::string, int*> abilityMap = 
    {
        {"Strength", &c.strength},
        {"Dexterity", &c.dexterity},
        {"Constitution", &c.constitution},
        {"Intelligence", &c.intelligence},
        {"Wisdom", &c.wisdom},
        {"Charisma", &c.charisma}
    };
    
    display_ability_menu();
    
    //user selects menu option and then relevent function will be called
    ability_menu_selection(abilityMap, abilitiesDone, abilities, standardArray, c);
    
    dividing_line();
    
    //Set Race
    race_function(c);
    
    dividing_line();
        
    //Set Class
    class_function(c);
    
    dividing_line();
    
    //Write to Text File
    write_character_txt(c);
    
    
return 0;
}