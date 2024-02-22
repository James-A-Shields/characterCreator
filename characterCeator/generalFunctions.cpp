#include"generalFunctions.h"

std::string capitalise_words(const std::string& input)
{
    //Make input lowercase
    std::string lowerInput;
    for (char c : input)
    {
        lowerInput += std::tolower(c);
    }

    std::istringstream stream(lowerInput);
    std::string result, word;

    while (stream >> word)
    {
        if (!result.empty())
        {
            result += " "; // Add space between words
        }

        // Capitalize the first letter of each word
        word[0] = std::toupper(word[0]);
        result += word;
    }
    return result;
}

void display_vector(std::vector<std::string> list)
{
    for(auto e : list)
    {
        std::cout << e << std::endl;
    }
        
    std::cout << " " << std::endl << std::endl;
        
    return;
}

void display_vector(std::vector<int> list)
{
    for(auto e : list)
    {
        std::cout << e << std::endl;
    }
        
    std::cout << " " << std::endl << std::endl;
        
    return;
}

bool check_if_in_vector(int num, std::vector<int> vec)
{
    bool inVector = false;
    for(auto i : vec)
    {
        if(num == i)
        {
            inVector = true;
            break;
        }
    }
    return inVector;
}

int dice_roll(int noOfRolls, int type)
{
        // Seed the random number generator with a random device
    std::random_device rd;
    std::mt19937 gen(rd());
    int total = 0;
    
    
    std::uniform_int_distribution<int> roll(1, type);
    for(int i = 0; i < noOfRolls; i++)
    {
        total += roll(gen);
    }
        
    return total;
}