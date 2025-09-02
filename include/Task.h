#include <string>

#ifndef TASK_HPP
#define TASK_HPP

class Task {
  int id;
  std::string description;
  bool completed;

  public:
    Task(int id, const std::string& desc);

    int get_id() const;
    const std::string& get_description() const;
    bool is_completed() const;
    void mark_completed();
};

#endif  // TASK_HPP
