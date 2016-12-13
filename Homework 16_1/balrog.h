/*
 * balrog.h
 *
 *  Created on: May 10, 2015
 *      Author: Jeffrey
 */

#ifndef BALROG_H_
#define BALROG_H_






#include "demon.h"





class balrog : public demon {
public:
	balrog();
	balrog(int newStrength, int newHitpoints);
	int getDamage() const;
	string getSpecies() const;
};






#endif /* BALROG_H_ */
