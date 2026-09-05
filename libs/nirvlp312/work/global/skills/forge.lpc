/*
 * This is the handler of the forge skill.
 * Written by Coogan, Apr-May 1997, updated 08-Jan-02.
 *
 */

#pragma strong_types

#include <skilltree.h>
#include <skills.h>
#include <prop/room.h>

inherit "basic/skill_handler";
inherit "basic/create";


int sight_influence(int sight) {
  if (environment(this_player())->query_property(P_OUTSIDE))
    return - (1000 - sight) / 20;
  else
    return - (1000 - sight) / 10;
}

int dex_influence(int dex) {
  return 5 * (dex/5) - 20;
}

int str_influence(int str) {
  return 5 * (str/5) - 20;
}

int load_influence(int load) {
  int l;
  l = (100 * load) / (this_player()->query_max_carry());  // 0..200 (percent)
  return 10 - (5 * (l/20));
}

int query_reward(object who, int success, int difficulty, string skill) {
  if (success > 0 || success <= -200) // success or fumble
    return (2*IMPROVE_SOMEWHAT) * (difficulty > 50 ? ((difficulty-40)/10) : 1);
}

void create() {
  set_influence(S_P_SMITH, "sight", "query_sight_quality", #'sight_influence);
  set_influence(S_P_SMITH, "dexterity", "query_dex",       #'dex_influence);
  set_influence(S_P_SMITH, "strength",  "query_str",       #'str_influence);
  set_influence(S_P_SMITH, "carry",     "query_carry",     #'load_influence);
}

