#pragma strong_types

#include <skills.h>
#include <light.h>
#include <skilltree.h>
#include <prop/room.h>

inherit "basic/create";
inherit "basic/skill_handler";

int sight_influence(int sight) {
  if (environment(this_player())->query_property(P_OUTSIDE))
    return - (1000 - sight) / 20;
  else
    return - (1000 - sight) / 10;
}

int int_influence(int intelligence) {
  switch (intelligence) {
  case  0.. 5: return - 5;
  case  6..10: return   0;
  case 11..15: return   5;
  case 16..20: return  10;
  case 21..30: return  15;
  default:
    if (intelligence > 30)
      return 20;
    return -10;
  }
  NO_WARN_MISSING_RETURN;  // Coogan, 26-Mar-2011
}

int dex_influence(int dexterity) {
  switch (dexterity) {
  case  0.. 5: return -10;
  case  6..10: return - 5;
  case 11..15: return   0;
  case 16..20: return   5;
  case 21..30: return  10;
  default:
    if (dexterity > 30)
      return 15;
    return -15;
  }
  NO_WARN_MISSING_RETURN;  // Coogan, 26-Mar-2011
}

void create() {
  set_influence(S_M_FIND_TRAPS,"sight","query_sight_quality",#'sight_influence);
  set_influence(S_P_FIND_TRAPS,"sight","query_sight_quality",#'sight_influence);

  set_influence(S_M_FIND_TRAPS, "intelligence", "query_int", #'int_influence);

  set_influence(S_P_FIND_TRAPS, "intelligence", "query_int", #'int_influence);
  set_influence(S_P_FIND_TRAPS, "dexterity",    "query_dex", #'dex_influence);
}

int query_reward(object who, int success, int difficulty, string skill) {
  if (success > 0 || success <= -200) // success or fumble
    return IMPROVE_SOMEWHAT * (difficulty > 50 ? ((difficulty-40)/10) : 1);
  return 0;  // Coogan, 26-Mar-2011
}

