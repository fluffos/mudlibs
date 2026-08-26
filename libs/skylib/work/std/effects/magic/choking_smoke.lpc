/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: choking_smoke.c,v 1.1 1998/01/06 04:16:50 ceres Exp $
 * $Log: choking_smoke.c,v $
 * Revision 1.1  1998/01/06 04:16:50  ceres
 * Initial revision
 * 
*/
/**
 * This is the effect skelton docs.  This effect
 * has a classification of "magic.smoke.choking".
 * <p>
 * Describe the arguments in here.
 * @classification magic.smoke.choking
 * @see help::effects
 */
#include <effect.h>

void create() {
   seteuid( (string)"/secure/master"->
         creator_file( file_name( this_object() ) ) );
} /* create() */

/** @ignore yes */
void beginning( object player, int amount, int id ) {
   player->submit_ee( 0, 0, EE_REMOVE );
} /* beginning() */

/** @ignore yes */
void end( object player, int amount, int id ) {
   int damage;
   object thing, *things;
   tell_object( player, "You cough and gag on the smoke.\n" );
   damage = amount - (int)player->query_ac( "gas", amount, "self" );
   player->adjust_hp( -damage );
   if ( (int)player->query_hp() < 0 )
      player->attack_by( this_object() );
   if ( !environment( player ) ) {
      tell_object( player, "The smoke clears.\n" );
      return;
   }
   things = all_inventory( environment( player ) );
   foreach( thing in things ) {
      if ( !living( thing ) || ( thing == player ) )
         continue;
      if ( amount > random( 20 * (int)thing->query_con() ) ) {
         tell_object( thing, "Vast amounts of smoke billow from "+
               (string)player->the_short() +" and you are forced, "+
               "coughing and crying, out of the area.\n" );
         thing->run_away();
      } else
         tell_object( thing, "Smoke billows from "+
               (string)player->the_short() +
               " but it doesn't seem to affect you.\n" );
   }
   tell_room( environment( player ), "The smoke clears.\n" );
} /* end() */

/** @ignore yes */
string query_classification() { return "magic.smoke.choking"; }

string query_name() { return "really nasty smoke"; }
