// Updated 09-Sep-98, Doomdark

#ifndef ARMOUR_H
#define ARMOUR_H

#ifndef _SERVERS_H
#include "servers.h"
#endif

#define	ARM_SP_BOOST_STAT		(1 << 8)
#define	ARM_SP_DRAIN_STAT		(1 << 9)
#define	ARM_SP_CAUSE_CONDITION		(1 << 10)
#define	ARM_SP_RESIST_CONDITION		(1 << 11)

#define	ARMOUR_FILE	"/lib/armour"

#define F_ARMOUR_TYPE_NAME(x)\
  ({"amulet", "armour", "belt", "boot", "bracers",\
    "cloak", "gloves", "helmet", "leggings", "mask", "ring",\
    "shield", "necklace"}) [((x <= 12) ? x : 1)]

#define	ARMOUR_TYPE_AMULET      "amulet"
#define	ARMOUR_TYPE_BODY_ARMOUR "armour"
#define	ARMOUR_TYPE_BELT        "belt"
#define	ARMOUR_TYPE_BOOTS       "boot"
#define	ARMOUR_TYPE_BRACERS     "bracers"
#define	ARMOUR_TYPE_CLOAK       "cloak"
#define	ARMOUR_TYPE_GLOVES      "gloves"
#define	ARMOUR_TYPE_HELMET      "helmet"
#define	ARMOUR_TYPE_LEGGINGS    "leggings"
#define	ARMOUR_TYPE_MASK        "mask"
#define	ARMOUR_TYPE_RING        "ring"
#define	ARMOUR_TYPE_SHIELD      "shield"
#define	ARMOUR_TYPE_NECKLACE    "necklace"

#endif
