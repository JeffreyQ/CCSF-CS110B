/*
 * demon.cpp
 *
 *  Created on: May 11, 2015
 *      Author: Jeffrey
 */






#include "demon.h"





/****************************************************************/
/* member functions for demon class				*/
/****************************************************************/
demon::demon()
{
        // do nothing but let the parent class constructor work
}






demon::demon(int newStrength, int newHitpoints) : creature(newStrength, newHitpoints)
{
        // do nothing but let the parent class constructor work
}







int demon::getDamage() const
{
	int damage;

	damage = creature::getDamage();		// call creature::getDamage()
//        cout << " attacks for " << damage << " points!" << endl;
	// Demons can inflict damage of 50 with a 25% chance
	if (rand() % 4 == 0)
	{
		damage = damage + 50;
		cout << "Demonic attack inflicts 50 additional damage points!" << endl;
	}

	return damage;
}






