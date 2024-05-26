#include "character.h"
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include <chrono> // std::chrono::seconds
#include <thread> // std::this_thread::sleep_for

void print(std::string s) {
  // Traverse the given string S
  for (int i = 0; i < s.length(); i++) {

    std::cout << s[i] << std::flush;

    // Waits for 50 milliseconds
    std::this_thread::sleep_for(std::chrono::milliseconds(75));
  }
}

int main() {
  std::string s = "Hello World!";

  print(s);

  return 0;
}
