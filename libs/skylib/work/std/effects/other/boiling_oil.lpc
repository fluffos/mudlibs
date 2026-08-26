/**
 * This effect has a classification of "misc.boiling_oil".
 * <p>
 * Nasty effect which burns (and dries) you lots, then gradually
 * burns you less and less.  It can be got rid of by getting your
 * wetness over 80.
 * <p>
 * The argument is the time in seconds you want the effect to
 * last for.
 * <p>
 * @classification body.poison
 * @see help::effects
 */
#include <effect.h>

/**
 * @ignore yes
 */
void beginning(object player, int time, int id) {
  tell_object(player,
    "You are covered in boiling oil!\n");
  // That should dry the water off them. :)
  if(sizeof(player->effects_matching("body.wetness"))) {
    player->delete_effect(player->effects_matching("body.wetness")[0]);
  }
  player->submit_ee("burn_them", ({20, 20}), EE_CONTINUOUS);
  player->submit_ee(0, time, EE_REMOVE);
} /* beginning() */

/**
 * @ignore yes
 */
int merge_effect(object player, int time1, int time2, int id) {
  player->submit_ee(0, time1 + time2 - player->expected_tt(), EE_REMOVE);
  return time1 + time2;
} /* merge_effect() */
 
/**
 * @ignore yes 
 */
void end(object player, int time, int id) {
  if(!player->query_property("dead")) {
    tell_object(player, 
      "The boiling oil sizzles briefly before cooling.\n");
  }
} /* end() */

/**
 * Burns the player unless they have wetness over 80.
 *
 * @param player The player to burn.
 * @param time The time left.
 * @param id The effect ID.
 */ 
void burn_them(object player, int time, int id) {
  mixed *wetness_args;
  int damage, wetness;
  wetness_args = player->effects_matching("body.wetness");
  if(sizeof(wetness_args)) {
    wetness = player->arg_of(wetness_args[0]);
    if(wetness > 80) {
      tell_object(player,
        "The heat of the oil dies on your soaking wet body.\n");
      player->submit_ee(0, 0, EE_REMOVE);
      return;
    }
  }
  // Burns worst at first and gradually cools...
  damage = (player->expected_tt() + random(300)) - wetness;
  if(wetness >= damage) {
    tell_object(player,
      "The heat of the oil dies on your soaking wet body.\n");
    player->submit_ee(0, 0, EE_REMOVE);
    return;
  }
  tell_object(player,
    "You scream in agony as the oil sticking to your body burns you!\n");
  tell_room(environment(player),
    player->one_short()+" screams in agony as the oil "
    +player->query_pronoun()+" is covered in sizzles!\n", player);
  player->adjust_hp(-damage, this_object());
  if(player->query_monitor()) {
    HEALTH_H->monitor_points(player, 1);
  }
  player->remove_hide_invis("hiding");
} /* burn_them() */

/**
 * @ignore yes
 */
string query_classification() {
  return "misc.boiling_oil";
} /* query_classification() */

/**
 * @ignore yes
 */
string query_death_name() {
  return "boiling oil";
} /* query_death_name() */

