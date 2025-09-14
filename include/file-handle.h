#ifndef FILE_HANDLE_H
#define FILE_HANDLE_H

#include "task.h"
#include <vector>
#include <fstream>
#include <string>

void create_file(const std::string& file_name);
void write_tasks(const std::vector<Task>& tasks, const std::string& file_name);
std::vector<Task> read_tasks(const std::string& file_name);

#endif  // FILE_HANDLE_H