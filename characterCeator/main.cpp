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

//Main
int main(){
    //Vectors, Variables etc.
    std::vector<std::string> abilities{"Strength", "Dexterity", "Constitution", "Intelligence", "Wisdom", "Charisma"};

    //Going to replace this with a vector built from filenames as I have done with Races
    std::vector<std::string> classes{"Barbarian","Bard","Cleric", 
    "Druid","Fighter","Monk","Paladin","Ranger","Rogue",
    "Sorcerer","Warlock","Wizard","Artificer","Blood Hunter"};
    
    std::vector<int> standardArray {15, 14, 13, 12, 10, 8};
    
    //Title
    display_title();
    dividing_line();
    
    //Name
    Character c(capitalise_words(get_char_name()));
    dividing_line();
    
    //PROBABLY MAKE TEHSE TWO INTO FUNCTIONS RATHER THAN HAVE THEM IN MAIN
    //Age
    std::cout << "Please enter the chacters age: ";
    int age;
    std::cin >> age;
    c.age = age;
    std::cout << "\nYour character is: " << age << std::endl;
    dividing_line();
    
    //Level 
    std::cout << "Please enter the chacters level: ";
    int lvl;
    std::cin >> lvl;
    c.lvl = lvl;
    std::cout << "\nYour character is level: " << lvl << std::endl;
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
    
    
    //THESE TWO SECTIONS NEED TO BE MADE INOT FUNCTIONS
    //Race
    std::cout << "Races:  " << std::endl << std::endl;
    
    std::string base_path = std::__fs::filesystem::current_path().string();
    std::string filepath = base_path +"/config/race";
    
    std::vector<std::string> races = read_options_from_XML(filepath);
    display_vector(races);
    std::cout << "Please enter a race:";
    std::string race = get_char_class_or_race(races);
    c.race = race;
    std::ifstream in_file = open_file_for_reading(race, "race");
    if (in_file.is_open())
    {
        std::cout << std::endl <<"Your character's race is: " << race << std::endl 
                  <<std::endl;
        
        update_character_stats_from_file(c, in_file, race);
    }
    else
        std::cerr << "Error reading race config file." << std::endl;
    dividing_line();
    
    //Class
    std::cout << "Character Classes: " << std::endl << std::endl;
    display_vector(classes);
    std::cout << "Please enter a class: ";
    std::string charClass = get_char_class_or_race(classes);
    c.charClass = charClass;
    in_file = open_file_for_reading(charClass, "class");
    if (in_file.is_open())
    {
        std::cout << std::endl <<"Your character's class is: " << charClass << std::endl 
                  <<std::endl;
        
        update_character_stats_from_file(c, in_file, charClass);
    }
    else
        std::cerr << "Error reading race config file." << std::endl;
    
    dividing_line();
    
    //Write to Text File
    write_character_txt(c);
    
    in_file.close();
    
return 0;
}