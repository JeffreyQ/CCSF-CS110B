/*
 * cyberdemon.h
 *
 *  Created on: May 10, 2015
 *      Author: Jeffrey
 */

#ifndef CYBERDEMON_H_
#define CYBERDEMON_H_






#include "demon.h"





class cyberdemon : public demon {
public:
	cyberdemon();
	cyberdemon(int newStrength, int newHitpoints);
	int getDamage() const;
	string getSpecies() const;
};






#endif /* CYBERDEMON_H_ */
