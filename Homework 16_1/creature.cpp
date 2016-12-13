/*
 * creature.cpp
 *
 *  Created on: May 10, 2015
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






string creature::getSpecies() const
{
	return "Creature";
}






int creature::getDamage() const
{
	int damage;

	// All creatures inflict damage which is a random number up to their strength
	damage = (rand() % strength) + 1;

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






