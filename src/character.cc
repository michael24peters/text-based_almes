#include <iostream>
#include <map>
#include <string>
#include <vector>
// setprecision() for floats
#include <iomanip>
#include <sstream>

#include "character.h"

//***CONSTRUCTORS***//
// Default constructor
Character::Character()
    : name("Nameless One"), hit_points(1), skills({}), combat({}),
      languages({{"northern", 1.0}}), religions({}), histories({}),
      supernatural({}), elder_races({}) {}

// Nearly-default constructor
// NOTE: User character needs default language set to 0.5
Character::Character(std::string name_)
    : name(name_), hit_points(1), skills({}), combat({}),
      languages({{"northern", 1.0}}), religions({}), histories({}),
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

void Character::print() {
  // TODO: implement progress_algorithm()
  std::stringstream ss;
  // Initial format
  ss << "\n/***************************************";
  ss << std::left << std::setw(10)
     << "\n* STR " + std::to_string((int)attr["STR"]) << std::right
     << std::setw(10) << "\tHP " + std::to_string(hit_points) << std::right
     << std::setw(19) << "*";
  ss << std::left << std::setw(10)
     << "\n* INT " + std::to_string((int)attr["INT"]) << std::right
     << std::setw(31) << "*";
  ss << std::left << std::setw(10)
     << "\n* WIS " + std::to_string((int)attr["WIS"]) << std::right
     << std::setw(31) << "*";
  ss << std::left << std::setw(10)
     << "\n* DEX " + std::to_string((int)attr["DEX"]) << std::right
     << std::setw(31) << "*";
  ss << std::left << std::setw(10)
     << "\n* CON " + std::to_string((int)attr["CON"]) << std::right
     << std::setw(31) << "*";
  ss << std::left << std::setw(10)
     << "\n* CHA " + std::to_string((int)attr["CHA"]) << std::right
     << std::setw(31) << "*";
  ss << "\n*" << std::right << std::setw(39) << "*";

  if (skills.size() > 0) {
    ss << "\n** SKILLS ******************************";
    for (auto &pair : skills)
      ss << std::left << std::setw(20) << "\n* " + pair.first << std::right
         << std::setw(4) << std::setprecision(1) << (pair.second);
    ss << "\n*";
  }

  if (combat.size() > 0) {
    ss << "\n** COMBAT ******************************";
    for (auto &pair : combat)
      ss << std::left << std::setw(20) << "\n* " + pair.first << std::right
         << std::setw(4) << std::setprecision(1) << (pair.second);
    ss << "\n*";
  }

  if (languages.size() > 0) {
    ss << "\n** LANGUAGES ***************************";
    for (auto &pair : languages)
      ss << std::left << std::setw(20) << "\n* " + pair.first << std::right
         << std::setw(4) << std::setprecision(1) << (pair.second);
    ss << "\n*";
  }

  if (religions.size() > 0) {
    ss << "\n** RELIGIONS ***************************";
    for (auto &pair : religions)
      ss << std::left << std::setw(20) << "\n* " + pair.first << std::right
         << std::setw(4) << std::setprecision(1) << (pair.second);
    ss << "\n*";
  }

  if (histories.size() > 0) {
    ss << "\n** HISTORIES ***************************";
    for (auto &pair : histories)
      ss << std::left << std::setw(20) << "\n* " + pair.first << std::right
         << std::setw(4) << std::setprecision(1) << (pair.second);
    ss << "\n*";
  }

  if (cultures.size() > 0) {
    ss << "\n** CULTURES ****************************";
    for (auto &pair : cultures)
      ss << std::left << std::setw(20) << "\n* " + pair.first << std::right
         << std::setw(4) << std::setprecision(1) << (pair.second);
    ss << "\n*";
  }

  if (supernatural.size() > 0) {
    ss << "\n** SUPERNATURAL ************************";
    for (auto &pair : supernatural)
      ss << std::left << std::setw(20) << "\n* " + pair.first << std::right
         << std::setw(4) << std::setprecision(1) << (pair.second);
    ss << "\n*";
  }

  if (elder_races.size() > 0) {
    ss << "\n** ELDER RACES *************************";
    for (auto &pair : elder_races)
      ss << std::left << std::setw(20) << "\n* " + pair.first << std::right
         << std::setw(4) << std::setprecision(1) << (pair.second);
    ss << "\n*";
  }

  ss << "\n***************************************/\n";

  std::cout << ss.str();
};
