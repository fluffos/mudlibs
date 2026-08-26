/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: edible_clothes.c,v 1.2 1999/10/25 23:13:45 pinkfish Exp $
 * $Log: edible_clothes.c,v $
 * Revision 1.2  1999/10/25 23:13:45  pinkfish
 * Next versio nof the edible clothes effect.
 *
 * Revision 1.1  1998/01/06 04:06:32  ceres
 * Initial revision
 * 
*/
/**
 * This is the effect skelton docs.  This effect
 * has a classification of "mudlib.clothing.edible".
 * <p>
 * There are no arguments to this effect.
 * <p>
 * This effect has a shadow associated with it.
 * @classification mudlib.clothing.edible
 * @see help::effects
 * @author Terano/Pinkfish
 */
#include "path.h"
#include <effect.h>

/** @ignore yes */
string query_classification() { return "mudlib.clothing.edible"; }

/** @ignore yes */
void begining(object player, mixed arg, int id) {
  call_out((: ($1?$1->init_eat_clothes_command():0) :), 2, player);
} /* begining() */

/** @ignore yes */
int query_indefinite() { return 1; }

/** @ignore yes */
string query_shadow_ob() { return SHADOWS + "edible_clothes"; }

/** @ignore yes */
object *merge_effect( object, object *old_arg, object *new_arg ) {
   return old_arg + new_arg;
} /* merge_effect() */

void restart( object player, object *edible ) {
  call_out((: ($1?$1->init_eat_clothes_command():0) :), 2, player);
} /* restart() */

/** @ignore yes */
void end( object player, object *edible ) {
} /* end() */
