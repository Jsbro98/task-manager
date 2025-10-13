#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#include "task.h"
#include <vector>
#include <unordered_set>
#include <random>

class TaskManager {
	std::vector<Task> tasks;
	std::unordered_set<int> current_ids;

	private:
		static std::minstd_rand eng;
		static std::uniform_int_distribution<int> dist;
		int get_unique_id();

	public:
		TaskManager() = default;
		TaskManager(std::vector<Task>&& task_list);
		TaskManager(const std::vector<Task>& task_list);

		Task* get_task(int id);
		void list_tasks();
		bool mark_task(int id);
		Task* create_task(const std::string& desc);
		Task* create_task(const std::string& desc, bool completed);
		bool remove_task(int id);
		const std::unordered_set<int>& get_all_ids() const;
		void update_ids();
		const std::vector<Task>& get_all_tasks() const;
};

#endif  // TASK_MANAGER_H
