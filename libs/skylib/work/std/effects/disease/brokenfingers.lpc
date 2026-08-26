/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: brokenfingers.c,v 1.1 1998/01/06 04:08:27 ceres Exp $
 * $Log: brokenfingers.c,v $
 * Revision 1.1  1998/01/06 04:08:27  ceres
 * Initial revision
 * 
*/
/**
 * This is the effect skelton docs.  This effect
 * has a classification of "misc.curse.smurf".
 * <p>
 * Describe the arguments in here.
 * @classification misc.curse.smurf
 * @see help::effects
 */
/* Broken fingers effect.                     -*- LPC -*-
 * Standard duration should be about 288 minutes to have it fit the
 * old version, so give it an argument of 172800
 */
#include <effect.h>
#include <disease.h>
inherit SIMPLE_DISEASE;

void setup() {
   set_name( "Broken fingers" );
   set_classification( "disease.injury.broken.fingers" );
   set_shadow_ob( SHADOWS "brokenfingers" );
   set_cure_rate( 600 );
} /* setup() */

void disease_start( object player, int arg ) {
   tell_object( player, "You feel a crunch as your fingers break.\n" );
   player->add_extra_look( this_object() );
} /* disease_start() */

void disease_worse( object player ) {
   tell_object( player, 
               "The throbbing in your fingers intensifies.\n" );
} /* disease_worse() */

void disease_better( object player ) {
   tell_object( player, 
               "You feel a sense of relief as the throbbing in your "
               "fingers becomes less painful.\n" );
   player->remove_extra_look( this_object() );
} /* disease_better() */

/** @ignore yes */
void disease_end( object player ) {
   tell_object( player, 
               "The throbbing in your fingers seems to have disappeared.\n" );
   player->remove_extra_look( this_object() );
} /* disease_end() */

void disease_action( object player, int arg, int id ) {
   if ( random( 5 ) == 0 )
      tell_object( player, "Your fingers throb painfully.\n" );
} /* disease_action() */

void restart( object player ) {
   player->add_extra_look( this_object() );
} /* restart() */

string extra_look( object player ) {
  return capitalize(player->query_pronoun()+" appears to have a problem with "+
                    "the fingers of one hand - they look broken!\n");
} /* extra_look() */
