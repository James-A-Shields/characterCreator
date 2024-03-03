#ifndef VECTORS_MAPS_ETC_H
#define VECTORS_MAPS_ETC_H

#include<vector>
#include<map>
#include<string>

#include"Character.h"

//Vectors
    std::vector<std::string> abilities{"Strength", "Dexterity", "Constitution", "Intelligence", "Wisdom", "Charisma"};
    
    std::vector<int> standardArray {15, 14, 13, 12, 10, 8};
    
//Maps
    
    auto createAbilityMap = [](Character &c) -> std::map<std::string, int*> 
    {
        return 
        {
            {"Strength", &c.strength},
            {"Dexterity", &c.dexterity},
            {"Constitution", &c.constitution},
            {"Intelligence", &c.intelligence},
            {"Wisdom", &c.wisdom},
            {"Charisma", &c.charisma}
        };
    };
//    std::map<std::string, int*> abilityMap = 
//    {
//        {"Strength", &c.strength},
//        {"Dexterity", &c.dexterity},
//        {"Constitution", &c.constitution},
//        {"Intelligence", &c.intelligence},
//        {"Wisdom", &c.wisdom},
//        {"Charisma", &c.charisma}
//    };

#endif //VECTORS_MAPS_ETC_H