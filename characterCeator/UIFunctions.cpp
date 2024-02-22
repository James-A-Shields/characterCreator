#include"UIFunctions.h"

void display_title()
{
    std::cout << std::endl << std::setw(14) << "" 
              << "Hello! Welccome to this D&D character creation tool!" << std::endl;
    return;
}

void dividing_line()
{
    std::cout << std::setfill('-') << std::setw(80) << "" << std::endl;
    std::cout << std::setfill(' ');
    return;
}

void display_ability_menu()
{
    std::cout << "You need to add ability scores to your character." 
              << std::endl << "How would you like to do so?" << std::endl << std::endl
              << "Please select one of the following options: " << std::endl <<std::endl
              << "1. Roll ability scores." << std::endl 
              << "2. Use the Standard Array." << std::endl
              << "3. Enter scores manually." << std::endl << std::endl
              << "Please enter your selection (e.g '1'): ";
}