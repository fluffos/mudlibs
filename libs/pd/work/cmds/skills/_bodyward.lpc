
#include <std.h>

#define COL "%^CYAN%^"
#define RES "%^RESET%^"

#define FAIL(s) return notify_fail(s)
#define AMULET "/cmds/skills/obj/bodyward_amulet"
#define CHECK "bodyward_spell"

inherit DAEMON;

int spell() {
  object tp=this_player();
  if (tp && tp->query_subclass() == "cleric" &&
      tp->query_skill("magic defense") >= 33*5 &&
      tp->query_skill("conjuring") >= 33*3)
        return 1;
  return 0;
}

string type() { return "conjuring"; }

void help() {
  message("help",
    "Syntax: <bodyward>\n\n"
    "This spell creates a protective amulet.",
    this_player() );
}

int can_cast(object tp) {

  if (!tp) return 0;

  if (environment(tp)->query_property("no magic"))
    FAIL("Some force interferes with your spell.\n");

  if (tp->query_ghost())
    FAIL("You cannot cast spells while dead.\n");

  if (objectp(tp->query(CHECK)))
    FAIL("You may only create one bodyward at a time.\n");
  
  return 1;
}

int cmd_bodyward(string str) {
  object tp=this_player();
  object env=environment(tp);
  object am;
  int cost, time, ac;

  if (!spell()) return 0;
  if (!can_cast(tp)) return 0;

  time = tp->query_skill("conjuring")*6;
  time += tp->query_skill("magic defense")/8;
  time += tp->query_skill("belief")/6;
  
  cost = time/3;

  if (tp->query_mp() < cost)
    FAIL("Not enough magic.\n");
  
  tp->add_mp(-(cost+random(cost/15)));

  // every 5 levels of maxed md, gain 1 ac
  ac = 2;
  ac += (tp->query_skill("magic defense")-(33*5))/(5*5);

  if (!(am = new(AMULET)))
    FAIL("A bug occurred. Please contact a staff member.\n");

  // the amulet needs the time in heart_beats, so /2
  am->setup(tp, time/2, ac);
  if (am->move(tp))
    am->move(env);
  // when the amulet disappears the am var will be a 0
  tp->set(CHECK, am);

  message("magic", COL+"A small object forms out of nowhere. "
                   "It glows brightly."+RES, env);

  return 1;
}
