
#include <std.h>

#define COL "%^BOLD%^%^GREEN%^"
#define COL2 "%^BOLD%^%^BLACK%^"
#define RES "%^RESET%^"

#define FAIL(s) return notify_fail(s+"\n")

#define BONESHIELD_OB "/cmds/skills/obj/boneshield_ob"
#define BONESHIELD_ID "boneshield_ob_id"
#define BONESHIELD_PROP "boneshield_spell_time"

inherit DAEMON;

object *shields=({});

int spell() {
  object tp=this_player();
  if (tp && tp->query_subclass() == "necromancer" &&
      tp->query_skill("necromancy") >= 6*25 &&
      tp->query_skill("magic defense") >= 4*25)
        return 1;
  return 0;
}

string type() { return "defense"; }

void help() {
  message("help",
    "Syntax: <boneshield>\n\n"
    "This necromancy spell enhances the bones from a dead body and "
    "turns them into a shield that can be worn.",
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

int cmd_boneshield(string str) {
  object tp=this_player();
  object env=environment(tp);
  object corpse;
  object shield;
  object *corpses;
  int cost, secs, ac;

  if (!spell()) return 0;

  corpses = filter(all_inventory(env), (: ($1->query_corpse() && !$1->is_living()) :) );
  if (sizeof(corpses))
    corpse=corpses[0];

  if (!can_cast(tp, corpse)) return 0;

  secs = 130;
  secs += (tp->query_skill("necromancy")-(6*25))/4;

  ac = 2;
  ac += (tp->query_skill("necromancy")-(6*25))/(6*5);
  ac += (tp->query_skill("magic defense")-(4*25))/(6*7);
  if (ac > 5) ac=5+(ac-5)/5;
  if (ac > 7) ac=7;
  
  cost = secs*2 + ac*15;

  if (tp->query_mp() < cost)
    FAIL("You need more magic.");

  if (!(shield=new(BONESHIELD_OB)))
    FAIL("An error occurred, please contact a staff member.");

  tp->add_mp(-(cost+random(cost/15)));
  tp->set_magic_round(2);
  tp->add_alignment(-3);

  message("magic", COL+"You reinforce the "+COL2+"bones"+COL+" from the corpse "
                   "with "+COL2+"shielding"+COL+" power."+RES, tp);
  message("magic", COL+tp->query_cap_name()+" reinforces the "+COL2+"bones"+COL+
                   " from the corpse with "+COL2+"shielding"+COL+" power."+RES,
                   env, tp);
  message("magic", COL2+"The rest of the "+RES+"body"+COL2+
                   " turns to "+RES+"dust"+COL2+"."+RES, env);

  shield->set_id(shield->query_id()+({BONESHIELD_ID}));
  shield->set_property(BONESHIELD_PROP, time()+secs);
  shield->setup(tp, ac);
  
  set_heart_beat(1);
  shields += ({shield});

  if (shield->move(tp))
    shield->move(env);
  corpse->remove();

  return 1;
}

void heart_beat() {
  foreach (object s in shields) {
    if (!s) shields -= ({s});
    else if (s->query_property(BONESHIELD_PROP) <= time()) {
      message("magic", "The "+s->query_name()+" decays and falls apart.",
        environment(s) );
      shields -= ({s});
      s->remove();
    }
  }
  if (!sizeof(shields)) set_heart_beat(0);
}

