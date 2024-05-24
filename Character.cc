#include <iostream>
#include <string>
#include <vector>
#include <map>

class Character {
    public:
        std::string name;
        // Attributes: strength, intelligence, wisdom, dexterity, constitution,
        // charisma
        std::map<std::string, float> attr = {{"STR", 3.0},{"INT", 3.0}, 
            {"WIS", 3.0}, {"DEX", 3.0}, {"CON", 3.0}, {"CHA", 3.0}};
        std::map<std::string, float> skills;
        // Combat skills
        std::map<std::string, float> combat;

        /*
         * HIDDEN SKILLS
         * 
         * These may become private variables. Once they are "discovered",
         * they are moved over to the public skills category.
        */

        /* .5 = broken speech; 1 = fluent speech; 1.5 = basic literacy; 2 = fluency
        -.5 = basic literacy; -1 = literate; -1.5 = broken speech; -2 = fluency */
        std::map<std::string, float> languages;
        std::map<std::string, float> religions;
        std::map<std::string, float> histories;
        std::map<std::string, float> cultures;
        std::map<std::string, float> supernatural;
        std::map<std::string, float> elder_races;
        int hit_points;
        // TODO: spell list
        // TODO: abilities

        //***CONSTRUCTORS***//
        // TODO: destructor
        // Default constructor
        Character() {
            attr["STR"] = 5.0;
            attr["INT"] = 5.0;
            attr["WIS"] = 5.0;
            attr["DEX"] = 5.0;
            attr["CON"] = 5.0;
            attr["CHA"] = 5.0;
            hit_points = 1;
        }
        
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

        //***METHODS***//
        std::vector<float> progress_algorithm(std::map<std::string, float> stat, int quality);
};

// Creates User Character
Character::Character(std::string nom) {
    name = nom;
    attr["STR"] = 5.0;
    attr["INT"] = 5.0;
    attr["WIS"] = 5.0;
    attr["DEX"] = 5.0;
    attr["CON"] = 5.0;
    attr["CHA"] = 5.0;
    languages["northern"] = 0.5;
}

// Fully paramaterized constructor
Character::Character(std::string name_, 
    std::map<std::string, float> skills_, 
    std::map<std::string, float> combat_,
    std::map<std::string, float> languages_,
    std::map<std::string, float> religions_, 
    std::map<std::string, float> histories_,
    std::map<std::string, float> cultures_, 
    std::map<std::string, float> supernatural_,
    std::map<std::string, float> elder_races_,
    int hit_points_) {

    name = name_;
    skills = skills_;
    combat = combat_;
    languages = languages_;
    religions = religions_;
    histories = histories_;
    cultures = cultures_;
    supernatural = supernatural_;
    elder_races = elder_races_;
    hit_points = hit_points_;
}