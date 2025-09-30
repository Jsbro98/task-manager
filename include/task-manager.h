#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#include "task.h"
#include <vector>
#include <unordered_set>

class TaskManager {
  std::vector<Task> tasks;
  std::unordered_set<int> current_ids;

  public:
    TaskManager() = default;
    TaskManager(std::vector<Task>&& task_list);
    TaskManager(const std::vector<Task>& task_list);

    Task* get_task(int id);
    void list_tasks();
    bool mark_task(int id);
    void create_task(int id, const std::string& desc);
    void create_task(int id, const std::string& desc, bool completed);
    bool remove_task(int id);
    const std::unordered_set<int>& get_all_ids() const;
    void update_ids();
};

#endif  // TASK_MANAGER_H
