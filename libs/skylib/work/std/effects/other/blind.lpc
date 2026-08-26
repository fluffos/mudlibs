/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: blind.c,v 1.1 1998/01/06 04:20:30 ceres Exp $
 * $Log: blind.c,v $
 * Revision 1.1  1998/01/06 04:20:30  ceres
 * Initial revision
 * 
*/
/**
 * This is the effect skelton docs.  This effect
 * has a classification of "mind.avoidance".
 * <p>
 * Describe the arguments in here.
 * @classification mind.avoidance
 * @see help::effects
 */
/* This effect blinds you. Unpleasant if used at the wrong time */
 
/* A quantity of 100 gives a blindness effect of about 40 seconds. */

inherit "/std/effects/basic";
#include "effect.h"
#include "path.h"

void create() {
  set_boundaries( ({ 21, 31 }), ({ 40, 70 }) );
}  

int query_pass_through(int *coord){
   return 30;
}

mixed *query_attrs( int *coord ) {
   int total;
   
   total = distance_within_region(coord) * 100 / 50;
   if (total > 100) total = 100;

   return ({ 60, 30, 
          ({ }), 
          ({ ({"dull brown", total }) }),
          ({ ({"oranges", total/2 }) }),
          ({ ({"oranges", total }) })
          });
}

void action_drunk( object ob, int *coord, int quantity ) {
   int str;
   object shadow;

   str = (distance_within_region(coord) * quantity) / 25;
   shadow = clone_object("/std/spells/priest/items/blind_shadow");
   shadow->setup_shadow(this_player());
   shadow->remove_shadow(str);
   return ;
} 

