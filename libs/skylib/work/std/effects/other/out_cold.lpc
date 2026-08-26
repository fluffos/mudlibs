/*
 * An effect to knock someone out.
 *
 * This effect takes one argument:
 * (int) time: the time until the person will regain 
 *             consciousness.
 *
 * If the person is already unconscious, <time> is added to the
 * length of time remaining until he regains consciousness.
 *
 * NB: the value of the "passed out" indicates an object's 
 * current state thus:
 *   0 = not asleep, not unconscious
 *   1 = not asleep, unconscious      (OUT_COLD)
 *   2 = asleep, not unconscious      (ASLEEP)
 *   3 = asleep, unconscious          (OUT_COLD + ASLEEP)
 *
 * The purpose of this effect is to modify the above states
 * accordingly when a player loses or regains consciousness.
 *
 * This effect is classified as "unconscious"
 * This effect has no shadow associated with it.
 *
 */

#include <effect.h>
#include <living.h>

#define CLASS "unconscious"

/** @ignore yes */
string query_classification() { return CLASS; }

/** @ignore yes */
int beginning( object player, int time ) {

  /* Determine the player's current state */

  int state = player->query_property( PASSED_OUT );

  /* If his state == 0, ie he is alert, give him a message
   * warning him that he's lost consciousness. */

  if( !state )
    tell_object( player, "You lose consciousness.\n" );

  /* If he currently alert or is asleep but not unconscious,
   * make him unconscious now.  NB: If he's both asleep and
   * unconscious, this will put him over the top but the next 
   * step will sort out his states */

  if( state != OUT_COLD )
    state += OUT_COLD;

  /* If he's beyond recognizable values, set him back to the
   * max value */

  if( state > OUT_COLD + ASLEEP ) 
    state = OUT_COLD + ASLEEP;

  /* Now we know what his new value for the "passed out" property
   * should be.  Add that and continue on with making him appear
   * to be unconscious. */

  player->add_property( PASSED_OUT, state );
  player->set_position( "lying" );
  player->add_extra_look( this_object() );

  /* Make sure we knock him out for negative time */
  if( time < 0 ) time = 0;

  player->submit_ee( 0, time, EE_REMOVE );
  return time;
} /* beginning() */

/** @ignore yes */
int merge_effect( object player, int old_time, int new_time ) {

  /* We already know he's unconscious.  Just add (or subtract)
   * the new time from the remaining duration of the old effect
   * and let it continue */

  new_time += player->expected_tt( 1, player->effects_matching( 
                  CLASS )[0] );

  /* Still don't knock him out for negative time */
  if( new_time < 0 ) new_time = 0;

  player->submit_ee( 0, new_time, EE_REMOVE );
  return new_time;
} /* merge_effect() */

/** @ignore yes */
void end( object player ) {

  /* We must determine what state he's in and therefore what state
   * to leave him in when he regains consciousness.  Ie: is he also
   * asleep? */

  int state = player->query_property( PASSED_OUT );

  /* If he was both asleep and unconscious, this will make him
   * only asleep.  If he was only unconscious, this will remove
   * the property.  If he was only asleep but not unconscious,
   * something has gone awry. */

  state -= OUT_COLD;  
  if( state < 0 )         // shouldn't happen
    state = 0;
  if( state == OUT_COLD ) // this shouldn't happen either
    state = 0;

  /* If he's fully alert now, tell him so.  Don't tell sleeping
   * players. */

  if( !state ) {
    player->remove_property( PASSED_OUT );
    tell_object( player, "You regain consciousness.\n" );
    player->new_parser( "groan" );
  }
  else 
    player->add_property( PASSED_OUT, state );
  player->remove_extra_look( this_object() );
} /* end() */

/** @ignore yes */
string extra_look( object player ) {
  if( !sizeof( player->effects_matching( CLASS ) ) )
    return "";

  return sprintf( "%s is unconscious.\n", 
                   capitalize( player->query_pronoun() ) );
} /* extra_look() */
