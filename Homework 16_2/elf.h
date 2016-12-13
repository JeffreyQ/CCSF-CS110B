/*
 * Name:	Jeffrey Qiu
 * Class:	CS110B
 * Date:	05/11/2015
 * Instructor:	Professor Harden
 * File Name:	elf.h
 *
 *
 *	One problem with this implementation is that it is unwieldy to add new creatures. Rewrite the class to use inheritance,
 *	which will eliminate the need for the variable "type". The creature class should be the base class. The classes demon,
 *	elf, and human should be derived from creature. The classes cyberdemon and balrog should be derived from demon.
 *	You will need to rewrite the getSpecies() and getDamage() functions so they are appropriate for each class.
 *
 */






#ifndef ELF_H_
#define ELF_H_






#include "creature.h"







class elf : public creature {
public:
	elf();
	elf(int newStrength, int newHitpoints);
	int getDamage() const;
	virtual string getSpecies() const;
};






#endif /* ELF_H_ */
