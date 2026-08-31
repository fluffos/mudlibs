
#include <std.h>

#define COL "%^BOLD%^%^WHITE%^"
#define RES "%^RESET%^"

#define FAIL(s) return notify_fail(s+"\n")

#define FOCUS_PROP "focus_abil_time"
#define FOCUS_TIME 24

inherit DAEMON;

int abil() {
  object tp=this_player();
  if (tp && tp->query_subclass() == "monk" &&
      tp->query_skill("healing") >= to_int(24*2.5))
        return 1;
  return 0;
}

string type() { return "other"; }

void help() {
  message("help",
    "Syntax: <focus>\n\n"
    "Monks can focus their chi to restore some of their own stamina.",
    this_player() );
}

int can_cast(object tp) {
  if (!tp) return 0;

  if (environment(tp)->query_property("no magic"))
    FAIL("Some force prevents that.");

  if (tp->query_disable() || tp->query_casting() || tp->query_magic_round())
    FAIL("You are busy.");

  if (sizeof(tp->query_attackers()))
    FAIL("You cannot focus while fighting.");

  if (tp->query(FOCUS_PROP)+FOCUS_TIME > time())
    FAIL("You are unable to focus again so soon.");
  
  return 1;
}

int cmd_focus(string str) {
  object tp=this_player();
  object env=environment(tp);
  int heal, cost;

  if (!abil()) return 0;

  if (!can_cast(tp)) return 0;

  heal = tp->query_level();
  heal += random(heal*2);
  heal += tp->query_skill("healing")*1.2;
  heal += tp->query_skill("faith")/4;
  heal += tp->query_stats("wisdom")*3/4;

  if (heal > 150) heal = 150+(heal-150)/3;
  
  cost = heal/3.3;

  if (tp->query_mp() < cost)
    FAIL("Your magic is too low.");

  tp->add_mp(-cost);
  tp->set_disable(2);
  tp->set(FOCUS_PROP, time());
  tp->add_sp(heal);
  
  message("magic", COL+"You focus your chi into a boost of energy."+RES, tp);
  message("magic", COL+tp->query_cap_name()+" focuses inward."+RES, env, tp);
  
  return 1;
}

