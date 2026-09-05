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

int int_influence(int intelligence) {
  switch (intelligence) {
  case  0..10: return -15;
  case 11..15: return   0;
  case 16..20: return  10;
  default:
    if (intelligence > 20)
      return 15;
  }
  return 0;  // Coogan, 26-Mar-2011
}

void create() {
  set_influence(S_SEARCH, "sight", "query_sight_quality", #'sight_influence);
  set_influence(S_SEARCH, "intelligence", "query_int",    #'int_influence);
}

int query_reward(object who,int success, int difficulty, string skill) {
  if (success > 0 || success <= -200) // success or fumble
    return 2 * IMPROVE_ROUTINE * (difficulty > 50 ? ((difficulty-40)/10) : 1);
  return 0;  // Coogan, 26-Mar-2011
}

