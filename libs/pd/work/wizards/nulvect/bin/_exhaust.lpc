
#include <std.h>
#include <daemons.h>

#define RES "%^RESET%^"
#define COL "%^BOLD%^%^BLACK%^"
#define COL2 "%^BOLD%^%^GREEN%^"
#define COL3 RES+"%^MAGENTA%^"

#define FAIL(s) return notify_fail(s+"\n")

inherit DAEMON;

int spell() {
  object tp=this_player();
  if (tp && tp->query_subclass() == "necromancer" &&
      tp->query_skill("necromancy") >= 31*6)
        return 1;
  return 0;
}

string type() { return "other"; }

void help() {
  message("help",
    "Syntax: <exhaust [whom]>\n\n"
    "",
    this_player() );
}

int can_cast(object tp, object tgt) {
  object env;
  
  if (!tp) return 0;

  env=environment(tp);
  if (env->query_property("no magic") || env->query_property("no attack"))
    FAIL("Some force prevents your spell.");

  if (tp->query_disable() || tp->query_casting() || tp->query_magic_round())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("You may not cast spells while dead.");

  if (!tgt)
    FAIL("Exhaust whom?");

  if (!living(tgt))
    FAIL("Only living things can be exhausted.");

  if (tp == tgt)
    FAIL("That would not be a good idea.");

  if (tgt->query_stat_bonus("constitution") < 0)
    FAIL(capitalize(tgt->query_subjective())+
      " has already been affected.");
  
  return 1;
}

int cmd_exhaust(string str) {
  object tp=this_player();
  object env=environment(tp);
  object tgt;
  int dmg, con, cost;
  float perc;

  if (!spell()) return 0;

  if (str)
    tgt=present(str, env);
  else
    tgt=tp->query_current_attacker();

  if (!can_cast(tp, tgt)) return 0;

  dmg = BALANCE3_D->get_damage(tp, tgt, 2,
    ({"necromancy"}),
    ({"intelligence"}) );

  dmg /= 3.8;

  perc = tp->query_stats("intelligence") - tgt->query_stats("wisdom");
  perc = perc/100.0;
  if (perc > 0.7) perc=0.7;

  con = tgt->query_base_stats("constitution")*perc;

  message("info", "Perc: "+(string)perc+", Con: "+(string)con, tp);

  cost = dmg+(con*2);

  if (tp->query_mp() < cost)
    FAIL("Your magic is too low.");

  tp->set_magic_round(1);
  tp->add_mp(-cost);

  message("magic", "You exhaust "+tgt->query_cap_name()+".", tp);
  message("magic", tp->query_cap_name()+" exhausts you.", tgt);
  message("magic", tp->query_cap_name()+" exhausts "+tgt->query_cap_name()+".",
    env, ({tp, tgt}) );

  tgt->add_stat_bonus("constitution", -con);
  tgt->add_sp(-dmg);
  if (tgt->query_sp() < -25)
    tgt->set_sp(-25);
  
  return 1;
}

