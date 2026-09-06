

/****************************************************************
*								*
*	Standard module defining race-dependant things;		*
*		inheritted by /obj/living.c			*
*								*
*	Version:	2.1c   					*
*								*
*	NEW:							*
* - No more dozens of funcs; "query_race_stat(RACE_XXX)" instead*
* - This is now included by living.c, not inheritted.		*
*								*
*- Added RACE_EAT_VALUE to take into account the amount of value*
*- one would get form eating. i.e. little hobbit, big food      *
*								*
*	Version:	2.1					*
*	Modified 05-Apr-95 by Kelgath				*
*	... and slightly 13-jan-95 by Doomdark.			*
* 	... 25-mar-96, reduced race bonuses. -+ Doomdark +-	*
*								*
*	Changes:  Race difference are now much more pronounced.	*
*-Extremes have been changed to allow greater differences 	*
*between similar races.						*
*-Dwarves enhanced to emphasives their hardyness. 		*
*-1/2-Orcs (1/2 Humans) changed to be more human like.		*
*								*
* 7-May-98 / Graah: Humans have too good stats, which cannot	*
*		    really be fixed. Dunno what to do.		*
*								*
****************************************************************/

#ifndef LIVING_C

int infravision;

#include <race.h>
#include <living_defs.h>
int query_level();
void race_update();
int query(int x);

#endif

string race;

string
query_race() { return race; }

int
query_infravision()
{
    // Infra 5: blinded in daylight, but sees in dark.
    if (race == "troll" || race == "dark elf") return 5;

    // Infra 4: Full vision in both daylight AND in darkness!
    // Graah 23-Jun-96
    if (query(LIV_UNDEAD)) return 4;
    if (race == "dwarf") return 4;

    if (race == "half-orc") return 3;
    if (race == "hobbit") return 2;
    if (race == "elf") return 1;

    return 0;
}

void
set_race(string str)
{
    race = str;
    race_update();
    infravision = query_infravision();
}

int
query_race_stat(int stat)
{
    int l;

    switch (stat) {
    case RACE_HP_RATE:
	/***************************************************************
	Race	Max	Change	Reason
	elf/de	252	none	-----
	dwarf	341	+29	Needed to be tougher, hardyness!
	hobbit	311	+29	SHOULD be tough little buggers
	1/2-orc	429	+87	Needed greater differnece than humanoid
	troll	518	+116	If we're gonna have trolls, let'em be TROLLS!
	human	282	none	Good base value
	****************************************************************/

	switch (race) {
	case "elf": return 7;
	case "dark elf": return 7;
	case "dwarf": return 10;
	case "hobbit": return 9;
	case "half-orc": return 12;
	    // Was 13. -+ Doomdark +-
	    // I think that as they're _half_-orcs, shouldn't have this high hps.
	case "troll": return 16;
	default: return 8;
	}

    case RACE_SP_RATE:

	/***************************************************************
	Race	Max	Change	Reason
	elf/de	428	+116	Let's make them REAL magic users
	dwarf	219	+87	Should be MUCH smarter than goblinoids
	hobbit	282	+60	Just a little slower than human
	1/2-orc	160	+58	They are 1/2 human (nods.Thark/pantha)
	troll	72	none	Sps? Can I eat that?
	human	340	+58	Humans needed to be smarter than goblins
	****************************************************************/

	switch(race) {
	case "elf": return 13;
	case "dark elf": return 13;
	case "dwarf": return 6;
	case "hobbit": return 8;
	case "half-orc": return 4;
	case "troll": return 1;
	case "human": return 9;
	default: return 10;
	}

    case RACE_FP_RATE:                  //Frobozz
	/***************************************************************
		Like I'm gonna mess with the Frobozz's Stuff!
	***************************************************************/

	switch(race) {
	case "elf":      return 3;  // *GRIN*
	case "dark elf": return 3;
	case "half-orc": return 10;
	case "troll":    return 11;
	case "dwarf":    return 12;
	case "hobbit":   return 6;
	default:         return 8;  // humans
	}

    case RACE_DRUNKNESS_RATE:
	/********************************************************************
	Dwarves can now drink more than humans, and elves less. 1.2.1993 //Frobozz 
	Hobbits can drink more than humans too...read "The Hobbit" sometime-Kel.
	********************************************************************/	

	switch(race) {
	case "elf": return -3;  /* Con - 3 == human - 6 */
	case "dark elf": return -3;
	case "dwarf": return 9; /* Con + 9 == human + 6 */
	case "troll": return 12; /* Experimental troll race //Graah */
	case "hobbit": return 6; /* Con + 6 == human + 3 */
	default: return 3;      /* Con + 3 == human, half-orc, hobbit */
	}

    case RACE_DAMAGE_RATE:
	// Adjust damage delivered with weapons
	/*********************************************************************
	1) Why make any difference between lord/non. IT"S race not rank!
	2) COnsidered the hardyness of dwarfs and 1/2-orcs
		Race	Damage Adjust	Reason
		elf/de	80		Elf's should hit like fairies!
		1/2-orc	120		Remeber, ther half-human too.
		dwarf	130		They SHOULD be very comfortable with weaps.
		troll	150		Can you say: Crush your skull??
	*********************************************************************/

	switch(race) {
	case "elf": return 90;		// Penalty 15% (Balance)
	case "dark elf": return 90;
	    // Was 85
	case "dwarf": return 112;
	    // Was 130
	case "half-orc": return 108;
	    // Was 120
	case "troll": return 120;
	    // Was 150
	default: return 100;
	}

    case RACE_AC_RATE:

	// Adjust damage from others (if we can move, it is checked elsewhere)
	// Damage is multiplied by this and divided by 100.
	/********************************************************************
	Needed to be based on ability of RACE to avoid damage! Natural dex 
	and quickness (or lack of it) should be considered.
	Race	Modif.	Reason
	hobbit	85	Small, fast, and quick!
	dwarf	95	Tough, dextrous (metal work, etc) and small in bulk
	troll	110	Hitting a barn is easy, especially when it moves SLOW!
	*******************************************************************/
	switch(race) {
	case "hobbit": return 85;
	case "dwarf": return 95;
	case "troll": return 110;
	default: return 100;
	}

    case RACE_CARRY_RATE:
	/*******************************************************************
	1) Size of carrier controls where things can be placed, how much.
	2) Dwarfs are designed to carry A LOT!
	3) Hobbits are about evan with elves.

	  Max carries with different races and strs:
	  str	human	elf/de/hobbit	half_orc	dwarf	troll
	   1	11	9               14		15	16
	  10	20	18              26		28	30
	  20 	30	27              39		42	45
	  30	40	36              52		56	60

	******************************************************************/
	switch(race) {
	case "troll": return 150;
	case "half-orc": return 130;
	case "dwarf": return 140;
	case "elf": return 90;
	case "dark elf": return 90;
	case "hobbit": return 90;
	default: return 100;
	}

    case RACE_NATURAL_WC:
	/********************************************************************
	Based on strenght of hit, dwarfs should be close to half-orcs.
	********************************************************************/

	l = query_level();
	switch (race) {
	case "troll":		// Too good?
	    // l += l * 2 / 3;	// Was l; 33% downgrade. -+ Doomdark +-
	    l = 5 + l / 2;	// This might be ok... -DD
	    break;
	case "half-orc":
	    l = (3 + l / 5);
	    break;
	case "dwarf":
	    l = (3+ l / 6);
	    break;
	default:
	    l = (3 + l / 7);
	    break;
	}
	if (l > 25) l = 25;
	else if (l < 3) l = 3;
	return l;

    case RACE_NATURAL_AC:
	/*********************************************************************
	1) Natural "racial" skin thickness and scalelyness (lizardiods someday?)
	2) Some thought to hardyness... how hard are they to injure.
		Max Natural Ac at:
	Race	lvl 1	lvl 20	lvl 40	Reason
	troll	1	3	6	Their scalely hide.
	dwarf	1	2	3	Hardyness, thought to kill. Thick skin.
	hobbit	0	1	2	Toughness, hardyness. (make-up low carry)
	1/2-orc	0	1	1	Slightly thicker than humans, not much.
	others	0	0	0	Can you say "wussy"?
	********************************************************************/

	l = query_level();

	switch(race) {
	case "troll":
	    l = 1 + (l / 8);
	    if (l > 5) l = 6;
	    return l;
	case "dwarf":
	    l = 1 + (l/15);
	    if (l > 3) l = 3;
	    return l;
	case "hobbit":
	    l=(l/15);
	    if (l > 2) l = 2;
	    return l;
	case "half-orc":
	    l = (l/20);
	    if (l > 1) l = 1;
	    return l;
	default:
	    return 0;
	}

    case RACE_HEAL_RATE:
	// This applies to hit points ONLY!
	/***************************************************************
	1) Bulk effects not only how many hits points you have, but how 
	much meat is there to be repaired each turn. 
	2) Big boys (trolls,1/2y's) have LOTS of hps, but heal them up 
	more slowly.
	3) Hardier races heal faster.
	***************************************************************/

	switch(race) {
	case "troll": return 3;
	case "half-orc": return 3;
	case "dwarf": return 4;
	case "hobbit": return 2;
	default: return 1;
	}

    case RACE_SP_HEAL_RATE:
	// And this applies to sps... as you may guess.
	/**************************************************************
	Natural intelligence should play some part. Hobbits and humans 
	regain sps quicker too. Or not. Humans are too good.
	**************************************************************/

	switch(race) {
	case "elf": return 4;
	case "dark elf": return 4;
	case "human": return 1; // Was 3, thank munchkins. /Graah
	case "hobbit": return 2;
	default: return 1;
	}

    case RACE_FP_HEAL_RATE:
	// And this applies to fps, how surprising
	/**************************************************************
	Tough guys: trolls, dwarves, half-orcs, hobbits and humans
	**************************************************************/

	switch(race) {
	case "trolls": return 4;
	case "dwarf": return 4;
	case "half-orcs": return 3;
	case "hobbit": return 2;
	case "human": return 2;
	default: return 1;
	}

    case RACE_EAT_RATE:
	// Max eat: constitution * this value
	switch(race) {
	    // Hobbits are big eaters!
	case "hobbit":
	case "troll":
	    return 16;
	default:
	    return 8;
	}

    case RACE_EAT_VALUE:
	// Adjusts value a player gets for eating food by race. 
	// Larger your bulk, the less value for food you consume.
	// Adjusted slightly to heal some more. //Graah
	switch(race) {
	case "elf": return 5;
	case "dark elf": return 5;
	case "dwarf": return 6;
	case "hobbit": return 3;
	case "half-orc": return 5;
	case "troll": return 7;
	default: return 6;
	}

    case RACE_HP_DELAY:
	switch (race) {
	case "dwarf":	return 8;
	case "elf":	return 12;
	case "dark elf":return 12;
	case "half-orc":return 8;
	case "hobbit":	return 6;
	case "human":	return 10;
	case "troll":	return 10;
	default:
	    return 10;
	}

    case RACE_SP_DELAY:
	switch (race) {
	case "dwarf":	return 12;
	case "elf":	return 6;
	case "dark elf":return 6;
	case "half-orc":return 14;
	case "hobbit":	return 8;
	case "human":	return 8;
	case "troll":	return 16;
	default:
	    return 8;
	}

    case RACE_FP_DELAY:
	switch (race) {
	case "dwarf":	return 6;
	case "elf":	return 16;
	case "dark elf":return 16;
	case "half-orc":return 10;
	case "hobbit":	return 8;
	case "human":	return 10;
	case "troll":	return 10;
	default:
	    return 10;
	}
    }

    return 0;
}
