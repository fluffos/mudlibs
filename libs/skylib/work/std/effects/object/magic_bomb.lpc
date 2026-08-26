/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: magic_bomb.c,v 1.2 1998/01/11 17:03:41 pinkfish Exp $
 * $Log: magic_bomb.c,v $
 * Revision 1.2  1998/01/11 17:03:41  pinkfish
 * fixed_up_the_extra_look_stuff,_tomake_them_ignored.
 *
 * Revision 1.1  1998/01/06 04:19:27  ceres
 * Initial revision
 * 
*/
/**
 * This is the effect skelton docs.  This effect
 * has a classification of "magic.bomb".
 * <p>
 * Describe the arguments in here.
 * <p>
 * This effect has a shadow associated with it.
 * @classification magic.bomb
 * @see help::effects
 */
#include "path.h"

/** @ignore yes */
string query_classification() { return "magic.bomb"; }

/** @ignore yes */
string query_shadow_ob() { return SHADOWS +"magic_bomb"; }

int query_indefinite() { return 1; }

/** @ignore yes */
void beginning( object thing, mixed *args, int id ) {
   thing->add_extra_look( this_object() );
} /* beginning() */

void restart( object thing, mixed *args, int id ) {
   thing->add_extra_look( this_object() );
} /* restart() */

/** @ignore yes */
string extra_look( object thing ) {
   int *enums;
   mixed *args;
   enums = (int *)thing->effects_matching( "magic.bomb" );
   if ( !sizeof( enums ) )
      return "";
   args = (mixed *)thing->arg_of( enums[ 0 ] );
   return args[ 1 ];
} /* extra_look() */
