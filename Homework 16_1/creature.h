/*
 * Name:	Jeffrey Qiu
 * Class:	CS110B
 * Date:	05/10/2015
 * Instructor:	Professor Harden
 * File Name:	creature.h
 *
 *
 *	One problem with this implementation is that it is unwieldy to add new creatures. Rewrite the class to use inheritance,
 *	which will eliminate the need for the variable "type". The creature class should be the base class. The classes demon,
 *	elf, and human should be derived from creature. The classes cyberdemon and balrog should be derived from demon.
 *	You will need to rewrite the getSpecies() and getDamage() functions so they are appropriate for each class.
 *
 */

#ifndef CREATURE_H_
#define CREATURE_H_






#include <iostream>
#include <ctime>
#include <cstdlib>






using namespace std;






/****************************************************************/
/* The following is the inheritance tree:						*/
/* 	creature -> human											*/
/* 	creature -> elf												*/
/* 	creature -> demon -> balrog									*/
/* 	creature -> demon -> cyberdemon								*/
/****************************************************************/
class creature {
private:
	int strength;		// how much damage this creature inflicts
	int hitpoints;		// how much damage this creature can sustain
public:
	creature(); 		// initialize to human, 10 strength, 10 hitpoints
	creature(int newStrength, int newHitpoints);
	string getSpecies() const;	// returns the type of the species
	int getDamage() const; 	// returns the amount of damage this Creature
				// inflicts in one round of combat
	// also include appropriate accessors and mutators
	int getStrength() const;
	void setStrength(int);
	int getHitpoints() const;
	void setHitpoints(int);
};





#endif /* CREATURE_H_ */
