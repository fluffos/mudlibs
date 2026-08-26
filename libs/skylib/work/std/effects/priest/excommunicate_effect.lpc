/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: excommunicate_effect.c,v 1.1 1998/01/06 04:15:00 ceres Exp $
 * $Log: excommunicate_effect.c,v $
 * Revision 1.1  1998/01/06 04:15:00  ceres
 * Initial revision
 * 
*/
/**
 * This is the effect skelton docs.  This effect
 * has a classification of "priest.excommunicate".
 * <p>
 * Describe the arguments in here.
 * <p>
 * This effect has a shadow associated with it.
 * @classification priest.excommunicate
 * @see help::effects
 */
#include <effect.h>
#include "path.h"

int query_secs_between_hb() { return 1; }

/** @ignore yes */
string query_classification() { return "priest.excommunicate"; }

/** @ignore yes */
int beginning(object player, mixed arg) { 
   tell_object(player, "You have been excommunicated!\n");
   return arg;
}

int effect_heart_beat(object player, int hbnum, mixed arg, int id){
   /* test for the duration finished yet */

   if (hbnum == arg) return REMOVE_THIS_EFFECT;
   return arg;
}

/** @ignore yes */
void end(object player) { 
   tell_object(player, "You feel the wrath of the gods lifting slightly.\n");
}

/** @ignore yes */
string query_shadow_ob() { return SHADOWS+"excommunicate_shadow"; }
