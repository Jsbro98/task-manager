#include "task.h"
#include <iostream>

int main() { 
	Task task{265, "Hello, World!"};

	std::cout << task.get_description() << '\n';
  std::cout << task.get_id() << '\n';
  std::cout << std::boolalpha << task.is_completed() << '\n';

  task.mark_completed();

  std::cout << std::boolalpha << task.is_completed() << std::endl;
}