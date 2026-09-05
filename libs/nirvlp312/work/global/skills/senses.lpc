/*
 * The skill handler for some senses, by Coogan, 04-Jan-02.
 *
 */

#pragma strong_types

#include <skills.h>
#include <light.h>
#include <skilltree.h>

inherit "basic/create";
inherit "basic/skill_handler";

int light_influence(int can_see) {
  if (!can_see)       // one can better taste/hear/smell when not able to see.
    return INFLUENCE_LARGE;
  return 0;
}

int query_can_see(object o) {
  return o->test_sight(environment(o), 1);
}

void create() {
  set_influence(S_HEAR,  "light", #'query_can_see, #'light_influence);
  set_influence(S_SMELL, "light", #'query_can_see, #'light_influence);
  set_influence(S_TASTE, "light", #'query_can_see, #'light_influence);
}

int query_reward(object who, int success, int difficulty, string skill) {
  if (success > 0 || success <= -200) // success or fumble
    return IMPROVE_ROUTINE * (difficulty > 50 ? ((difficulty-40)/10) : 1);
}

