#ifndef ATTRIBUTES_H
#define ATTRIBUTES_H 1

#include "/neu/sys/properties.h"

/* If we know we deal with a softcoded attribute. */
#define SOFTCODED 1

/*===========================================================================
 * The default 'too dark' and 'too bright' message for the see() function.
 */
#define TOO_DARK_MSG   "You can't see anything because it's too dark.\n"
#define TOO_BRIGHT_MSG "You can't see anything because it's too bright.\n"

/*===========================================================================
 * The default and interchangeable attributes.
 */

// Not builtin in std/living
#define A_CORPSE        "Corpse"
#define A_GUILD         P_GUILD
#define A_SIZE          P_SIZE

// --- std/living/body
#define A_HP            "HP"
#define A_MAX_HP        "MaxHP"
#define A_RATE_HP       "RateHP"
#define A_POISON        "Poison"
#define A_MAX_POISON    "MaxPoison"
#define A_RATE_POISON   "RatePoison"
#define A_SP            "SP"
#define A_MAX_SP        "MaxSP"
#define A_RATE_SP       "RateSP"
#define A_WIMPY         "Wimpy"
#define A_XP            "XP"

// --- std/living/combat ---
#define A_ARMOURS       "Armours"
#define A_COMBAT_STYLE  "CombatStyle"
#define A_DEFENSE       P_DEFENSE
#define A_WEAPONS       "Weapons"

// --- std/living/description ---
#define A_ACTIONS       "Actions"
#define A_ADS           P_ADS
#define A_ALIGN         "Align"
#define A_FROG          "Frog"
#define A_GENDER        "Gender"
#define A_GHOST         "Ghost"
#define A_IDS           P_IDS
#define A_INVIS         "Invis"
#define A_INT_LONG      P_INT_LONG
#define A_INT_NOISE     P_INT_NOISE
#define A_INT_SMELL     P_INT_SMELL
#define A_INT_SHORT     P_INT_SHORT
#define A_IVISION       "IVision"
#define A_MAGIC_DEFENSE "MagicDefense"
#define A_LEVEL         "Level"
#define A_LONG          P_LONG
#define A_LSTATE        "LState"
#define A_MMSGIN        "MMsgIn"
#define A_MMSGOUT       "MMsgOut"
#define A_MSGIN         "MsgIn"
#define A_MSGOUT        "MsgOut"
#define A_NAME          "Name"
#define A_NOISE         P_NOISE
#define A_RACE          "Race"
#define A_SHORT         P_SHORT
#define A_SMELL         P_SMELL
#define A_UVISION       "UVision"

// --- std/living/enemies ---
#define A_AGGRESSIVE    "Aggressive"
#define A_ATTACK_CHANCE "AttackChance"

// --- std/living/hands ---
#define A_FREE_HANDS    "FreeHands"
#define A_HANDS         "Hands"

// --- std/living/moving
#define A_GO_CHANCE     "GoChance"

// --- std/living/stats
#define A_CHA           "Cha"
#define A_CON           "Con"
#define A_DEX           "Dex"
#define A_GNO           "Gno"
#define A_INT           "Int"
#define A_STR           "Str"

// --- std/npc/view
#define A_BRIEF         "Brief"
#define A_OBVIOUS       "Obvious"

// --- std/player/skills
#define A_STAT_DATA     "StatData"

//---------------------------------------------------------------------------

/* The presay of the living.
 * softcoded - string
 */
#define A_PRESAY        "Presay"

/* The title of the living.
 * softcoded - string
 */
#define A_TITLE         "Title"

/* Current soaked value.
 * hardcoded - integer: 0..+100
 */
#define A_SOAKED        "Soaked"

/* Maximum soaked value.
 * hardcoded - integer: 0..+100
 */
#define A_MAX_SOAKED    "MaxSoaked"

/* Current alcohol level.
 * hardcoded - integer: 0..+100
 */
#define A_ALCOHOL       "Alcohol"

/* Maximum alcohol level.
 * hardcoded - integer: 0..+100
 */
#define A_MAX_ALCOHOL   "MaxAlcohol"

/* Current food level.
 * hardcoded - integer: 0..+100
 */
#define A_FOOD          "Food"

/* Maximum food level.
 * hardcoded - integer: 0..+100
 */
#define A_MAX_FOOD      "MaxFood"

//===========================================================================
// An array with the names of all default (builtin) attributes.

#define LIVING_ATTRS \
  ({ A_HP, A_MAX_HP, A_RATE_HP \
   , A_POISON, A_MAX_POISON, A_RATE_POISON \
   , A_SP, A_MAX_SP, A_RATE_SP \
   , A_WIMPY, A_XP \
   , A_ARMOURS, A_DEFENSE, A_WEAPONS \
   , A_ACTIONS, A_ADS, A_ALIGN, A_GENDER, A_LSTATE, A_IDS, A_INVIS \
   , A_INT_LONG, A_INT_NOISE, A_INT_SMELL, A_INT_SHORT \
   , A_IVISION, A_LEVEL, A_LONG \
   , A_MMSGIN, A_MMSGOUT, A_MSGIN, A_MSGOUT \
   , A_NAME, A_NOISE, A_RACE, A_SHORT, A_SMELL \
   , A_UVISION, A_AGGRESSIVE, A_ATTACK_CHANCE \
   , A_HANDS, A_GO_CHANCE \
   })

#endif
