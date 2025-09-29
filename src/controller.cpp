#include "controller.h"
#include <iostream>
#include <string>

Controller::Controller(TaskManager& man) : manager(man) {};

/*
* TODOs:
* 
* - deal with duplicate id problem in Command::Add
* 
* - possibly remove Command::Invalid as filtered cases
* occur in select_command
* 
* - Command::Add only reads one word, change to std::getline
*/

void Controller::dispatch(Command cmd) {
  static int id_counter{};

  switch (cmd) {
    case Command::Add: {
      std::cout << "Please provide a description of the task\n";
      std::cout << "input 'exit' to cancel\n";

      std::string desc{};
      std::cin >> desc;

      if (desc == "exit") return;

      manager.create_task(id_counter, desc);
      std::cout << "Task created with ID: " << id_counter
                << ", and with the description: " << desc << std::endl;
      id_counter++;
      break;
    }
    case Command::Mark: {
      std::cout << "Please provide the id of the task to be marked complete";
      std::cout << "input '0' to cancel";
      int task_id{1};

      while (true) {
        std::cin >> task_id;

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
      int task_id{1};
      bool was_task_removed = false;

      do {
        std::cin >> task_id;

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
    case Command::Invalid:
      std::cout << "Command was invalid, please try again";
      break;
  }
}