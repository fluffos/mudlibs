/*
 * An effect to put someone to sleep.  
 *
 * This effect takes one argument:
 * (int) time: the time until the person will wake up.
 *
 * If the person is already asleep, <time> is added to the
 * length of time remaining until he wakes.
 *
 * NB: the value of the "passed out" indicates an object's 
 * current state thus:
 *   0 = not asleep, not unconscious
 *   1 = not asleep, unconscious      (OUT_COLD)
 *   2 = asleep, not unconscious      (ASLEEP)
 *   3 = asleep, unconscious          (OUT_COLD + ASLEEP)
 *
 * The purpose of this effect is to modify the above states
 * accordingly when a player falls asleep or wakes up.
 *
 *
 * This effect is classified as "asleep"
 * This effect has a shadow associated with it.
 *
 */

#include <effect.h>
#include <living.h>

#define CLASS "asleep"
#define SHADOW "/std/shadows/other/asleep"

/** @ignore yes */
string query_classification() { return CLASS; }

/** @ignore yes */
string query_shadow_ob() { return SHADOW; }

/** @ignore yes */
int beginning( object player, int time ) {

  /* Determine the player's current state */

  int state = player->query_property( PASSED_OUT );

  /* If his state == 0, ie he is alert, give him a message
   * warning him that he's fallen asleep. */

  if( !state )
    tell_object( player, "You fall asleep.\n" );

  /* If he currently alert or is unconscious but not asleep,
   * put him to sleep now.  NB: If he's both asleep and
   * unconscious, this will put him over the top but the next 
   * step will sort out his states */

  if( state != ASLEEP )
    state += ASLEEP;

  /* If he's beyond recognizable values, set him back to the
   * max value */

  if( state > ASLEEP + OUT_COLD ) 
    state = ASLEEP + OUT_COLD;

  /* Now we know what his new value for the "passed out" property
   * should be.  Add that and continue on with making him appear
   * to be asleep. */

  player->add_property( PASSED_OUT, state );
  player->set_position( "lying" );
  player->add_extra_look( this_object() );

  /* Don't put him to sleep for negative time */

  if( time < 0 ) time = 0;
  player->submit_ee( 0, time, EE_REMOVE );
  return time;
} /* beginning() */


/** @ignore yes */
int merge_effect( object player, int old_time, int new_time ) {

  /* We already know he's asleep.  Just add (or subtract)
   * the new time from the remaining duration of the old effect
   * and let it continue */

  new_time += player->expected_tt( 1, player->effects_matching( 
                  CLASS )[0] );

  /* Still don't put him to sleep for a negative time */
  if( new_time < 0 ) new_time = 0;
  player->submit_ee( 0, new_time, EE_REMOVE );
  return new_time;
} /* merge_effect() */


/** @ignore yes */
void end( object player ) {

  /* We must determine what state he's in and therefore what state
   * to leave him in when he wakes up.  Ie: is he also unconscious? */

  int state = player->query_property( PASSED_OUT );

  /* If he was both asleep and unconscious, this will make him
   * only unconscious.  If he was only asleep, this will remove
   * the property.  If he was only unconscious but not asleep,
   * something has gone awry. */

  state -= ASLEEP;  
  if( state < 0 )         // shouldn't happen
    state = 0;
  if( state == ASLEEP ) // this shouldn't happen either
    state = 0;

  /* If he's fully alert now, remove the property and tell him
   * he's woken up.  If he's still unconscious, don't give him a
   * message and reset his "passed out" value. */

  if( !state ) {
    player->remove_property( PASSED_OUT );
    tell_object( player, "You wake up.\n" );
    player->new_parser( "yawn" );
    player->new_parser( "stretch sleepily" );
  }
  else 
    player->add_property( PASSED_OUT, state );

  player->remove_extra_look( this_object() );
} /* end() */

/** @ignore yes */
string extra_look( object player ) {
  if( !sizeof( player->effects_matching( CLASS ) ) )
    return "";

  return sprintf( "%s is asleep.\n", 
                   capitalize( player->query_pronoun() ) );
} /* extra_look() */
