#pragma once
#include "Shared Libraries and Headers.h"

// DEFINITION OF OBJECTS (not done in Objects.h to avoid multiple definitions - if objects are created in a header file, then each source file that includes Objects.h
// will create its own copy of the object, violating the "one definition rule" and resulting in the linker error LNK2005.)

// Weapon Objects
Weapon flimsyStick("Flimsy Stick", 0, 5);
Weapon rustySword("Rusty Sword", 1, 5);
Weapon piercingDagger("Piercing Dagger", 2, 15);
Weapon heavyGreatsword("Heavy Greatsword", 3, 40);
Weapon bludgeoningHamaxe("Bludgeoning Hamaxe", 4, 85);

Weapon allWeapons[] = { flimsyStick, rustySword, piercingDagger, heavyGreatsword, bludgeoningHamaxe };

// Player Object
Player player1(/*name*/"", /*chosen item id*/0, /*base health*/100, /*base attack*/ 5, /*alive status*/true,
	/*unassigned stat points*/20, /*strength stat points*/0, /*vitality stat points*/0, /*defense stat points*/0);

// Enemy Objects
Enemy slime(/*name*/"Slime", /*max health*/75, /*current health*/75, /*base attack*/82, /*alive status*/true, /*current enemy status*/false);
Enemy zombie("Zombie", 100, 100, 83, true, false);
Enemy mutantSpider("Mutant Spider", 150, 150, 84, true, false);

Enemy allEnemies[] = { slime, zombie, mutantSpider };