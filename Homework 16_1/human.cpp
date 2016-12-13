/*
 * human.cpp
 *
 *  Created on: May 10, 2015
 *      Author: Jeffrey
 */






#include "human.h"





/****************************************************************/
/* member functions for human class				*/
/****************************************************************/
human::human()
{
	// do nothing but let the parent class constructor work
}






human::human(int newStrength, int newHitpoints) : creature(newStrength, newHitpoints)
{
	// do nothing but let the parent class constructor work
}






string human::getSpecies() const
{
	return "Human";
}






int human::getDamage() const
{
        int damage;

        damage = creature::getDamage();		// call creature::getDamage()
        cout << getSpecies() << " attacks for " << damage << " points!" << endl;

        return damage;
}






