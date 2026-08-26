/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: hallucinate.c,v 1.1 1998/01/06 04:20:30 ceres Exp $
 * $Log: hallucinate.c,v $
 * Revision 1.1  1998/01/06 04:20:30  ceres
 * Initial revision
 * 
*/
/**
 * This is the effect skelton docs.  This effect
 * has a classification of "mind.fluster".
 * <p>
 * Describe the arguments in here.
 * @classification mind.fluster
 * @see help::effects
 */
/* This effect makes you see things. */
 
/* A quantity of 100 gives a hallucination effect of about 40 seconds. */

inherit "/std/effects/basic";
#include "effect.h"
#include "path.h"

void create() {
  set_boundaries( ({ -40, -30 }), ({ -12, -12 }) );
}  

int query_pass_through(int *coord){
   return 20;
}

mixed *query_attrs( int *coord ){
   int total;
   
   total = distance_within_region(coord) * 100 / 35;
   if (total > 100) total = 100;

   return ({ 20, 30, 
          ({ }), 
          ({ ({"sparkling purple", total }) }),
          ({ ({"fresh mountain air", total/2 }) }),
          ({ ({"cherries", total }) })
          });
}

void action_drunk( object ob, int *coord, int quantity ) {
   int str;
   object shadow;

   str = (distance_within_region(coord) * quantity) / 35;
   shadow = clone_object("/std/spells/priest/items/hallucinate_shadow");
   shadow->setup_shadow(this_player());
   shadow->remove_shadow(str);
   return ;
} 

