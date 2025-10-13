#include "io-handle.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>

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
	static const std::unordered_map<std::string_view, Command> commands_map {
			{"exit", Command::Invalid},
			{"add", Command::Add},
			{"mark", Command::Mark},
			{"remove", Command::Remove},
			{"print", Command::Print}};

	print_commands();

	while (true) {
		std::string input{};
		std::cout << "Please select a command, type 'exit' to leave program: ";
		std::cin >> input;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		// make command_selected lowercase
		std::transform(input.begin(), input.end(),
									 input.begin(), ::tolower);

		if (input == "help") {
			print_commands();
			continue;
		}

		auto it = commands_map.find(input);
		if (it != commands_map.end()) {
			return it->second;
		}

		std::cout << "Invalid command, try again\n";
	}
}