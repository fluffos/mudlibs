/*
 * This shadow goes with the effect classified as "asleep"
 *
 * It intercepts the message given when a player attempts to use
 * commands while passed out.  It intercepts only when the player
 * is asleep and not also unconscious.
 *
 */

#include <living.h>

inherit "/std/effect_shadow";

/** @ignore yes */
string query_passed_out_message() {
  if( player->query_property( PASSED_OUT ) == ASLEEP )
     return "You are sound asleep and can't do anything.\n";
}
