#include "catch.hpp"
#include "character.h"
#include <iostream>
#include <map>
#include <string>

TEST_CASE("character constructors") {
  // Fully paramaterized values
  std::string name = "Tharrack";
  int hit_points = 33;
  std::map<std::string, float> attr = {{"STR", 13.0}, {"INT", 8.0},
                                       {"WIS", 6.0},  {"DEX", 12.0},
                                       {"CON", 19.0}, {"CHA", 3.0}};
  std::map<std::string, float> skills = {
      {"athletics", 2.0}, {"horseriding", 1.0}, {"trapping", 2.0}};
  std::map<std::string, float> combat = {{"sword", 3.0},
                                         {"glaive-guisarme", 4.0}};
  std::map<std::string, float> languages = {
      {"northern", 1.5}, {"goblin", 1.0}, {"central", -0.5}};
  std::map<std::string, float> religions = {{"death goddess", 1.0},
                                            {"animism", 1.0}};
  std::map<std::string, float> histories = {{"almes woodlands", 0.5}};
  std::map<std::string, float> cultures = {{"almes barbarians", 3.0},
                                           {"great kingdom", 1.0}};
  std::map<std::string, float> supernatural = {};
  std::map<std::string, float> elder_races = {{"mi-go", 1.0}};

  // Useful default variables
  std::map<std::string, float> def_attr = {{"STR", 3.0}, {"INT", 3.0},
                                           {"WIS", 3.0}, {"DEX", 3.0},
                                           {"CON", 3.0}, {"CHA", 3.0}};
  std::map<std::string, float> empty = {};
  std::map<std::string, float> def_lang = {{"northern", 1.0}};

  // Characters
  Character c_def;
  Character c_name("Balthazar");
  Character c_param(name, hit_points, attr, skills, combat, languages,
                    religions, histories, cultures, supernatural, elder_races);
  Character c_copy(c_param);

  SECTION("default constructor") {
    REQUIRE(c_def.name == "Nameless One");
    REQUIRE(c_def.hit_points == 1);
    REQUIRE(c_def.attr == def_attr);
    REQUIRE(c_def.skills == empty && c_def.combat == empty &&
            c_def.religions == empty && c_def.histories == empty &&
            c_def.supernatural == empty && c_def.elder_races == empty);
    REQUIRE(c_def.languages == def_lang);
  }
  SECTION("name constructor") {
    REQUIRE(c_def.name == "Balthazar");
    REQUIRE(c_def.hit_points == 1);
    REQUIRE(c_def.attr == def_attr);
    REQUIRE(c_def.skills == empty && c_def.combat == empty &&
            c_def.religions == empty && c_def.histories == empty &&
            c_def.supernatural == empty && c_def.elder_races == empty);
    REQUIRE(c_def.languages == def_lang);
  }
  SECTION("full parameterized constructor") {
    REQUIRE(c_param.name == name);
    REQUIRE(c_param.hit_points == hit_points);
    REQUIRE(c_param.attr == attr);
    REQUIRE(c_param.skills == skills);
    REQUIRE(c_param.combat == combat);
    REQUIRE(c_param.languages == languages);
    REQUIRE(c_param.religions == religions);
    REQUIRE(c_param.histories == histories);
    REQUIRE(c_param.supernatural == supernatural);
    REQUIRE(c_param.elder_races == elder_races);
  }
  SECTION("copy constructor") {
    REQUIRE(c_param.name == c_copy.name);
    REQUIRE(c_param.hit_points == c_copy.hit_points);
    REQUIRE(c_param.attr == c_copy.attr);
    REQUIRE(c_param.skills == c_copy.skills);
    REQUIRE(c_param.combat == c_copy.combat);
    REQUIRE(c_param.languages == c_copy.languages);
    REQUIRE(c_param.religions == c_copy.religions);
    REQUIRE(c_param.histories == c_copy.histories);
    REQUIRE(c_param.supernatural == c_copy.supernatural);
    REQUIRE(c_param.elder_races == c_copy.elder_races);
  }
}
