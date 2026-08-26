#include "diseases.h"

#define PREDEFINED_TYPES ([ "milk" : 30, "meat" : 40, "confectionary" : 1,\
                            "fruit" : 20 ])
#define ALL_DISEASES ([ "/std/effects/disease/headache" : 30,\
                        "/std/effects/disease/revulsion" : 20,\
                     ])

void apply_effect(object, string, int);

/**
 * @ignore yes
 */
void create() {
} /* create() */

/**
 * This method calculates a mapping of the chances for each particular
 * disease occuring.
 * It then chooses the actual disease.
 */
string choose_disease() {
  int total_rating;
  float i;
  string disease;
  mapping individual_chances = ([]);

  //Work out each diseases individual rating, though store it in the
  //return mapping for now, to reduce memory usage.
  foreach(disease in keys(ALL_DISEASES)) {
    individual_chances[disease] = random(ALL_DISEASES[disease]);
  }

  //Calculate the total rating of the diseases.
  foreach(disease in keys(individual_chances)) {
    total_rating += individual_chances[disease];
  }

  if(total_rating < 1) { return keys(ALL_DISEASES)[0]; } //Hack, avoid div by 0 errors.

  i = 0;
  foreach(disease in keys(individual_chances)) {
  //Actually calculate the diseases individual chance.
    individual_chances[disease] = ({
      i, ((individual_chances[disease] / (total_rating + 0.0)) * 100) + i});
    i = individual_chances[disease][1];
  }

  //Choose the actual disease.
  i = random(100);
  foreach(disease in keys(individual_chances)) {
    if(i >= individual_chances[disease][0] && i < individual_chances[disease][1]) {
      return disease;
    }
  }
} /* calculate_chances() */

mixed stats() { return ALL_DISEASES; }

void consume_food(object player, int decomposition, int weight,
                  string type) {
  int chance;
  if(type == "disease_free") return;
  chance = weight;
  // Change food.c so that weight passed in is the weight of food
  // consumed, not the weight of the total food.
  chance += decomposition * 10;
  chance += PREDEFINED_TYPES[type];
  chance += (((0 - player->query_con()) + 30) * 2);
  if(random(chance) > 60) {
    apply_effect(player, choose_disease(), chance);
    return;
  }
  if(!random(40)) {
    apply_effect(player, choose_disease(), chance);
  }
} /* consume_food() */

/**
 * This method can catch diseases that need specific syntaxes to be
 * activated. If the disease isn't listed, it is just applied normally.
 */
void apply_effect(object player, string effect, int severity) {
// Removed the player from the arguments as it's passed to the effect
// automatically and is causing runtimes when merging effects.
// Sandoz.
// player->add_effect(effect, player, severity);
  player->add_effect(effect, severity);
} /* apply_effect() */
