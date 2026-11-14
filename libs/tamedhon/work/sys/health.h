// SilberLand MUDlib
//
// sys/health.h -- healing constants...
//
// $Date: 1997/11/25 12:32:56 $
/* $Revision: 1.2 $
 * $Log: health.h,v $
 * Revision 1.2  1997/11/25 12:32:56  Feyaria
 * HEAL_DELAY auf 3
 *
 * Revision 1.1  1997/11/25 12:30:41  Woody
 * Initial revision
 *
 */

#ifndef __HEALTH_H__
#define __HEALTH_H__

/*
 * health.h
 *
 * A configuration file for all food and drink stuff
 */

/* These are tune macros to determine the actual effect of food, */
/* drink and alcohol */
#define ALOCHOL_VALUE(strength) strength
#define DRINK_VALUE(strength) strength
#define FOOD_VALUE(strength) strength

/* How fast alcohol wears off and drink and food are reduced */
#define ALCOHOL_DELAY 4 /* quite fast */
#define DRINK_DELAY 10 /* quite slow */
#define FOOD_DELAY 10 /* quite slow */
#define HEAL_DELAY 3 /* quite fast */
#define THEAL_DELAY 1 /* (multiplies with HEAL_DELAY !) */
#define TEMP_DELAY 4 /* quite fast */

#define MAX_POISON 14
#define POISON_DELAY 4
#define POISON_MERCY_DELAY 3

#endif
