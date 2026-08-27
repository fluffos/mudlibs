/*
 * wa_types.h
 *
 * This file defines the different types of weapons and armour
 * and thier damage modifers. Any weapon or armour int the game
 * must be of one these types. No other are accepted.
 */

#ifndef WA_TYPES_DEF
#define WA_TYPES_DEF

/*
 * GUIDANCE FOR WEAPONS and GUIDANCE FOR ARMOURS
 *
 * Can be found under /doc/man/general/weapon and /doc/man/general/armour
 *
 */

/*
 * Sublocations for combat tools
 */
#define SUBLOC_WIELD  "wielded"
#define SUBLOC_WORNA  "worn_a"

/*
 * This defines the chance a recoverable weapon or armour has not to be
 * recovered. (/100)
 */
#define PERCENTAGE_OF_RECOVERY_LOST 30

/* Damage types */

#define W_IMPALE    1
#define W_SLASH     2
#define W_BLUDGEON  4

#define W_NO_DT     3

/*
 * The magic damage type is used to indicate that no ac will prevent
 * this type of attack.
 */
#define MAGIC_DT    8

#define W_HAND_HIT  15
#define W_HAND_PEN  6
#define A_NAKED_MOD ({ 0, 0, 0 })

#define W_MAX_HIT   ({ 100, 50, 90, 30, 60, 70, 30, 40 })
#define W_MAX_PEN   ({ 100, 50, 90, 30, 60, 70, 30, 40 })

/*
 * Tool slots for humanoids.
 *
 * The armourtype is a bitwise combination of these slots. Some of the
 * slots correspond to hitlocations.
 *
 * There is also a magic flag that can be set in the armourtype, indicating
 * that the armour is magically enhanced.
 */
#define TS_TORSO        2
#define TS_HEAD         4
#define TS_LEGS         8
#define TS_RARM         16
#define TS_LARM         32
#define TS_ROBE         64

#define TS_RHAND        128
#define TS_LHAND        256
#define TS_RWEAPON	512
#define TS_LWEAPON	1024
#define TS_RFOOT        2048
#define TS_LFOOT        4096
#define TS_WAIST	8192
#define TS_NECK		16384
#define TS_RFINGER	32768
#define TS_LFINGER  	65536
#define TS_RFOREARM	131072
#define TS_LFOREARM	262144

#define MAX_TS		262144


#define TS_HBODY        (TS_TORSO | TS_LEGS | TS_RARM | TS_LARM | TS_HEAD)

/* Weapon hand, only applicable to humanoids
 *
 * Some of these are used as attack id's
 */
#define W_RIGHT     TS_RWEAPON
#define W_LEFT      TS_LWEAPON
#define W_BOTH      (W_RIGHT | W_LEFT)
#define W_FOOTR     TS_RFOOT
#define W_FOOTL     TS_LFOOT

#define W_ANYH      0               /* These mark that any hand is possible */
#define W_NONE      0

#define W_NO_WH     6

/*
 * Hitlocations for humanoids
 *
 */
#define A_BODY      	TS_TORSO
#define A_TORSO     	TS_TORSO
#define A_HEAD      	TS_HEAD
#define A_NECK	    	TS_NECK
#define A_WAIST     	TS_WAIST

#define A_LEGS		TS_LEGS

#define A_R_ARM     	TS_RARM
#define A_L_ARM     	TS_LARM
#define A_ARMS     	(TS_RARM | TS_LARM)
#define A_ANY_ARM	(-TS_RARM)

#define A_R_FOREARM	TS_RFOREARM
#define A_L_FOREARM	TS_LFOREARM
#define A_FOREARMS	(TS_RFOREARM | TS_LFOREARM)
#define A_ANY_FOREARM	(-TS_RFOREARM)

#define A_R_HAND    	TS_RHAND
#define A_L_HAND    	TS_LHAND
#define A_HANDS    	(TS_RHAND | TS_LHAND)
#define	A_ANY_HAND	(-TS_RHAND)

#define A_R_FINGER  	TS_RFINGER
#define A_L_FINGER  	TS_LFINGER
#define A_FINGERS    	(TS_RFINGER | TS_LFINGER) 
#define A_ANY_FINGER	(-TS_RFINGER)
 
#define A_R_FOOT    	TS_RFOOT
#define A_L_FOOT    	TS_LFOOT
#define A_FEET      	(TS_RFOOT | TS_LFOOT)
#define A_ANY_FOOT	(-TS_RFOOT)

#define A_ROBE      	TS_ROBE

#define A_SHIELD    	-(TS_RWEAPON | TS_RFOREARM)
#define A_BUCKLER	-(TS_RFOREARM)


/*
 * Magic flag, this is used in armourtypes in combination with tool slots.
 * Note that this is not a slot, any number of magic armours can be used.
 *
 * Magical combat tools can be used without allocating a tool slot.
 * see (/std/combat/ctool.c)
 */
#define A_MAGIC     -2

#define A_NO_T      16

#define A_UARM_AC   1

#define A_MAX_AC    ({ 100, 100, 100, 100, 100, 100, 100, 100, \
		       100, 100, 100, 100, 100, 100, 100, 100 })

#define SH_PUKLERZ		0
#define SH_LEKKA		1
#define SH_TARCZA		2
#define SH_RYCERSKA		3
#define SH_DLUGA_RYCERSKA 	4
#define SH_PELNA_PIECHOTY 	5

#include "/config/sys/wa_types2.h"

#endif
