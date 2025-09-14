#include "task-manager.h"
#include <algorithm>
#include <iostream>

void TaskManager::create_task(int id, const std::string& desc) {
  tasks.push_back(Task(id, desc));
}

void TaskManager::create_task(int id, const std::string& desc, bool completed) {
  tasks.push_back(Task(id, desc, completed));
}

Task* TaskManager::get_task(int id) {
  // look through our vector and compare each Task id to the param id
  // return ref to the Task object if found
  auto it =
      std::find_if(tasks.begin(), tasks.end(),
                   [id](const Task& curr) { return curr.get_id() == id; });

  // did you find a match?
  if (it != tasks.end()) {
    // turn the refrence into a pointer of type Task
    return &(*it);
  }

  return nullptr;
}

void TaskManager::list_tasks() {
  for (auto& task : tasks) {
    std::cout << task.get_id() << ", " << task.get_description() << ", "
              << std::boolalpha << task.is_completed() << '\n';
  }
}

bool TaskManager::mark_task(int id) {
  Task* task = get_task(id);

  if (task != nullptr) {
    task->mark_completed();
    return true;
  }

  return false;
}