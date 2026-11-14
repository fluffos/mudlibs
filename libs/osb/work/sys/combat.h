#ifndef _COMBAT_
#define _COMBAT_ 1

#include "equipment.h"

// Path defines for /obj/weapons
#define WEAPONS_BASE    "/obj/weapons/"
#define W_ARCHERY(x)    WEAPONS_BASE+"archery/"+x
#define W_AXES(x)       WEAPONS_BASE+"axes/"+x
#define W_BULLETS(x)    WEAPONS_BASE+"bullets/"+x
#define W_CHAINS(x)     WEAPONS_BASE+"chains/"+x
#define W_CLUBS(x)      WEAPONS_BASE+"clubs/"+x
#define W_DISTANTS(x)   WEAPONS_BASE+"distants/"+x
#define W_HAMMERS(x)    WEAPONS_BASE+"hammers/"+x
#define W_HANDS(x)      WEAPONS_BASE+"hands/"+x
#define W_INFANTRIES(x) WEAPONS_BASE+"infantries/"+x
#define W_KNIFES(x)     WEAPONS_BASE+"knifes/"+x
#define W_RAPIERS(x)    WEAPONS_BASE+"rapiers/"+x
#define W_SPEARS(x)     WEAPONS_BASE+"spears/"+x
#define W_SWORDS(x)     WEAPONS_BASE+"swords/"+x
#define W_STAFFS(x)     WEAPONS_BASE+"staffs/"+x
#define W_WHIPS(x)      WEAPONS_BASE+"whips/"+x
#define W_SPECIAL(x)    WEAPONS_BASE+"special/"+x
#define W_UNIQUE(x)     WEAPONS_BASE+"unique/"+x

// Path defines for /obj/armours
#define ARMOURS_BASE    "/obj/armours/"
#define A_AMULETS(x)    ARMOURS_BASE+"amulets/"+x
#define A_BELTS(x)      ARMOURS_BASE+"belts/"+x
#define A_BOOTS(x)      ARMOURS_BASE+"boots/"+x
#define A_CLOAKS(x)     ARMOURS_BASE+"cloaks/"+x
#define A_GLOVES(x)     ARMOURS_BASE+"gloves/"+x
#define A_HELMETS(x)    ARMOURS_BASE+"helmets/"+x
#define A_MAILS(x)      ARMOURS_BASE+"mails/"+x
#define A_RINGS(x)      ARMOURS_BASE+"rings/"+x
#define A_SHIELDS(x)    ARMOURS_BASE+"shields/"+x
#define A_SKINS(x)      ARMOURS_BASE+"skins/"+x
#define A_TROUSERS(x)   ARMOURS_BASE+"trousers/"+x
#define A_SPECIAL(x)    ARMOURS_BASE+"special/"+x
#define A_UNIQUE(x)     ARMOURS_BASE+"unique/"+x


// Generic ID for arrows
#define GENERIC_ARROW_ID " generic arrow"

// Party combat
#define PARTYOBJECT "/std/player/bin/party"

// Class scale for weapons

#define MAX_CLASS   20  // Nominal maximum value
#define CLASS_SCALE  5  // Scalefactor to cvert class values <-> 0..100 range.
 
// Combat skills, partially used as weapontypes as well

#define CS_HAND      "CsHand"     // Martial arts, also defensive
#define CS_KNIFE     "CsKnife"    // Knifes
#define CS_SWORD     "CsSword"    // Swords
#define CS_AXE       "CsAxe"      // Axes
#define CS_SPEAR     "CsSpear"    // Spears
#define CS_CLUB      "CsClub"     // Clubs
#define CS_STAFF     "CsStaff"    // Combat staffs
#define CS_WHIP      "CsWhip"     // Whips
#define CS_INFANTRY  "CsInfantry" // Halberds and other infantry weapons
#define CS_CHAIN     "CsChain"    // Morningstars and other chained weapons
#define CS_RAPIER    "CsRapier"   // piercing Swords
#define CS_HAMMER    "CsHammer"   // Hammers
#define CS_DISTANT   "CsDistant"  // just a skill: Bows etc
#define CS_BULLET    "CsBullet"   // just a type: Bullets, Arrows, etc

// Defensive combat skills

#define CS_DODGE     "CsDodge"

// Armourtypes
// Negative types protect the living everywhere (mostly non-physical)
// Positive types are also target zones for physical attacks.
// 0 is illegal.

#define AT_SKIN      -1  // internally used by livings!
#define AT_RING      -2
#define AT_AMULET    -3
#define AT_BELT      -4

#define AT_BOOTS      1  // Feet
#define AT_CLOAK      2  // Remaining open skin
#define AT_MAIL       3  // Body
#define AT_GLOVES     4  // Hands
#define AT_HELMET     5  // Head
#define AT_SHIELD     6  // Arms
#define AT_TROUSERS   7  // Legs

#define AT_HITZONES   7  // Number of target zones

// Damage types
// Negative types affect the whole victim

#define DT_SLASH     1   // a sword does slash
#define DT_BLUDGEON  2   // Damage done by concentrated impact (clubs)
#define DT_PIERCE    3   // spears are piercing weapons
#define DT_FIRE      4   // physical heat
#define DT_COLD      5   // physical cold
#define DT_WATER     6   // water??
#define DT_GAS       7   // poison gas
#define DT_ZAP	     8   // finger of death
#define DT_ELECTRO   9   // 
#define DT_ACID     10   //
#if 0
#define DT_POISON   -1   // all sorts of poison
#define DT_PSYCHO   -2   // mental attack
#else
#define DT_POISON   11   // all sorts of poison
#define DT_PSYCHO   12   // mental attack
#endif
#define DT_NOAIR    13   // suffocation

#define DT_CONV      3   // Number of 'conventional' damages
#define DT_MAGIC     4   // First non-conventional damage

// Some defines for experience points handling

#define MAX_XP_ADD   50000
#define XP_GAIN(x)   ((x) / 35)
#define XP_DEATH(x)  (((x) * 2) / 3)

// Optional argument to QueryWimpy() to return the absolute value.

#define ABS_WIMPY 1

// ---------- Compatibility ----------

#define WT_SWORD    CS_SWORD
#define WT_AXE      CS_AXE
#define WT_CLUB     CS_CLUB
#define WT_SPEAR    CS_SPEAR
#define WT_KNIFE    CS_KNIFE
#define WT_STAFF    CS_STAFF
#define WT_WHIP     CS_WHIP
#define WT_INFANTRY CS_INFANTRY
#define WT_CHAIN    CS_CHAIN
#define WT_RAPIER   CS_RAPIER
#define WT_HAMMER   CS_HAMMER

#define DT_INTR 0
#define DT_CONVENTIONALS DT_CONV

#define VALID_WEAPON_TYPE(t) (member( \
	({WT_SWORD, WT_AXE, WT_CLUB, WT_SPEAR, WT_KNIFE, WT_STAFF, WT_INFANTRY\
         ,WT_WHIP, WT_CHAIN, WT_RAPIER, WT_HAMMER }),t ) != -1)

#define VALID_ARMOUR_TYPE(t) (member( \
	({AT_MAIL, AT_HELMET, AT_RING, AT_GLOVES, AT_CLOAK, AT_BOOTS,\
	AT_SHIELD, AT_AMULET, AT_TROUSERS, AT_BELT, "armour", "helmet",\
	"amulet", "ring", "gloves", "cloak", "boots", "shield"}) \
	, t) != -1)

#ifndef WEAPON_CLASS_OF_HANDS
#define WEAPON_CLASS_OF_HANDS	1
#endif
#ifndef ARMOUR_CLASS_OF_BASE
#define ARMOUR_CLASS_OF_BARE	0
#endif

#ifndef HAND_SHORT
#define HAND_SHORT 0
#define HAND_WEAPON 1
#define HAND_WC 2
#endif

#if 0
/* The decceleration values for combat attribute learning. */
#define HP_DCC     200
#define MAX_HP_DCC 400
#define SP_DCC     200
#define MAX_SP_DCC 400
#define DEX_DCC    400
#define MAG_DCC    400

/* The threshold when we start learning something. */
#define MAX_HP_THRESHOLD 900 // 0..1024
#define DEX_THRESHOLD    900 // 0..1024
#define MAG_THRESHOLD    900 // 0..1024

#endif

#endif
