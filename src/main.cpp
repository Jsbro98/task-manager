#include "task.h"
#include "task-manager.h"
#include "file-handle.h"
#include <iostream>

int main() {

  // test 1 scope
  {
    Task task{265, "Hello, World!"};

    std::cout << task.get_description() << '\n';
    std::cout << task.get_id() << '\n';
    std::cout << std::boolalpha << task.is_completed() << '\n';

    task.mark_completed();

    std::cout << std::boolalpha << task.is_completed() << std::endl;
  }

  // test 2 scope
  {
    TaskManager man{};
    man.create_task(451, "What's Up!");
    man.create_task(225, "Hey There!");
    man.create_task(265, "Yep, I'm Here!");

    Task* task{man.get_task(225)};

    if (task != nullptr) {
      std::cout << task->get_description() << std::endl;
    }

    man.list_tasks();

    man.mark_task(451);
    task = man.get_task(451);

    std::cout << std::boolalpha << "Task 451 is marked " << task->is_completed()
              << std::endl;
  }

  // test scope 3
  //{
  //  std::fstream data_file{open_data("data.txt")};

  //  if (data_file.is_open()) {
  //    // writing UTF-8 BOM first to make windows notepad happy
  //    data_file << "\xEF\xBB\xBF" << '\n';
  //    data_file << "Hello, World!";
  //    data_file.flush();
  //    data_file.seekg(0);
  //  }

  //  for (size_t i = 0; i < 3 && data_file.is_open(); ++i) {
  //    std::string line;
  //    std::getline(data_file, line);
  //    std::cout << line << std::endl;
  //  }

  //  data_file.close();
  //}
}