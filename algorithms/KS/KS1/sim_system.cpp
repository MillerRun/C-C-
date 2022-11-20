#include "sim_system.h"



sim_system::sim_system(const mode_t _m_mode) : m_mode(_m_mode)
{
	this->m_processors = std::make_unique<std::vector<processor_t>>();
	this->m_task_queue = std::make_unique<std::list<task_t>>();

	for (operation_t i = 0; i < this->mc_processor_quantity; i++)
		this->m_processors->push_back(processor_t(i + 1, (i + 1) * 10));
}



bool sim_system::launch()
{
	srand(time(0));
	while(true)		// main system loop
	{
		if (rand() % 100 < TASK_APPEARENCE_PROBABILITY)
			this->generate_task();

		this->distribute_task();
		this->print();
		for (auto& proc : *this->m_processors)
			proc.do_task();

		if (std::cin.get() == 'q')
		{
			system("cls");
			break;
		}
			
		system("cls");
	}

	return true;
}

size_t sim_system::get_proc_index(size_t proc_id)
{
	for (size_t i = 0; i < this->m_processors->size(); i++)
	{
		if (this->m_processors->at(i).get_id() == proc_id)
			return i;
	}
	return 0;
}

bool sim_system::distribute_task()
{
	if (this->m_task_queue->empty())
		return false;

	task_t task = *this->m_task_queue->begin();

	if (task.get_avaliable_proc()->empty())		// deleting non executable task
	{
		this->m_task_queue->pop_front();
		return false;
	}

	size_t proc_queue_index = get_proc_index(task.get_avaliable_proc()->at(0));
	if (task.get_avaliable_proc()->size() == 1)
	{
		if (this->m_processors->at(proc_queue_index).not_full())
		{
			this->m_processors->at(proc_queue_index).push(task);
			this->m_task_queue->pop_front();
		}
		else
			return false;
	}
	else
	{
		operation_t min_proc_loadment = this->m_processors->at(proc_queue_index).get_loadment();
		size_t needed_proc_index = proc_queue_index;

		for (size_t i = 1; i < task.get_avaliable_proc()->size(); i++)
		{
			proc_queue_index = get_proc_index(task.get_avaliable_proc()->at(i));
			if (this->m_processors->at(proc_queue_index).get_loadment() < min_proc_loadment && this->m_processors->at(proc_queue_index).not_full())
			{
				min_proc_loadment = this->m_processors->at(proc_queue_index).get_loadment();
				needed_proc_index = proc_queue_index;
			}
		}
		if (!this->m_processors->at(needed_proc_index).not_full())
			return false;
		this->m_processors->at(needed_proc_index).push(task);
		this->m_task_queue->pop_front();
	}
	return true;
}

void sim_system::generate_task()
{
	this->m_task_queue->push_back(task_t(this->generate_avaliable_processors(), rand() % 200));
}

std::vector<size_t> sim_system::generate_avaliable_processors()
{
	std::vector<size_t> res = std::vector<size_t>();
	for (const auto& el : *this->m_processors)
	{
		if (rand() % this->m_processors->size() == 0)
			res.push_back(el.get_id());
	}
	if (res.empty())
		res.push_back(this->m_processors->at(rand() % this->m_processors->size()).get_id());
	return res;
}

void sim_system::print()
{
	std::cout << "\t\tSystem task distribution\n\n" << "Algorithm:\tFIFO" << std::endl;
	std::cout << "Processors\t\"id(speed)\":";
	for (const auto& proc : *this->m_processors)
		std::cout << '\t' << proc.get_id() << '(' << proc.get_speed() << ')';
	std::cout << "\nMain task queue\t\"complexity(avaliable processors)\":";
	for (const auto& task : *this->m_task_queue)
	{
		std::cout << '\t' << task.get_complexity() << '(';
		for (size_t i = 0; i < task.get_avaliable_proc()->size() - 1; i++)
			std::cout << task.get_avaliable_proc()->at(i) << ", ";
		std::cout << task.get_avaliable_proc()->back() << ')';
	}
		
	std::cout << "\n\n  ID  SPEED    STATUS\tLOADMENT\tTASKS";
	for (const auto& proc : *this->m_processors)
	{
		std::cout << "\n +---+------+-----------+-------+---------------------------------------------------------------" << std::endl;
		std::cout << " | " << proc.get_id() << " |  " << proc.get_speed() << "  |  " << "working";
		std::cout << " \t| " << proc.get_loadment() << "\t| ";
		for (const auto& proc_task : proc.get_tasks_list())
			std::cout << proc_task.get_complexity() << ' ';
		
	}
	std::cout << "\n +---+------+------------+-------+--------------------------------------------------------------" << std::endl;
	std::cout << "Press:\n\tENTER - to continue\n\tq + ENTER - to quit" << std::endl;
}