// This file contains a whole bunch of stuff for the mage classes.

#define MAGES "/d/class/wizard/"
#define M_OBJ(X) MAGES+"obj/"+"X"

// This is the message given when a mage lacks suficiant sp's to
// cast a specific spell.

#define NOT_ENOUGH_SP "You cannot muster the energies to cast that.\n"

#define MAX_TO_SPELLS 1

#define SUMMON_MULT 3.33

mapping ABJURATION = ([
"abjuration" : 0,
"alarm" : 1,
"minorglobe" : 4,
"globe" : 6,
"prismsphere" : 9,
]);

mapping ALTERATION = ([
"alteration" : 0,
"enlarge" : 1, "light" : 1,
"strength" : 2,
"wraithform" : 3, "infravision" : 3, "item" : 3,
"fireshield" : 4, "stoneskin" : 4, 
"disintegrate" : 6, "transform" : 6, 
"wilting" : 8, "heartstone" : 8,
"disjunction" : 9, "timestop" : 9
]);

mapping CONJURATION = ([
"conjuration" : 0,
"armor" : 1, 
"glitter" : 2,
"summon1" : 3,
"summon2" : 4,
"summon3" : 5,
"summon4" : 6,
"stun" : 7, "prism" : 7, "summon5" : 7,
"blind" : 8, "summon6" : 8,
"summon7" : 9, "gate" : 9, "prismsphere" : 9,
"summon8" : 10, "wyrmfury" : 10,
]);

mapping DIVINATION = ([
"divination" : 0,
//"seeinvis" : 2,
"locate" : 4,
"vision" : 5, 
//"truesight" : 6,
//"screen" : 8,
"foresight" : 9,
]);

mapping ENCHANTMENT = ([
"enchantment" : 0,
"taunt" : 1,
"feeblemind" : 5,
"disjunction" : 9
]);

mapping ILLUSION = ([
"illusion" : 0,
"invisibility" : 2, "blur" : 2, "images" : 2,
"wraithform" : 3,
//"terrain" : 4,
//"image" : 6,
//"screen" : 8,
]);

mapping INVOCATION = ([
"invocation" : 0,
"fog" : 2,
"alarm" : 1, "missile" : 1, "shield" : 1, 
"fireball" : 3, "bolt" : 3, 
"coldcone" : 5, 
"lightning" : 6, "transform" : 6,
"acidstorm" : 7, "mordsword" : 7,
"swarm" : 9,
"tellblow" : 10
]);

mapping NECROMANCY = ([
"necromancy" : 0,
"chill" : 1,
"embalm" : 3,
"necrobolt" : 3,
// "enervation" : 4,
"animate" : 5,
"trollish" : 6,
"finger" : 7,
"wilting" : 8, "heartstone" : 8,
]);

mapping UNIVERSAL = ([
"universal" : 0,
"detect_magic" : 1,
"vocalize" : 2, 
"dispel" : 3,
"teleport" : 5,
]);
