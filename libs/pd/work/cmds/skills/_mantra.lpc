
#include <std.h>

#define COL "%^BOLD%^%^WHITE%^"
#define RES "%^RESET%^"

#define FAIL(s) return notify_fail(s+"\n")

#define MANTRA_PROP "mantra_abil_time"
#define MANTRA_TIME 24

inherit DAEMON;

int spell() {
  object tp=this_player();
  if (tp && tp->query_subclass() == "monk" &&
      tp->query_skill("healing") >= to_int(30*2.5) &&
      tp->query_skill("faith") >= 30*6)
        return 1;
  return 0;
}

string type() { return "healing"; }

void help() {
  message("help",
    "Syntax: <mantra>\n\n"
    "Monks can use a short mantra to focus their chi and restore some of their own stamina.",
    this_player() );
}

int can_cast(object tp) {
  if (!tp) return 0;

  if (environment(tp)->query_property("no magic"))
    FAIL("Some force prevents that.");

  if (tp->query_busy())
    FAIL("You are busy.");

  if (sizeof(tp->query_attackers()))
    FAIL("You cannot focus while fighting.");

  if (tp->query(MANTRA_PROP)+MANTRA_TIME > time())
    FAIL("You are unable to focus again so soon.");
  
  return 1;
}

int cmd_mantra(string str) {
  object tp=this_player();
  object env=environment(tp);
  int heal, cost;

  if (!spell()) return 0;

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
  tp->set(MANTRA_PROP, time());
  tp->add_sp(heal);
  
  message("magic", COL+"You focus your chi into a boost of energy."+RES, tp);
  message("magic", COL+tp->query_cap_name()+" focuses inward."+RES, env, tp);
  
  return 1;
}

