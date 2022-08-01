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
	// ����� ���
	unsigned id;
	unsigned arrival_time;
	unsigned burst_time;

	// ��� ��� ����������
	unsigned wait_time;
	unsigned turn_around_time;
	unsigned start_time;
	unsigned finish_time;
	
	process(unsigned _id = 0, unsigned _at = 0, unsigned _bt = 0);
};

void rr(process& p, unsigned& tmp_bt, unsigned& time);	// ��������� ������ "����" ��������� ������� ���������� RR
void sjf(process& p, unsigned& tmp_bt, unsigned& time);	// ��������� ������ ������� ������� ������, ������� �� �� ������������

void find_waiting_time(vector<process>& pArray);		// ��������� ��������� ������� �� ������ ���� ���� �� �� ������ �������
void find_turn_around_time(vector<process>& pArray);	// ��������� ������ Turn-Around-Time
void print_results(const vector<process>& pAraray);
double average_wt(const vector<process>& pArray);
double average_tat(const vector<process>& pArray);
