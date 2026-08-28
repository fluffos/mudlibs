/* Majik 4 server
 * Copyright (C) 1998, 1999  Majik Development Team <majik@majik.netti.fi>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include <race.h>
#include <symbol.h>
#include <living.h>
#include <color.h>
#include <natweap.h>
#include <hitloc.h>
#include <weapon.h>

mapping hitlocs = ([
BT_HUMANOID : ([
/* loc          		 hp    type   maxbleed size  arming type
    |         		      |      |         \   /        /  		*/
"head"			 	: ({ 30, HITLOC_VITAL, 40, 3, ARMTYPE_NONE }),
"neck"			 	: ({ 25, HITLOC_VITAL, 50, 2, ARMTYPE_NONE }),
"chest"			 	: ({ 40, HITLOC_VITAL, 50, 4, ARMTYPE_NONE }),
"stomach"		 	: ({ 35, HITLOC_VITAL, 40, 3, ARMTYPE_NONE }),
"hip"			 	: ({ 30, HITLOC_VITAL, 35, 3, ARMTYPE_NONE }),
"right shoulder" 	: ({ 30, HITLOC_NONVITAL, 40, 2, ARMTYPE_NONE }),
"left shoulder"  	: ({ 30, HITLOC_NONVITAL, 40, 2, ARMTYPE_NONE }),
"right upper arm"	: ({ 25, HITLOC_NONVITAL, 35, 2, ARMTYPE_NONE }),
"left upper arm"	: ({ 25, HITLOC_NONVITAL, 35, 2, ARMTYPE_NONE }),
"right elbow"		: ({ 15, HITLOC_NONVITAL, 30, 1, ARMTYPE_NONE }),
"left elbow"		: ({ 15, HITLOC_NONVITAL, 30, 1, ARMTYPE_NONE }),
"right forearm"		: ({ 20, HITLOC_NONVITAL, 25, 3, ARMTYPE_NONE }),
"left forearm"		: ({ 20, HITLOC_NONVITAL, 25, 3, ARMTYPE_NONE }),
"right wrist"		: ({ 10, HITLOC_NONVITAL, 20, 1, ARMTYPE_NONE }),
"left wrist"		: ({ 10, HITLOC_NONVITAL, 20, 1, ARMTYPE_NONE }),
"right hand"		: ({ 15, HITLOC_NONVITAL, 10, 1, ARMTYPE_WIELD }),
"left hand"			: ({ 15, HITLOC_NONVITAL, 10, 1, ARMTYPE_WIELD }),
"right thigh"		: ({ 30, HITLOC_NONVITAL, 40, 4, ARMTYPE_NONE }),
"left thigh"		: ({ 30, HITLOC_NONVITAL, 40, 4, ARMTYPE_NONE }),
"right knee"		: ({ 15, HITLOC_NONVITAL, 35, 1, ARMTYPE_NONE }),
"left knee"			: ({ 15, HITLOC_NONVITAL, 35, 1, ARMTYPE_NONE }),
"right shin"		: ({ 20, HITLOC_NONVITAL, 30, 4, ARMTYPE_NONE }),
"left shin"			: ({ 20, HITLOC_NONVITAL, 30, 4, ARMTYPE_NONE }),
"right ankle"		: ({ 10, HITLOC_NONVITAL, 25, 1, ARMTYPE_NONE }),
"left ankle"		: ({ 10, HITLOC_NONVITAL, 25, 1, ARMTYPE_NONE }),
"right foot"		: ({ 15, HITLOC_NONVITAL, 15, 1, ARMTYPE_NONE }),
"left foot"			: ({ 15, HITLOC_NONVITAL, 15, 1, ARMTYPE_NONE }),
]),

BT_HOOVED : ([
"head"					: ({ 40, HITLOC_VITAL, 40, 5, ARMTYPE_NONE }),
"neck"					: ({ 30, HITLOC_VITAL, 50, 4, ARMTYPE_NONE }),
"chest"					: ({ 50, HITLOC_VITAL, 35, 3, ARMTYPE_NONE }),
"stomach"				: ({ 30, HITLOC_VITAL, 35, 4, ARMTYPE_NONE }),
"rear"					: ({ 35, HITLOC_VITAL, 30, 4, ARMTYPE_NONE }),
"right upper front leg" : ({ 20, HITLOC_NONVITAL, 20, 2, ARMTYPE_NONE }),
"left upper front leg"  : ({ 20, HITLOC_NONVITAL, 20, 2, ARMTYPE_NONE }),
"right front hoove"     : ({ 5, HITLOC_IRRELEVANT, 0, 1, ARMTYPE_NONE }),
"left front hoove"		: ({ 5, HITLOC_IRRELEVANT, 0, 1, ARMTYPE_NONE }),
"right upper hind leg"  : ({ 25, HITLOC_NONVITAL, 25, 3, ARMTYPE_NONE }),
"left upper hind leg"   : ({ 25, HITLOC_NONVITAL, 25, 3, ARMTYPE_NONE }),
"right hind hoove"      : ({ 5, HITLOC_IRRELEVANT, 0, 1, ARMTYPE_NONE }),
"left hind hoove"		: ({ 5, HITLOC_IRRELEVANT, 0, 1, ARMTYPE_NONE }),
]),

BT_MAMMAL : ([ 
"head"                  : ({ 40, HITLOC_VITAL, 40, 3, ARMTYPE_NONE }),
"neck"                  : ({ 30, HITLOC_VITAL, 50, 4, ARMTYPE_NONE }),
"chest"                 : ({ 40, HITLOC_VITAL, 35, 3, ARMTYPE_NONE }),
"stomach"               : ({ 30, HITLOC_VITAL, 35, 4, ARMTYPE_NONE }),
"rear"                  : ({ 35, HITLOC_VITAL, 30, 4, ARMTYPE_NONE }),
"right upper front leg" : ({ 25, HITLOC_NONVITAL, 20, 2, ARMTYPE_NONE }),
"left upper front leg"  : ({ 25, HITLOC_NONVITAL, 20, 2, ARMTYPE_NONE }),
"right front paw"       : ({ 20, HITLOC_NONVITAL, 15, 1, ARMTYPE_NONE }),
"left front paw"        : ({ 20, HITLOC_NONVITAL, 15, 1, ARMTYPE_NONE }),
"right upper hind leg"  : ({ 35, HITLOC_NONVITAL, 25, 3, ARMTYPE_NONE }),
"left upper hind leg"   : ({ 35, HITLOC_NONVITAL, 25, 3, ARMTYPE_NONE }),
"right hind paw"        : ({ 20, HITLOC_NONVITAL, 15, 1, ARMTYPE_NONE }),
"left hind paw"         : ({ 20, HITLOC_NONVITAL, 15, 1, ARMTYPE_NONE }),
]),

]);

mapping bodytypes = ([

BT_HUMANOID : ([
"head"      : ({ ({"head"}), ({"neck","torso","right arm","left arm","right leg","left leg"}), BODYPART_CAPITAL }),
"neck"      : ({ ({"neck"}), ({"torso","right arm","left arm","right leg","left leg"}), BODYPART_CAPITAL }),
"torso"     : ({ ({"chest","stomach","hip"}), ({"right leg","left leg"}), BODYPART_HUB }),
"right arm" : ({ ({"right shoulder","right upper arm","right elbow","right forearm","right wrist","right hand"}), ({ }), BODYPART_LIMB }),
"left arm"  : ({ ({"left shoulder","left upper arm","left elbow","left forearm","left wrist","left hand"}), ({ }), BODYPART_LIMB }),
"right leg" : ({ ({"right thigh","right knee","right shin","right ankle","right foot"}), ({ }), BODYPART_SUPPORTING }),
"left leg"  : ({ ({"left thigh","left knee","left shin","left ankle","left foot"}), ({ }), BODYPART_SUPPORTING })
]),

BT_HOOVED : ([
"head"			  : ({ ({"head"}), ({"neck","torso","right front leg","left front leg","right hind leg","left hind leg"}), BODYPART_CAPITAL }),
"neck"			  : ({ ({"neck"}), ({"torso","right front leg","left front leg","right hind leg","left hind leg"}), BODYPART_CAPITAL }),
"torso"			  : ({ ({"chest","stomach","rear"}), ({"right hind leg","left hind leg"}), BODYPART_HUB }),
"right front leg" : ({ ({"right upper front leg","right front hoove"}), ({ }), BODYPART_SUPPORTING }),
"left front leg"  : ({ ({"left upper front leg","left front hoove"}), ({ }), BODYPART_SUPPORTING }),
"right hind leg"  : ({ ({"right upper hind leg","right hind hoove"}), ({ }), BODYPART_SUPPORTING }),
"left hind leg"   : ({ ({"left upper hind leg","left hind hoove"}), ({ }), BODYPART_SUPPORTING }),
]),

BT_MAMMAL : ([
"head"            : ({ ({"head"}), ({"neck","torso","right front leg","left front leg","right hind leg","left hind leg"}), BODYPART_CAPITAL }),
"neck"            : ({ ({"neck"}), ({"torso","right front leg","left front leg","right hind leg","left hind leg"}), BODYPART_CAPITAL }),
"torso"           : ({ ({"chest","stomach","rear"}), ({"right hind leg","left hind leg"}), BODYPART_HUB }),
"right front leg" : ({ ({"right upper front leg","right front paw"}), ({ }), BODYPART_SUPPORTING }),
"left front leg"  : ({ ({"left upper front leg","left front paw"}), ({ }), BODYPART_SUPPORTING }),
"right hind leg"  : ({ ({"right upper hind leg","right hind paw"}), ({ }), BODYPART_SUPPORTING }),
"left hind leg"   : ({ ({"left upper hind leg","left hind paw"}), ({ }), BODYPART_SUPPORTING }),
]),

]);

mapping natural_weapons = ([
"humanoid" : ([ "right punch" : ({ 20, DT_IMPACT, "right hand", "punch", "close", NAT_BLOCK }),
   		        "left punch"  : ({ 20, DT_IMPACT, "left hand", "punch", "close", NAT_BLOCK }),
				"right kick"  : ({ 30, DT_IMPACT, "right foot", "kick", "close", NAT_NOBLOCK }),
                "left kick"   : ({ 30, DT_IMPACT, "left foot", "kick", "close", NAT_NOBLOCK }),
		     ]),

"brate" : ([ "right punch" : ({ 20, DT_IMPACT, "right hand", "punch", "close", NAT_BLOCK }),
			 "left punch"  : ({ 20, DT_IMPACT, "left hand", "punch", "close", NAT_BLOCK }),
             "right kick"  : ({ 30, DT_IMPACT, "right foot", "kick", "close", NAT_NOBLOCK }),
             "left kick"   : ({ 30, DT_IMPACT, "left foot", "kick", "close", NAT_NOBLOCK }),
             "right claw"  : ({ 20, DT_CUT, "right hand", "claw", "close", NAT_NOBLOCK }),
             "left claw"   : ({ 20, DT_CUT, "left hand", "claw", "close", NAT_NOBLOCK }),
			 "fangs"       : ({ 20, DT_STAB, "head", "bite", "close", NAT_NOBLOCK }),
          ]),

"goat" : ([ "butt" 			  :	({ 45, DT_IMPACT, "head", "butt", "close", NAT_NOBLOCK }),
			"right back kick" : ({ 35, DT_IMPACT, "right hind hoove", "kick", "close", NAT_NOBLOCK }),
			"left back kick"  : ({ 35, DT_IMPACT, "left hind hoove", "kick", "close", NAT_NOBLOCK }),
		 ]),

"feline" : ([ "left paw"  : ({ 40, DT_CUT, "left front paw", "claw", "close", NAT_NOBLOCK }),
              "right paw" : ({ 40, DT_CUT, "right front paw", "claw", "close", NAT_NOBLOCK }),
              "fangs"     : ({ 50, DT_STAB, "head", "bite", "close", NAT_NOBLOCK }),
           ]),
]);

mapping initial_skills = ([
"human" : ([ "punch" : ({ 15000, 15000 }),
			 "kick"  : ({ 5000, 5000 }),
           	 "dodge" : ({ 2000, 2000 }),
             "throwing" : ({ 20000, 20000 }),
          ]),

"dwarf" : ([ "punch" : ({ 10000, 10000 }),
             "dodge" : ({ 10000, 10000 }),
             "axes" : ({ 30000, 30000 }),
             "hammers" : ({ 25000, 25000 }),
             "polearms" : ({ 10000, 10000 }),
             "crossbows" : ({ 10000, 10000 }),
             "picking" : ({ 10000, 10000 }),
             "mineral lore" : ({ 0, 20000 }),
             "true knowledge of earth" : ({ 5000, 5000 }),
           ]),
            
"brate" : ([ "punch" : ({ 35000, 35000 }),
			 "kick" : ({ 5000, 5000 }),
             "claw" : ({ 40000, 40000 }),
             "bite" : ({ 30000, 30000 }),
			 "berserker charging" : ({ 20000, 20000 }),
          ]),

"goat" : ([ "butt" : ({ 20000, 20000 }),
			"kick" : ({ 10000, 10000 }),
			"berserker charging" : ({ 8500, 8500 }),
		 ]),

"tiger" : ([ "claw" : ({ 500000, 500000 }),
             "bite" : ({ 500000, 500000 }),
          ]),

"cat" : ([ "claw" : ({ 10000, 10000 }),
           "bite" : ({ 10000, 10000 }),
        ]),
]);

mapping races = ([

/* humanoids */
"human" : ({ BT_HUMANOID, CS_HUMANOID, C_WHITE, ({ 10,10,10,10,10,10,10,10,10 }), "humanoid", ({ GENDER_MALE, GENDER_FEMALE }) }),
"elf"   : ({ BT_HUMANOID, CS_HUMANOID, C_CYAN, ({ 9,13,9,13,13,16,14,12,13 }), "humanoid", ({ GENDER_MALE, GENDER_FEMALE }) }),
"orc"   : ({ BT_HUMANOID, CS_HUMANOID, C_GREEN, ({ 14,8,10,12,9,10,8,10,6 }), "humanoid", ({ GENDER_MALE, GENDER_FEMALE }) }),
"troll" : ({ BT_HUMANOID, CS_HUMANOID, C_DARK_GRAY, ({ 18,5,14,20,6,4,6,12,4 }), "humanoid", ({ GENDER_MALE, GENDER_FEMALE }) }),
"dwarf" : ({ BT_HUMANOID, CS_HUMANOID, C_RED, ({ 12,11,12,10,6,10,10,12,8 }), "humanoid", ({ GENDER_MALE, GENDER_FEMALE }) }),
"brate" : ({ BT_HUMANOID, CS_HUMANOID, C_BROWN, ({ 16,4,17,13,4,9,9,12,7 }), "brate", ({ GENDER_MALE }) }),
"dryad" : ({ BT_HUMANOID, CS_HUMANOID, C_LIGHT_GREEN, ({ 6,11,8,12,14,11,10,11,16 }), "humanoid", ({ GENDER_FEMALE }) }),

/* hooved animals */
"goat"  : ({ BT_HOOVED, CS_MAMMAL, C_LIGHT_GRAY, ({ 5,2,12,12,8,2,2,4,3 }), "goat", ({ GENDER_MALE, GENDER_FEMALE }) }),

/* small mammals */
"cat"   : ({ BT_MAMMAL, CS_MAMMAL, C_DARK_GRAY, ({ 2,2,2,5,16,5,5,14,15 }), "feline", ({ GENDER_MALE, GENDER_FEMALE }) }),

/* large mammals */
"tiger" : ({ BT_MAMMAL, CS_LARGE_MAMMAL, C_DARK_GRAY, ({ 30,2,25,14,18,5,5,14,15 }), "feline", ({ GENDER_MALE, GENDER_FEMALE }) }),

/* monsters */
"basilisk" : ({ BT_REPTILE, CS_REPTILE, C_DARK_GRAY, ({ 4,3,3,10,7,3,3,16,2 }), "basilisk", ({ GENDER_MALE, GENDER_FEMALE }) }),
"greater demon" : ({ BT_HUMANOID, CS_DEMON, C_RED, ({ 150,12,130,140,110,120,120,180,2 }), "humanoid", ({ GENDER_MALE, GENDER_FEMALE }) }),

/* ethereal undead */
"shadow" : ({ BT_HUMANOID, CS_ETHEREAL_UNDEAD, C_DARK_GRAY, ({ 8,10,8,8,14,11,10,12,1 }), "humanoid", ({ GENDER_MALE, GENDER_FEMALE }) }),
]);

string
query_random_race()
{
   string *k = keys(races);
   return k[random(sizeof(k))];
}

mapping
query_races()
{
   return races;
}

int
query_bodytype(string race)
{
   return races[race][I_BODYTYPE];
}

int
query_gridchar(string race)
{
   return races[race][I_GRIDCHAR];
}

int
query_gridcolor(string race)
{
   return races[race][I_GRIDCOLOR];
}

int *
query_stats(string race)    /* This was a pointer to a race mapping element */
{                           
   int i;
   int *temp = allocate(9);
   for (i=0;i<A_MAX;i++)
	 temp[i] = races[race][I_STATS][i];
   return temp;
   /* return races[race][I_STATS]; */
}

string
query_natweapon_index(string race)
{
   return races[race][I_NATWEAP];
}

int *
query_genders(string race)
{
   return races[race][I_GENDERS];
}

mapping
query_natural_weapons()
{
   return natural_weapons;
}

mapping
query_initial_skills()
{
   return initial_skills;
}

mapping
query_bodytypes()
{
   return bodytypes;
}

mapping
query_hitlocs()
{
   return hitlocs;
}
