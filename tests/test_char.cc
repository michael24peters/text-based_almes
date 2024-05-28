#include "catch.hpp"
#include "character.h"
#include <iostream>
#include <map>
#include <string>

TEST_CASE("character constructors") {
  // Fully paramaterized values
  std::string name = "Tharrack";
  int hit_points = 72;
  std::map<std::string, float> attr = {{"STR", 13.5},  {"INT", 8.1},
                                       {"WIS", 6.0},   {"DEX", 12.0},
                                       {"CON", 18.99}, {"CHA", 3.0}};
  std::map<std::string, float> skills = {
      {"athletics", 2.77}, {"horseriding", 1.125}, {"trapping", 2.231}};
  std::map<std::string, float> combat = {{"sword", 3.91},
                                         {"glaive-guisarme", 4.0}};
  std::map<std::string, float> s_languages = {{"common", 1.5},
                                              {"beastfolk", 1.0}};
  std::map<std::string, float> l_languages = {{"old oeridian", 1.5}};
  std::map<std::string, float> religions = {{"death goddess", 1.0},
                                            {"animism", 1.0}};
  std::map<std::string, float> histories = {{"adri forest", 0.67}};
  std::map<std::string, float> cultures = {{"adri barbarians", 3.0},
                                           {"flinty hills", 1.0}};
  std::map<std::string, float> supernatural = {};
  std::map<std::string, float> elder_races = {{"mi-go", 1.0}};

  // Useful default variables
  std::map<std::string, float> def_attr = {{"STR", 3.0}, {"INT", 3.0},
                                           {"WIS", 3.0}, {"DEX", 3.0},
                                           {"CON", 3.0}, {"CHA", 3.0}};
  std::map<std::string, float> empty = {};
  std::map<std::string, float> def_slang = {{"northern", 1.0}};

  // Characters
  Character c_def;
  Character c_name("Balthazar");
  Character c_param(name, hit_points, attr, skills, combat, s_languages,
                    l_languages, religions, histories, cultures, supernatural,
                    elder_races);
  Character c_copy(c_param);

  SECTION("default constructor") {
    REQUIRE(c_def.name == "Nameless One");
    REQUIRE(c_def.hit_points == 1);
    REQUIRE(c_def.attr == def_attr);
    REQUIRE(c_def.skills == empty);
    REQUIRE(c_def.combat == empty);
    REQUIRE(c_def.l_languages == empty);
    REQUIRE(c_def.religions == empty);
    REQUIRE(c_def.histories == empty);
    REQUIRE(c_def.supernatural == empty);
    REQUIRE(c_def.elder_races == empty);
    REQUIRE(c_def.s_languages == def_slang);
  }
  SECTION("name constructor") {
    REQUIRE(c_name.name == "Balthazar");
    REQUIRE(c_name.hit_points == 1);
    REQUIRE(c_name.attr == def_attr);
    REQUIRE(c_name.skills == empty);
    REQUIRE(c_name.combat == empty);
    REQUIRE(c_name.l_languages == empty);
    REQUIRE(c_name.religions == empty);
    REQUIRE(c_name.histories == empty);
    REQUIRE(c_name.supernatural == empty);
    REQUIRE(c_name.elder_races == empty);
    REQUIRE(c_name.s_languages == def_slang);
  }
  SECTION("full parameterized constructor") {
    REQUIRE(c_param.name == name);
    REQUIRE(c_param.hit_points == hit_points);
    REQUIRE(c_param.attr == attr);
    REQUIRE(c_param.skills == skills);
    REQUIRE(c_param.combat == combat);
    REQUIRE(c_param.s_languages == s_languages);
    REQUIRE(c_param.l_languages == l_languages);
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
    REQUIRE(c_param.s_languages == c_copy.s_languages);
    REQUIRE(c_param.l_languages == c_copy.l_languages);
    REQUIRE(c_param.religions == c_copy.religions);
    REQUIRE(c_param.histories == c_copy.histories);
    REQUIRE(c_param.supernatural == c_copy.supernatural);
    REQUIRE(c_param.elder_races == c_copy.elder_races);
  }
}
