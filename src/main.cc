#include <iostream>
#include <map>
#include <string>
#include <vector>

#include <chrono> // std::chrono::seconds
#include <thread> // std::this_thread::sleep_for

#include "character.h"

void msg(std::string s, int pace = 40) {
  // Pause before printing message
  std::this_thread::sleep_for(std::chrono::milliseconds(10 * pace));
  // Traverse the given string s
  for (int i = 0; i < s.length(); i++) {

    // Print character
    std::cout << s[i] << std::flush;

    // If there is a period mark, wait longer
    if (s[i] == '.') {
      std::this_thread::sleep_for(std::chrono::milliseconds(10 * pace));
    } else if (s[i] == ';') {
      std::this_thread::sleep_for(std::chrono::milliseconds(7 * pace));
    } else if (s[i] == ',') {
      std::this_thread::sleep_for(std::chrono::milliseconds(3 * pace));
    }

    // Delay
    std::this_thread::sleep_for(std::chrono::milliseconds(pace));
  }
}

void intro() {
  msg("*A bitter wind whistles in the air. A layer of snow rests on the trees"
      "\nand mountains filling the background.*\n\n",
      30);

  msg("*In this wintery valley are two groups of people dressed in formal "
      "attire,"
      "\nleft and right. One notable exception is a heavily-scarred warrior on"
      "\nthe right, clad in much simpler, functional dress. In the middle"
      "\nstands a figure with a raven's headdress and antlers. A fire is slowly"
      "\nkindled on both sides. Then, a man, a woman, and a child step forward"
      "\nfrom the left; a man, a woman, and a child step forward from the "
      "right."
      "\nThe children pull the fire on each side, meeting in the middle.*\n\n",
      30);

  msg("*The man from the left side calls out.*\n\n", 30);

  msg("Left Man: \"Now let there be peace between us, Ásmundar-do!\"\n\n");

  msg("Right Man: \"Peace... but for how long?\"\n\n");

  msg("Mysterious figure: \"The signs be good, your flames strong. Here gather"
      "\ntwo houses prepared to swear to peace.\"\n...\n\"Swear to uphold "
      "peace.\"\n\n");
}

int main() {
  intro();
  return 0;
}
