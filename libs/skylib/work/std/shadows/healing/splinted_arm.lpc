/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: splinted_arm.c,v 1.1 1999/07/13 20:53:35 tannah Exp $
 *
 *
 */

#define CLASS "body.damage.arm.splinted"
inherit "/std/effect_shadow";

/** @ignore yes */
int *set_hold(object ob, int pos) {
  int *args;                     /* args of effect */

  args = player->arg_of( player->effects_matching( CLASS )[0] );
  if( pos == 0 && args[2] )  return ({ });
  if( pos == 1 && args[0] )  return ({ });
  return player->set_hold( ob, pos );
}

/** @ignore yes */
int query_free_limbs() {
   int *args;
   int free_hands;

   args = player->arg_of( player->effects_matching( CLASS )[0] );
   free_hands = player->query_free_limbs() - args[0] - args[2];

   return ( free_hands < 0 ? 0 : free_hands );
} /* query_free_limbs() */

