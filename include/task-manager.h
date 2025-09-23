#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#include "task.h"
#include <vector>

class TaskManager {
  std::vector<Task> tasks;

  public:
    TaskManager(std::vector<Task>& task_list);
    TaskManager();

    Task* get_task(int id);
    void list_tasks();
    bool mark_task(int id);
    void create_task(int id, const std::string& desc);
    void create_task(int id, const std::string& desc, bool completed);
};

#endif  // TASK_MANAGER_H
