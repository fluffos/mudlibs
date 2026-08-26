/* This is the OC prisoner effect *
 * Coded By Laffs 21/04/99        */

#include <effect.h>
#include "path.h"

string query_classification() { return "OC.prisoner"; }

string query_shadow_ob() { return SHADOWS+"OCprisoner"; }

int beginning(object player, int arg) {
  player->submit_ee(0, arg, EE_REMOVE);
  return arg;
} /* beginning() */

int merge_effect( object player, int time1, int time2 ) {
  int duration;
  duration = (time2/2 + player->expected_tt() );
  player->submit_ee( 0, duration, EE_REMOVE );
  return duration;
} /* merge_effects() */

void end( object player ) {
tell_object( player, "Your depressing experience in jail is finally over.\n" );
  player->remove_property("tell block");
  player->remove_property("OC criminal");
  player->remove_property("OC prison briefed");
} /* end() */

void restart( object player ) {
  tell_object( player, "You return to the gloom of the Jail cell.\n" );
} /* restert () */ 
