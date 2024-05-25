#include "catch.hpp"
#include "character.h"
#include <iostream>
#include <string>
#include <map>

TEST_CASE("Example test case 2") {
    std::string name = "Tharrack";
    int hit_points = 33;
    std::map<std::string, float> attr = {{"STR", 13.0},{"INT", 8.0},
        {"WIS", 6.0}, {"DEX", 12.0}, {"CON", 19.0}, {"CHA", 3.0}};
    std::map<std::string, float> skills = {{"athletics", 2.0},
        {"horseriding", 1.0}, {"trapping", 2.0}};
    std::map<std::string, float> combat = {{"sword", 3.0},
        {"glaive-guisarme", 4.0}};
    std::map<std::string, float> languages = {{"northern", 1.5},
        {"goblin", 1.0}, {"central", -0.5}};
    std::map<std::string, float> religions = {{"death goddess", 1.0},
        {"animism", 1.0}};
    std::map<std::string, float> histories = {{"almes woodlands", 0.5}};
    std::map<std::string, float> cultures = {{"almes barbarians", 3.0},
        {"great kingdom", 1.0}};
    std::map<std::string, float> supernatural = {};
    std::map<std::string, float> elder_races = {{"mi-go", 1.0}};

    Character c_default;
//    Character c_name("Balthazar");
//    Character c_param(name, hit_points, attr, skills, combat, languages,
//        religions, histories, cultures, supernatural, elder_races);
//    Character c_copy(c_param);
    REQUIRE(1 + 2 == 3);
}
