/*
 * demon.h
 *
 *  Created on: May 10, 2015
 *      Author: Jeffrey
 */

#ifndef DEMON_H_
#define DEMON_H_






#include "creature.h"





class demon : public creature {
public:
	demon();
	demon(int newStrength, int newHitpoints);
	int getDamage() const;
	string getSpecies() const;
};






#endif /* DEMON_H_ */
