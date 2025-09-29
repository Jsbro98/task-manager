#ifndef IO_HANDLE_H
#define IO_HANDLE_H

#include <string>

enum class Command { Add, Mark, Remove, Print, Invalid };

void print_commands();
void add_command();
void mark_command();
void remove_command();
void list_tasks_command();
Command select_command();

#endif  // IO_HANDLE_H