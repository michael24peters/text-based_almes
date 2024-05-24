#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "Character.h"

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
        NPC(std::string name_, std::string type) {

        }

        NPC(Character& c, std::string type_, int loc_id_,
        std::vector<bool> interactions_) : Character(c) {
                type = type;
                loc_id = loc_id_;
                interactions = interactions_;
            }
};