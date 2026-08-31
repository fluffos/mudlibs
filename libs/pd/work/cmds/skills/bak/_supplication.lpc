
#include <std.h>
#include <daemons.h>

#define FAIL(s) return notify_fail(s+"\n");
#define COL "%^BOLD%^%^WHITE%^"
#define COL2 "%^BOLD%^%^CYAN%^"
#define RES "%^RESET%^"

#define SUPPLICATION_PROP "supplication_spell_time"

inherit DAEMON;

mapping bonus = ([
  /*
  "attack" : ({ "skill", 0.15 }),
  "defense" : ({ "skill", 0.15 }),
  */
  "strength" : ({ "stat", 0.15 }),
  "dexterity" : ({ "stat", 0.15 }),
  "constitution" : ({ "stat", 0.25 }),
]);

int spell() {
  object tp = this_player();
  if (tp && tp->query_subclass() == "monk" &&
      tp->query_skill("faith") >= 12*6)
        return 1;
  return 0;
}

string type() { return "faith"; }

void help() {
  message("help",
    "Syntax: <supplication [whom]>\n\n"
    "Monks can pray for divine aid to be granted upon themselves "
    "or their comrades, increasing the target's physical prowess.",
    this_player() );
}

int can_cast(object tp, object tgt) {

  if (!tp) return 0;

  if (environment(tp)->query_property("no magic"))
    FAIL("Some force prevents your power.");

  if (tp->query_busy())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("Your prayers come out as howls.");

  if (tp->query_current_attacker())
    FAIL("You are too busy fighting!");

  if (!tgt)
    FAIL("Perform supplication for whom?");

  if (!living(tgt))
    FAIL("That is not alive.");

  if (!alignment_ok(tp))
    FAIL("Your prayers go unanswered.");

  if (tgt->query(SUPPLICATION_PROP) > time())
    FAIL("You have already performed supplication for "+
        (tgt == tp ? "yourself" : tgt->query_objective())+".");

  if (tp->query_mp() < 50)
    FAIL("Your magic is too low.");
  
  return 1;
}

int cmd_supplication(string str) {
  object tp = this_player();
  object env = environment(tp);
  object tgt;
  int time, cost, flag = 0;
 
  if (!spell()) return 0;

  if (!str || str == "me")
    tgt = tp;
  else
    tgt = present(str, env);

  if (!can_cast(tp, tgt)) return 0;

  time = tp->query_skill("faith")/2 + tp->query_stats("wisdom");

  cost = time*2;
  if (tp->query_mp() < cost)
    FAIL("Your magic is too low.");

  foreach (string what, mixed *info in bonus) {
    switch (info[0]) {
      case "skill":
        if (tgt->query_skill_bonus(what) > 0) continue;
        tgt->add_skill_bonus(what,
            to_int(tgt->query_base_skill(what)*info[1]), time);
      break;
      case "stat":
        if (tgt->query_stat_bonus(what) > 0) continue;
        tgt->add_stat_bonus(what,
            to_int((int)tgt->query_base_stats()[what]*info[1]), time);
      break;
    }
    flag = 1;
  }

  if (!flag)
    FAIL("Some other power has already enhanced "+
        (tgt == tp ? "you" : tgt->query_objective())+".");
  
  message("magic", COL+"You pray for divine aid."+RES, tp);
  message("magic", COL+tp->query_cap_name()+" prays for divine aid."+RES, env, tp);
  message("magic", COL2+"You feel an "+COL+"incredible boost"+COL2+
      " in your strength and stamina."+RES, tgt);
  message("magic", COL2+tgt->query_cap_name()+" suddenly looks "+
      COL+"stronger"+COL2+" and more imposing."+RES, env, tgt);

  tp->add_mp(-(cost+random(cost/7)));
  tp->set_magic_round(1);

  tgt->set(SUPPLICATION_PROP, time()+time);
  DELAY_D->add_delay(time, this_object(), "supp_off", ({ tgt }), 1);

  return 1;
}

void supp_off(object tgt) {
  object env;
  if (!tgt) return;
  env = environment(tgt);

  message("magic", COL2+"The powers of supplication fade away."+RES, tgt);
  message("magic", COL2+tgt->query_cap_name()+" seems to return to "+
      tgt->query_possessive()+" normal strength."+RES, env, tgt);
}

