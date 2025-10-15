#include "file-handle.h"
#include "controller.h"
#include <iostream>
#include <string>
#include <filesystem>

TaskManager make_task_manager(const std::string& file_name) {
	const std::string path = "./" + file_name;
	const bool file_exist = std::filesystem::exists(path);

	if (!file_exist) create_file(file_name);

	return TaskManager{read_tasks(file_name)};
}

static int get_id_from_user() { 
	int task_id{1};

	while (true) {
		std::cin >> task_id;

		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input, please enter a number: ";
			continue;
		}

		break;
	}

	// discard leftover input
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return task_id;
}



// create a TaskManager instance for the entire Controller class
// the file is always named "tasks.txt"
TaskManager Controller::manager{make_task_manager("tasks.txt")};


void Controller::dispatch(Command cmd) {
	switch (cmd) {
		case Command::Add: {
			std::cout << "Please provide a description of the task\n";
			std::cout << "input 'exit' to cancel\n";

			std::string desc{};
			std::getline(std::cin, desc);

			if (desc == "exit") return;

			Task* task = manager.create_task(desc);
			std::cout << "Task created with ID: " << task->get_id()
								<< ", and with the description: " << desc << '\n' << std::endl;
			break;
		}
		case Command::Mark: {
			std::cout << "Please provide the id of the task to be marked complete\n";
			std::cout << "input '0' to cancel\n";
			manager.list_tasks();
			int task_id{1};

			while (true) {
				task_id = get_id_from_user();
				if (task_id == 0) return;

				Task* task{manager.get_task(task_id)};

				if (!task) {
					std::cout << "Incorrect ID, please try again\n";
					continue;
				}

				if (task->is_completed()) {
					std::cout << "Task is already complete, try again\n";
					continue;
				}

				task->mark_completed();
				std::cout << "Task with ID: " << task_id << " was marked completed\n\n";
				break;
			}

			break;
		}
		case Command::Remove: {
			std::cout << "Please enter the task ID you'd like to remove\n";
			std::cout << "input '0' to cancel\n";
			manager.list_tasks();
			bool was_task_removed = false;
			int task_id{};

			do {
				task_id = get_id_from_user();
				if (task_id == 0) return;

				was_task_removed = manager.remove_task(task_id);

				if (was_task_removed) {
					std::cout << "task with ID: " << task_id << " removed successfully\n\n";
				} else {
					std::cout << "task ID not found. Please try again: ";
				}
			} while (!was_task_removed);  // repeat until removal succeeds or cancels

			break;
		}
		case Command::Print:
			manager.list_tasks();
			std::cout << '\n';
			break;
	}
}

const std::vector<Task>& Controller::get_task_list() {
	return Controller::manager.get_all_tasks();
}