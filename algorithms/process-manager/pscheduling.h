#pragma once
#include <iostream>
#include <vector>

#define QUANTUM_RR 8
#define QUANTUM_SJF 2

using std::vector;
using std::size_t;
using std::cout;
using std::endl;

struct process
{
	// Вхідні дані
	unsigned id;
	unsigned arrival_time;
	unsigned burst_time;

	// Дані для заповнення
	unsigned wait_time;
	unsigned turn_around_time;
	unsigned start_time;
	unsigned finish_time;
	
	process(unsigned _id = 0, unsigned _at = 0, unsigned _bt = 0);
};

void rr(process& p, unsigned& tmp_bt, unsigned& time);	// Процедура робить "крок" обчислень процесу алгоритмом RR
void sjf(process& p, unsigned& tmp_bt, unsigned& time);	// Процедура виконує повністю фоновий процес, оскільки він не переривається

void find_waiting_time(vector<process>& pArray);		// Процедура розподіляє процеси по чергам доки вони всі не будуть виконані
void find_turn_around_time(vector<process>& pArray);	// Процедура пошуку Turn-Around-Time
void print_results(const vector<process>& pAraray);
double average_wt(const vector<process>& pArray);
double average_tat(const vector<process>& pArray);
