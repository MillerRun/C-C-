#include "pscheduling.h"

process::process(unsigned _id, unsigned _at, unsigned _bt) : id(_id), arrival_time(_at), burst_time(_bt)
{
	wait_time = 0;
	turn_around_time = 0;
	start_time = 0;
	finish_time = 0;
}

void find_waiting_time(vector<process>& pArray)
{
	vector<unsigned> tmp_bt;	// ������-���� burst_time �������, �� ���������� �������� ��� ��� ��������� ������ �������
	for (const auto& el : pArray)
		tmp_bt.push_back(el.burst_time);

	unsigned time = 0;	// ������� ��������� ���� ��������� � 0
	while (1)
	{
		bool all_processes_done = true;
		for (size_t i = 0; i < pArray.size(); i++)
		{
			if ((tmp_bt[i] > 0))
			{
				all_processes_done = false;
				if (pArray[i].arrival_time <= time)		// ���������� ���������� ���� ���� ������ ������ � �� �� ���������
				{
					if (pArray[i].burst_time <= QUANTUM_SJF)	// ���� ������ ���������� �������, �� �� ������������ �� �������
					{
						size_t shortest_i = i;					// ����� ������������ (� ��� ����������) ������� ��� ��������� SJF
						for (size_t j = 0; j < pArray.size(); j++)
							if ((pArray[j].arrival_time <= time) && (tmp_bt[j] < tmp_bt[shortest_i]) && (tmp_bt[j] > 0))
								shortest_i = j;
						sjf(pArray[shortest_i], tmp_bt[shortest_i], time);
					}
					else
						rr(pArray[i], tmp_bt[i], time);			// ���� � ������ ���������� �����, �� �� ������������ ���������� RR
				}
			}
		}
		time++;
		if (all_processes_done) break;
	}
}

void rr(process& p, unsigned& tmp_bt, unsigned& time)
{
	if (p.burst_time == tmp_bt)		// ���� ������ �� �� �����������, �� ����� ������� ���� ������
		p.start_time = time;
	if (tmp_bt > QUANTUM_RR)			// ���� ��� ������ ������� ������ �� ����� ����
	{									// �� ��� ����� ���� ���������, � ��� ��������� ������� ����������
		time += QUANTUM_RR;				// �� ��� �� �����. �������� �� �� ���������, ��� ���� ����� �������
		tmp_bt -= QUANTUM_RR;
	}	
	else														// ���� � ��� ��������� ������� ������� �� ����� ������ ������ ����,
	{															// �� ��������� ��� ���������� �� ��� ������ ������� � ������ ��������� ���������,
		time += tmp_bt;											// ������� ��� ���� ������ ���� ���������
		p.finish_time = time;
		p.wait_time = time - p.arrival_time - p.burst_time;
		tmp_bt = 0;	// ��� ������� 0 ��������� ���������
	}
}

void sjf(process& p, unsigned& tmp_bt, unsigned& time)
{
	if (p.burst_time == tmp_bt)		// ���� ������ �� �� �����������, �� ����� ������� ���� ������
		p.start_time = time;
	time += tmp_bt; // ������ ���������� � �� ������������, ���� ��������� ��������� ���� ��� ���� ���������
	tmp_bt = 0;
	p.finish_time = time;
	p.wait_time = time - p.arrival_time - p.burst_time;
}

void find_turn_around_time(vector<process>& pArray)
{
	for (auto& el : pArray)
		el.turn_around_time = el.burst_time + el.wait_time;
}

void print_results(const vector<process>& pAraray)
{
	cout << "AT - Arrival time\nBT - burst time\nWT - waiting time\nTAT - turn around time\nST - start time\nFT - finish time" << endl;
	cout << "\n\t\tAT\tBT\tWT\tTAT\tST\tFT" << endl;
	for (const auto& el : pAraray)
		cout << "Process " << el.id << '\t' << el.arrival_time << '\t' << el.burst_time << '\t' << el.wait_time << '\t' << el.turn_around_time << '\t' << el.start_time << '\t' << el.finish_time << endl;
}

double average_wt(const vector<process>& pArray)
{
	double wt_sum = 0;
	for (const auto& el : pArray)
		wt_sum += (double)el.wait_time;
	return wt_sum / pArray.size();
}

double average_tat(const vector<process>& pArray)
{
	double tat_sum = 0;
	for (const auto& el : pArray)
		tat_sum += (double)el.turn_around_time;
	return tat_sum / pArray.size();
}