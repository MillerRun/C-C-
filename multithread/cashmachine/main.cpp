#include "processes.h"

using namespace std;

int main()
{
	mailbox mb;
	thread tA(A);
	thread tB(B);
	thread tC(C);

	tA.join();
	tB.join();
	tC.join();

	return 0;
}