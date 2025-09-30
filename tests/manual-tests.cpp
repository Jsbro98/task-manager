#include "task.h"
#include "task-manager.h"
#include "file-handle.h"
#include "manual-tests.h"
#include <iostream>

void execute_tests() {
  // test 1 scope
  {
    Task task{265, "Hello, World!"};

    std::cout << task.get_description() << '\n';
    std::cout << task.get_id() << '\n';
    std::cout << std::boolalpha << task.is_completed() << '\n';

    task.mark_completed();

    std::cout << std::boolalpha << task.is_completed() << std::endl;
  }

  // test scope 2
  {
    create_file("tasks.txt");

    Task task1{6, "Check jira tickets"};
    Task task2{7, "Look through logs", true};
    Task task3{8, "Delete old cache"};

    std::vector<Task> tasks{task1, task2, task3};

    write_tasks(tasks, "tasks.txt");

    tasks.clear();
    tasks = read_tasks("tasks.txt");

    for (const Task& task : tasks) {
      std::cout << "ID: " << task.get_id() << '\n';
      std::cout << "Desc: " << task.get_description() << '\n';
      std::cout << std::boolalpha << "Completed: " << task.is_completed()
                << '\n';
      std::cout << '\n';
    }
  }

  // test scope 3
  {
    // uses the previously created tasks.txt file for testing purposes
    TaskManager tm{read_tasks("tasks.txt")};

    tm.create_task("Start the dryer");
    tm.create_task("Walk the dog");

    std::cout << "ID set size: " << tm.get_all_ids().size() << '\n';

    for (int id : tm.get_all_ids()) {
      std::cout << id << '\n';
    }

    std::cout << std::endl;
  }
}