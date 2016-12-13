/*
 * elf.cpp
 *
 *  Created on: May 10, 2015
 *      Author: Jeffrey
 */






#include "elf.h"





/****************************************************************/
/* member functions for elf class				*/
/****************************************************************/
elf::elf()
{
	// do nothing but let the parent class constructor work
}






elf::elf(int newStrength, int newHitpoints) : creature(newStrength, newHitpoints)
{
        // do nothing but let the parent class constructor work
}






string elf::getSpecies() const
{
	return "Elf";
}






int elf::getDamage() const
{
        int damage;

        damage = creature::getDamage();		// call creature::getDamage()
        cout << getSpecies() << " attacks for " << damage << " points!" << endl;

        // Elves inflict double magical damage with a 50% chance
        if ((rand() % 2) == 0) {
        	cout << "Magical attack inflicts " << damage << " additional damage points!" << endl;
        	damage *= 2;
        }

        return damage;
}






