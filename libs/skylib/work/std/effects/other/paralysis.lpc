/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: paralysis.c,v 1.1 1998/01/06 04:20:30 ceres Exp $
 * $Log: paralysis.c,v $
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
/* This effect freezes you to the spot. Unpleasant if used at the wrong time */
/* A quantity of 100 lasts for about 40 seconds. */
 
inherit "/std/effects/basic";
#include "effect.h"
#include "path.h"

void create() {
  set_boundaries( ({ 10, -10 }), ({ 30, 5 }) );
}  

int query_pass_through(int *coord){
   return 40;
}

mixed *query_attrs( int *coord ){
   int total;
   
   total = distance_within_region(coord) * 100 / 25;
   if (total > 100) total = 100;

   return ({ 40, 70, 
          ({ }), 
          ({ ({"yellow", total }) }),
          ({ ({"lemon", total/2 }) }),
          ({ ({"bitter", total }) })
          });
}

void action_drunk( object ob, int *coord, int quantity ) {
   int str;
   object shadow;

   str = (distance_within_region(coord) * quantity) / 25;
   shadow = clone_object("/std/spells/priest/items/freeze_shadow");
   shadow->setup_shadow(this_player());
   shadow->remove_shadow(str);
   return ;
} 

