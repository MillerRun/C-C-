#include "processor.h"



processor_t::processor_t(const size_t _m_id, const operation_t _m_speed) : m_id(_m_id), m_speed(_m_speed)
{
	this->m_todo_tasks = std::make_unique<std::list<task_t>>();
}

size_t processor_t::get_id() const
{
	return this->m_id;
}

operation_t processor_t::get_speed() const
{
	return this->m_speed;
}

operation_t processor_t::get_loadment() const
{
	operation_t loadment = 0;
	for (const auto& el : *this->m_todo_tasks)
		loadment += el.get_complexity();
	return loadment;
}

std::list<task_t> processor_t::get_tasks_list() const
{
	return *this->m_todo_tasks;
}

void processor_t::push(const task_t& _task)
{
	this->m_todo_tasks->push_back(_task);
}

bool processor_t::not_full() const
{
	return this->m_todo_tasks->size() < this->mc_max_task_quantity;
}

bool processor_t::do_task()
{
	if (this->m_todo_tasks->empty())
		return false;

	operation_t job_left = this->m_speed;
	do
	{
		auto curr_task = this->m_todo_tasks->begin();	
		if (curr_task->get_complexity() <= job_left)		// if task can be done per one iteration, decreases
		{												// the number of work processor may do per 1 time
			job_left -= curr_task->get_complexity();		// and marks task as completed (sets it to 0 and pop() )
			this->m_todo_tasks->pop_front();
		}
		else
		{
			curr_task->set_complexity(curr_task->get_complexity() - job_left);
			job_left = 0;
		}
	} while (job_left && !this->m_todo_tasks->empty());

	return true;
}