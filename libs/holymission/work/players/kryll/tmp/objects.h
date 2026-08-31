#ifndef __OBJECTS_H__

#define __OBJECTS_H__

#define MAX_WC       25
#define MAX_WEAP_MC  10
#define MAX_AC       10
#define MAX_ARM_MC   5

#define BLUDGEON              0
#define PIERCE                1
#define SLASH                 2
#define BLUDGEON_PIERCE       3
#define BLUDGEON_SLASH        4
#define PIERCE_SLASH          5
#define BLUDGEON_PIERCE_SLASH 6

#define NO_OF_WEAPON_TYPES    7

#define WEAPON_TYPES ({ "blugeoning", "piercing", "slashing",\
  "bludgeoning & piercing", "bludgeoning & slashing",\
  "piercing & slashing", "bludgeoning, piercing, and slashing" })

#define ARMOUR_TYPES ({ "other", "ring", "cloak", "robe", "helmet",\
  "amulet", "armour", "arm", "glove", "shield", "leg", "boot",\
  "guild", "glasses", "neck", "ear", "belt", "bracelet" })

#define MAX_ARMOUR_ACS ({ 2, 1, 1, 1, 2, 1, 10, 3, 1, 5, 3, 2,\
  3, 0, 1, 0, 1, 0 })

 
#endif // __OBJECTS_H__
