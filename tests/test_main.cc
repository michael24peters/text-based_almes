#include <iostream>
#include <map>
#include <string>
#include <vector>

#include <chrono> // std::chrono::seconds
#include <thread> // std::this_thread::sleep_for

#include "character.h"

void msg(std::string s) {
  // Traverse the given string S
  for (int i = 0; i < s.length(); i++) {

    std::cout << s[i] << std::flush;

    // Waits for 50 milliseconds
    std::this_thread::sleep_for(std::chrono::milliseconds(40));
  }
}

#include "catch.hpp"
#include "character.h"
#include <iostream>
#include <map>
#include <string>

TEST_CASE("test main") {
  msg("Let's take a look at Tharrack's character sheet:");

  std::string name = "Tharrack";
  int hit_points = 72;
  std::map<std::string, float> attr = {{"STR", 13.5},  {"INT", 8.1},
                                       {"WIS", 6.0},   {"DEX", 12.0},
                                       {"CON", 18.99}, {"CHA", 3.0}};
  std::map<std::string, float> skills = {
      {"athletics", 2.0}, {"horseriding", 1.0}, {"trapping", 2.0}};
  std::map<std::string, float> combat = {{"sword", 3.0},
                                         {"glaive-guisarme", 4.0}};
  std::map<std::string, float> s_languages = {{"common", 1.5},
                                              {"beastfolk", 1.0}};
  std::map<std::string, float> l_languages = {{"old oeridian", 1.5}};
  std::map<std::string, float> religions = {{"death goddess", 1.0},
                                            {"animism", 1.0}};
  std::map<std::string, float> histories = {{"adri forest", 0.5}};
  std::map<std::string, float> cultures = {{"adri barbarians", 3.0},
                                           {"flinty hills", 1.0}};
  std::map<std::string, float> supernatural = {};
  std::map<std::string, float> elder_races = {{"mi-go", 1.0}};

  Character tharrack(name, hit_points, attr, skills, combat, s_languages,
                     l_languages, religions, histories, cultures, supernatural,
                     elder_races);

  tharrack.print();
}