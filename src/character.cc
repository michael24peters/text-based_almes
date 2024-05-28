#include <iostream>
#include <map>
#include <string>
#include <vector>
// setw(), left/right justify
#include <iomanip>
// print()
#include <sstream>

#include "character.h"

//***CONSTRUCTORS***//
// Default constructor
Character::Character()
    : name("Nameless One"), hit_points(1), skills({}), combat({}),
      s_languages({{"northern", 1.0}}), l_languages({}), religions({}),
      histories({}), supernatural({}), elder_races({}) {}

// Nearly-default constructor
// NOTE: User character needs default language set to 0.5
Character::Character(std::string name_)
    : name(name_), hit_points(1), skills({}), combat({}),
      s_languages({{"northern", 1.0}}), l_languages({}), religions({}),
      histories({}), supernatural({}), elder_races({}) {}

// Full parameterized constructor
Character::Character(std::string name_, int hit_points_,
                     std::map<std::string, float> attr_,
                     std::map<std::string, float> skills_,
                     std::map<std::string, float> combat_,
                     std::map<std::string, float> s_languages_,
                     std::map<std::string, float> l_languages_,
                     std::map<std::string, float> religions_,
                     std::map<std::string, float> histories_,
                     std::map<std::string, float> cultures_,
                     std::map<std::string, float> supernatural_,
                     std::map<std::string, float> elder_races_)
    : name(name_), hit_points(hit_points_), attr(attr_), skills(skills_),
      combat(combat_), s_languages(s_languages_), l_languages(l_languages_),
      religions(religions_), histories(histories_), cultures(cultures_),
      supernatural(supernatural_), elder_races(elder_races_) {}

// Copy constructor
Character::Character(Character &c)
    : name(c.name), hit_points(c.hit_points), attr(c.attr), skills(c.skills),
      combat(c.combat), s_languages(c.s_languages), l_languages(c.l_languages),
      religions(c.religions), histories(c.histories), cultures(c.cultures),
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

  // Name
  ss << "\n** " << std::left << std::setw(28) << name << std::right
     << std::setw(9) << "HP " + std::to_string(hit_points) + " *";
  ss << "\n*" << std::right << std::setw(39) << "*";

  // Attributes and hit points
  ss << std::left << std::setw(10)
     << "\n* STR " + std::to_string((int)attr["STR"]) << std::right
     << std::setw(31) << "*";
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

  // Skills
  if (skills.size() > 0) {
    ss << "\n** SKILLS ******************************";
    for (auto &pair : skills)
      ss << std::left << std::setw(20) << "\n* " + pair.first << std::right
         << std::setw(4) << std::to_string((int)pair.second) << std::right
         << std::setw(17) << "*";
    ss << "\n*" << std::right << std::setw(39) << "*";
  }
  if (combat.size() > 0) {
    ss << "\n** COMBAT ******************************";
    for (auto &pair : combat)
      ss << std::left << std::setw(20) << "\n* " + pair.first << std::right
         << std::setw(4) << std::to_string((int)pair.second) << std::right
         << std::setw(17) << "*";
    ss << "\n*" << std::right << std::setw(39) << "*";
  }
  if (s_languages.size() > 0) {
    ss << "\n** SPOKEN LANGUAGES ********************";
    for (auto &pair : s_languages)
      ss << std::left << std::setw(20) << "\n* " + pair.first << std::right
         << std::setw(4) << std::to_string((int)pair.second) << std::right
         << std::setw(17) << "*";
    ss << "\n*" << std::right << std::setw(39) << "*";
  }
  if (l_languages.size() > 0) {
    ss << "\n** LITERATE LANGUAGES ******************";
    for (auto &pair : l_languages)
      ss << std::left << std::setw(20) << "\n* " + pair.first << std::right
         << std::setw(4) << std::to_string((int)pair.second) << std::right
         << std::setw(17) << "*";
    ss << "\n*" << std::right << std::setw(39) << "*";
  }
  if (religions.size() > 0) {
    ss << "\n** RELIGIONS ***************************";
    for (auto &pair : religions)
      ss << std::left << std::setw(20) << "\n* " + pair.first << std::right
         << std::setw(4) << std::to_string((int)pair.second) << std::right
         << std::setw(17) << "*";
    ss << "\n*" << std::right << std::setw(39) << "*";
  }
  if (histories.size() > 0) {
    ss << "\n** HISTORIES ***************************";
    for (auto &pair : histories)
      ss << std::left << std::setw(20) << "\n* " + pair.first << std::right
         << std::setw(4) << std::to_string((int)pair.second) << std::right
         << std::setw(17) << "*";
    ss << "\n*" << std::right << std::setw(39) << "*";
  }
  if (cultures.size() > 0) {
    ss << "\n** CULTURES ****************************";
    for (auto &pair : cultures)
      ss << std::left << std::setw(20) << "\n* " + pair.first << std::right
         << std::setw(4) << std::to_string((int)pair.second) << std::right
         << std::setw(17) << "*";
    ss << "\n*" << std::right << std::setw(39) << "*";
  }
  if (supernatural.size() > 0) {
    ss << "\n** SUPERNATURAL ************************";
    for (auto &pair : supernatural)
      ss << std::left << std::setw(20) << "\n* " + pair.first << std::right
         << std::setw(4) << std::to_string((int)pair.second) << std::right
         << std::setw(17) << "*";
    ss << "\n*" << std::right << std::setw(39) << "*";
  }
  if (elder_races.size() > 0) {
    ss << "\n** ELDER RACES *************************";
    for (auto &pair : elder_races)
      ss << std::left << std::setw(20) << "\n* " + pair.first << std::right
         << std::setw(4) << std::to_string((int)pair.second) << std::right
         << std::setw(17) << "*";
    ss << "\n*" << std::right << std::setw(39) << "*";
  }

  // Final format
  ss << "\n***************************************/\n";

  // Print to cout
  std::cout << ss.str();
};
