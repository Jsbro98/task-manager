#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "task-manager.h"
#include "io-handle.h"

class Controller {
  TaskManager manager;

  explicit Controller(TaskManager& man);

  public:
    void dispatch(Command cmd);
};

#endif  // CONTROLLER_H