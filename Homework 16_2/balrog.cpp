/*
 * balrog.cpp
 *
 *  Created on: May 11, 2015
 *      Author: Jeffrey
 */






#include "balrog.h"






/****************************************************************/
/* member functions for balrog class				*/
/****************************************************************/
balrog::balrog()
{
        // do nothing but let the parent class constructor work
}






balrog::balrog(int newStrength, int newHitpoints) : demon(newStrength, newHitpoints)
{
        // do nothing but let the parent class constructor work
}






string balrog::getSpecies() const
{
	return "Balrog";
}






int balrog::getDamage() const
{
        int damage;

//	cout << "The balrog";
        damage = demon::getDamage();		// call demon::getDamage()

        // Balrogs are so fast they get to attack twice
        int damage2 = (rand() % getStrength()) + 1;
        cout << "Balrog speed attack inflicts " << damage2 << " additional damage points!" << endl;
        damage += damage2;

        return damage;
}






