#include "task.h"
#include "task-manager.h"
#include "file-handle.h"
#include "manual-tests.h"
#include "io-handle.h"
#include <iostream>
#include <string>

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
	Command test{select_command()};

	std::cout << "You inputted: " << test << std::endl;

	return 0;
}