#include "file-handle.h"
#include <fstream>
#include <string>

void create_file(const std::string& file_name) {
  std::ofstream file(file_name);

  // write UTF-8 BOM for notepad compatability
	file << "\xEF\xBB\xBF";
}

void write_tasks(const std::vector<Task>& tasks, const std::string& file_name) {
  std::ofstream file(file_name);

  for (size_t i = 0; i < tasks.size(); ++i) {
    const Task& task = tasks[i];

    file << task.get_id() << '\n';
    file << task.get_description() << '\n';
    file << (task.is_completed() ? "1" : "0") << '\n';

    if (i != tasks.size() - 1) {
      file << '\n';  // only inserts a blank line between tasks
    }
  }
}



std::vector<Task> read_tasks(const std::string& file_name) {
   /*
   * tasks.txt is formatted as such:
   *
   * id
   * description
   * completed
   *
   * id
   * description
   * completed
   *
   * etc...
   */

  std::vector<Task> tasks;
  std::ifstream file(file_name);

  std::string line{};
  while (true) {
    int id{};
    std::string desc{};
    bool completed{};

    if (!std::getline(file, line)) break;
    if (line.empty()) continue;  // skip accidental blanks
    id = std::stoi(line);

    if (!std::getline(file, line)) break;
    desc = line;

    if (!std::getline(file, line)) break;
    completed = (line == "1");

    Task task(id, desc, completed);

    tasks.push_back(task);
  }

  return tasks;
}