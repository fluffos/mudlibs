
#include <std.h>

#define COL "%^BLUE%^"
#define RES "%^RESET%^"

#define VANISH_PROP "vanish_abil_time"
#define VANISH_DELAY 20

#define FAIL(s) return notify_fail(s+"\n")

inherit DAEMON;

/*
 * who = ({
 *   ({ attacker, this player, time }),
 *   ({ attacker, other player, time }),
 *   ...
 * });
 */
mixed *who = ({ });

// this will be level 36 for scout, 40 for assassin/thief
int abil() {
  object tp = this_player();
  if (tp &&
      member_array(tp->query_subclass(),
        ({ "assassin", "scout", "thief" }) ) != -1 &&
      tp->query_skill("stealth") >= 40*5 &&
      tp->query_skill("agility") >= 30*6)
        return 1;
  return 0;
}

string type() { return "defense"; }

void help() {
  message("help",
    "Syntax: <vanish>\n\n"
    "Sometimes even a rogue can get surrounded by enemies, "
    "but the quickest ones can dodge between the bodies "
    "and vanish from the fight for a moment. In the short "
    "time he has, the rogue can make a run for it, or maybe "
    "try to even the odds with a sneak attack.",
    this_player() );
}

int can_cast(object tp, int s) {

  if (!tp) return 0;

  if (s == 0)
    FAIL("You are not fighting anyone right now.");

  if (tp->query_busy())
    FAIL("You're too busy to vanish from combat!");

  if (s < 2)
    FAIL("There aren't enough opponents to vanish.");

  foreach (string l in tp->query_walking_limbs())
    if (member_array(l, tp->query_severed_limbs()) != -1)
      FAIL("You can't do that without your "+l+"!");

  if (tp->query_sp() < 250)
    FAIL("You need more energy to vanish!");

  if (tp->query(VANISH_PROP)+VANISH_DELAY > time())
    FAIL("You can't push your body so hard this soon.");

  return 1;
}

int cmd_vanish(string str) {
  object tp = this_player();
  object env = environment(tp);
  object *atkrs;
  int s, cost, stealth, flag;

  if (!abil()) return 0;

  tp->clean_up_attackers();
  atkrs = tp->query_attackers();
  s = sizeof(atkrs);

  if (!can_cast(tp, s)) return 0;

  stealth = tp->query_skill("agility")/2;
  stealth += tp->query_skill("stealth")/2;
  stealth += random(stealth);
  stealth += tp->query_stats("dexterity")*3;

  // stealth-350 is safe because the skill reqs ensure stealth
  // will be at least 420
  cost = 110 + log(pow(stealth-350, 9));
  cost += (cost/4)*(s-2);
  cost += random(cost/13);

  if (tp->query_sp() < cost)
    FAIL("You need more energy to vanish!");

  tp->add_sp(-cost);
  tp->set_disable(1);
  tp->set(VANISH_PROP, time());
  set_heart_beat(1);

  foreach (object atk in atkrs) {
    int perc, time;

    perc = atk->query_skill("perception")*9/4;
    perc += atk->query_stats("intelligence")*4;
    // more opponents makes it easier to vanish
    perc -= (s-2)*(stealth-400);

    perc = stealth - perc;

    // how many rounds before they find us again
    if (perc < 1)
      time = 0;
    else if (perc <= 80)
      time = 1;
    else
      time = 2;
    
    if (time) {
      flag = 1;
      atk->remove_attacker(tp);
      tp->remove_attacker(atk);
      who += ({ ({ atk, tp, time()+time*2 }) });
    }
  }

  if (flag) {
    message("combat", "You run and do"+COL+"dg"+RES+"e "
                      "b"+COL+"e"+RES+"t"+COL+"wee"+RES+"n "
                      "your opponents, and "+COL+"vanish"+RES+
                      " from sight for a moment.", tp);
    tp->add_stealth(15);
  }
  else
    message("combat", "You run and dodge between your opponents, "
                      "but don't manage to get away.", tp);

  return 1;
}

void heart_beat() {
  foreach (mixed *args in who) {
    object atk = args[0];
    object tp = args[1];
    int time = args[2];

    if (!atk || !tp || !time) {
      who -= ({ args });
      continue;
    }

    if (time <= time()) {
      if (member_array(tp, atk->query_attackers()) == -1) {
        if (environment(tp) == environment(atk)) {
          atk->force_me("kill "+tp->query_name());
          atk->kill_ob(tp);
        }
        else {
          atk->add_attacker(tp);
          tp->add_attacker(atk);
        }
      }
      tp->add_stealth(-15);
      who -= ({ args });
    }
  }
  if (!sizeof(who)) set_heart_beat(0);
}


