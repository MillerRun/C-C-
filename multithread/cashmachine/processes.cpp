#include "processes.h"

mailbox mb;

extern bool is_rest;

void A()
{
	unsigned cost[] = { 1, 28, 37, 50, 77, 91};
	if (cost[0])
	{
		srand(time(NULL));
		do
		{
			size_t user_input = (long long)(rand() % 5 + 1);
			mb.put1(100 - cost[user_input]);
			std::this_thread::sleep_for(std::chrono::milliseconds(2));
		} while (is_rest == true);
		cout << std::this_thread::get_id() << "\tNo more rest to give..." << endl;
	}
}

void B()
{
	unsigned cost[] = { 1, 28, 37, 50, 77, 91 };
	if (cost[0])
	{
		srand(time(NULL));
		do
		{
			size_t user_input = rand() % 5 + 1;
			mb.put2(100 - cost[user_input]);
			std::this_thread::sleep_for(std::chrono::milliseconds(2));
		} while (is_rest == true);
		cout << std::this_thread::get_id() << "\tNo more rest to give..." << endl;
	}
}

void C()
{
	coin_count c(50, 25, 20, 15, 10, 5);
	is_rest = true;

	do
	{
		unsigned rest;
		mb.get(rest);
		is_rest = is_possible_to_give_rest(rest, c);
	} while (is_rest == true);
	
	
	
}

//size_t n = 0;

bool is_possible_to_give_rest(unsigned rest, coin_count& c)
{	
	coin_count tmp = c;
	while (rest != 0)
	{
		if (rest >= 50 && tmp.c50 != 0) { rest -= 50; tmp.c50--; }
		else if (rest >= 25 && tmp.c25 != 0) { rest -= 25; tmp.c25--; }
		else if (rest >= 10 && tmp.c10 != 0) { rest -= 10; tmp.c10--; }
		else if (rest >= 5 && tmp.c5 != 0) { rest -= 5; tmp.c5--; }
		else if (rest >= 2 && tmp.c2 != 0) { rest -= 2; tmp.c2--; }
		else if (rest >= 1 && tmp.c1 != 0) { rest -= 1; tmp.c1--; }
		else
			return false;
	}
	c = tmp;
	return true;


	/*if (n++ < 100)
		return true;
	return false;*/
}