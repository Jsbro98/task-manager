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

  // test scope 3
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

  // test scope 4
  {
    // uses the previously created tasks.txt file for testing purposes
    TaskManager tm{read_tasks("tasks.txt")};

    tm.create_task(265, "Start the dryer");
    tm.create_task(889, "Walk the dog");

    std::cout << "ID set size: " << tm.get_all_ids().size() << '\n';

    for (int id : tm.get_all_ids()) {
      std::cout << id << '\n';
    }

    std::cout << std::endl;
  }
}