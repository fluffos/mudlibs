/**
 * The effect that handles restoration of life-force.
 * Contains the code handling how much must be drunken
 * to restore life force, etc. Pray for me.
 * @author Shiannar
 */

#include <effect.h>
#define IMM_FALL 1.5 //The immediate falloff.
                     //Makes sipping until you get a life wasteful. :)

#define REQ_BASE 100
#define REQ_EXP  2.5

#define CON_DROP 3
#define CUT_OFF  10

int required(object);
int gift(object, int);

int beginning(object drinker, int amount, int id) {
  drinker->submit_ee("reduce", ({ 2, 10 }), EE_CONTINUOUS);
  if(amount < required(drinker)) {
    tell_object(drinker, "A warming sensation glows in your stomach, "
                         "but it quickly fades and becomes a quiet "
                         "glow.\n");
    amount /= IMM_FALL;
    return amount;
  }
  tell_object(drinker, "A warming sensation glows in your stomach, "
                       "lasting for a few moments.\n");
  return to_int(gift(drinker, amount) / IMM_FALL);
}

int merge_effect(object drinker, int old_amount, int new_amount, int id) {
  if(old_amount + new_amount < required(drinker)) {
    tell_object(drinker, "Your stomach warms again, but once again "
                         "it fades to a quiet glow.\n");
    new_amount /= IMM_FALL;
    return old_amount + new_amount;
  }
  else {
    tell_object(drinker, "The warmth in your stomach heats up, lasting "
                         "a while before cooling again.\n");
    return to_int(gift(drinker, old_amount + new_amount));
  }
}

void end(object drinker, int amount, int id) {
  tell_object(drinker, "The quiet glow in your stomach "
              "fades completely.\n");
}

int required(object ob) {
  return REQ_BASE + pow(ob->query_max_deaths()-6, REQ_EXP);
}

int gift(object ob, int amount) {
  if(ob->query_con() > CON_DROP) {
    ob->adjust_tmp_con(-CON_DROP);
    amount -= required(ob);
    ob->adjust_max_deaths(1);
    tell_object(ob, "Your muscles relax as a calming wave passes "
                    "through you, leaving you feeling weak.\n");
    return amount / IMM_FALL;
  }
  return amount;
}

void reduce(object ob, int arg, int id) {
  if(arg < CUT_OFF) {
    ob->submit_ee(0, 0, EE_REMOVE);
  }
  else {
    arg /= IMM_FALL;
    ob->set_arg_of(ob->sid_to_enum(id), arg);
  }
}

string query_classification() { return "body.ingested.life_potion";}
