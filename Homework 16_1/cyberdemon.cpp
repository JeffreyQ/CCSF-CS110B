/*
 * cyberdemon.cpp
 *
 *  Created on: May 10, 2015
 *      Author: Jeffrey
 */






#include "cyberdemon.h"






/****************************************************************/
/* member functions for cyberdemon class			*/
/****************************************************************/
cyberdemon::cyberdemon()
{
        // do nothing but let the parent class constructor work
}






cyberdemon::cyberdemon(int newStrength, int newHitpoints) : demon(newStrength, newHitpoints)
{
        // do nothing but let the parent class constructor work
}






string cyberdemon::getSpecies() const
{
	return "Cyberdemon";
}






int cyberdemon::getDamage() const
{
        int damage;

	cout << "The cyberdemon";
        damage = demon::getDamage();		// call demon::getDamage()

        return damage;
}






