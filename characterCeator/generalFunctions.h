#ifndef GENERAL_FUNCTIONS_H
#define GENERAL_FUNCTIONS_H

#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<random>

std::string capitalise_words(const std::string& input);

void display_vector(std::vector<std::string>);
void display_vector(std::vector<int>);
bool check_if_in_vector(int, std::vector<int>);

int dice_roll(int noOfRolls, int type);

template<typename t1, typename t2>
bool valid_entry(const t1& a,const t2& b)
{
    return typeid(a) == typeid(b);
}

#endif // GENERAL_FUNCTIONS_H