#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "character.h"

class NPC : public Character {
    private:
        std::string type;
    public:
        int loc_id;
        std::vector<bool> interactions;

        // Nearly-default constructor
        NPC(std::string name_) : Character(name_) {
            loc_id = 0;
            interactions.push_back(false);
            type = "Unknown";
        }

        // Construct generic NPC based on type
        NPC(std::string name_, std::string type_) : Character(name_) {
            type = type_;

            // TODO: generic Character archetypes
            if(type == "farmer") {
            } else if (type == "warrior") {
            } else if (type == "rogue") {
            } else if (type == "priest") {
            } else if (type == "mage") {
            } else if (type == "animal") {
            } else {}
        }

        NPC(Character& c, std::string type_, int loc_id_,
        std::vector<bool> interactions_) : Character(c) {
                type = type_;
                loc_id = loc_id_;
                interactions = interactions_;
            }
};