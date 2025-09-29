#include "io-handle.h"
#include <algorithm>
#include <iostream>
#include <string>

void print_commands() {
  std::cout << "Valid Commands:\n";
  std::cout << "1. add\n"
            << "2. mark\n"
            << "3. remove\n"
            << "4. print\n"
            << "5. help\n"
            << std::endl;
}

Command select_command() {
  print_commands();

  while (true) {
    std::string input{};
    std::cout << "Please select a command: ";
    std::cin >> input;

    // make command_selected lowercase
    std::transform(input.begin(), input.end(),
                   input.begin(), ::tolower);

    if (input == "help") {
      print_commands();
      continue;
    }

    // this is ugly, will fix
    if (input == "add") return Command::Add;
    if (input == "mark") return Command::Mark;
    if (input == "remove") return Command::Remove;
    if (input == "print") return Command::Print;

    std::cout << "Invalid command, try again\n";
  }
}