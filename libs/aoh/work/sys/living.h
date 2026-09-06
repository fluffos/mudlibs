#ifndef _LIVING_
#define _LIVING_

#include "combat.h"
#include "health.h"
#include "attributes.h"

// Stat scale for

#define MAX_STAT   20  // Nominal maximum value
#define STAT_SCALE  5  // Scalefactor to cvert stat values <-> 0..100 range.
 
//  Default stats for npc

//-----------------------------------------------------------------------
// Return codes of fask(str, 1)

#define ASK_OK           1  // Question understood and answered
#define ASK_NO_ARG      -1  // No arg given
#define ASK_CANT_PARSE  -2  // Arg string not in required syntax
#define ASK_SHRUG       -3  // Answer not known.

//-----------------------------------------------------------------------
// Standard heart_beat() functions.

#define HEART_BODY    "body_heartbeat"
#define HEART_COMBAT  "combat_heartbeat"

//-----------------------------------------------------------------------
// Entries in the Hands mapping

#define HAND_DAM  0  // Hand damage, or WC for normal hands
#define HAND_OBJ  1  // 0 for free hands, 1 for 'claws', 'obj' for used hands

#define HAND_SIZE   2

// Default Hand class

#ifndef HAND_WC
#define HAND_WC 10
#endif

//-----------------------------------------------------------------------
// Values for the third parameter of Defend()

#define DEFEND_F_NOLIV  (1<<0)  // Attacker is not a living and will not
                                // be put into the list of enemies
#define DEFEND_F_NOMSG  (1<<1)  // Suppress Combat messages

// Most used value combinations

#define DEFEND_NOLIV  DEFEND_F_NOLIV
#define DEFEND_NOMSG  DEFEND_F_NOMSG

//-----------------------------------------------------------------------
// Entries in the P_ARMOURS mapping (indexed by Armourtype)

#define ARMOUR_OBJ  0  // The actual armour
#define ARMOUR_MSG  1  // Armour has 'DefenseMsg' function

#define ARMOUR_SIZE 2

//-----------------------------------------------------------------------
// Entries in the P_WEAPONS mapping (indexed by object)

#define WEAPON_TYPE  0  // the weaponskill/-type
#define WEAPON_MOD   1  // Weapon has 'ModifyAttack' function

#define WEAPON_SIZE  2

//-----------------------------------------------------------------------
// Entries in the P_Enemies mapping (indexed by object)

#define ENEMY_STATUS  0

#define ENEMY_SIZE  1

#define ENEMY_FORGET  300  // Seconds between 'forgets' of enemies

//-----------------------------------------------------------------------
// Gender

#ifndef GENDER_OTHER

#define GENDER_UNSET   0
#define GENDER_MALE    1
#define GENDER_FEMALE  2
#define GENDER_OTHER   3
#define GENDER_NEUTER  GENDER_OTHER

#endif

//-----------------------------------------------------------------------
// Living states

#ifndef LSTATE_NORMAL

#define LSTATE_NORMAL  0
#define LSTATE_GHOST   1
#define LSTATE_FROG    2

#endif

//-----------------------------------------------------------------------
// (Over)Load handling

#define LOAD_LIMIT(max) ((max * 9)/13)

#define LOAD_THRESH     80
#define LOAD_DTHRESH    30
#define LOAD_MINHP(hp)  (hp / 20)

//-----------------------------------------------------------------------
// Compatibility

#ifndef WEAPON_CLASS_OF_HANDS
#define WEAPON_CLASS_OF_HANDS	1
#endif

#define NEUTER GENDER_OTHER
#define MALE   GENDER_MALE
#define FEMALE GENDER_FEMALE

#endif
