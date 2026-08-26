/*  -*- LPC -*-  */
/*
 * $Locker:  $
 * $Id: brokenarm.c,v 1.2 1999/03/23 02:46:43 sin Exp $
 * $Log: brokenarm.c,v $
 * Revision 1.2  1999/03/23 02:46:43  sin
 * Fixed the shadow
 *
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
   set_name( "Broken arm" );
   set_classification( "disease.injury.broken.arm" );
   set_shadow_ob( SHADOWS "disease/brokenfingers" );
   set_cure_rate( 600 );
} /* setup() */

void disease_start( object player, int arg ) {
   tell_object( player, "You feel a crunch as your arm breaks.\n" );
   player->add_extra_look( this_object() );
} /* disease_start() */

void disease_worse( object player ) {
   tell_object( player, 
               "The throbbing in your arm intensifies.\n" );
} /* disease_worse() */

void disease_better( object player ) {
   tell_object( player, 
               "You feel a sense of relief as the throbbing in your "
               "arm becomes less painful.\n" );
   player->remove_extra_look( this_object() );
} /* disease_better() */

/** @ignore yes */
void disease_end( object player ) {
   tell_object( player, 
               "The throbbing in your arm seems to have disappeared.\n" );
   player->remove_extra_look( this_object() );
} /* disease_end() */

void disease_action( object player, int arg, int id ) {
   if ( random( 5 ) == 0 )
      tell_object( player, "Your arm throb painfully.\n" );
} /* disease_action() */

void restart( object player ) {
   player->add_extra_look( this_object() );
} /* restart() */

string extra_look( object player ) {
  return capitalize(player->query_pronoun()+" appears to have a problem with "+
                    "an arm - it looks broken!\n");
} /* extra_look() */
