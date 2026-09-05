#pragma strong_types

#include <skills.h>
#include <skilltree.h>

inherit "basic/skill_handler";
inherit "basic/create";

int sight_influence(int sight) {
  if (sight < 200)
    return -10;
  if (sight < 700)
    return  -5;
  return 0;  // Coogan, 26-Mar-2011
}

int int_influence(int intelligence) {
  switch (intelligence) {
  case 0..10: 
    return -10;
  case 11..20:
    return 0;
  case 21..30:
    return 10;
  default:
    if (intelligence > 30)
      return 20;
    return -20;
  }
  NO_WARN_MISSING_RETURN;  // Coogan, 26-Mar-2011
}

void create() {
  set_influence(S_READ_COMMON,"sight","query_sight_quality",#'sight_influence);
  set_influence(S_READ_COMMON,"intelligence", "query_int",  #'int_influence);
}

int query_reward(object who,int success, int difficulty, string skill) {
  if (success > 0 || success <= -200) // success or fumble
    return IMPROVE_ROUTINE * (difficulty > 50 ? ((difficulty-40)/10) : 1);
  return 0;  // Coogan, 26-Mar-2011
}

