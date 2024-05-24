#include <iostream>
#include <string>
#include <vector>
#include <map>

class Character {
    private:
        std::string name;
        // Attributes: strength, intelligence, wisdom, dexterity, constitution,
        // charisma
        std::map<std::string, float> attr = {{"STR", 3.0},{"INT", 3.0}, 
            {"WIS", 3.0}, {"DEX", 3.0}, {"CON", 3.0}, {"CHA", 3.0}};
        std::map<std::string, float> skills;
        // Combat skills
        std::map<std::string, float> combat;
        // Hidden skill categories
        /* .5 = broken speech; 1 = fluent speech; 1.5 = basic literacy; 2 = fluency */
        /* -.5 = basic literacy; -1 = literate; -1.5 = broken speech; -2 = fluency */
        std::map<std::string, float> languages;
        std::map<std::string, float> religions;
        std::map<std::string, float> histories;
        std::map<std::string, float> cultures;
        std::map<std::string, float> supernatural;
        std::map<std::string, float> elder_races;
        int hit_points = 1;
        // TODO: spell list
        // TODO: abilities

    public:
        //***CONSTRUCTORS***//
        // Default constructor
        Character() {
            attr["STR"] = 5.0;
            attr["INT"] = 5.0;
            attr["WIS"] = 5.0;
            attr["DEX"] = 5.0;
            attr["CON"] = 5.0;
            attr["CHA"] = 5.0;
            languages["northern"] = 0.5;
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
            std::map<std::string, float> elder_races_);

        //***GETTERS & SETTERS***//
        std::string getName() const { return name; }
        void setName(const std::string &name_) { name = name_; }

        std::map<std::string, float> getAttr() const { return attr; }
        void setAttr(const std::map<std::string, float> &attr_) { attr = attr_; }

        std::map<std::string, float> getSkills() const { return skills; }
        void setSkills(const std::map<std::string, float> &skills_) { skills = skills_; }

        std::map<std::string, float> getCombat() const { return combat; }
        void setCombat(const std::map<std::string, float> &combat_) { combat = combat_; }

        std::map<std::string, float> getLanguages() const { return languages; }
        void setLanguages(const std::map<std::string, float> &languages_) { languages = languages_; }

        std::map<std::string, float> getReligions() const { return religions; }
        void setReligions(const std::map<std::string, float> &religions_) { religions = religions_; }

        std::map<std::string, float> getHistories() const { return histories; }
        void setHistories(const std::map<std::string, float> &histories_) { histories = histories_; }

        std::map<std::string, float> getCultures() const { return cultures; }
        void setCultures(const std::map<std::string, float> &cultures_) { cultures = cultures_; }

        std::map<std::string, float> getSupernatural() const { return supernatural; }
        void setSupernatural(const std::map<std::string, float> &supernatural_) { supernatural = supernatural_; }

        std::map<std::string, float> elderRaces() const { return elder_races; }
        void setElderRaces(const std::map<std::string, float> &elderRaces) { elder_races = elderRaces; }

        int hitPoints() const { return hit_points; }
        void setHitPoints(int hitPoints) { hit_points = hitPoints; }

        //***METHODS***//
        std::vector<float> progress_algorithm(std::map<std::string, float> stat);
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
    std::map<std::string, float> elder_races_) {

    name = name_;
    skills = skills_;
    combat = combat_;
    languages = languages_;
    religions = religions_;
    histories = histories_;
    cultures = cultures_;
    supernatural = supernatural_;
    elder_races = elder_races_;
}