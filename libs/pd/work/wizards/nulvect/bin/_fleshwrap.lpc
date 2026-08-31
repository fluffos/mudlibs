
#include <std.h>

#define COL "%^BOLD%^%^GREEN%^"
#define COL2 "%^BOLD%^%^BLACK%^"
#define RES "%^RESET%^"

#define FAIL(s) return notify_fail(s+"\n")

#define FLESHWRAP_OB "/cmds/skills/obj/fleshwrap_ob"
#define FLESHWRAP_ID "fleshwrap_ob_id"
#define FLESHWRAP_PROP "fleshwrap_spell_time"

inherit DAEMON;

object *wraps=({});

int spell() {
  object tp=this_player();
  if (tp && tp->query_subclass() == "necromancer" &&
      tp->query_skill("necromancy") >= 6*18 &&
      tp->query_skill("magic defense") >= 4*18)
        return 1;
  return 0;
}

string type() { return "defense"; }

void help() {
  message("help",
    "Syntax: <fleshwrap>\n\n"
    "This necromancy spell hardens the flesh of a corpse so that "
    "it can be worn as a light armour.",
    this_player() );
}

int can_cast(object tp, object corpse) {

  if (!tp) return 0;

  if (environment(tp)->query_property("no magic"))
    FAIL("Some force prevents your spell.");

  if (tp->query_disable() || tp->query_casting() || tp->query_magic_round())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("In a humorous twist of fate, your necromancy doesn't work while you're dead.");

  if (!corpse)
    FAIL("You need a fresh corpse first.");
  
  return 1;
}

int cmd_fleshwrap(string str) {
  object tp=this_player();
  object env=environment(tp);
  object corpse;
  object wrap;
  object *corpses;
  int cost, secs, ac;

  if (!spell()) return 0;

  corpses = filter(all_inventory(env), (: ($1->query_corpse() && !$1->is_living()) :) );
  if (sizeof(corpses))
    corpse=corpses[0];

  if (!can_cast(tp, corpse)) return 0;

  secs = 90;
  secs += (tp->query_skill("necromancy")-(6*18))/4;

  ac = 2;
  ac += (tp->query_skill("necromancy")-(6*18))/(6*5);
  ac += (tp->query_skill("magic defense")-(4*18))/(6*7);
  if (ac > 5) ac=5+(ac-5)/5;
  if (ac > 7) ac=7;
  
  cost = secs*2 + ac*15;

  if (tp->query_mp() < cost)
    FAIL("You need more magic.");

  if (!(wrap=new(FLESHWRAP_OB)))
    FAIL("An error occurred, please contact a staff member.");

  tp->add_mp(-(cost+random(cost/15)));
  tp->set_magic_round(2);
  tp->add_alignment(-3);

  message("magic", COL+"You harden the "+COL2+"flesh"+COL+" from the corpse "
                   "into "+COL2+"armour"+COL+"."+RES, tp);
  message("magic", COL+tp->query_cap_name()+" hardens the "+COL2+"flesh"+COL+
                   " from the corpse into "+COL2+"armour"+COL+"."+RES,
                   env, tp);
  message("magic", COL2+"The rest of the "+RES+"body"+COL2+
                   " turns to "+RES+"dust"+COL2+"."+RES, env);

  wrap->set_id(wrap->query_id()+({FLESHWRAP_ID}));
  wrap->set_property(FLESHWRAP_PROP, time()+secs);
  wrap->setup(tp, ac);
  
  set_heart_beat(1);
  wraps += ({wrap});

  if (wrap->move(tp))
    wrap->move(env);
  corpse->remove();

  return 1;
}

void heart_beat() {
  foreach (object w in wraps) {
    if (!w) wraps -= ({w});
    else if (w->query_property(FLESHWRAP_PROP) <= time()) {
      message("magic", "The "+w->query_name()+" decays and falls apart.",
        environment(w) );
      wraps -= ({w});
      w->remove();
    }
  }
  if (!sizeof(wraps)) set_heart_beat(0);
}

