#ifndef SIM_SYSTEM_H
#define SIM_SYSTEM_H

#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <memory>

#include "processor.h"



#define MAX_TASK_QUANTITY 10
#define TASK_APPEARENCE_PROBABILITY 60 // 60% 

class sim_system
{
private:
	enum mode_t { FIFO, WEAK, STRONG, CUSTOM_STONG };

	mode_t m_mode;
	const size_t mc_processor_quantity = 5;
	std::unique_ptr<std::vector<processor_t>> m_processors;		// processors
	std::unique_ptr<std::list<task_t>> m_task_queue;			// main task queue (before distribution)
	
	bool distribute_task();
	void generate_task();				// generates task with avaliable processors list and complexity
	std::unique_ptr<task_t> get_task();
	size_t get_proc_index(size_t proc_id);
	std::vector<size_t> generate_avaliable_processors();	// generates a set of avaliable processors for a task
public:
	sim_system(const mode_t _m_mode = FIFO);

	bool launch();		// start point
	void print();
};

#endif // SIM_SYSTEM_H