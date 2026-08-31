
#include <std.h>

#define COL "%^BOLD%^%^GREEN%^"
#define COL2 "%^BOLD%^%^BLACK%^"
#define RES "%^RESET%^"

#define FAIL(s) return notify_fail(s+"\n")

#define SKULLHELM_OB "/cmds/skills/obj/skullhelm_ob"
#define SKULLHELM_ID "skullhelm_ob_id"
#define SKULLHELM_PROP "skullhelm_spell_time"

inherit DAEMON;

object *helms=({});

int spell() {
  object tp=this_player();
  if (tp && tp->query_subclass() == "necromancer" &&
      tp->query_skill("necromancy") >= 6*32 &&
      tp->query_skill("magic defense") >= 4*32)
        return 1;
  return 0;
}

string type() { return "defense"; }

void help() {
  message("help",
    "Syntax: <skullhelm>\n\n"
    "This necromancy spell infuses a skull with magic to harden it "
    "and make it into a suitable helmet.",
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

int cmd_skullhelm(string str) {
  object tp=this_player();
  object env=environment(tp);
  object corpse;
  object helm;
  object *corpses;
  int cost, secs, ac;

  if (!spell()) return 0;

  corpses = filter(all_inventory(env), (: ($1->query_corpse() && !$1->is_living()) :) );
  if (sizeof(corpses))
    corpse=corpses[0];

  if (!can_cast(tp, corpse)) return 0;

  secs = 150;
  secs += (tp->query_skill("necromancy")-(6*32))/4;

  ac = 3;
  ac += (tp->query_skill("necromancy")-(6*32))/(6*5);
  ac += (tp->query_skill("magic defense")-(4*32))/(6*7);
  if (ac > 6) ac=6+(ac-6)/5;
  if (ac > 8) ac=8;
  
  cost = secs*2 + ac*15;

  if (tp->query_mp() < cost)
    FAIL("You need more magic.");

  if (!(helm=new(SKULLHELM_OB)))
    FAIL("An error occurred, please contact a staff member.");

  tp->add_mp(-(cost+random(cost/15)));
  tp->set_magic_round(2);
  tp->add_alignment(-3);

  message("magic", COL+"You infuse the "+COL2+"skull"+COL+" from the corpse "
                   "with magic to "+COL2+"harden"+COL+" it."+RES, tp);
  message("magic", COL+tp->query_cap_name()+" infuses the "+COL2+"skull"+COL+
                   " from the corpse with magic to "+
                   COL2+"harden"+COL+" it."+RES,
                   env, tp);
  message("magic", COL2+"The rest of the "+RES+"body"+COL2+
                   " turns to "+RES+"dust"+COL2+"."+RES, env);

  helm->set_id(helm->query_id()+({SKULLHELM_ID}));
  helm->set_property(SKULLHELM_PROP, time()+secs);
  helm->setup(tp, ac);
  
  set_heart_beat(1);
  helms += ({helm});

  if (helm->move(tp))
    helm->move(env);
  corpse->remove();

  return 1;
}

void heart_beat() {
  foreach (object w in helms) {
    if (!w) helms -= ({w});
    else if (w->query_property(SKULLHELM_PROP) <= time()) {
      message("magic", "The "+w->query_name()+" decays and falls apart.",
        environment(w) );
      helms -= ({w});
      w->remove();
    }
  }
  if (!sizeof(helms)) set_heart_beat(0);
}

