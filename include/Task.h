#ifndef TASK_H
#define TASK_H

#include <string>

class Task {
	int id;
	std::string description;
	bool completed;

	public:
		Task(int id, const std::string& desc);
		Task(int id, const std::string& desc, bool completed);

		int get_id() const;
		const std::string& get_description() const;
		bool is_completed() const;
		void mark_completed();
};

#endif  // TASK_H
