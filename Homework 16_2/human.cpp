/*
 * human.cpp
 *
 *  Created on: May 11, 2015
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

















