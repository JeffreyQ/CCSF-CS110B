/*
 * creature.cpp
 *
 *  Created on: May 11, 2015
 *      Author: Jeffrey
 */






#include "creature.h"






/****************************************************************/
/* member functions for creature class				*/
/****************************************************************/
creature::creature()
{
	strength = 10;
	hitpoints = 10;
}






creature::creature(int newStrength, int newHitpoints)
{
	strength = newStrength;
	hitpoints = newHitpoints;
}






int creature::getDamage() const
{
	int damage;

	// All creatures inflict damage which is a random number up to their strength
	damage = (rand() % strength) + 1;
	cout << "The " << getSpecies() << " attacks for " << damage << " points!" << endl;

	return damage;
}






int creature::getStrength() const
{
	return strength;
}






void creature::setStrength(int iStrength)
{
	strength = iStrength;
}






int creature::getHitpoints() const
{
	return hitpoints;
}





void creature::setHitpoints(int iHitpoints)
{
	hitpoints = iHitpoints;
}






int battleArena(creature &creature1, creature& creature2)
{
	int battleResult = 0;
	bool battleFinished = false;
	string specie1 = creature1.getSpecies();
	string specie2 = creature2.getSpecies();

	cout << endl << "--------------------------------------------------" << endl;
	cout << "The battle between " << specie1 << " and " << specie2 << " starts ..." << endl << endl;

	while (!battleFinished)
	{
		int c1Result = creature1.getHitpoints() - creature2.getDamage();
		int c2Result = creature2.getHitpoints() - creature1.getDamage();

		cout << "Creature " << specie1 << " remaining hitpoints = " << c1Result << endl;
		cout << "Creature " << specie2 << " remaining hitpoints = " << c2Result << endl;

		if (c1Result <= 0 && c2Result <= 0)
		{
			battleResult = 0;		// this is a tie
			battleFinished = true;
		}
		else if (c1Result > 0 && c2Result <= 0)
		{
			battleResult = 1;		// creature1 wins
			battleFinished = true;
		}
		else if (c1Result <= 0 && c2Result > 0)
		{
			battleResult = -1;		// creature2 wins
			battleFinished = true;
		}

		creature1.setHitpoints(c1Result);
		creature2.setHitpoints(c2Result);
	}

	cout << endl;
	if (battleResult == 0)
		cout << "Game tied." << endl;
	else if (battleResult < 0)
		cout << "Game over. Creature " << specie1 << " wins." << endl;
	else
		cout << "Game over. Creature " << specie2 << " wins." << endl;

	return battleResult;
}












