/*
 * The skill handler for 'play instrument' skills, by Coogan, 15-Jan-02.
 *
 */

#pragma strong_types

#include <skills.h>
#include <skilltree.h>
#include <light.h>

inherit "basic/create";
inherit "basic/skill_handler";

int sight_influence(int can_see, int skill_level) {
  if (!can_see) {       // one can badly play when not seeing the environment
    switch (skill_level) {  // and is not skilled enough
    case  0 ..  9: return - 2 * INFLUENCE_LARGE;
    case 10 .. 19: return -(3 * INFLUENCE_LARGE) / 2;
    case 20 .. 29: return    -  INFLUENCE_LARGE;
    case 30 .. 39: return    - (INFLUENCE_LARGE / 2);
    default: return 0;
    }
  }
  return 0;
}

int query_can_see(object o) {
  return o->test_sight(environment(o), 1);
}

int sight_influence_play(int can_see) {
  return sight_influence(can_see,
                         this_player()->query_skill(S_P_PLAY));
}

int sight_influence_play_brass(int can_see) {
  return sight_influence(can_see, 
                         this_player()->query_skill(S_P_PLAY_BRASS));
}

int sight_influence_play_drum(int can_see) {
  return sight_influence(can_see, 
                         this_player()->query_skill(S_P_PLAY_DRUM));
}

int sight_influence_play_flute(int can_see) {
  return sight_influence(can_see, 
                         this_player()->query_skill(S_P_PLAY_FLUTE));
}

int sight_influence_play_keyboard(int can_see) {
  return sight_influence(can_see, 
                         this_player()->query_skill(S_P_PLAY_KEYBOARD));
}

int sight_influence_play_pluck(int can_see) {
  return sight_influence(can_see, 
                         this_player()->query_skill(S_P_PLAY_PLUCK));
}

int sight_influence_play_stringed(int can_see) {
  return sight_influence(can_see, 
                         this_player()->query_skill(S_P_PLAY_STRINGED));
}

void create() {
  set_influence(S_P_PLAY,          "sight", #'query_can_see,
                                              #'sight_influence_play);
  set_influence(S_P_PLAY_BRASS,    "sight", #'query_can_see,
                                              #'sight_influence_play_brass);
  set_influence(S_P_PLAY_DRUM,     "sight", #'query_can_see,
                                              #'sight_influence_play_drum);
  set_influence(S_P_PLAY_FLUTE,    "sight", #'query_can_see,
                                              #'sight_influence_play_flute);
  set_influence(S_P_PLAY_KEYBOARD, "sight", #'query_can_see,
                                              #'sight_influence_play_keyboard);
  set_influence(S_P_PLAY_PLUCK,    "sight", #'query_can_see,
                                              #'sight_influence_play_pluck);
  set_influence(S_P_PLAY_STRINGED, "sight", #'query_can_see,
                                              #'sight_influence_play_stringed);
}

int query_reward(object who, int success, int difficulty, string skill) {
  if (success > 0 || success <= -200) // success or fumble
    return IMPROVE_ROUTINE * (difficulty > 50 ? ((difficulty-40)/10) : 1);
}

