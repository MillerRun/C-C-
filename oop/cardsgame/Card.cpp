#include "Class.h"

using namespace hmv;

Card::Card() : name("none"), cost(0), id(id_counter++)		//id ��������� ������������� �������� id ���� � ����� ����������� ��� ����������� ������������
{
	if(debug_mode == true)
		std::cout << this << "\t����������� �� ��������� Card" << std::endl;
}

Card::Card(std::string _name = "none", short _cost = 0) : name(_name), cost(_cost), id(id_counter++)
{
	if (debug_mode == true)
		std::cout << this << "\t����������� � ����������� Card" << std::endl;
}

Card::Card(const Card& other) : name(other.name), cost(other.cost), id(id_counter++)
{
	if (debug_mode == true)
		std::cout << this << "\t����������� ����������� Card" << std::endl;
}

Card::~Card()
{
	this->id_counter--;		//id �������� ���� ���������, ���������� ����� ��� ����� ���� (�������� ����� ������)
	if (debug_mode == true)
		std::cout << this << "\t���������� Card" << std::endl;
}

Card& Card::operator= (const Card& other)
{
	this->name = other.name;
	this->cost = other.cost;
	//this->id = other.id;
	return *this;
}

void Card::SetName(std::string _name)
{
	this->name = _name;
}

void Card::SetCost(short _cost)
{
	this->cost = _cost;
}

std::string Card::GetName()
{
	return this->name;
}

short Card::GetCost()
{
	return this->cost;
}

Card::clong Card::GetId()
{
	return this->id;
}