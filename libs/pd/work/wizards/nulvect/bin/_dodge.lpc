
#include <std.h>

#define COL "%^YELLOW%^"
#define RES "%^RESET%^"

#define FAIL(s) return notify_fail(s+"\n")

#define DODGE_PROP "dodge_abil_time"

inherit DAEMON;

int abil() {
  object tp = this_player();
  if (tp && tp->query_class() == "rogue" && tp->query_level() >= 2)
    return 1;
  return 0;
}

string type() { return "defense"; }

void help() {
  message("help",
    "Syntax: <dodge>\n\n"
    "A rogue's ability to dodge his opponent's blows for a while.",
    this_player() );
}

int can_cast(object tp) {
  if (!tp) return 0;

  if (tp->query_busy())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("You float around.");

  if (tp->query_sp() < 20)
    FAIL("You are too tired.");

  if (!sizeof(tp->query_attackers()))
    FAIL("You're not fighting anyone!");

  if (tp->query(DODGE_PROP) >= time())
    FAIL("You are already dodging!");

  return 1;
}

int cmd_dodge(string str) {
  object tp = this_player();
  object env = environment(tp);
  int rounds, bonus, cost;

  if (!abil()) return 0;

  if (!can_cast(tp)) return 0;

  rounds = 5 + tp->query_level()/10;
  rounds += tp->query_skill("defense")/(4*9);
  if (rounds > 8) rounds = 8 + ((rounds-8)/2);
  if (rounds > 12) rounds = 12 + ((rounds-12)/2);

  bonus = tp->query_skill("agility");

  cost = rounds*3 + bonus/11;

  if (tp->query_sp() < cost)
    FAIL("You are too tired.");


  tp->add_sp(-cost);
  tp->add_skill_bonus("defense", bonus, rounds*2);
  tp->set(DODGE_PROP, time()+rounds*2);

  message("combat", "You "+COL+"dodge"+RES+" around, trying not to get hit.", tp);
  message("combat", tp->query_cap_name()+" starts to "+COL+"dodge"+RES+
    " back and forth.", env, tp);

  return 1;
}

