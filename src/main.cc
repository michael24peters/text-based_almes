#include <iostream>
#include <map>
#include <string>
#include <vector>

#include <chrono> // std::chrono::seconds
#include <thread> // std::this_thread::sleep_for

#include "character.h"

std::vector<std::string> store_in_chunks(const std::string &str,
                                         std::size_t chunkSize = 80) {
  std::size_t length = str.length();
  std::size_t start = 0;
  std::vector<std::string> chunks = {};

  while (start < length) {
    std::size_t end = start + chunkSize;

    // If the end index exceeds the length of the string, set it to the length
    // of the string
    if (end >= length) {
      chunks.push_back(str.substr(start) + "\n");
      break;
    }

    // Find the last space within the chunk
    std::size_t lastSpace = str.rfind(' ', end);

    // If there's no space within the chunk, print the whole chunk
    if (lastSpace == std::string::npos || lastSpace <= start) {
      lastSpace = end;
    }

    chunks.push_back(str.substr(start, lastSpace - start) + "\n");
    start = lastSpace + 1;
  }
  return chunks;
}

void msg(std::string line, int pace = 40) {
  std::vector<std::string> chunks = store_in_chunks(line);
  for (int j = 0; j < chunks.size(); j++) {
    std::string s = chunks[j];
    for (int i = 0; i < s.length(); i++) {

      // Print character
      std::cout << s[i] << std::flush;

      // If there is a period mark, wait longer
      // TODO: #19 fix delay at end of dialogue lines for quotation marks
      // TODO: #18 more timing options and control for msg()
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
}

void intro_1() {
  std::vector<std::string> intro = {};

  msg("*A bitter wind whistles in the air. A layer of snow rests on the trees "
      "and mountains filling the background.*\n\n",
      30);

  msg("*In this wintery valley are two groups of people dressed in formal "
      "attire, left and right. One notable exception is a heavily-scarred "
      "warrior on the right, clad in much simpler, functional dress. In the "
      "middle stands a figure with a raven's headdress and antlers. A fire is "
      "slowly kindled on both sides. Then, a man, a woman, and a child step "
      "forward from the left; a man, a woman, and a child step forward from "
      "the right. The children pull the fire on each side, meeting in the "
      "middle.*\n\n",
      30);

  msg("*The man from the left side calls out.*\n\n", 30);

  msg("Left Man: \"Now let there be peace between us, Ásmundar-do!\"\n\n");

  msg("Ásmundar-do: \"Peace... but for how long?\"\n\n");

  std::this_thread::sleep_for(std::chrono::milliseconds(1000));

  msg("Mysterious figure: \"The signs be good, your flames strong. Here gather "
      "two houses prepared to swear to peace.\"\n...\n\"Swear to uphold "
      "peace.\"\n\n");

  msg("Left: \"Krom as my witness, I swear to uphold peace.\"\n\n");

  msg("Ásmundar-do: \"I swear to uphold peace.\"\n\n");

  msg("Mysterious figure: \"Swear by your sons.\"\n\n");

  msg("Left: \"I swear by my second son.\"\n\n");

  msg("Ásmundar-do: \"I swear by my third son.\"\n\n");

  msg("Mysterious figure: \"Swear by the Flame.\"\n\n");

  msg("Left: \"By Krom, I swear by the Flame.\"\n\n");

  msg("Ásmundar-do: \"...I swear by the Flame.\"\n\n", 50);

  msg("Mysterious figure: \"Swear by Apep.\"\n\n");

  msg("Left side, in unison, except for the leading three: \"!!\"\n\n");

  msg("*A long silence ensues.*\n\n");

  msg("Mysterious figure: \"Swear by the serpent god, Apep. Do it.\"\n\n");

  msg("Left: \"...");

  std::this_thread::sleep_for(std::chrono::milliseconds(1000));

  msg("I...I swear by Apep.\"\n\n", 60);

  msg("Ásmundar-do: \"I swear by Apep, Bringer of Life.\"\n\n");

  msg("Mysterious figure: \"Then it is done!\"\n\n");

  msg("*The right party speaks with their son. The left side does not.*\n\n");

  msg("*The mysterious figure looks at the two children. A bass of black, "
      "yellow serpent eyes, distortion on the world. The camera zooms to the "
      "leftmost child, who now walks to the right, then stops, looks back, "
      "their family's face obscured by the snow.*\n\n");

  msg("Mysterious figure: *G o, c h i l d.*\n\n", 80);

  msg("*The leftmost child walks to the right family, and the screen fades to "
      "black as they both leave the scene.*\n\n");
}

int main() {
  // std::string testStr = "This is a long string that we want to print in
  // chunks of 80 characters. "
  //                       "Each chunk will be printed on a new line to ensure
  //                       that the output is " "properly formatted and easy to
  //                       read. Let's see how this works!";
  // std::vector<std::string> chunks = store_in_chunks(testStr);
  // for (std::string s : chunks) msg(s);
  intro_1();

  return 0;
}
