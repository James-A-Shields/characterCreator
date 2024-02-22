#ifndef CHARACTER_H
#define CHARACTER_H

#include<string>
#include<iostream>
#include<vector>
#include<map>

struct Character
{
    //Basics
    std::string name;
    int age;
    std::string race;
    std::string charClass;
    
    std::string charSize;

    //Lvl & Xp
    int lvl{1};
    int xp{0};
    
    //Hp & Hit Dice
    int hp{0};
    int hpMax{0};
    
    int hitDice{0};
    int hitDiceMax{0};
    int hitDiceType{0};
    
    //Stats
    int baseSpeed{0};
    int ac{0};
    int profBonus{0};
    int strength{0};
    int dexterity{0};
    int constitution{0};
    int intelligence{0};
    int wisdom{0};
    int charisma{0};
    
    //Inventory
    int gold;
    int silver;
    int copper;
    std::vector<std::string> inventory;
    
    //Spells & Cantrips
    std::vector<std::string> cantrips;
    std::vector<std::string> spells;

    //Proficiencies, Traits, Skills etc.
    std::vector<std::string> proficiencies;
    std::vector<std::string> languages;
    std::vector<std::string> traits;
    std::vector<std::string> feats;
    std::vector<std::string> savingThrows;
    std::vector<std::string> abilities;


    //Constructor & Destructor
    Character(std::string x);
    ~Character();
    
    //Function Templates

    
    //Functions
};

#endif //CHARACTER_H
