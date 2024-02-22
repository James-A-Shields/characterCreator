#include"fileFunctions.h"

std::ifstream open_file_for_reading(const std::string& filename, const std::string& type)
{
    std::string base_path = std::__fs::filesystem::current_path().string();
    std::string filepath = base_path +"/config/" + type + "/" + filename + ".xml";

    // Check if the file exists
    if (!std::__fs::filesystem::exists(filepath))
    {
        std::cerr << "File not found: " << filepath << std::endl;
        return std::ifstream();  // Return an empty ifstream if the file doesn't exist
    }

    std::ifstream in_file(filepath);

    if (!in_file.is_open())
    {
        std::cerr << "Error opening file: " << filepath << std::endl;
    }

    return in_file;
}
void update_character_stats_from_file(Character& c, std::ifstream& in_file, const std::string& type)
{
    if(!in_file.is_open())
    {
        std::cerr << "Error: Unable to open file." << std::endl;
        return;
    }
    
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load(in_file);
    
    if(result)
    {
        pugi::xml_node root = doc.child(type.c_str());
        if(root)
        {
            pugi::xml_node statsNode = root.child("Stats");
            
            if(statsNode)
            {

                pugi::xml_attribute charSizeAttr = statsNode.child("charSize").attribute("value");
                if (charSizeAttr)
                {
                    c.charSize = charSizeAttr.value();
                }

                
                pugi::xml_node baseSpeedNode = statsNode.child("baseSpeed");
                if(baseSpeedNode)
                {
                    c.baseSpeed = baseSpeedNode.attribute("value").as_int();
                }
                
                pugi::xml_node strengthNode = statsNode.child("strength");
                if(strengthNode)
                {
                    c.strength += strengthNode.attribute("value").as_int();
                }
                
                pugi::xml_node dexterityNode = statsNode.child("dexterity");
                if(dexterityNode)
                {
                    c.dexterity += dexterityNode.attribute("value").as_int();
                }
                
                pugi::xml_node constitutionNode = statsNode.child("constitution");
                if(constitutionNode)
                {
                    c.constitution += constitutionNode.attribute("value").as_int();
                }
                
                pugi::xml_node intelligenceNode = statsNode.child("intelligence");
                if(intelligenceNode)
                {
                    c.intelligence += intelligenceNode.attribute("value").as_int();
                }
                
                pugi::xml_node wisdomNode = statsNode.child("wisdom");
                if(wisdomNode)
                {
                    c.wisdom += wisdomNode.attribute("value").as_int();
                }
                
                pugi::xml_node charismaNode = statsNode.child("charisma");
                if(charismaNode)
                {
                    c.charisma += charismaNode.attribute("value").as_int();
                }
                
                pugi::xml_node hitDicePLNode = statsNode.child("hitDicePerLevel");
                if(hitDicePLNode)
                {
                    c.hitDice = hitDicePLNode.attribute("value").as_int() * c.lvl;
                    c.hitDiceMax = c.hitDice;
                }
                
                pugi::xml_node hitDiceTNode = statsNode.child("hitDiceType");
                if (hitDiceTNode)
                {
                    c.hitDiceType = hitDiceTNode.attribute("value").as_int();
                }
                
                if (c.lvl == 1)
                {
                    pugi::xml_node levelOneHealthNode = statsNode.child("levelOneHealth");
                    if(levelOneHealthNode)
                    {
                        c.hp = levelOneHealthNode.attribute("value").as_int() + ((c.constitution - 10)/2);
                    }
                }
                
                if (c.lvl > 1)
                {
                    c.hp = (dice_roll(c.lvl - 1, c.hitDiceType)) + ((c.constitution - 10)/2);
                    
                }
                
            }
           
            pugi::xml_node traitsNode = root.child("Traits");
            if(traitsNode)
            {
                int count = traitsNode.attribute("count").as_int();
                for (int i = 0; i < count; ++i) 
                {
                    pugi::xml_node traitNode = traitsNode.child("trait");
                    if (traitNode) 
                    {
                        c.traits.push_back(traitNode.child_value());
                    }
                } 
            }
            
            pugi::xml_node proficienciesNode = root.child("Proficiencies");
            if(proficienciesNode)
            {
                int count = proficienciesNode.attribute("count").as_int();
                for (pugi::xml_node proficiencyNode = proficienciesNode.child("proficiency"); proficiencyNode; proficiencyNode = proficiencyNode.next_sibling("proficiency"))
                {
                    c.proficiencies.push_back(proficiencyNode.child_value());
                }
            }
            
            pugi::xml_node languagesNode = root.child("Languages");
            if(languagesNode)
            {
                int count = languagesNode.attribute("count").as_int();
                for (int i = 0; i < count; ++i)
                {
                    pugi::xml_node languageNode = languagesNode.child("language");
                    if(languageNode)
                    {
                        c.languages.push_back(languageNode.child_value());
                    }
                }
            }
            
            pugi::xml_node savingThrowsNode = root.child("SavingThrows");
                if (savingThrowsNode)
                {
                    for (pugi::xml_node savingThrowNode = savingThrowsNode.child("savingThrow"); savingThrowNode; savingThrowNode = savingThrowNode.next_sibling("savingThrow"))
                    {
                        c.savingThrows.push_back(savingThrowNode.child_value());
                    }
                }
                
            pugi::xml_node featsNode = root.child("Feats");
                if (featsNode)
                {
                    int count = featsNode.attribute("count").as_int();
                    for (pugi::xml_node featNode = featsNode.child("feat"); featNode; featNode = featNode.next_sibling("feat"))
                    {
                        c.feats.push_back(featNode.child_value());
                    }
                }
        }
    }

    else
    {
        std::cerr << "Error: Unable to load XML file. " << result.description() << std::endl;
    }
    
}

void write_character_txt(Character& c)
{
    std::ofstream out_file;
    std::string filepath = "../characters/" + c.name + ".txt";
    out_file.open(filepath);
    
    if(!out_file.is_open())
    {
        std::cerr << "File not open." << std::endl;
    }
    
    out_file << "Name: " << c.name << std::endl
             << "Age: " << c.age << std::endl
             << "Race: " << c.race << std::endl
             << "Class: " << c.charClass << std::endl
             << "Size: " << c.charSize << std::endl
             << "Level: " << c.lvl << std::endl
             << "XP: " << c.xp << std::endl
             << "HP: " << c.hp << std::endl
             << "Max HP: " << c.hpMax << std::endl
             << "Hit Dice: " << c.hitDice << "/" << c.hitDiceMax << "d" << c.hitDiceType << std::endl
             << "Base Speed: " << c.baseSpeed << std::endl
             << "AC: " << c.ac << std::endl
             << "Strength: " << c.strength << std::endl
             << "Dexterity: " << c.dexterity << std::endl
             << "Constitution: " << c.constitution << std::endl
             << "Intelligence: " << c.intelligence << std::endl
             << "Wisdom: " << c.wisdom << std::endl
             << "Charisma: " << c.charisma << std::endl;
             
    out_file << "\nProficiencies:" << std::endl;
    for(auto p : c.proficiencies)
    {
        out_file << p << std::endl;
    }
    out_file << "\nLanguages:" << std::endl;
    for(auto l : c.languages)
    {
        out_file << l << std::endl;
    }
    out_file << "\nTraits:" << std::endl;
    for(auto t : c.traits)
    {
        out_file << t << std::endl;
    }
    out_file << "\nFeats:" << std::endl;
    for(auto f : c.feats)
    {
        out_file << f << std::endl;
    }
    out_file << "\nSaving Throws:" << std::endl;
    for(auto st : c.savingThrows)
    {
        out_file << st << std::endl;
    }
    out_file << "\nAbilities:" << std::endl;
    for(auto a : c.abilities)
    {
        out_file << a << std::endl;
    }
    
    out_file.close();
}