/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: life_saving.c,v 1.1 1998/01/06 04:06:32 ceres Exp $
 * $Log: life_saving.c,v $
 * Revision 1.1  1998/01/06 04:06:32  ceres
 * Initial revision
 * 
*/
/**
 * This is the effect skelton docs.  This effect
 * has a classification of "magic.health.life-saving".
 * <p>
 * Describe the arguments in here.
 * <p>
 * This effect has a shadow associated with it.
 * @classification magic.health.life-saving
 * @see help::effects
 */
#include "path.h"
#include <effect.h>

/** @ignore yes */
string query_classification() { return "magic.health.life-saving"; }

int query_indefinite() { return 1; }

/** @ignore yes */
void beginning( object player ) {
   player->submit_ee( "count_things", 0, EE_ONCE );
} /* beginning() */

/** @ignore yes */
void merge_effect( object player ) {
   player->submit_ee( "count_things", 0, EE_ONCE );
} /* merge_effect() */

/** @ignore yes */
void end( object player ) { return; }

/** @ignore yes */
string query_shadow_ob() { return SHADOWS +"life_saving"; }

int test_for_effect( object thing ) {
   return member_array( file_name( this_object() ),
         (string *)thing->query_wear_effects() ) != -1;
} /* test_for_effect() */

void count_things( object player, mixed dummy, int id ) {
   object *things;
   things = filter_array( (object *)player->query_armours(),
         "test_for_effect", this_object() );
   if ( sizeof( things ) )
      player->set_arg_of( (int)player->sid_to_enum( id ), things );
   else
      player->delete_effect( (int)player->sid_to_enum( id ) );
   return;
} /* count_things() */
