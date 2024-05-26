#ifndef NPC_H
#define NPC_H

#include "character.h"
#include <map>
#include <string>
#include <vector>

class NPC : public Character {
private:
  std::string type;

public:
  int loc_id;
  std::vector<bool> interactions;

  //***CONSTRUCTORS***//
  NPC();

  // Nearly-default constructor
  NPC(std::string name_);

  // Construct generic NPC based on type
  NPC(std::string name_, std::string type_, int loc_id_);

  // Fully parameterized constructor
  NPC(Character &c, std::string type_, int loc_id_,
      std::vector<bool> interactions_);

  //***METHODS***//
  // Overload Character print() method to include NPC information
  std::string print();
};

#endif // NPC_H
