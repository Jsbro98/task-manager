#include "task.h"
#include "task-manager.h"
#include "file-handle.h"
#include "manual-tests.h"
#include "io-handle.h"
#include "controller.h"
#include <iostream>
#include <string>

int main() { 
	std::cout << "Starting Task-Manager\n";
	std::cout << "type 'exit' to exit the program\n\n";

	while (true) {
		Command command{select_command()};

		if (command == Command::Invalid) break;

		Controller::dispatch(command);
	}

	std::string file_name{"tasks.txt"};
	write_tasks(Controller::get_task_list(), file_name);

	return 0;
}