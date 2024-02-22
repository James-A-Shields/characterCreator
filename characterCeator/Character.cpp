#include "Character.h"

//constructor & destructor
Character::Character(std::string x)
{
        name = x;
        std::cout << std::endl << "Character: " << name <<  " created." << std::endl;

}

Character::~Character()
{
}

