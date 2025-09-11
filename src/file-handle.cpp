#include "file-handle.h"
#include <fstream>
#include <string>

void create_file() {
	const std::string file_name = "tasks.txt";
  std::ofstream file(file_name);

  // Write UTF-8 BOM for notepad compatability
	file << "\xEF\xBB\xBF";
	file.close();
}

void write_tasks(const std::vector<Task>& tasks) {
  // implement writing tasks here
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

    Task task(id, desc);

    if (completed) task.mark_completed();

    tasks.push_back(task);

    // Eat trailing blank line (if any)
    std::getline(file, line);
  }
}