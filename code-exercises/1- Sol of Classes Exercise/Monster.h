#pragma once

class Monster
{
private:
	char name;
	float power, health;
public:
	// Constructors & Destructor
	Monster(); // zero-arg constructor
	Monster(char n, float p, float h); // constructor with arguments
	~Monster();

	// Setters and Getters
	void setName(char n);
	char getName();
	void setPower(float p);
	float getPower();
	void setHealth(float h);
	float getHealth();
	
	// Print and Read
	void print();
	void read();

	// Other functions
	void decHealth(float amount);
	bool isKilled();
	void attack(Monster& monster2);
	bool fight(Monster& monster2);

	
};

