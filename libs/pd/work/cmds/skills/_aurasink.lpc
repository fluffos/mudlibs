
#include <std.h>

#define FAIL(s) return notify_fail(s+"\n");

#define RES "%^RESET%^"
#define COL RES+"%^CYAN%^"
#define COL2 RES+"%^RED%^"

#define AURASINK_OB "/cmds/skills/obj/aurasink_ob"
#define AURASINK_ID "aurasink_ob_id"

inherit DAEMON;

int spell() {
  object tp=this_player();
  if (tp &&
      member_array(tp->query_subclass(), ({"kataan","antipaladin"})) != -1 &&
      tp->query_skill("magic defense") >= to_int(17*3/2) && // 25 md
      tp->query_skill("magic attack") >= 17*5) // 85 ma
        return 1;
  return 0;
}

string type() { return "defense"; }

void help() {
  message("help",
    "Syntax: <aurasink>\n\n"
    "Using this dark spell creates a magical aura of malevolent force "
    "around the caster. This aura drinks in the natural defenses of "
    "anyone around, and uses this stolen "
    "power to sustain itself and protect the caster.",
    this_player() ); 
}

int can_cast(object tp) {

  if (!tp) return 0;

  if (environment(tp)->query_property("no magic"))
    FAIL("Some force prevents your magic.");

  if (!alignment_ok(tp))
    FAIL("You have betrayed the source of your powers.");

  if (present(AURASINK_ID, tp))
    FAIL("You are already surrounded by that magic.");
  
  return 1;
}

int cmd_aurasink(string str) {
  object tp=this_player();
  object env=environment(tp);
  object ob;
  int rounds, init, max, cost, decay;

  if (!spell()) return 0;

  if (!can_cast(tp)) return 0;

  init = (tp->query_level()-20)/15;
  max = (tp->query_skill("magic attack")/5)/7;
  rounds = tp->query_skill("magic defense")*3/4;
  decay = (tp->query_stats("wisdom")-20)/3;

  if (init < 1) init=1;
  if (init > 3) init=3;
  if (max < 2) max=2;
  if (max > 10) max=10;
  if (init > max) init=max;
  if (rounds < 35) rounds=35;
  if (decay < 5) decay=5;
  if (decay > 25) decay=25;

  cost = to_int(rounds*5/2) + init*30 + max*5;

  if (tp->query_mp() < cost)
    FAIL("You are too low on magic to cast that.");

  tp->add_mp(-(cost+random(cost/13)));

  if (!(ob=new(AURASINK_OB)))
    FAIL("An error occurred, please contact a staff member.");

  ob->set_id(ob->query_id()+({AURASINK_ID}) );
  ob->setup(tp, init, max, rounds, decay);
  ob->move(tp);

  message("magic", COL+"A "+COL2+"dark aura"+COL+
                   " sh"+COL2+"i"+COL+"mm"+COL2+"e"+COL+"rs "
                   "into existence around you."+RES, tp);
  message("magic", COL+"A "+COL2+"dark aura"+COL+
                   " sh"+COL2+"i"+COL+"mm"+COL2+"e"+COL+"rs "
                   "into existence around "+tp->query_cap_name()+"."+RES, env, tp);
  
  return 1;
}

