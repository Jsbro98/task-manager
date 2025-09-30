#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "task-manager.h"
#include "io-handle.h"

class Controller {
  static TaskManager manager;

  public:
    static void dispatch(Command cmd);
    static void set_task_manager(TaskManager& man);
};

#endif  // CONTROLLER_H