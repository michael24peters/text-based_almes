#include <iostream>
#include <string>
#include <vector>
#include <map>

class Character {
    public:
        // Default constructor
        Character();
        
        // Creates User Character
        Character(std::string name_);

        // Full parameterized constructor
        Character(std::string name_, 
            std::map<std::string, float> skills_, 
            std::map<std::string, float> combat_,
            std::map<std::string, float> languages_,
            std::map<std::string, float> religions_, 
            std::map<std::string, float> histories_,
            std::map<std::string, float> cultures_, 
            std::map<std::string, float> supernatural_,
            std::map<std::string, float> elder_races_,
            int hit_points_);

        // Updates progress of stats
        std::vector<float> progress_algorithm(std::map<std::string, float> stat, int quality);
};