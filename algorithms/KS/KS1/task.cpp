#include "task.h"

task_t::task_t(const std::vector<size_t>& _m_avaliable_proc, const operation_t _m_complexity) : m_complexity(_m_complexity)
{
	this->m_avaliable_proc = std::make_shared<std::vector<size_t>>(_m_avaliable_proc);
	//std::cout << "Task created\navaliable processes: ";
	//for (const auto& el : *this->m_avaliable_proc)
	//{
	//	std::cout << el << ' ';
	//}
	//std::cout << "\ncomplexity: " << this->m_complexity << '\n' << std::endl;
}

operation_t task_t::get_complexity() const
{
	return this->m_complexity;
}

std::shared_ptr<std::vector<size_t>> task_t::get_avaliable_proc() const
{
	return this->m_avaliable_proc;
}

void task_t::set_complexity(operation_t val)
{
	this->m_complexity = val;
}