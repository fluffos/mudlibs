#pragma strong_types

#include <skills.h>
#include <skilltree.h>
#include <prop/room.h>

inherit "basic/skill_handler";
inherit "basic/create";

int sight_influence(int sight) {
  if (environment(this_player())->query_property(P_OUTSIDE))
    return - (1000 - sight) / 20;
  else
    return - (1000 - sight) / 10;
}

int dex_influence(int dexterity) {
  switch (dexterity) {
  case  0.. 5: return -10;
  case  6..10: return  -5;
  case 11..15: return   0;
  case 16..20: return   5;
  case 21..30: return  10;
  default:
    if (dexterity > 30)
      return 15;
    return -20;
  }
  NO_WARN_MISSING_RETURN;  // Coogan, 26-Mar-2011
}

int str_influence(int strength) {
  switch (strength) {
  case  0.. 5: return -20;
  case  6..10: return -10;
  case 11..15: return   0;
  case 16..20: return  10;
  default:
    if (strength > 20)
      return 20;
    return -40;
  }
  NO_WARN_MISSING_RETURN;  // Coogan, 26-Mar-2011
}

int load_influence(int load) {
  int l;
  l = (100 * load) / (this_player()->query_max_carry());  // 0..200 (percent)
  return 10 - (5 * (l/20));
}

void create() {
  set_influence(S_CLIMB, "sight", "query_sight_quality", #'sight_influence);
  set_influence(S_CLIMB, "dexterity", "query_dex",       #'dex_influence);
  set_influence(S_CLIMB, "strength",  "query_str",       #'str_influence);
  set_influence(S_CLIMB, "carry",     "query_carry",     #'load_influence);
}

int query_reward(object who,int success, int difficulty, string skill) {
  if (success > 0 || success <= -200) // success or fumble
    return IMPROVE_ROUTINE * (difficulty > 50 ? ((difficulty-40)/10) : 1);
  return 0;  // Coogan, 26-Mar-2011
}

