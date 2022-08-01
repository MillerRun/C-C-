#pragma once
#include <iostream>
#include <string>
#include <list>

extern bool debug_mode;

namespace hmv
{
	class Card		// Абстрактный клас карточки, имеет только имя, стоимость и id
	{
	public:
		typedef unsigned long long clong;

		Card();
		Card(std::string _name, short _cost);
		Card(const Card& other);
		~Card();

		void SetName(std::string _name);
		void SetCost(short _cost);

		std::string GetName();
		short GetCost();
		clong GetId();

		Card& operator= (const Card& other);
		virtual void PrintInfo() = 0;

		static clong id_counter; // Переменная для id генератора

	protected:
		std::string name;
		short cost;
		clong id;
	};

	class Unit : public Card	// Класс Unit - тоже карточка, но с полями Атака и Здоровье
	{
	public:
		Unit();
		Unit(std::string _name, short _cost, short _DMG, short _HP);
		Unit(const Unit& other);
		~Unit();

		Unit& operator= (const Unit& other);

		void SetDMG(short _DMG);
		void SetHP(short _HP);

		short GetDMG();
		short GetHP();

		void PrintInfo() override;
		void Hit(Unit* enemy);

	protected:
		short DMG;
		short HP;
	};

	class Spell : public Card	// Класс Spell - карточка с полем impact, определяющим как измениться Здоровье, если применить это Заклинание
	{
	public:
		Spell();
		Spell(std::string _name, short _cost, short _impact);
		Spell(const Spell& other);
		~Spell();

		Spell& operator= (const Spell& other);

		void SetImpact(short _impact);
		short GetImpact();
		void SearchStatus();
		void PrintInfo() override;

	protected:		// ДОБАВИТЬ разделение на атакующие заклинания и лечащие
		short impact;
	};
	
	class Deck
	{
	public:
		Deck();
		Deck(Card* _cards_list[], size_t _size);
		Deck(const Deck& other);
		~Deck();

		Deck& operator= (const Deck& other);

		unsigned GetSize();
		Card* GetCard(const unsigned num);		// Возвращает указатель на карточку и вызывает RemoveCard()
		void RemoveCard(const unsigned num);	// Удаляет карточку из списка deck
		void PutCard(Card* card);				// Замешивает карточку в deck
		void PrintDeck();
		//void MixDeck();						ПЕРЕМЕШИВАЕТ колоду

	private:
		unsigned size;
		std::list<Card*>::iterator it;
		std::list<Card*> deck;

		void SetIterator(const unsigned num);	// Устанавливает итератор на нужный элемент, альтернатива оператору []
	};



	class Hero	// ДОБАВИТЬ имя, расы, оружие, силу героя
	{
	public:
		Hero();
	private:
		Deck basic;
		Deck hand;
		short HP;
	};
}