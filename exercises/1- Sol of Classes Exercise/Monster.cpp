#include "Monster.h"
#include <iostream>
using namespace std;

Monster::Monster() // zero-arg constructor
{
	name = '-';
	power = 0;
	health = 0;
	cout << "Default Monster " << name << " is constructed." << endl;
}

Monster::Monster(char n, float p, float h) // constructor with arguments
{
	setName(n); // this is a function call
	setPower(p);
	setHealth(h);
	cout << "Monster " << name << " is constructed." << endl;
}

Monster::~Monster()
{
	cout << "~ Monster " << name << " is destructed." << endl;
}

void Monster::setName(char n) // this is a function defintion
{
	name = n;
}

char Monster::getName()
{
	return name;
}

void Monster::setPower(float p)
{
	if (p >= 0)
		power = p;
}

float Monster::getPower() 
{
	return power;
}

void Monster::setHealth(float h)
{
	if (h >= 0)
		health = h;
}

float Monster::getHealth()
{
	return health;
}

void Monster::print()
{
	cout << "Monster " << name << " (" << power << "," << health << ")" << endl;
}

void Monster::read()
{
	char n;
	float p, h;
	cout << "Enter name, power, and health: " << endl;
	cin >> n >> p >> h;
	setName(n);
	setPower(p);
	setHealth(h);
	// cin >> name >> power >> health; // not best sol
}

void Monster::decHealth(float amount)
{
	health = health - amount;
}

bool Monster::isKilled()
{
	return health <= 0;
}

// Function Call: monster1.Attack(monster2)
void Monster::attack(Monster& monster2)
{
	//cout << health; // health of the current monster (calling obj)
	//cout << this->health; // health of the current monster (calling obj)
	//cout << monster2.getHealth(); // health of the passed monster (func paramter)
	//cout << monster2.health; // health of the passed monster (func paramter)

	if (!this->isKilled()) // or just: if (!isKilled())
		monster2.decHealth(power);
	// monster2.decHealth(this->power); // another way
}

bool Monster::fight(Monster& monster2)
{
	// here: "this" is a pointer to monster1 (pointer to calling object)
	this->attack(monster2);
	monster2.attack(*this); // *ptr
	return this->isKilled() || monster2.isKilled();

	// alternative sol
	//attack(monster2);
	//monster2.attack(*this); // *ptr
	//return isKilled() || monster2.isKilled();
}