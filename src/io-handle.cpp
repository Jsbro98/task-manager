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
            << std::endl;
}

std::string select_command() {
  print_commands();

  while (true) {
    std::string command_selected{};
    std::cout << "Please select a command: ";
    std::cin >> command_selected;

    // make command_selected lowercase
    std::transform(command_selected.begin(), command_selected.end(),
                   command_selected.begin(), ::tolower);

    if (command_selected == "add" || command_selected == "mark" ||
        command_selected == "remove" || command_selected == "print")
      return command_selected;

    std::cout << "Invalid command, try again\n";
  }
}