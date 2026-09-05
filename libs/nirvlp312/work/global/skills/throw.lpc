/*
 * The skill handler for throw, by Coogan, 05-Jan-02.
 *
 */

#pragma strong_types

#include <skills.h>
#include <light.h>
#include <skilltree.h>

inherit "basic/create";
inherit "basic/skill_handler";

int sight_influence(int can_see) {
  if (!can_see)       // one can badly throw when not seeing the environment
    return -2 * INFLUENCE_LARGE;
  return 0;
}

int query_can_see(object o) {
  return o->test_sight(environment(o), 1);
}

void create() {
  set_influence(S_THROW, "sight", #'query_can_see, #'sight_influence);
}

int query_reward(object who, int success, int difficulty, string skill) {
  if (success > 0 || success <= -200) // success or fumble
    return IMPROVE_ROUTINE * (difficulty > 50 ? ((difficulty-40)/10) : 1);
}

