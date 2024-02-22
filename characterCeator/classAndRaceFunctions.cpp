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