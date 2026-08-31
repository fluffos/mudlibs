
#include <std.h>
#include <reaction_cl.h>

#define FAIL(s) return notify_fail(s+"\n");

#define COL "%^BOLD%^%^BLUE%^"
#define RES "%^RESET%^"

int parry_attack(class Reaction);
void parry_post(class Reaction);

mapping types = ([
  "blade" : 100,
  "projectile" : 120,
  "axe" : 80,
  "blunt" : 90,
]);

int abil() {
  object tp = this_player();
  if (tp &&
      (tp->query_class() == "fighter" ||
      tp->query_subclass() == "swashbuckler") &&
      tp->query_level() >= 3)
        return 1;
  return 0;
}

string type() { return "defense"; }

void help() {
  message("help",
    "Syntax: <parry [who]>\n\n"
    "This lets you block an oncoming attack.",
    this_player() );
}

int can_cast(object tp, object tgt, object *weps) {

  if (!tp) return 0;

  if (tp->query_busy())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("You are dead.");

  if (!sizeof(weps))
    FAIL("You must wield a blade, spear, axe, or blunt weapon to parry.");

  if (tp->query_rest_type())
    FAIL("You must stand up first!");

  if (!tgt)
    FAIL("Parry who?");

  if (member_array(tgt, tp->query_attackers()) == -1)
    FAIL("You are not fighting "+tgt->query_objective()+"!");

  if (environment(tp)->query_property("no attack"))
    FAIL("Some force prevents violence here.");

  if (tp->query_reaction_name("parry"))
    FAIL("You are already trying to parry!");

  return 1;
}

int cmd_newparry(string str) {
  object tp = this_player();
  object env = environment(tp);
  object tgt;
  object *weps;
  class Reaction parry;

  if (!abil()) return 0;

  if (str)
    tgt = present(str, env);
  else
    tgt = tp->query_current_attacker();

  weps = filter(tp->query_wielded(), (:
    member_array($1->query_type(), $2) != -1
  :), keys(types) );

  if (!can_cast(tp, tgt, weps)) return 0;

  parry = new(class Reaction);
  init_reaction(parry);
  parry->name = "parry";
  parry->time = time()+4;
  parry->type = REACTION_TYPE_ATTACK | REACTION_TYPE_PHYSICAL;
  parry->ignore =
    REACTION_TYPE_MAGIC | REACTION_TYPE_FAITH | REACTION_TYPE_SONG |
    REACTION_TYPE_DANCE | REACTION_TYPE_CONJURING;
  parry->func = (: parry_attack :);
  parry->postfunc = (: parry_post :);
  parry->misc = weps;

  tp->add_reaction(parry);
  tp->add_sp(-(2+random(3)));
  message("combat", "You prepare to parry the next attack.", tp);

  return 1;
}

int parry_attack(class Reaction parry) {
  object tp = parry->current["target"];
  object tgt = parry->current["subject"];
  object *weps = parry->misc;
  string sk;
  int def, cost;

  if (!tp) return 0;

  weps = filter(weps, (: ($1 && $1->query_wielded() == $2) :), tp);

  // not wielding any of the weapons we started with
  if (!sizeof(weps)) {
    return REACTION_FAILED;
  }

  cost = 5+random(5+tp->query_skill("defense")/15);

  if (tp->query_sp() < cost) {
    message("combat", "You try to parry, but you are too tired.", tp);
    return REACTION_FAILED;
  }

  sk = weps[random(sizeof(weps))]->query_type();

  def = tp->query_skill("defense");
  def += tp->query_skill(sk)*types[sk]/100;
  def += tp->query_stats("dexterity");
  if (sizeof(tp->query_wielded()) > 1)
    def += tp->query_skill("double wielding")/2;

  def -= tgt->query_skill("attack");
  def -= tgt->query_skill("agility");
  def -= tgt->query_stats("strength");

  if (def < 1) {
    message("combat", "You try to parry, but you are too slow!", tp);
    return REACTION_FAILED;
  }

  message("combat", "You parry the blow aside!", tp);
  tp->add_magic_protection( ({ 0, def, 0 }) );
  parry->misc = def;

  return REACTION_SUCCEEDED;
}

void parry_post(class Reaction parry) {
  object tp = parry->current["target"];
  int def = parry->misc;
  if (tp)
    tp->add_magic_protection( ({ 0, -def, 0 }) );
}

