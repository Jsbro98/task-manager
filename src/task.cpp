#include "task.h"

Task::Task(int id, const std::string& desc) 
	: id(id), description(desc), completed(false) {}

int Task::get_id() const { return id; }

const std::string& Task::get_description() const { return description; }

bool Task::is_completed() const { return completed; }

void Task::mark_completed() { completed = true; }