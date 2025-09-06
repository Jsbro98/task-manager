#include "task.h"
#include "task-manager.h"
#include <iostream>

int main() {

  // test 1 scope
  {
    Task task{265, "Hello, World!"};

    std::cout << task.get_description() << '\n';
    std::cout << task.get_id() << '\n';
    std::cout << std::boolalpha << task.is_completed() << '\n';

    task.mark_completed();

    std::cout << std::boolalpha << task.is_completed() << std::endl;
  }

  // test 2 scope
  {
    TaskManager man{};
    man.create_task(451, "What's Up!");
    man.create_task(225, "Hey There!");
    man.create_task(265, "Yep, I'm Here!");

    Task* task{man.get_task(225)};

    if (task != nullptr) {
      std::cout << task->get_description() << std::endl;
    }

    man.list_tasks();

    man.mark_task(451);
    task = man.get_task(451);

    std::cout << std::boolalpha << "Task 451 is marked " << task->is_completed()
              << std::endl;
  }
}