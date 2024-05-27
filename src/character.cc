#include "character.h"
#include <iostream>
#include <map>
#include <string>
#include <vector>

//***CONSTRUCTORS***//
// Default constructor
Character::Character()
    : name("Nameless One"), hit_points(1), skills({}), combat({}),
      languages({{"northern", 1.0}}), religions({}), histories({}),
      supernatural({}), elder_races({}) {}

// Nearly-default constructor (User character)
Character::Character(std::string name_)
    : name(name_), hit_points(1), skills({}), combat({}),
      languages({{"northern", 0.5}}), religions({}), histories({}),
      supernatural({}), elder_races({}) {}

// Full parameterized constructor
Character::Character(std::string name_, int hit_points_,
                     std::map<std::string, float> attr_,
                     std::map<std::string, float> skills_,
                     std::map<std::string, float> combat_,
                     std::map<std::string, float> languages_,
                     std::map<std::string, float> religions_,
                     std::map<std::string, float> histories_,
                     std::map<std::string, float> cultures_,
                     std::map<std::string, float> supernatural_,
                     std::map<std::string, float> elder_races_)
    : name(name_), hit_points(hit_points_), attr(attr_), skills(skills_),
      combat(combat_), languages(languages_), religions(religions_),
      histories(histories_), cultures(cultures_), supernatural(supernatural_),
      elder_races(elder_races_) {}

// Copy constructor
Character::Character(Character &c)
    : name(c.name), hit_points(c.hit_points), attr(c.attr), skills(c.skills),
      combat(c.combat), languages(c.languages), religions(c.religions),
      histories(c.histories), cultures(c.cultures),
      supernatural(c.supernatural), elder_races(c.elder_races) {}

//***METHODS***//
std::vector<float>
Character::progress_algorithm(std::map<std::string, float> stat, int quality) {
  // TODO: implement progress_algorithm()
  return {};
};

std::string Character::print() {
  // TODO: implement progress_algorithm()
  return {};
};
