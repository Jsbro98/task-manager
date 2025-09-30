#include "controller.h"
#include <iostream>
#include <string>

static int get_id_from_user() { 
  int task_id{1}; 
  std::cin >> task_id;
  return task_id;
}

Controller::Controller(TaskManager& man) : manager(man) {};

void Controller::dispatch(Command cmd) {
  switch (cmd) {
    case Command::Add: {
      std::cout << "Please provide a description of the task\n";
      std::cout << "input 'exit' to cancel\n";

      std::string desc{};
      // clear the input buffer before user input
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::getline(std::cin, desc);

      if (desc == "exit") return;

      Task* task = manager.create_task(desc);
      std::cout << "Task created with ID: " << task->get_id()
                << ", and with the description: " << desc << std::endl;
      break;
    }
    case Command::Mark: {
      std::cout << "Please provide the id of the task to be marked complete";
      std::cout << "input '0' to cancel";
      int task_id{get_id_from_user()};

      while (true) {
        if (task_id == 0) return;

        Task* task{manager.get_task(task_id)};

        if (task) {
          task->mark_completed();
          std::cout << "Task with ID: " << task_id << " was marked completed\n";
          break;
        } else {
          std::cout << "Incorrect ID, please try again\n";
        }
      }

      break;
    }
    case Command::Remove: {
      std::cout << "Please enter the task ID you'd like to remove\n";
      std::cout << "input '0' to cancel\n";
      int task_id{get_id_from_user()};
      bool was_task_removed = false;

      do {
        if (task_id == 0) return;

        was_task_removed = manager.remove_task(task_id);

        if (was_task_removed) {
          std::cout << "task with ID: " << task_id << " removed successfully\n";
        } else {
          std::cout << "task ID not found. Please try again: ";
        }
      } while (!was_task_removed);  // repeat until removal succeeds or cancels

      break;
    }
    case Command::Print:
      manager.list_tasks();
      break;
  }
}