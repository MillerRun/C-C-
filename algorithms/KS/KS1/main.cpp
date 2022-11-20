#include "sim_system.h"

extern bool bedug;

int main(void)
{
	sim_system s;
	s.launch();
	s.print();
	

	return 0;
}