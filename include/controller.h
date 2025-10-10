#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "task-manager.h"
#include "io-handle.h"
#include <string>

TaskManager make_task_manager(const std::string& file_name);

class Controller {
  static TaskManager manager;

  public:
    static void dispatch(Command cmd);
    static const std::vector<Task>& get_task_list();
};

#endif  // CONTROLLER_H