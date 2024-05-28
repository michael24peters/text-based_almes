#ifndef CHARACTER_H
#define CHARACTER_H

#include <map>
#include <string>
#include <vector>

class Character {
public:
  //***MEMBER VARIABLES***//
  std::string name;
  int hit_points;
  std::map<std::string, float> attr = {{"STR", 3.0}, {"INT", 3.0},
                                       {"WIS", 3.0}, {"DEX", 3.0},
                                       {"CON", 3.0}, {"CHA", 3.0}};
  std::map<std::string, float> skills;
  std::map<std::string, float> combat;
  // 1 = basic literacy; 2 = literate; 3 = well-read; 4 = scholar
  std::map<std::string, float> l_languages;
  // 1 = broken speech; 2 = fluent speech; 3 = well-spoken; 4 = orator
  std::map<std::string, float> s_languages;
  std::map<std::string, float> religions;
  std::map<std::string, float> histories;
  std::map<std::string, float> cultures;
  std::map<std::string, float> supernatural;
  std::map<std::string, float> elder_races;
  // TODO: spells
  // TODO: special abilities

  //***CONSTRUCTORS***//
  Character();
  Character(std::string name_);
  Character(std::string name_, int hit_points_,
            std::map<std::string, float> attr_,
            std::map<std::string, float> skills_,
            std::map<std::string, float> combat_,
            std::map<std::string, float> s_languages_, // Spoken languages
            std::map<std::string, float> l_languages_, // Literate languages
            std::map<std::string, float> religions_,
            std::map<std::string, float> histories_,
            std::map<std::string, float> cultures_,
            std::map<std::string, float> supernatural_,
            std::map<std::string, float> elder_races_);
  Character(Character &c);

  //***METHODS***//
  std::vector<float> progress_algorithm(std::map<std::string, float> stat,
                                        int quality);
  // Print character sheet
  void print();
};

#endif // CHARACTER_H
