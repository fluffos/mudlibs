
#include <std.h>

#define COL "%^YELLOW%^"
#define RES "%^RESET%^"

#define FAIL(s) return notify_fail(s)
#define AMULET "/cmds/skills/obj/soulward_amulet"
#define CHECK "soulward_spell"
#define HOW_OFTEN 60*60*24*4

inherit DAEMON;

int spell() {
  object tp=this_player();
  if (tp && tp->query_subclass() == "cleric" &&
      tp->query_skill("belief") >= 60*6 &&
      tp->query_skill("faith") >= 60*6 &&
      tp->query_skill("healing") >= 60*6 &&
      tp->query_skill("magic defense") >= 60*5 &&
      tp->query_skill("conjuring") >= 60*3)
        return 1;
  return 0;
}

string type() { return "conjuring"; }

void help() {
  message("help",
    "Syntax: <soulward>\n\n"
    "This spell creates a special amulet which can "
    "protect the soul and life of the one who wears it. "
    "These amulets are only granted by the gods occaisonally.",
    this_player() );
}

int can_cast(object tp) {

  if (!tp) return 0;

  if (environment(tp)->query_property("no magic"))
    FAIL("Some force interferes with your spell.\n");

  if (tp->query_ghost())
    FAIL("You cannot cast spells while dead.\n");

  if (!alignment_ok(tp))
    FAIL("You have betrayed the source of your powers.\n");
  
  if (tp->query(CHECK)+HOW_OFTEN > time())
    FAIL("You may not create another soulward yet.\n");
  
  return 1;
}

int cmd_soulward(string str) {
  object tp=this_player();
  object env=environment(tp);
  object am;
  int cost, time, ac;

  if (!spell()) return 0;
  if (!can_cast(tp)) return 0;

  time = tp->query_skill("conjuring");
  time += tp->query_skill("faith");
  time += tp->query_skill("belief");
  time += tp->query_skill("healing");
  time += tp->query_skill("magic defense");
  time *= 2+((tp->query_stats("wisdom")-100)/35);
  
  cost = tp->query_max_mp();

  if (tp->query_mp() < cost)
    FAIL("You need all of your magical powers to do that.\n");
  
  tp->add_mp(-(cost+200));

  if (!(am = new(AMULET)))
    FAIL("A bug occurred. Please contact a staff member.\n");

  // the amulet needs the time in heart_beats, so /2
  am->setup(tp, time/2);
  if (am->move(tp))
    am->move(env);

  tp->set(CHECK, time());

  message("magic", COL+"A small object forms out of nowhere. "
                   "It glows brilliantly."+RES, env);

  return 1;
}
