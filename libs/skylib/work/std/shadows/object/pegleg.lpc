/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: pegleg.c,v 1.1 1998/01/06 04:40:23 ceres Exp $
 * $Log: pegleg.c,v $
 * Revision 1.1  1998/01/06 04:40:23  ceres
 * Initial revision
 * 
*/
#include "path.h"

inherit "/std/effect_shadow";

string query_msgin()
{
  return "*thump* *click* *thump* *click* $N arrive$s from $F";
}

string query_msgout()
{
  return "*thump* *click* *thump* *click* $N leave$s $T.";
}

int test_for_effect( object thing ) {
   return member_array( EFFECTS +"pegleg",
      (string *)thing->query_wear_effects() ) != -1;
} /* test_for_effect() */

void taken_off(object what, string eff)
{
  if (eff != EFFECTS + "pegleg")
    player->taken_off(what, eff);
  else {
    remove_this_effect();
  }
}

mixed *stats()
{
  return ({
    ({ "peggy leggy", 1 })
    }) + player->stats();
}
