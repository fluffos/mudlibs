/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: paralysis_effect.c,v 1.1 1998/01/06 04:15:00 ceres Exp $
 * $Log: paralysis_effect.c,v $
 * Revision 1.1  1998/01/06 04:15:00  ceres
 * Initial revision
 * 
*/
/**
 * This is the effect skelton docs.  This effect
 * has a classification of "priest.paralysis".
 * <p>
 * Describe the arguments in here.
 * <p>
 * This effect has a shadow associated with it.
 * @classification priest.paralysis
 * @see help::effects
 */
#include <effect.h>
#include "path.h"

/** @ignore yes */
string query_classification() { return "priest.paralysis"; }

/** @ignore yes */
void beginning( object player, int number ) {
   tell_object(player, "You can't move! You seem to be paralysed.\n");
   player->submit_ee( 0, number, EE_REMOVE );
} /* beginning() */

/** @ignore yes */
int merge_effect( object player, int number1, int number2 ) {
   return number1 + number2;
} /* merge_effect() */

/** @ignore yes */
void end( object player ) {
   tell_object(player, "You can move again.\n"); 
} /* end() */

/** @ignore yes */
string query_shadow_ob() { return SHADOWS+"paralysis_shadow"; }
