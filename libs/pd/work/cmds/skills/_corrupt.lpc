
#include <std.h>

#define FAIL(s) return notify_fail(s+"\n")

#define COL "%^YELLOW%^"
#define COL2 "%^BOLD%^%^BLACK%^"
#define RES "%^RESET%^"

#define CORRUPT_PROP "corrupt_spell_data"

inherit DAEMON;

object *weps_corrupted = ({});

int corrupt_special(object atk, object wep);

int spell() {
  object tp = this_player();
  if (tp && tp->query_subclass() == "antipaladin" &&
      tp->query_level() >= 6)
        return 1;
  return 0;
}

string type() { return "faith"; }

void help() {
  message("help",
    "Syntax: <corrupt [weapon]>\n\n"
    "A dark spell that corrupts one's weapon with a demonic essence. "
    "The weapon will cause more damage against those of a good alignment.",
    this_player() );
}

int can_cast(object tp, object wep) {

  if (!tp) return 0;

  if (environment(tp)->query_property("no magic"))
    FAIL("Some force prevents your spell.");

  if (tp->query_busy())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("You are not alive.");

  if (!alignment_ok(tp))
    FAIL("The demons ignore you.");

  if (!wep)
    FAIL("Corrupt what?");

  if (!wep->is_weapon())
    FAIL("That is not a weapon.");

  if (wep->query_property(CORRUPT_PROP))
    FAIL("It has already been corrupted.");

  if (tp->query_mp() < 50)
    FAIL("Too low on magic.");

  return 1;
}

int cmd_corrupt(string str) {
  object tp = this_player();
  object env = environment(tp);
  object wep;
  object *wielded;
  mixed old_hit;
  int cost, time, dmg;
  string wepname;
  function f;
  
  if (!spell()) return 0;

  if (!str) {
    wielded = tp->query_wielded();
    if (sizeof(wielded))
      wep = wielded[random(sizeof(wielded))];
  }
  else
    wep = present(str, tp);

  if (!can_cast(tp, wep)) return 0;

  time = 30 + 2*tp->query_stats("wisdom");
  dmg = 5 + tp->query_skill("faith")/2;
  old_hit = wep->query_hit();

  cost = time*2/3 + random(dmg);
  if (tp->query_mp() < cost)
    FAIL("Too low on magic.");

  wep->set_property(CORRUPT_PROP, ({ time()+time, dmg, old_hit }) );
  wep->set_hit( (: corrupt_special($1, $(wep)) :) );

  wepname = remove_article(strip_color(replace_string(wep->query_short(), " (wielded)", "")));

  message("magic", COL+"You corrupt your "+COL2+wepname+COL+
                   " with a dem"+COL2+"oni"+COL+"c essence."+RES, tp);
  message("magic", COL+tp->query_cap_name()+" corrupts "+
                   tp->query_possessive()+" "+wepname+" with a "
                   "dem"+COL2+"oni"+COL+"c essence."+RES, env, tp);

  tp->add_mp(-cost);
  tp->set_magic_round(1);

  weps_corrupted += ({ wep });
  set_heart_beat(5);

  return 1;
}

void heart_beat() {
  foreach (object wep in weps_corrupted) {
    mixed *info;
    mixed old_hit;
    int time;
    if (!wep) {
      weps_corrupted -= ({ wep });
      continue;
    }
    info = wep->query_property(CORRUPT_PROP);
    if (!sizeof(info)) {
      weps_corrupted -= ({ wep });
      continue;
    }
    time = info[0];
    old_hit = info[2];
    if (time < time()) {
      wep->set_hit(old_hit);
      wep->remove_property(CORRUPT_PROP);
      weps_corrupted -= ({ wep });
    }
  }
  if (!sizeof(weps_corrupted)) set_heart_beat(0);
}

int corrupt_special(object atk, object wep) {
  mixed *info = wep->query_property(CORRUPT_PROP);
  int time = info[0];
  int dmg = info[1];
  mixed old_hit = info[2];
  int align = atk->query_alignment();
  string wepname = remove_article(strip_color(replace_string(wep->query_short(), " (wielded)", "")));
  object env;

  env = environment(wep);
  if (env)
    env = environment(env);
  if (!env || !env->is_room())
    return 0;

  if (time < time()) {
    wep->set_hit(old_hit);
    wep->remove_property(CORRUPT_PROP);
    return 0;
  }

  else if ( align-0 > random(5000) ) {
    message("magic", COL2+"The "+wepname+" "+COL+"glows"+COL2+
                     " with a sinister light!", env);
    return 10 + dmg/2 + random(dmg/2) - random(dmg/2);
  }

  return 0;
}

