#pragma once
#include "Class.h"

using namespace hmv;

Spell::Spell() : Card(), impact(0)
{
	if (debug_mode == true)
		std::cout << this << "\tКонструктор по умолчанию Spell" << std::endl;
}

Spell::Spell(std::string _name, short _cost, short _impact) : Card(_name, _cost), impact(_impact)
{
	if (debug_mode == true)
		std::cout << this << "\tКонструктор с параметрами Spell" << std::endl;
}

Spell::Spell(const Spell& other) : Card(other.name, other.cost), impact(other.impact)
{
	if (debug_mode == true)
		std::cout << this << "\tКонструктор копирования Spell" << std::endl;
}

Spell::~Spell()
{
	if (debug_mode == true)
		std::cout << this << "\tДеструктор Spell" << std::endl;
}

Spell& Spell::operator= (const Spell& other)
{
	this->name = other.name;
	this->cost = other.cost;
	this->impact = other.impact;

	return *this;
}

void Spell::SetImpact(short _impact)
{
	this->impact = _impact;
}

short Spell::GetImpact()
{
	return this->impact;
}

//Вывод информации. Если Заклинание уменьшает количество Здоровья, то пишеться слово "Урон" с абсолютным значением урона, если увеличивает, то слово "Лечение"
void Spell::PrintInfo()
{
	std::cout << "Название: " << this->name << "\nID заклинания: " << this->id << "\nМана: " << this->cost << std::endl;
	(this->impact > 0) ? (std::cout << "Лечение: " << this->impact) : (std::cout << "Урон: " << -this->impact);
	std::cout << std::endl << std::endl;
}