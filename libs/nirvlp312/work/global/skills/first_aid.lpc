#pragma strong_types

#include <skills.h>
#include <skilltree.h>

inherit "basic/skill_handler";
inherit "basic/create";

int sight_influence(int quality) {
  if (quality > 800)
    return 10;
  if (quality < 200)
    return -10;
  return 0;  // Coogan, 26-Mar-2011
}

int dex_influence(int dexterity) {
  switch (dexterity) {
  case  5..10: return   0;
  case 11..15: return   5;
  case 16..20: return  10;
  case 21..30: return  15;
  case 31..40: return  20;
  case 41..50: return  25;
  case 51..60: return  30;
  case 61..70: return  35;
  default:
    if (dexterity > 70)
      return 40;
    return -5;
  }
  NO_WARN_MISSING_RETURN;  // Coogan, 26-Mar-2011
}

// the more wounded somebody is, the more problems he has for bandaging
int get_hp_ratio(object who) {
  return
    to_int(100.0 * to_float(who->query_hp()) / to_float(who->query_max_hp()));
}

int hp_ratio_influence(int ratio) {
  if (ratio > 80)
    return 0;
  return (ratio * 3) / 4 - 60;  // 0..80 -> -60..0
}

void create() {
  set_influence(S_M_FIRST_AID,"sight", "query_sight_quality",#'sight_influence);
  set_influence(S_M_FIRST_AID,"dexterity", "query_dex",      #'dex_influence);
  set_influence(S_M_FIRST_AID,"wounded", #'get_hp_ratio,  #'hp_ratio_influence);
}

int query_reward(object who,int success, int difficulty, string skill) {
  if (success > 0 || success <= -200) // success or fumble
    return IMPROVE_SOMEWHAT * (difficulty > 50 ? ((difficulty-40)/10) : 1);
  return 0;  // Coogan, 26-Mar-2011
}

