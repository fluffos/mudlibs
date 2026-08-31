
#include <std.h>
#include <daemons.h>

#define FAIL(s) return notify_fail(s+"\n")

#define COL "%^BOLD%^%^WHITE%^"
#define RES "%^RESET%^"

inherit DAEMON;

int abil() {
  object tp = this_player();
  if (tp && tp->query_subclass() == "swashbuckler")
    return 1;
  return 0;
}

string type() { return "attack"; }

void help() {
  message("help",
    "Syntax: <thrust [whom]>\n\n"
    "This is a basic thrusting attack with a sword, "
    "usually the first thing a swashbuckler learns.",
    this_player() );
}

int can_cast(object tp, object tgt, object *weps) {

  if (!tp) return 0;

  if (environment(tp)->query_property("no attack"))
    FAIL("Some force prevents your violence.");

  if (tp->query_busy())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("You cannot do that while dead.");

  if (!tgt)
    FAIL("Attack whom?");

  if (!sizeof(weps))
    FAIL("You must use a sword for that.");

  if (!tgt->is_living())
    FAIL("You thrust your sword at it, but nothing happens.");

  if (tgt == tp)
    FAIL("What a dishonorable way to die.");

  if (tp->query_rest_type())
    FAIL("You must stand up first!");

  if (tp->query_sp() < 10)
    FAIL("You are too tired.");

  if (!tp->ok_to_kill(tgt))
    FAIL("You cannot attack "+tgt->query_cap_name()+".");

  return 1;
}

int cmd_thrust(string str) {
  object tp = this_player();
  object env = environment(tp);
  object tgt, wep;
  object *weps;
  string limb;
  int rank, dmg, cost, level;

  if (!abil()) return 0;

  if (str)
    tgt = present(str, env);
  else
    tgt = tp->query_current_attacker();

  weps = filter(tp->query_wielded(), (: $1->query_type() == "blade" :) );

  if (!can_cast(tp, tgt, weps)) return 0;

  level = tp->query_level();

  rank=1 + level/13;

  dmg = BALANCE3_D->get_damage(tp, tgt, rank,
    ({ "blade", }),
    ({ "dexterity" }),
    ({ "strength", "dexterity" }) );

  // this does 70 - 90% of max damage, gaining 1% per level up to level 20
  if (level > 20) level = 20;
  dmg = dmg* (70+level) / 100;

  cost = dmg/13;

  if (tp->query_sp() < cost)
    FAIL("You are too tired.");

  tp->kill_ob(tgt);
  tp->add_sp(-cost);
  tp->set_disable();

  if (!tgt->query_blind() && 
      tgt->query_stats("dexterity") >
        tp->query_stats("dexterity")-random(10)+random(10)) {
    message("combat", "You thrust your blade at "+tgt->query_cap_name()+", "
                      "but "+tgt->query_subjective()+" dodges it.", tp);
    message("combat", tp->query_cap_name()+" thrusts "+tp->query_possessive()+
                      " blade at you, but you dodge it.", tgt);
    message("combat", tp->query_cap_name()+" thrusts "+tp->query_possessive()+
                      " blade at "+tgt->query_cap_name()+", but "+
                      tgt->query_subjective()+" dodges it.",
                      env, ({ tp, tgt }) );
    return 1;
  }

  do {
    limb = tgt->return_target_limb();
  } while (limb == "head");

  if (regexp(limb, "torso|abdomen"))
    dmg += random(dmg/7);

  message("combat", "You "+COL+"thrust"+RES+" your blade into "+
    tgt->query_cap_name()+"'s "+limb+"!", tp);
  message("combat", tp->query_cap_name()+" "+COL+"thrusts"+RES+" "+
    tp->query_possessive()+" blade into your "+limb+"!", tgt);
  message("combat", tp->query_cap_name()+" "+COL+"thrusts"+RES+" "+
    tp->query_possessive()+" blade into "+tgt->query_cap_name()+"'s "+limb+"!",
    env, ({ tp, tgt }) );

  tgt->do_damage(limb, dmg);

  return 1;
}

