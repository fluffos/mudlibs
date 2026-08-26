/**
 * This effect has a classification
 * of "other.bunny".
 * <p>
 * @author Turrican
 * @classification other.bunny
 * @see help::effects
 */

#include <effect.h>
#include <broadcaster.h>
#include <player.h>

#include "path.h"

/** @ignore yes */
string query_classification() { return "other.bunny"; }

/** @ignore yes */
string query_shadow_ob() { return SHADOWS + "bunny"; }

/** @ignore yes */
void beginning(object player, int time) {
  player->submit_ee("rand_mess", ({ 25, 40 }), EE_CONTINUOUS);
  player->submit_ee(0, time, EE_REMOVE);
  player->add_extra_look(this_object());
  player->set_position("hopping about");
  player->add_alias("rabbit");
} /* beginning() */

/** @ignore yes */
int merge_effect(object player, int time1, int time2) {
  int newtime;

  newtime = time2 + player->expected_tt();
  if (newtime < 0) {
    newtime = 0;
  }
  player->submit_ee(0, newtime, EE_REMOVE);
  return newtime;
} /* merge_effect() */

void restart(object player) {
  player->add_extra_look(this_object());
  player->set_position("hopping about");
  player->add_alias("rabbit");
} /* restart() */

/** @ignore yes */
void end(object player, int time) {
  if (!player->query_property("dead")) {
    tell_object(player, "Your craving for carrots disappears.\n");
    tell_room(environment(player), player->one_short() + " suddenly looks "
              "a lot more human.\n", player);
  }
  player->set_position("standing");
  player->remove_extra_look(this_object());
  player->remove_alias("rabbit");
} /* end() */

/** @ignore yes */
void rand_mess(object player) {
  string str = "I DON'T HAVE FLUFFY RABBIT EARS!";

  switch (random(7)) {
  case 0:
    tell_object(player, "You hop around aimlessly.\n");
    tell_room(environment(player), player->one_short() + " hops around "
              "aimlessly.\n", player);
    break;
  case 1:
    tell_object(player, "You twitch your nose cutely.\n");
    tell_room(environment(player), player->one_short() + " twitches " +
              player->query_possessive() + " nose cutely.\n", player);
    break;
  case 2:
    tell_object(player, "You twitch your tail happily.\n");
    tell_room(environment(player), player->one_short() + " twitches " +
              player->query_possessive() + " tail happily.\n", player);
    break;
  case 3:
    tell_object(player, "People passing by take pictures of you!\n");
    tell_room(environment(player), "People passing by take pictures of " +
              player->one_short() + ".\n", player);
    break;
  case 4:
    if ((player->query_property("player") == 1) && !creatorp(player) ) {
      if (player->adjust_sp(-SHOUT_COST * ((strlen(str) / 10) + 1)) < 0) {
        break;
      }
      player->adjust_max_sp(-(SHOUT_COST * ((strlen(str) / 10) + 1) / 10));
    }
    player->remove_hide_invis("hiding");
    tell_object(player, "You yell: " + str + "\n");
    user_event(player, "person_shout",
               player->one_short() + " yells",
               str, "common", environment(player)->query_co_ord(),
               (100 * (player->query_con() + player->query_str())) / 3);
    environment(player)->event_person_shout(0, player->one_short() + " yells",
                                            str, "common");

    BROADCASTER->npc_shout_event(player, player->one_short() + " yells", str,
                                 "common", environment(player)->query_co_ord(),
                                 (100 * (player->query_con() +
                                         player->query_str())) / 3);
    break;
  case 5:
    tell_object(player, "You feel a craving for carrots.\n");
    tell_room(environment(player), player->one_short() + " searches around "
              "for a carrot.\n", player);
    break;
  case 6:
    tell_room(environment(player), "Someone yells: Show us your pink "
              "fluff!\n");
    break;
  }
} /* rand_mess() */

/** @ignore yes */
string extra_look(object player) {
  int *enums;

  enums = player->effects_matching("other.bunny");
  if (!sizeof(enums)) {
    player->remove_extra_look(this_object());
    return "";
  }
  return "You can't help but notice that " + player->query_possessive() +
    " ears seem rather long, fluffy and definately pink.\n" +
      capitalize(player->query_possessive()) + " nose twitches nervously.\n";
}/* end query_extra_look() */
