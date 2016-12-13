/*
 * demon.h
 *
 *  Created on: May 11, 2015
 *      Author: Jeffrey
 */

#ifndef DEMON_H_
#define DEMON_H_






#include "creature.h"





class demon : public creature {
public:
	demon();
	demon(int newStrength, int newHitpoints);

	virtual string getSpecies() const = 0;	// make this a pure virtual funciton
	int getDamage() const;
};






#endif /* DEMON_H_ */
