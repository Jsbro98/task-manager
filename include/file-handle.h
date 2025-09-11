#ifndef FILE_HANDLE_H
#define FILE_HANDLE_H

#include "task.h"
#include <vector>
#include <fstream>
#include <string>

void create_file();
void write_tasks(const std::vector<Task>& tasks);
std::vector<Task> read_tasks(const std::string& file_name);

#endif  // FILE_HANDLE_H