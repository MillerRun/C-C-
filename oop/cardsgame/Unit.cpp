#pragma once
#include "Class.h"

using namespace hmv;

Unit::Unit() : Card(), DMG(0), HP(0)
{
	if (debug_mode == true)
		std::cout << this << "\t����������� �� ��������� Unit" << std::endl;
}

Unit::Unit(std::string _name, short _cost, short _DMG = 0, short _HP = 0) : Card(_name, _cost), DMG(_DMG), HP(_HP)
{
	if (debug_mode == true)
		std::cout << this << "\t����������� � ����������� Unit" << std::endl;
}

Unit::Unit(const Unit& other) : Card(other.name, other.cost), DMG(other.DMG), HP(other.HP)
{
	if (debug_mode == true)
		std::cout << this << "\t����������� ����������� Unit" << std::endl;
}

Unit::~Unit()
{
	if (debug_mode == true)
		std::cout << this << "\t���������� Unit" << std::endl;
}

Unit& Unit::operator= (const Unit& other) 
{
	this->name = other.name;
	this->cost = other.cost;
	this->DMG = other.DMG;
	this->HP = other.HP;

	return *this;
}

void Unit::SetDMG(short _DMG)
{
	this->DMG = _DMG;
}

void Unit::SetHP(short _HP)
{
	this->HP = _HP;
}

short Unit::GetDMG()
{
	return this->DMG;
}

short Unit::GetHP()
{
	return this->HP;
}

void Unit::PrintInfo() //��������, ���������
{
	std::cout << "���:\t" << this->name << "\nID ��������:\t" << this->id << "\n����:\t" << this->cost << "\n�����:\t" << this->DMG << "\n��:\t" << this->HP << std::endl << std::endl;
}

//����� Hit ��������� ����� ��������. ��� "���������" ���� � �����, � �������� ���� �������� ������� ����������� �� �������� ���� ����� �� ����������
void Unit::Hit(Unit* enemy = nullptr)
{
	if (enemy == nullptr)
		return;

	enemy->SetHP(enemy->GetHP() - this->DMG);
	this->HP -= enemy->GetDMG();
}
