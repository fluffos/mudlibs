//      _keep.c
//      mage spell
//      created by Descartes of Borg 921116
//
//      cleaned up by Nulvect 2011-09-28

#include <std.h>
#include <daemons.h>

#define FAIL(s) return notify_fail(s)

inherit DAEMON;

void help() {
  message("help",
    "Syntax: <keep [what] for [player]>\n"
    "\n"
    "This spell makes it impossible for anyone to carry an object other\n"+
    "than the person named by the spell caster. The duration of the spell\n"+
    "is based on the spell casters ability to cast conjuring spells.",
    this_player()
  );
}

int spell() {
  object tp = this_player();
  if (tp && tp->query_class() == "mage" && tp->query_level() >= 9)
    return 1;
  return 0;
}

string type() { return "conjuring"; }

int can_cast(object tp, object item, string who) {
  if (!tp) return 0;

  if (environment(tp)->query_property("no magic"))
    FAIL("Some force prevents your magic.");

  if (tp->query_busy())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("Your spell fails.");

  if (!item || !who)
    FAIL("Keep what for whom?");

  if (item->query_property("no keep") || item->query_property("keep"))
    FAIL("It resists your spell.");

  if (tp->query_mp() < 25)
    FAIL("Too low on magic.");

  return 1;
}

int cmd_keep(string str) {
  object ob, owner;
  string who, what;
  int conj, cost, time;
  object tp = this_player();
  object env = environment(tp);

  if (!spell())
    return 0;

  if (str && sscanf(str, "%s for %s", what, who) == 2) {
    ob = present(what, env);
    if (!ob)
      ob = present(what, tp);
    who = lower_case(who);
  }

  if (!can_cast(tp, ob, who))
    return 0;

  conj = tp->query_skill("conjuring");
  cost = conj + random(conj);
  time = conj*8 + random(conj);

  if (tp->query_mp() < cost)
    FAIL("Too low on magic power.");

  message("magic",
    "You cast a spell to keep the "+what+
    " in "+capitalize(who)+"'s possession.", tp
  );
  message("magic",
    tp->query_cap_name()+" casts a spell of keeping on "+
    definite_article(what)+".",
    env, tp
  );

  ob->set_property("keep", who);
  tp->add_skill_points("conjuring", cost/6);
  tp->add_mp(-cost);

  DELAY_D->add_delay(time, this_object(), "remove_keep", ({ ob }), 1);

  return 1;
}

void remove_keep(object ob) {
  if (ob)
    ob->remove_property("keep");
}

