#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this
                          // in one cpp file

#include "catch.hpp"
#include "character.h"
#include "npc.h"
#include <iostream>
#include <map>
#include <string>

TEST_CASE("npc constructors") {
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

  std::string type = "half-orc";
  int loc_id = 1;
  std::vector<bool> interactions = {true, true, false};

  // Useful default variables
  std::map<std::string, float> def_attr = {{"STR", 3.0}, {"INT", 3.0},
                                           {"WIS", 3.0}, {"DEX", 3.0},
                                           {"CON", 3.0}, {"CHA", 3.0}};
  std::map<std::string, float> empty = {};
  std::vector<bool> def_interactions = {false};
  std::map<std::string, float> def_lang = {{"northern", 1.0}};

  // NPCs
  NPC npc_def;
  NPC npc_name("Balthazar");
  Character c_param(name, hit_points, attr, skills, combat, languages,
                    religions, histories, cultures, supernatural, elder_races);
  NPC npc_param(c_param, type, loc_id, interactions);
  // TODO: npc_type
  // TODO: npc_copy

  SECTION("default constructor") {
    REQUIRE(npc_def.name == "Nameless One");
    REQUIRE(npc_def.hit_points == 1);
    REQUIRE(npc_def.attr == def_attr);
    REQUIRE(npc_def.skills == empty);
    REQUIRE(npc_def.combat == empty);
    REQUIRE(npc_def.religions == empty);
    REQUIRE(npc_def.histories == empty);
    REQUIRE(npc_def.supernatural == empty);
    REQUIRE(npc_def.elder_races == empty);
    REQUIRE(npc_def.languages == def_lang);
    // type is a private variable
    REQUIRE(npc_def.get_type() == "Unknown");
    REQUIRE(npc_def.loc_id == 0);
    REQUIRE(npc_def.interactions == def_interactions);
  }
  SECTION("name constructor") {
    REQUIRE(npc_name.name == "Balthazar");
    REQUIRE(npc_name.hit_points == 1);
    REQUIRE(npc_name.attr == def_attr);
    REQUIRE(npc_name.skills == empty);
    REQUIRE(npc_name.combat == empty);
    REQUIRE(npc_name.religions == empty);
    REQUIRE(npc_name.histories == empty);
    REQUIRE(npc_name.supernatural == empty);
    REQUIRE(npc_name.elder_races == empty);
    REQUIRE(npc_name.languages == def_lang);
    REQUIRE(npc_name.languages == def_lang);
    // type is a private variable
    REQUIRE(npc_name.get_type() == "Unknown");
    REQUIRE(npc_name.loc_id == 0);
    REQUIRE(npc_name.interactions == def_interactions);
  }
  SECTION("full parameterized constructor") {
    REQUIRE(npc_param.name == c_param.name);
    REQUIRE(npc_param.hit_points == c_param.hit_points);
    REQUIRE(npc_param.attr == c_param.attr);
    REQUIRE(npc_param.skills == c_param.skills);
    REQUIRE(npc_param.combat == c_param.combat);
    REQUIRE(npc_param.languages == c_param.languages);
    REQUIRE(npc_param.religions == c_param.religions);
    REQUIRE(npc_param.histories == c_param.histories);
    REQUIRE(npc_param.supernatural == c_param.supernatural);
    REQUIRE(npc_param.elder_races == c_param.elder_races);
    // type is a private variable
    REQUIRE(npc_param.get_type() == "half-orc");
    REQUIRE(npc_param.loc_id == 1);
    REQUIRE(npc_param.interactions == interactions);
  }
  SECTION("copy constructor") {
    // TODO
  }
}
