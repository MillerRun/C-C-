//#include "Class.h"
//#define _DECK_SIZE_ 4
//
//using namespace hmv;
//
//Card::clong Card::id_counter = 0; //Для id генератора (возможно найду место получше для инициализации)
//
bool debug_mode = false;







#include <iostream>

using namespace std;

struct list
{
	struct node
	{
		node* next;
		int data;
	};
	node* head;


	void push_back(int elem)
	{
		node* tmp = new node;
		if (head == nullptr)
		{
			tmp->data = elem;
			tmp->next = nullptr;
			head = tmp;
		}
		else
		{
			while (tmp->next != nullptr)
			{
				tmp = tmp->next;
			}
			tmp->next = new node;
			tmp = tmp->next;
			tmp->data = elem;
			tmp->next = nullptr;
		}
		delete tmp;
		tmp = nullptr;
	}

	void print()
	{
		node* tmp = new node;

		while (tmp != nullptr)
		{
			cout << tmp->data << ' ';
		}
		cout << endl;

		delete tmp;
		tmp = nullptr;
	}
};

int main(int argc, char *argv[])
{
	list A;
	for (int i = 0; i < 5; ++i)
		A.push_back(i);
	A.print();
	
	return 0;
}