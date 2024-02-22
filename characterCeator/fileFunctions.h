#ifndef FILE_FUNCTIONS_H
#define FILE_FUNCTIONS_H

#include<fstream>
#include<string>
#include<iostream>
#include<iomanip>
#include<filesystem>

#include"Character.h"

#include"generalFunctions.h"

#include"pugixml.hpp" //XML reader library

std::ifstream open_file_for_reading(const std::string& filename, const std::string& type);

void update_character_stats_from_file(Character& c, std::ifstream& in_file, const std::string& type);

void write_character_xml(Character& c);
void write_character_txt(Character& c);

#endif //FILE_FUNCTIONS_H