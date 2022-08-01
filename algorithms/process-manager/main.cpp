#include "pscheduling.h"

int main()
{
    vector<process> pArray = { {1, 1, 20}, {2, 10, 3}, {3, 9, 16}, {4, 10, 5} };
    find_waiting_time(pArray);
    find_turn_around_time(pArray);
    print_results(pArray);
    cout << "\nAverage waiting time:\t\t" << average_wt(pArray) << endl;
    cout << "Average turn around time:\t" << average_tat(pArray) << endl;
    return 0;
}
