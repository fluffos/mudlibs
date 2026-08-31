
#include <std.h>
#include <daemons.h>

#define RES "%^RESET%^"
#define COL RES+"%^RED%^"
#define COL2 "%^BOLD%^%^BLACK%^"
#define COL3 "%^BOLD%^%^WHITE%^"

#define FAIL(s) return notify_fail(s+"\n")

inherit DAEMON;

int is_undead(object tgt);

int spell() {
  object tp=this_player();
  if (tp && tp->query_subclass() == "necromancer" &&
      tp->query_skill("necromancy") >= 17*6 &&
      tp->query_skill("magic attack") >= 17*6)
        return 1;
  return 0;
}

string type() { return "healing"; }

void help() {
  message("help",
    "Syntax: <siphon>\n\n"
    "A spell that absorbs the life force of all your opponents.",
    this_player() );
}

int can_cast(object tp) {
  object env;

  if (!tp) return 0;

  env=environment(tp);
  if (env->query_property("no magic") || env->query_property("no attack"))
    FAIL("Some force prevents your magic.");

  if (tp->query_disable() || tp->query_casting() || tp->query_magic_round())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("It's a bit late to try that.");

  if (!sizeof(tp->query_attackers()))
    FAIL("You are not fighting anybody.");
  
  return 1;
}

int cmd_siphon(string str) {
  object tp=this_player();
  object env=environment(tp);
  object *tgts, *hit = ({});
  
  if (!spell()) return 0;

  tp->clean_up_attackers();

  if (!can_cast(tp)) return 0;

  tgts = filter(tp->query_attackers(), (: !is_undead($1) :) );

  foreach (object tgt in tgts) {
    int dmg, cost;

    dmg = BALANCE3_D->get_damage(tp, tgt, 2,
      ({"necromancy", "magic attack"}),
      ({"intelligence"}) );

    dmg *= 0.35;
    
    cost = dmg/9.3;

    if (tp->query_mp() < cost) {
      if (!sizeof(hit))
        FAIL("You need more magic.");
      else
        break;
    }

    tp->add_mp(-(cost+random(cost/15)));
    hit += ({ ({tgt, dmg}) });
  }

  message("magic",COL+"You r"+COL2+"eac"+COL+"h both hands outwards "
                  "and "+COL3+"siphon"+COL+" off some "+
                  COL2+"he"+COL+"al"+COL2+"th"+COL+
                  " from your foes!"+RES, tp);
  message("magic",COL+tp->query_cap_name()+" r"+COL2+"eache"+COL+"s "
                  "both hands outwards "
                  "and "+COL3+"siphons"+COL+" off some "+
                  COL2+"he"+COL+"al"+COL2+"th"+COL+
                  " from you!"+RES, hit);
  message("magic",COL+tp->query_cap_name()+" r"+COL2+"eache"+COL+"s "
                  "both hands outwards "
                  "and "+COL3+"siphons"+COL+" off some "+
                  COL2+"he"+COL+"al"+COL2+"th"+COL+
                  " from "+tp->query_possessive()+" foes!"+RES,
                  env, ({tp})+hit);

  tp->add_alignment(-8);
  tp->add_skill_points("magic attack", 25);
  tp->set_magic_round(1);

  foreach (mixed info in hit) {
    object tgt=info[0];
    int dmg=info[1];
    tgt->add_hp(-dmg);
    tp->add_hp(dmg*0.4);
  }

  return 1;
}

int is_undead(object tgt) {
  if (tgt->query_undead() || member_array(tgt->query_race(),
      ({"undead","vampire","lich","ghoul","zombie",
      "corpse","ghost","ghast","wight","spirit",
      "skeleton","spectre","wraith","spirit"})) != -1)
        return 1;
  return 0;
}

