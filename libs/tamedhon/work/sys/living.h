// SilberLand MUDlib
//
// sys/living.h -- living header
//
// $Date: 1997/03/31 12:58:36 $
/* $Revision: 1.1 $
 * $Log: living.h,v $
 * Revision 1.1  1997/03/31 12:58:36  Woody
 * prepared for revision control
 *
 */

#include "/sys/living/life.h"
#include "/sys/living/attributes.h"
#include "/sys/living/put_and_get.h"
#include "/sys/living/combat.h"

#ifndef __LIVING_H__
#define __LIVING_H__

#define INTERVAL_BETWEEN_HEALING	10
#define WEAPON_CLASS_OF_HANDS		(3)
#define ARMOUR_CLASS_OF_BARE		0
#define KILL_NEUTRAL_ALIGNMENT		10
#define ADJ_ALIGNMENT(al)		((-al - KILL_NEUTRAL_ALIGNMENT)/4)
#define MAX_LIST			20
#define NAME_OF_GHOST			"some mist"

/* Hands */
#define HAND_SHORT 0
#define HAND_WEAPON 1
#define HAND_WC 2

#endif
