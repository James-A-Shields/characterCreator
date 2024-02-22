#ifndef CLASS_AND_RACE_FUNCTIONS_H
#define CLASS_AND_RACE_FUNCTIONS_H

#include "pugixml.hpp"
#include <filesystem>
#include<iostream>
#include<string>
#include<vector>

#include"generalFunctions.h"

std::string get_char_class_or_race(std::vector<std::string>);

std::vector<std::string> read_options_from_XML(const std::string& folderPath);

#endif //CLASS_AND_RACE_FUNCTIONS_H