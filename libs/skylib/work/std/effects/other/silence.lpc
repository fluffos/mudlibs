/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: silence.c,v 1.1 1998/01/06 04:20:30 ceres Exp $
 * $Log: silence.c,v $
 * Revision 1.1  1998/01/06 04:20:30  ceres
 * Initial revision
 * 
*/
/**
 * This is the effect skelton docs.  This effect
 * has a classification of "covert.shadowing".
 * <p>
 * Describe the arguments in here.
 * @classification covert.shadowing
 * @see help::effects
 */
/* This effect steals your voice. */
 
/* A quantity of 100 gives a silence effect of about 40 seconds. */

inherit "/std/effects/basic";
#include "effect.h"
#include "path.h"

void create() {
   set_boundaries( ({ -40, -10 }), ({ -15, -5 }) );
}  

int query_pass_through( int *coord ){
   return 25;
}

mixed *query_attrs( int *coord ){
   int total;
   
   total = distance_within_region(coord) * 100 / 25;
   if (total > 100) total = 100;

   return ({ 20, 30, 
          ({ }), 
          ({ ({"sparkling blue", total }) }),
          ({ ({"fresh mountain air", total/2 }) }),
          ({ ({"strawberries", total/2 }) })
          });
}

void action_drunk( object ob, int *coord, int quantity ) {
   int str;
   object shadow;

   str = (distance_within_region(coord) * quantity) / 25;
   shadow = clone_object("/std/spells/priest/items/silence_shadow");
   shadow->setup_shadow(this_player());
   shadow->remove_shadow(str);
   return ;
} 

