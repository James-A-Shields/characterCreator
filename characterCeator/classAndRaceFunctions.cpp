#include"classAndRaceFunctions.h"

namespace fs = std::__fs::filesystem;

std::vector<std::string> read_options_from_XML(const std::string& folderPath) {
    std::vector<std::string> options;

    for (const auto& entry : fs::directory_iterator(folderPath)) {
        if (entry.is_regular_file() && entry.path().extension() == ".xml") {
            std::string fileName = entry.path().filename().stem().string(); // Extract filename without extension
            options.push_back(fileName);
        }
    }

    return options;

}

std::string get_char_class_or_race(std::vector<std::string> list)
{
    std::string entry;
    std::string entryFormatted;
    bool valid = false;
    
    do
    {
        getline(std::cin, entry);
        entryFormatted = capitalise_words(entry);
        for(auto e : list)
        {
            if (entryFormatted == e)
            {
                valid = true;
                break;
            }
        }
        
        if(!valid)
        {
            std::cout << entryFormatted << " does not appear in the class list." << std::endl;
        }
        
    }while(! valid);
    
    return entryFormatted;
}

void race_function(Character &c)
{
    std::cout << "Races:  " << std::endl << std::endl;
    
    std::string base_path = std::__fs::filesystem::current_path().string();
    std::string filepath = base_path +"/config/race";
    
    std::vector<std::string> races = read_options_from_XML(filepath);
    display_vector(races);
    std::cout << "Please enter a race:";
    std::string race = get_char_class_or_race(races);
    c.race = race;
    std::ifstream in_file = open_file_for_reading(race, "race");
    if (in_file.is_open())
    {
        std::cout << std::endl <<"Your character's race is: " << race << std::endl 
                  <<std::endl;
        
        update_character_stats_from_file(c, in_file, race);
    }
    else
        std::cerr << "Error reading race config file." << std::endl;
    in_file.close();
}

void class_function(Character &c)
{
    std::string base_path = std::__fs::filesystem::current_path().string();
    std::string filepath = base_path +"/config/class";
    
    std::vector<std::string> classes = read_options_from_XML(filepath);
    display_vector(classes);
    std::cout << "Please enter a class: ";
    std::string charClass = get_char_class_or_race(classes);
    c.charClass = charClass;
    std::ifstream in_file = open_file_for_reading(charClass, "class");
    if (in_file.is_open())
    {
        std::cout << std::endl <<"Your character's class is: " << charClass << std::endl 
                  <<std::endl;
        
        update_character_stats_from_file(c, in_file, charClass);
    }
    else
        std::cerr << "Error reading race config file." << std::endl;
    
    in_file.close();
}