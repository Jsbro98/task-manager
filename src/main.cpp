#include "task.h"
#include "task-manager.h"
#include "file-handle.h"
#include "manual-tests.h"
#include "io-handle.h"
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
  std::vector<Task> tasks{read_tasks(file_name)};

  TaskManager tm{read_tasks(file_name)};

  std::cout << "Starting Task-Manager\n\n";
  print_commands();

	return 0;
}