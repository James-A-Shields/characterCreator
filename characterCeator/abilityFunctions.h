#ifndef ABILITY_FUNCTIONS_H
#define ABILITY_FUNCTIONS_H

#include<vector>
#include<iostream>
#include<string>
#include<deque>
#include<map>
#include<algorithm>

#include"Character.h"

#include"generalFunctions.h"
#include"UIFunctions.h"

std::vector<int> get_ability_scores();

void ability_menu_selection(std::map<std::string, int*> abilityMap, bool abilitiesDone, std::vector<std::string> abilities, std::vector<int> standardArray, Character c);

void set_ability_scores(Character& c, std::vector<int>, std::vector<std::string>, std::map<std::string, int*>);

void manually_set_abilities(Character& c, std::vector<std::string>, std::map<std::string, int*>);

#endif //ABILITY_FUNCTIONS_H