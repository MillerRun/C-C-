#include "Class.h"

using namespace hmv;

Deck::Deck() : size(0)
{
	if (debug_mode == true)
		std::cout << this << "\tконструктор по умолчанию Deck" << std::endl;
}

// Конструктор принимает массив Карточек, достает каждую и размещает её в своём контейнере deck типа list
Deck::Deck(Card* _cards_list[], size_t _size)
{
	std::cout << this << "\tконструктор с параметрами Deck" << std::endl;

	if (_cards_list == nullptr || _size == 0)
	{
		this->size = 0;
		if (debug_mode == true)
			std::cerr << "deck CONSTRUCTOR:\tno cards to add" << std::endl;
	}
	else
	{
		for (size_t i = 0; i < _size; i++)
			this->deck.push_back(_cards_list[i]);
		this->size = _size;
	}
}

Deck::Deck(const Deck& other) : size(other.size), deck(other.deck)
{
	if (debug_mode == true)
		std::cout << this << "\tКонструктор копирования Deck" << std::endl;
}

Deck& Deck::operator= (const Deck& other)
{
	this->size = other.size;
	this->deck = other.deck;

	return *this;
}

Deck::~Deck()
{
	if (debug_mode == true)
		std::cout << this << "\tдеструктор Deck" << std::endl;
	this->deck.clear();
}

unsigned Deck::GetSize()
{
	return this->size;
}

void Deck::SetIterator(const unsigned num)
{
	this->it = deck.begin();
	for (size_t i = 0; i < num && this->it != this->deck.end(); i++)
		this->it++;
}

Card* Deck::GetCard(const unsigned num)
{
	SetIterator(num);
	Card* tmp = *this->it;
	RemoveCard(num);
	return tmp;
}

void Deck::RemoveCard(const unsigned num)
{
	SetIterator(num);
	this->deck.erase(this->it);
	this->size--;
}

void Deck::PutCard(Card* card)
{
	this->deck.push_back(card);
	this->size++;
}

// Вызов метода PrintInfo() у каждого элемента списка deck
void Deck::PrintDeck()
{
	for (this->it = this->deck.begin(); this->it != this->deck.end(); ++this->it)
		(*this->it)->PrintInfo();
}

