#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <queue>
#include <list>
#include <memory>

#include "task.h"
//#include <iostream>



struct processor_t
{
private:
	size_t m_id;
	operation_t m_speed;	// speed of execution
	const size_t mc_max_task_quantity = 5;
	std::unique_ptr<std::list<task_t>> m_todo_tasks;
	

public:
	explicit processor_t(const size_t _m_id, const operation_t _m_speed = 0);

	void push(const task_t&);
	bool do_task();		// makes one processing iteration
	bool not_full() const;
	size_t get_id() const;
	operation_t get_loadment() const;
	operation_t get_speed() const;
	std::list<task_t> get_tasks_list() const;
};

#endif // PROCESSOR_H