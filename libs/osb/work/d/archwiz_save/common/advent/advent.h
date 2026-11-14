#ifndef _ARCHWIZ_ADVENT_H_
#define _ARCHWIZ_ADVENT_H_ 1

#include "path.h"

// --- Some definitions ---

#define A_ADVDATA  "AdventData"
  // Attribute in the player to store the persistant data

#define P_ADVROOM  "AdventRoom"
  // Mandatory property set in all Advent rooms.

#define P_NONPC  "AdventRoomNoNPC"
  // Property set in rooms allowing no Advent NPC to go in

#define P_FOOCOUNT "AdventFooCount"
  // Property in the player, counting which of the 'fee fie foe foo'
  // she already said.

#define P_DWARVES  "AdventDwarves"
  // Property in the player, counting how many dwarves he killed yet.

#define P_KNOWNBIRDS  "AdventKnownBirds"
  // Property in the snake, showing which birds it isn't afraid of.

#define P_NODWARF  "AdventNoDwarf"
  // Property for rooms where the dwarf mustn't appear.

#define P_NOORIG "AdventNoOrig"
  // Property for rooms which details are always to appear, even if the
  // player runs around in 'original' mode.

#define P_OILED  "AdventDoorOiled"
  // Property of o/rustydoor, non-zero if the hinges are oiled.

#define P_ORIGLIST "AdventOrigList"
  // List of a room's details/smells/noises which exist in the original game.

#define P_TAMER "AdventBearTamer"
  // Property set in the Cave Bear, denoting the player who tamed the bear.

#define P_TREASURE  "AdventTreasure"
  // Property set in Treasure objects to their resp. treasure marker flag

#define P_WATEREXTRA  "AdventWaterExtra"
  // Property in o/water for an additional text for the P_LONG.


// --- Ids and Codes ---
#define ADV_GRATE_KEYCODE "\nadventkeys"
  // The code for the keys to open then entrance grate.

#define ADV_BEANSTALK  "\nbeanstalk"
  // The special id for the beanstalk, also used as property.

#define ADV_BEAR  "\ncavebear"
  // The special id for the cavebear, also used as property.

#define ADV_BLACKROD "\nblackrod"
  // The special id for the black rod, also used as property.

#define ADV_CHAIN  "\nchain"
  // The special id for the golden chain, also used as property.

#define ADV_CLAM "\nclam"
  // The special id for the enormous clam, also used as property.
  // Value 1: the clam, unopened yet.
  // Value 2: the clam, once opened and thus pearl-less.

#define ADV_DRAGON  "\ndragon"
  // The special id for the dragon, also used as property.

#define ADV_DWARF  "\ndwarf"
  // The special id for the dwarf, also used as property.

#define ADV_LITTLEBIRD  "\nlittlebird"
  // The special id for the little bird, also used as property.

#define ADV_NEST  "\nnest"
  // The special id for the nest of golden eggs, also used as property.

#define ADV_NUGGET  "\nnugget"
  // The special id for the nugget, also used as property.

/* #define ADV_QUESTNAME   "advent" */
  // The id-string denoting the mini-quest. Used in r/trdump.c.
  // If this define doesn't exist, the quest code is deactivated.

#define ADV_SNAKE  "\ngreensnake"
  // The special id for the green snake, also used as property.

#define ADV_TROLL  "\nbridgetroll"
  // The special id for the troll, also used as property.

#define ADV_TRIDENT  "\ntrident"
  // The special id for the jeweled trident, also used as property.

#define ADV_DWARVES 5
  // Number of dwarves a player has to kill at max.


// --- Bitflags ---
// Treasure marker flags
#define F_NONE      0  // The 'No treasure' object
#define F_PCHEST    1  // The Pirate's Treasure Chest (Pirate's Dead End)
#define F_NUGGET    2  // The Nugget of Gold (Nugget Room)
#define F_DIAMONDS  3  // Some Diamonds (West Side of Fissure)
#define F_SILVER    4  // Bars of Silver (Low N/S Passage)
#define F_JEWELRY   5  // Precious Jewelry (South Side Chamber)
#define F_COINS     6  // Rare Coins (West Side Chamber)
#define F_RUG       7  // Persian Rug (Secret Canyon)
#define F_NEST      8  // Nest of Golden Eggs (Giant Room)
#define F_TRIDENT   9  // Jeweled Trident (Cavern with Waterfall)
#define F_VASE     10  // Ming Vase (Oriental Room)
#define F_EMERALD  11  // Large Emerald (Plover Room)
#define F_PYRAMID  12  // Platinum Pyramid (Dark Room)
#define F_PEARL    13  // Large Pearl (Shell Room/Cul De Sac)
#define F_SPICES   14  // Rare Spices (Chamber of Boulders)
#define F_CHAIN    15  // Golden Chain (Cave Bear, Barren Room)

#define F_NUM_TREASURES 15  // Total number of treasures

// Various flags
#define F_XYZZY    100  // Command 'xyzzy' enabled
#define F_PLUGH    101  // Command 'plugh' enabled
#define F_IN_MISTS 102  // Reached the Hall of Mists
#define F_SNAKE    103  // Scared the Snake away
#define F_DRAGON   104  // Killed the Dragon with bare hands
#define F_TROLL    105  // Tricked out the Troll
#define F_FIEFOO   106  // Magic formula 'fee fie foe foo' enabled
#define F_WITSEND  107  // Dropped the 'Spelunker Today' at Witt's End.
#define F_PIRATE   108  // Spotted the Pirate's Treasure Chest.
#define F_BEAR     110  // Tamed the bear.
#define F_MACHINE  111  // Found the vending machine
#define F_PIRATE_S 112  // Player spotted the Pirate
#define F_PIRATE_R 113  // Player had been robbed by the Pirate
#define F_DWARF    114  // Dwarf threw axe at player.
#define F_TERSE    115  // Player prefers the original details
#define F_SOLVED   116  // Player solved the cave (this one is magic!)

#endif
