#ifndef IO_HANDLE_H
#define IO_HANDLE_H

#include <string>

enum class Command { Add, Mark, Remove, Print };

void print_commands();
Command select_command();

#endif  // IO_HANDLE_H