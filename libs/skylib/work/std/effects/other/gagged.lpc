/**
 * This effect has a classification of "mudlib.gagged".
 * <p>
 * @author Shiannar
 * @classification "mudlib.gagged"
 * @see help::effects
 */
#include <effect.h>
#include "path.h"

/* @ignore yes */
string query_classification() { return "mudlib.gagged"; }

/* @ignore yes */
string query_shadow_ob() { return SHADOWS+"gagged"; }

/* @ignore yes */
void beginning(object player, mixed *arg) {
  int duration;
  string gagger;
  string name;
  duration = arg[0];
  gagger = arg[1];
  if(gagger) {
    if(find_player(gagger)) {
      name = find_player(gagger)->the_short();
    }
    else {
      name = capitalize(gagger);
    }
  }
  else {
    name = "an unknown person or thing";
  }
  tell_object(player, "You have been gagged by "+name+" for "+
     time_string(duration)+".  Until the gag is removed, "
     "you will be unable to shout or use channels.\n");
  player->submit_ee(0, duration, EE_REMOVE);
} /* beginning() */

/* @ignore yes */
void end(object player, mixed *arg) {
  string gagger;
  string reason;
  gagger = arg[1];
  reason = arg[2];
  tell_object(player, "Your gag has been lifted.\nPlease let this be "
    "a lesson to you.\n");
  if(find_player(gagger)) {
    tell_object(find_player(gagger), "Your gag on "+
       capitalize(player->query_name())+" for \""+reason+"\" has expired "
       "or otherwise been removed.\n");
  }
} /* end() */

mixed *merge_effect(object player, mixed *old_arg, mixed *new_arg) {
  int old_time;
  int new_time;
  string gagger;
  string name;
  old_time = player->expected_tt();
  new_time = new_arg[0];
  gagger = new_arg[1];
  if(old_time > new_time) {
    if(gagger && find_player(gagger)) {
      tell_object(find_player(gagger), capitalize(player->query_name())+
         " has already been gagged for a longer duration by "+
         capitalize(old_arg[1])+"!\n");
    }
    return old_arg;
  }
  if(gagger) {
    if(find_player(gagger)) {
      name = find_player(gagger)->the_short();
    }
    else {
      name = capitalize(gagger);
    }
  }
  else {
    name = "an unknown person or thing";
  }
  tell_object(player, "Your gag has been extended by "+name+" to "+
    time_string(new_time)+".\n");
  player->submit_ee(0, new_time, EE_REMOVE);
  return new_arg;
}