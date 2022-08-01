#pragma once
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <iostream>
#include <chrono>

#define MBOX_SIZE 2

using std::queue;
using std::mutex;
using std::condition_variable;
using std::unique_lock;
using std::cout;
using std::endl;

extern bool is_rest;

struct coin_count
{
	coin_count(unsigned _c1 = 0, unsigned _c2 = 0, unsigned _c5 = 0, unsigned _c10 = 0, unsigned _c25 = 0, unsigned _c50 = 0);

	unsigned c1;
	unsigned c2;
	unsigned c5;
	unsigned c10;
	unsigned c25;
	unsigned c50;
};

struct mailbox
{
public:
	mailbox(unsigned _id = 0);

	mutex mail_mutex;
	condition_variable not_full;
	condition_variable not_empty;

	void put1(const unsigned&);
	void put2(const unsigned&);
	void get(unsigned&);

private:
	unsigned id;
	queue<unsigned> messages;
};

