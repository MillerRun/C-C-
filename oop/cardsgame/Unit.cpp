#pragma once
#include "Class.h"

using namespace hmv;

Unit::Unit() : Card(), DMG(0), HP(0)
{
	if (debug_mode == true)
		std::cout << this << "\tКонструктор по умолчанию Unit" << std::endl;
}

Unit::Unit(std::string _name, short _cost, short _DMG = 0, short _HP = 0) : Card(_name, _cost), DMG(_DMG), HP(_HP)
{
	if (debug_mode == true)
		std::cout << this << "\tКонструктор с параметрами Unit" << std::endl;
}

Unit::Unit(const Unit& other) : Card(other.name, other.cost), DMG(other.DMG), HP(other.HP)
{
	if (debug_mode == true)
		std::cout << this << "\tКонструктор копирования Unit" << std::endl;
}

Unit::~Unit()
{
	if (debug_mode == true)
		std::cout << this << "\tДестурктор Unit" << std::endl;
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

void Unit::PrintInfo() //ИЗМЕНИТЬ, некрасиво
{
	std::cout << "Имя:\t" << this->name << "\nID существа:\t" << this->id << "\nМана:\t" << this->cost << "\nАтака:\t" << this->DMG << "\nХП:\t" << this->HP << std::endl << std::endl;
}

//Метод Hit имитирует драку карточек. Они "ударяются" друг о друга, а значения поля Здоровье каждого уменьшается на значение поля Атака их противника
void Unit::Hit(Unit* enemy = nullptr)
{
	if (enemy == nullptr)
		return;

	enemy->SetHP(enemy->GetHP() - this->DMG);
	this->HP -= enemy->GetDMG();
}
