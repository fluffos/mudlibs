// if(lockpick = (object *)(this_player()->query_wield()))
//   if (lockpick->id("\nlockpick"))
//      bonus_skill = ((int)(lockpick->query_class())) * 5;

// light, wielded picklock, S_M_LOCK_PICK, S_P_LOCK_PICK, quality of picklock

#pragma strong_types

#include <skills.h>
#include <skilltree.h>
#include <prop/room.h>
#include <prop/item.h>

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
  case 21..25: return  10;
  case 26..30: return  15;
  default:
    if (dexterity > 30)
      return 20;
    return -20;
  }
  NO_WARN_MISSING_RETURN;  // Coogan, 26-Mar-2011
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

int load_influence(int load) {
  int l;
  l = (100 * load) / (this_player()->query_max_carry());  // 0..200 (percent)
  return 10 - (5 * (l/20));
}

int pick_influence(object wielded) {
  if (wielded) {
    if (wielded->query_property(P_PICKLOCK))
      return wielded->query_lockpick_quality();
    else
      return -20;
  }
  return -40;
}

void create() {
  set_influence(S_M_PICK_LOCK,"sight","query_sight_quality",#'sight_influence);
  set_influence(S_P_PICK_LOCK,"sight","query_sight_quality",#'sight_influence);

  set_influence(S_M_PICK_LOCK, "intelligence", "query_int", #'int_influence);

  set_influence(S_P_PICK_LOCK, "dexterity", "query_dex",   #'dex_influence);
  set_influence(S_P_PICK_LOCK, "carry",     "query_carry", #'load_influence);
  set_influence(S_P_PICK_LOCK, "wield",     "query_wield", #'pick_influence);
}

int query_reward(object who,int success, int difficulty, string skill) {
  if (success > 0 || success <= -200) {  // success or fumble
    if (skill == S_P_PICK_LOCK)
      return IMPROVE_SOMEWHAT * (difficulty > 50 ? ((difficulty-40)/10) : 1);
    else
      return IMPROVE_SLIGHTLY * (difficulty > 50 ? ((difficulty-40)/10) : 1);
  }
  return 0;  // Coogan, 26-Mar-2011
}

