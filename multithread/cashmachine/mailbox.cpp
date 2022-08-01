#include "mailbox.h"

bool is_rest;

coin_count::coin_count(unsigned _c1, unsigned _c2, unsigned _c5, unsigned _c10, unsigned _c25, unsigned _c50) : c1(_c1), c2(_c2), c5(_c5), c10(_c10), c25(_c25), c50(_c50)
{

}

coin_count& coin_count::operator-(const coin_count& other)
{
	this->c1 -= other.c1;
	this->c2 -= other.c2;
	this->c5 -= other.c5;
	this->c10 -= other.c10;
	this->c25 -= other.c25;
	this->c50 -= other.c50;
	return *this;
}

mailbox::mailbox(unsigned _id) : id(_id)
{

}

void mailbox::put1(const unsigned& msg)
{

	unique_lock<mutex> ul(mail_mutex);
	cout << std::this_thread::get_id() << "\t!A";
	if (is_rest)
	{
		not_full.wait(ul, [&]() { return messages.size() < MBOX_SIZE; });
		cout << " a";

		messages.push(msg);
		//ul.unlock();
		not_empty.notify_one();

		cout << " A" << endl;
	}
}
	

void mailbox::put2(const unsigned& msg)
{

	unique_lock<mutex> ul(mail_mutex);
	cout << std::this_thread::get_id() << "\t!B";
	if (is_rest)
	{
		not_full.wait(ul, [&]() { return messages.size() < MBOX_SIZE; });
		cout << " b";

		messages.push(msg);
		//ul.unlock();
		not_empty.notify_one();

		cout << " B" << endl;
	}
}

void mailbox::get(unsigned& msg)
{

	unique_lock<mutex> ul(mail_mutex);
	cout << std::this_thread::get_id() << "\t!C";
	if (is_rest)
	{
		not_empty.wait(ul, [&]() { return messages.size() > 0; });
		cout << " c";

		msg = messages.front();
		messages.pop();
		//ul.unlock();
		not_full.notify_one();

		cout << " C" << endl;
	}
	
}