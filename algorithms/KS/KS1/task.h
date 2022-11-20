#ifndef TASK_H
#define TASK_H

#include <vector>
#include <set>
#include <memory>

#include <iostream>

#define bebug false

typedef unsigned short operation_t;

struct task_t
{
private:
	std::shared_ptr<std::vector<size_t>> m_avaliable_proc;		// set of avaliable processors
	operation_t m_complexity;
public:
	explicit task_t(const std::vector<size_t>& _m_avaliable_proc, const operation_t _m_complexity = 0);
	operation_t get_complexity() const;
	std::shared_ptr<std::vector<size_t>> get_avaliable_proc() const;
	void set_complexity(operation_t);
};

#endif // TASK_H