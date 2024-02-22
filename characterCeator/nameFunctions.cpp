#include"nameFunctions.h"

std::string get_char_name()
{
    std::string name;
    std::cout << "Please enter a name for the character: ";
    do
    {
        getline(std::cin, name);
        if(! valid_entry(name, std::string("")))
        {
            std::cout << "Invalid entry, please try again: ";
        }
    
    }while(! valid_entry(name, std::string("")));
    
    return name;
}