/*
** FILE:    learnspell.c
** PURPOSE: This file determines the spells a priest is able to learn,
**          and places the into an array.
** CREDITS:
**   18 Aug 97  Cyanide wrote Learn v2.0 for wizards
**   28 Nov 97  Cyanide changed all the two-D string arrays to mappings
**              of ([ "spell" : lvl ]); they are simpler, less buggy,
**              more robust, and self-checking (to an extent).    
**   04 Jun 98  Ilzarion overhauled the code (and removed the comments
**              and headers) in order to accomodate priests.
**   01 Sep 99  Cyanide decided to repair this code and clean it up.
**              He also replaced the headers.
*/

#include <priest_spheres.h>

string learn_spell( object player ) {
    int level, i, flag, maxlvl, *spell_level;
    object guildob;
    string *majorspheres, *minorspheres, *spells, *known_spells,
    *sphere_spells, thissphere;
    mapping spheres;

    level = player->query_level("priest");

    if (player->query_level("ranger") || 
      player->query_level("paladin") || 
      player->query_level("knight") )
	level = player->query_level() - 8;

    if (!level) {
	write ("You don't have a priest level!\n"+
	  "Notify Cyanide immeditely!\n");
	return 0;
    }

    guildob = present("#CLASS_OBJECT#", player);
    if (!guildob){
	write ("You don't have a class object!\n"+
	  "Notify Cyanide immeditely!\n");
    }

    majorspheres = guildob->query("major");
    minorspheres = guildob->query("minor");
    known_spells = player->query("priest_spells");
    spells = ({});

    flag = 1;
    while(flag) {
	switch(flag) {    
	case 1 : spheres = ALL; thissphere = "all"; break;
	case 2 : spheres = ANIMAL; thissphere = "animal"; break;
	case 3 : spheres = ASTRAL; thissphere = "astral"; break;
	case 4 : spheres = CHAOS; thissphere = "chaos"; break;
	case 5 : spheres = CHARM; thissphere = "charm"; break;
	case 6 : spheres = COMBAT; thissphere = "combat"; break;
	case 7 : spheres = CREATION; thissphere = "creation"; break;
	case 8 : spheres = DIVINATION; thissphere = "divination"; break;
	case 9 : spheres = AIR; thissphere = "air"; break;
	case 10 : spheres = EARTH; thissphere = "earth"; break;
	case 11 : spheres = FIRE; thissphere = "fire"; break;
	case 12 : spheres = WATER; thissphere = "water"; break;
	case 13 : spheres = GUARDIAN; thissphere = "guardian"; break;
	case 14 : spheres = HEALING; thissphere = "healing"; break;
	case 15 : spheres = LAW; thissphere = "law"; break;
	case 16 : spheres = NECROMANTIC; thissphere = "necromantic"; break;
	case 17 : spheres = NUMBERS; thissphere = "numbers"; break;
	case 18 : spheres = PLANT; thissphere = "plant"; break;
	case 19 : spheres = PROTECTION; thissphere = "protection"; break;
	case 20 : spheres = SUMMONING; thissphere = "summoning"; break;
	case 21 : spheres = SUN; thissphere = "sun"; break;
	case 22 : spheres = THOUGHT; thissphere = "thought"; break;
	case 23 : spheres = TIME; thissphere = "time"; break;
	case 24 : spheres = TRAVELERS; thissphere = "travelers"; break;
	case 25 : spheres = WAR; thissphere = "war"; break;
	case 26 : spheres = WARDS; thissphere = "wards"; break;
	case 27 : spheres = WEATHER; thissphere = "weather"; break;
	default : flag = (-1); break;
	} 

	// This is to make sure that the player has access to the sphere.
	if ( (member_array(thissphere, majorspheres) != -1) ||
	  (member_array(thissphere, minorspheres) != -1) ) {
	    maxlvl = (level >> 1);
	    if (!maxlvl) maxlvl = 1;
	    if (maxlvl > 7) maxlvl = 7;

	    /*  We don't want to use these anymore.
	    if ((maxlvl > 6)&&(player->query("stat/wisdom")< 18)) maxlvl = 6;
	    if ((maxlvl > 5)&&(player->query("stat/wisdom")< 17)) maxlvl = 5;
	    */

	    if ((maxlvl > 5) && (member_array(thissphere, minorspheres) != -1))
		maxlvl = 3;

	    spell_level = values(spheres);
	    sphere_spells = keys(spheres);

	    for (i=0;i<sizeof(spheres);i++)    
		if ((spell_level[i] < (maxlvl+1)) &&
		  (member_array(sphere_spells[i], known_spells) == -1) )
		    spells += ({ sphere_spells[i] });
	}
	flag++;
    }

    // Hopefully now we have an array of learnable spells!

    thissphere = spells[ random(sizeof(spells)) ];

    return thissphere;
}

/* EOF */
