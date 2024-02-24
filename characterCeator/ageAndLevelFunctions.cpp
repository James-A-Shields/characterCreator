#include"ageAndLevelFunctions.h"

void age_function(Character &c)
{
    std::cout << "Please enter the chacters age: ";
    int age;
    std::cin >> age;
    c.age = age;
    std::cout << "\nYour character is: " << age << std::endl;
}

void level_function(Character &c)
{
    std::cout << "Please enter the chacters level: ";
    int lvl;
    std::cin >> lvl;
    c.lvl = lvl;
    std::cout << "\nYour character is level: " << lvl << std::endl;
}