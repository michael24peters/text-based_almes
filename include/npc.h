#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "character.h"

class NPC : public Character {
        // Nearly-default constructor
        NPC(std::string name_) : Character(name_);

        // Construct generic NPC based on type
        NPC(std::string name_, std::string type_);

        NPC(Character& c, std::string type_, int loc_id_,
        std::vector<bool> interactions_);

        // Overload Character print() method to include NPC information
        std::string print();
};