#include "Monster.h"
#include <iostream>
using namespace std;

// global functions
bool fight(Monster& monster1, Monster& monster2)
{
	monster1.attack(monster2);
	monster2.attack(monster1);
	return monster1.isKilled() || monster2.isKilled();
}

int attackMany(Monster& m, Monster monsters[], int size)
{
	int count = 0;
	for(int i = 0; i < size; i++)
	{
		m.attack(monsters[i]);
		if(monsters[i].isKilled())
			count++;
	}
	return count;
}

int main()
{
	// === Using Objects ===
	cout << endl << "=== Using Objects ===\n" << endl;
	Monster monster1('a', 30, 100); // strong
	Monster monster2('b', 10, 100); // weak
	monster1.print();
	monster2.print();
	//monster1.read();
	//monster1.print();
	monster1.setHealth(-90);
	cout << monster1.getHealth() << endl;
	monster1.decHealth(5);
	cout << monster1.getHealth() << endl;
	
	bool b = monster1.isKilled();
	if (b)
		cout << "monster 1 is killed" << endl;
	else
		cout << "monster 1 is NOT killed" << endl;

	cout << "\nTesting Attack Function: " << endl;
	monster1.print();
	monster2.print();
	cout << "monster1 attacks monster2:" << endl;
	monster1.attack(monster2);
	monster1.print();
	monster2.print();

	cout << "\nTesting Fight Function: " << endl;
	//monster1.attack(monster2); // member fn
	fight(monster1, monster2); // global fn
	//monster1.fight(monster2); // member fn
	cout << "monster1 and 2 fight:"<< endl;
	monster1.print();
	monster2.print();

	// === Using Pointers ===
	cout << endl << "=== Using Pointers ===\n" << endl;
	Monster * pMonster10 = new Monster; // default constr
	Monster * pMonster20 = new Monster('y', 50, 100);
	//pMonster10->read();
	pMonster10->print();
	pMonster10->attack(*pMonster20);
	fight(*pMonster10, *pMonster20);

	delete pMonster10;
	delete pMonster20;

	Monster * pMonster30 = &monster1;
	pMonster30->setPower(33);
	cout << "power should 33: " << monster1.getPower() << endl;

	// === Using Array of Objects ===
	cout << endl << "=== Using Array of Objects ===\n" << endl;
	Monster m('m', 5, 100);
	Monster arrMonsters[3]; // created by default constructor (array of objects)
	for(int i = 0; i < 3; i++)
		arrMonsters[i].read();
	int count = attackMany(m, arrMonsters, 3);
	for(int i = 0; i < 3; i++)
		arrMonsters[i].print();
	cout << "Number of killed monsters = " << count << endl;
	return 0;
}