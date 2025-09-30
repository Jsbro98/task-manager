#include "task-manager.h"
#include <algorithm>
#include <iostream>
#include <vector>

TaskManager::TaskManager(std::vector<Task>&& task_list)
    : tasks(std::move(task_list)) {
  update_ids();
}
TaskManager::TaskManager(const std::vector<Task>& task_list) : tasks(task_list) {
  update_ids();
}

// instantiate random number generation vars
std::minstd_rand TaskManager::eng(std::random_device{}());
std::uniform_int_distribution<int> TaskManager::dist(1, 1'000);

// internal rng helper
int TaskManager::get_unique_id() {
  int new_id{1};

  while (true) {
    new_id = dist(eng);

    if (!current_ids.count(new_id)) break;
  }

  return new_id;
}

void TaskManager::create_task(int id, const std::string& desc) {
  tasks.push_back(Task(id, desc));
  current_ids.insert(id);
}

void TaskManager::create_task(int id, const std::string& desc, bool completed) {
  tasks.push_back(Task(id, desc, completed));
  current_ids.insert(id);
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

bool TaskManager::remove_task(int id) {
  auto it = std::find_if(tasks.begin(), tasks.end(),
                         [id](const Task& t) { return t.get_id() == id; });

  if (it != tasks.end()) {
    current_ids.erase(id);
    tasks.erase(it);
    return true;
  }

  return false;
}

const std::unordered_set<int>& TaskManager::get_all_ids() const {
  return current_ids;
}

void TaskManager::update_ids() {
  current_ids.clear();

  for (Task& task : tasks) {
    current_ids.insert(task.get_id());
  }
}