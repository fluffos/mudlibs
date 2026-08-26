/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: blue_light.c,v 1.1 1998/01/06 04:16:50 ceres Exp $
 * $Log: blue_light.c,v $
 * Revision 1.1  1998/01/06 04:16:50  ceres
 * Initial revision
 * 
*/
/**
 * This is the effect skelton docs.  This effect
 * has a classification of "magic.misc.light.blue".
 * <p>
 * Describe the arguments in here.
 * @classification magic.misc.light.blue
 * @see help::effects
 */
#include "defs.h"
#include <effect.h>

/** @ignore yes */
string query_classification() { return "magic.misc.light.blue"; }

/** @ignore yes */
void beginning( object player, int number, int id ) {
   object light;
   light = clone_object( NPCS +"blue_light" );
   light->set_owner( player, id );
   light->move( environment( player ) );
   player->submit_ee( 0, number, EE_REMOVE );
} /* beginning() */

/* no merging - multiple lights are fine */

void restart( object player, int number, int id ) {
   object light;
   light = clone_object( NPCS +"blue_light" );
   light->set_owner( player, id );
   call_out( "move_to_player", 1, light, player );
} /* restart() */

void move_to_player( object light, object player ) {
   if ( !objectp( player ) ) {
      light->go_away();
      return;
   }
   if ( !environment( player ) ) {
      call_out( "move_to_player", 1, light, player );
      return;
   }
   light->move( environment( player ) );
} /* move_to_player() */

/** @ignore yes */
void end( object player, int number, int id ) {
   object light;
   foreach( light in children( NPCS +"blue_light" ) ) {
      if ( ( (object)light->query_owner() == player ) &&
            ( (int)light->query_oeid() == id ) )
         light->go_away();
   }
} /* end() */
