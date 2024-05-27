#include "npc.h"
#include "character.h"
#include <iostream>
#include <map>
#include <string>
#include <vector>

//***CONSTRUCTORS***//
// Default constructor
NPC::NPC() : loc_id(0), type("Unknown"), interactions({false}), {}

// Nearly-default constructor
NPC::NPC(std::string name_)
    : Character(name_), type("Unknown"), loc_id(0), interactions({false}) {}

// Construct generic NPC based on type
NPC::NPC(std::string name_, std::string type_, int loc_id_)
    : Character(name_), type(type_), loc_id(loc_id_) {

  // TODO: generic Character archetypes
  if (type == "farmer") {
  } else if (type == "warrior") {
  } else if (type == "rogue") {
  } else if (type == "priest") {
  } else if (type == "mage") {
  } else if (type == "animal") {
  } else {
  }
}

// Full parameterized constructor
NPC::NPC(Character &c, std::string type_, int loc_id_,
         std::vector<bool> interactions_)
    : Character::Character(c), type(type_), loc_id(loc_id_),
      interactions(interactions_) {}

//***METHODS***//
// type getter()
std::string NPC::get_type() { return type; }

// Overload Character print() method to include NPC information
std::string NPC::print() { return ""; }
