/*
 * Name:	Jeffrey Qiu
 * Class:	CS110B
 * Date:	05/10/2015
 * Instructor:	Professor Harden
 * File Name:	a16_1.cpp
 *
 *
 *	One problem with this implementation is that it is unwieldy to add new creatures. Rewrite the class to use inheritance,
 *	which will eliminate the need for the variable "type". The creature class should be the base class. The classes demon,
 *	elf, and human should be derived from creature. The classes cyberdemon and balrog should be derived from demon.
 *	You will need to rewrite the getSpecies() and getDamage() functions so they are appropriate for each class.
 *
 */






#include <iostream>
#include <ctime>
#include <cstdlib>
#include "human.h"
#include "elf.h"
#include "balrog.h"
#include "cyberdemon.h"






int main() {
	srand(time(0));

	human h1;
	elf e1;
	cyberdemon c1;
	balrog b1;

	human h(20, 30);
	elf e(40, 50);
	cyberdemon c(60, 70);
	balrog b(80, 90);


	cout << "default human strength/hitpoints: " << h1.getStrength() << "/" << h1.getHitpoints() << endl;
	cout << "default elf strength/hitpoints: " << e1.getStrength() << "/" << e1.getHitpoints() << endl;
	cout << "default cyberdemon strength/hitpoints: " << c1.getStrength() << "/" << c1.getHitpoints() << endl;
	cout << "default balrog strength/hitpoints: " << b1.getStrength() << "/" << b1.getHitpoints() << endl;
	cout << "non-default human strength/hitpoints: " << h.getStrength() << "/" << h.getHitpoints() << endl;
	cout << "non-default elf strength/hitpoints: " << e.getStrength() << "/" << e.getHitpoints() << endl;
	cout << "non-default cyberdemon strength/hitpoints: " << c.getStrength() << "/" << c.getHitpoints() << endl;
	cout << "non-default balrog strength/hitpoints: " << b.getStrength() << "/" << b.getHitpoints() << endl;
	cout << endl << endl;

	cout << "Examples of " << h.getSpecies() << " damage: " << endl;
	for (int i = 0; i < 10; i++){
		int damage = h.getDamage();
		cout << " Total damage = " << damage << endl;
		cout << endl;
	}
	cout << endl;



	cout << "Examples of " << e.getSpecies() << " damage: " << endl;
	for (int i = 0; i < 10; i++){
		int damage = e.getDamage();
		cout << " Total damage = " << damage << endl;
		cout << endl;
	}
	cout << endl;



	cout << "Examples of " << c.getSpecies() << " damage: " << endl;
	for (int i = 0; i < 10; i++){
		int damage = c.getDamage();
		cout << " Total damage = " << damage << endl;
		cout << endl;
	}
	cout << endl;



	cout << "Examples of " << b.getSpecies() << " damage: " << endl;
	for (int i = 0; i < 10; i++){
		int damage = b.getDamage();
		cout << " Total damage = " << damage << endl;
		cout << endl;
	}
	cout << endl;
}









/*

default human strength/hitpoints: 10/10
default elf strength/hitpoints: 10/10
default cyberdemon strength/hitpoints: 10/10
default balrog strength/hitpoints: 10/10
non-default human strength/hitpoints: 20/30
non-default elf strength/hitpoints: 40/50
non-default cyberdemon strength/hitpoints: 60/70
non-default balrog strength/hitpoints: 80/90


Examples of Human damage:
Human attacks for 9 points!
 Total damage = 9

Human attacks for 13 points!
 Total damage = 13

Human attacks for 1 points!
 Total damage = 1

Human attacks for 17 points!
 Total damage = 17

Human attacks for 5 points!
 Total damage = 5

Human attacks for 3 points!
 Total damage = 3

Human attacks for 6 points!
 Total damage = 6

Human attacks for 8 points!
 Total damage = 8

Human attacks for 2 points!
 Total damage = 2

Human attacks for 11 points!
 Total damage = 11


Examples of Elf damage:
Elf attacks for 20 points!
Magical attack inflicts 20 additional damage points!
 Total damage = 40

Elf attacks for 17 points!
 Total damage = 17

Elf attacks for 33 points!
 Total damage = 33

Elf attacks for 11 points!
Magical attack inflicts 11 additional damage points!
 Total damage = 22

Elf attacks for 17 points!
Magical attack inflicts 17 additional damage points!
 Total damage = 34

Elf attacks for 7 points!
 Total damage = 7

Elf attacks for 7 points!
 Total damage = 7

Elf attacks for 31 points!
 Total damage = 31

Elf attacks for 21 points!
 Total damage = 21

Elf attacks for 12 points!
Magical attack inflicts 12 additional damage points!
 Total damage = 24


Examples of Cyberdemon damage:
The cyberdemon attacks for 13 points!
 Total damage = 13

The cyberdemon attacks for 4 points!
 Total damage = 4

The cyberdemon attacks for 32 points!
 Total damage = 32

The cyberdemon attacks for 26 points!
 Total damage = 26

The cyberdemon attacks for 42 points!
Demonic attack inflicts 50 additional damage points!
 Total damage = 92

The cyberdemon attacks for 53 points!
 Total damage = 53

The cyberdemon attacks for 18 points!
 Total damage = 18

The cyberdemon attacks for 1 points!
 Total damage = 1

The cyberdemon attacks for 3 points!
Demonic attack inflicts 50 additional damage points!
 Total damage = 53

The cyberdemon attacks for 46 points!
 Total damage = 46


Examples of Balrog damage:
The balrog attacks for 1 points!
Balrog speed attack inflicts 9 additional damage points!
 Total damage = 10

The balrog attacks for 39 points!
Demonic attack inflicts 50 additional damage points!
Balrog speed attack inflicts 7 additional damage points!
 Total damage = 96

The balrog attacks for 40 points!
Balrog speed attack inflicts 13 additional damage points!
 Total damage = 53

The balrog attacks for 50 points!
Demonic attack inflicts 50 additional damage points!
Balrog speed attack inflicts 14 additional damage points!
 Total damage = 114

The balrog attacks for 3 points!
Balrog speed attack inflicts 42 additional damage points!
 Total damage = 45

The balrog attacks for 23 points!
Balrog speed attack inflicts 73 additional damage points!
 Total damage = 96

The balrog attacks for 71 points!
Balrog speed attack inflicts 79 additional damage points!
 Total damage = 150

The balrog attacks for 5 points!
Balrog speed attack inflicts 56 additional damage points!
 Total damage = 61

The balrog attacks for 22 points!
Balrog speed attack inflicts 61 additional damage points!
 Total damage = 83

The balrog attacks for 75 points!
Demonic attack inflicts 50 additional damage points!
Balrog speed attack inflicts 18 additional damage points!
 Total damage = 143

 */



