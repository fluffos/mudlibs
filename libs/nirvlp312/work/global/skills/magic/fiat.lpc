/*
 *
 * Written by Coogan, Dec-1998.
 *
 * TODO: status is unfinished
 */

#pragma strong_types

#include <skills.h>
#include <skilltree.h>   // Coogan, 26-Mar-2011
#include <living.h>      // Coogan, 26-Mar-2011

#define MAX_REWARD 40

inherit "basic/create";
inherit "basic/skill_handler";
inherit "basic/math";

int strength_influence    (int strength,     object player);
int dexterity_influence   (int dexterity,    object player);
int intelligence_influence(int intelligence, object player);
int constitution_influence(int constitution, object player);
int health_influence      (int hp,           object player);
int load_influence        (int load,         object player);
int sight_influence       (int sight,        object player);

void create() {
  set_influences(S_MAGIC_FIAT,
                 ({
                    ({ "dexterity",   "query_dex", #'dexterity_influence }),
                    ({ "health",      "query_hp",  #'health_influence }),
                    ({ "intelligence","query_int", #'intelligence_influence }),
                    ({ "load",        "query_carry", #'load_influence }),
                    ({ "sight",       #'query_light, #'sight_influence }),
                 }));
}

int dexterity_influence(int dexterity, object player) {
  return (INFLUENCE_MIDDLE * dexterity) / MAX_STAT;
}

int health_influence(int health, object player) {
  return 0;
}

int intelligence_influence(int intelligence, object player) {
  return 0;
}

int load_influence(int load, object player) {
  load /= 2500;  // Coogan, 07-Jan-99
  if (load > 0)
    return -1 * to_int((INFLUENCE_LARGE / abs(LOAD_FACTOR)) *
           (log((1.0 * load) / MAX_LOAD) - LOAD_FACTOR) + 0.1);
  return 0;
}

int sight_influence(int sight, object player) {}

/*
 * this function returns the reward for a skill-test
 * The higher the success, the lower the reward (because a high success
 * means a high skill)
 * The higher the difficulty the higher the reward.
 * A fumble is treated like a very high success.
 */

int query_reward(object who, int success, int difficulty, string skill) {
  if (success > 0 || success <= -200)
    return to_int(
      COMBAT_SKILL_REWARD_FACTOR *
      IMPROVE_SLIGHTLY *
      (success > 0 ?
        (COMBAT_SKILL_REWARD * difficulty) / to_float(success) :
        (COMBAT_SKILL_REWARD * difficulty) / 200.0));
  return 0;  // Coogan, 26-Mar-2011
}

