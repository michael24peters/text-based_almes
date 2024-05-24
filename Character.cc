#include <iostream>
#include <string>
#include <vector>
#include <map>

class Character {
    public:
        std::string name;
        int hit_points;
        // Attributes: STRength, INTelligence, WISdom, DEXterity, CONstitution,
        // CHArisma
        std::map<std::string, float> attr = {{"STR", 3.0},{"INT", 3.0}, {"WIS", 3.0}, {"DEX", 3.0}, {"CON", 3.0}, 
        {"CHA", 3.0}};
        std::map<std::string, float> skills;
        // Combat skills
        std::map<std::string, float> combat;

        /*
         * HIDDEN SKILLS
         * 
         * These may become private variables. Once they are "discovered",
         * they are moved over to the public skills category.
        */

        /* 1 = broken speech; 2 = fluent speech; 3 = basic literacy; 4 = fluency
        -1 = basic literacy; -2 = literate; -3 = broken speech; -4 = fluency */
        std::map<std::string, float> languages;
        std::map<std::string, float> religions;
        std::map<std::string, float> histories;
        std::map<std::string, float> cultures;
        std::map<std::string, float> supernatural;
        std::map<std::string, float> elder_races;
        // TODO: spell list
        // TODO: abilities

        //***CONSTRUCTORS***//        
        // Nearly-default constructor
        Character(std::string name_) : name(name_) {
            languages["northern"] = 0.5;
            hit_points = 1;
        }

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

        // Copy constructor
        Character(Character& c) {
            name = c.name;
            skills = c.skills;
            combat = c.combat;
            languages = c.languages;
            religions = c.religions;
            histories = c.histories;
            cultures = c.cultures;
            supernatural = c.supernatural;
            elder_races = c.elder_races;
            hit_points = c.hit_points;
        }

        //***METHODS***//
        std::vector<float> progress_algorithm(std::map<std::string, float> stat, int quality);
};