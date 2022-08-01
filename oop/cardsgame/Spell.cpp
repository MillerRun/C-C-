#pragma once
#include "Class.h"

using namespace hmv;

Spell::Spell() : Card(), impact(0)
{
	if (debug_mode == true)
		std::cout << this << "\t����������� �� ��������� Spell" << std::endl;
}

Spell::Spell(std::string _name, short _cost, short _impact) : Card(_name, _cost), impact(_impact)
{
	if (debug_mode == true)
		std::cout << this << "\t����������� � ����������� Spell" << std::endl;
}

Spell::Spell(const Spell& other) : Card(other.name, other.cost), impact(other.impact)
{
	if (debug_mode == true)
		std::cout << this << "\t����������� ����������� Spell" << std::endl;
}

Spell::~Spell()
{
	if (debug_mode == true)
		std::cout << this << "\t���������� Spell" << std::endl;
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

//����� ����������. ���� ���������� ��������� ���������� ��������, �� �������� ����� "����" � ���������� ��������� �����, ���� �����������, �� ����� "�������"
void Spell::PrintInfo()
{
	std::cout << "��������: " << this->name << "\nID ����������: " << this->id << "\n����: " << this->cost << std::endl;
	(this->impact > 0) ? (std::cout << "�������: " << this->impact) : (std::cout << "����: " << -this->impact);
	std::cout << std::endl << std::endl;
}