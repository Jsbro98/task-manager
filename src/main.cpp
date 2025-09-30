#include "task.h"
#include "task-manager.h"
#include "file-handle.h"
#include "manual-tests.h"
#include "io-handle.h"
#include "controller.h"
#include <iostream>
#include <string>
#include <filesystem>

// make Command vars work with std::cout
static std::ostream& operator<<(std::ostream& os, Command com) {
	switch (com) { 
	  case Command::Add:
      os << "add";
      break;
    case Command::Mark:
      os << "mark";
      break;
    case Command::Print:
      os << "print";
      break;
    case Command::Remove:
      os << "remove";
      break;
    default:
      os << "invalid";
      break;
	}

  return os;
}

int main() { 
	const std::string file_name = "tasks.txt";
  const std::string path = "./" + file_name;
  const bool file_exist = std::filesystem::exists(path);

  if (!file_exist) create_file(file_name);

  TaskManager tm{std::move(read_tasks(file_name))};
  Controller::set_task_manager(tm);

  std::cout << "Starting Task-Manager\n";
  std::cout << "type 'exit' to exit the program\n\n";

  while (true) {
    Command command{select_command()};

    if (command == Command::Invalid) break;

    Controller::dispatch(command);
  }

	return 0;
}