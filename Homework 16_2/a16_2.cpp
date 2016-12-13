/*
 *  Name:	Jeffrey Qiu
 *  Class:	CS110B
 *  Date:	05/11/2015
 *  Instructor:	Professor Harden
 *  File Name:	a16_2.cpp
 *
 *	One problem with this implementation is that it is unwieldy to add new creatures. Rewrite the class to use inheritance,
 *	which will eliminate the need for the variable "type". The creature class should be the base class. The classes demon,
 *	elf, and human should be derived from creature. The classes cyberdemon and balrog should be derived from demon.
 *	You will need to rewrite the getSpecies() and getDamage() functions so they are appropriate for each class.
 *
 */







#include "creature.h"
#include "human.h"
#include "elf.h"
#include "demon.h"
#include "balrog.h"
#include "cyberdemon.h"








int main()
{
	srand((time(0)));

	elf e(50,50);
	balrog b(50,50);
	human h(50, 50);
	cyberdemon c(50, 50);

	battleArena(e, b);

	e.setStrength(50);
	e.setHitpoints(50);
	h.setStrength(50);
	h.setHitpoints(50);
	battleArena(e, h);

	e.setStrength(50);
	e.setHitpoints(50);
	c.setStrength(50);
	c.setHitpoints(50);
	battleArena(e, c);

	b.setStrength(50);
	b.setHitpoints(50);
	h.setStrength(50);
	h.setHitpoints(50);
	battleArena(b, h);

	b.setStrength(50);
	b.setHitpoints(50);
	c.setStrength(50);
	c.setHitpoints(50);
	battleArena(b, c);

	h.setStrength(50);
	h.setHitpoints(50);
	c.setStrength(50);
	c.setHitpoints(50);
	battleArena(h, c);
}








/*

--------------------------------------------------
The battle between Elf and Balrog starts ...

The Balrog attacks for 29 points!
The Elf attacks for 39 points!
Creature Elf remaining hitpoints = 21
Creature Balrog remaining hitpoints = 11
The Balrog attacks for 31 points!
The Elf attacks for 19 points!
Creature Elf remaining hitpoints = -10
Creature Balrog remaining hitpoints = -8

Game tied.

--------------------------------------------------
The battle between Elf and Human starts ...

The Human attacks for 40 points!
The Elf attacks for 40 points!
Creature Elf remaining hitpoints = 10
Creature Human remaining hitpoints = 10
The Human attacks for 13 points!
The Elf attacks for 9 points!
Creature Elf remaining hitpoints = -3
Creature Human remaining hitpoints = 1

Game over. Creature Elf wins.

--------------------------------------------------
The battle between Elf and Cyberdemon starts ...

The Cyberdemon attacks for 18 points!
The Elf attacks for 3 points!
Creature Elf remaining hitpoints = 32
Creature Cyberdemon remaining hitpoints = 47
The Cyberdemon attacks for 7 points!
The Elf attacks for 26 points!
Creature Elf remaining hitpoints = 25
Creature Cyberdemon remaining hitpoints = 21
The Cyberdemon attacks for 12 points!
The Elf attacks for 43 points!
Creature Elf remaining hitpoints = 13
Creature Cyberdemon remaining hitpoints = -22

Game over. Creature Cyberdemon wins.

--------------------------------------------------
The battle between Balrog and Human starts ...

The Human attacks for 46 points!
The Balrog attacks for 38 points!
Creature Balrog remaining hitpoints = 4
Creature Human remaining hitpoints = 12
The Human attacks for 15 points!
The Balrog attacks for 19 points!
Creature Balrog remaining hitpoints = -11
Creature Human remaining hitpoints = -7

Game tied.

--------------------------------------------------
The battle between Balrog and Cyberdemon starts ...

The Cyberdemon attacks for 20 points!
The Balrog attacks for 22 points!
Creature Balrog remaining hitpoints = 30
Creature Cyberdemon remaining hitpoints = 28
The Cyberdemon attacks for 21 points!
The Balrog attacks for 41 points!
Creature Balrog remaining hitpoints = 9
Creature Cyberdemon remaining hitpoints = -13

Game over. Creature Cyberdemon wins.

--------------------------------------------------
The battle between Human and Cyberdemon starts ...

The Cyberdemon attacks for 48 points!
The Human attacks for 29 points!
Creature Human remaining hitpoints = 2
Creature Cyberdemon remaining hitpoints = 21
The Cyberdemon attacks for 47 points!
The Human attacks for 23 points!
Creature Human remaining hitpoints = -45
Creature Cyberdemon remaining hitpoints = -2

Game tied.

 */























