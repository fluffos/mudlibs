
#include <std.h>
#include <daemons.h>
#include <effect_cl.h>

#define FAIL(s) return notify_fail(s+"\n");
#define COL "%^BOLD%^%^WHITE%^"
#define COL2 "%^BOLD%^%^CYAN%^"
#define RES "%^RESET%^"

inherit DAEMON;

int spell() {
  object tp = this_player();
  if (tp && tp->query_subclass() == "monk" &&
      tp->query_skill("faith") >= 12*6)
        return 1;
  return 0;
}

string type() { return "faith"; }

void help() {
  message("help",
    "Syntax: <supplication [whom]>\n\n"
    "Monks can pray for divine aid to be granted upon themselves "
    "or their comrades, increasing the target's physical prowess and regeneration.",
    this_player() );
}

int can_cast(object tp, object tgt) {

  if (!tp) return 0;

  if (environment(tp)->query_property("no magic"))
    FAIL("Some force prevents your power.");

  if (tp->query_busy())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("Your prayers come out as howls.");

  if (tp->query_current_attacker())
    FAIL("You are too busy fighting!");

  if (!tgt)
    FAIL("Perform supplication for whom?");

  if (!living(tgt))
    FAIL("That is not alive.");

  if (!alignment_ok(tp))
    FAIL("Your prayers go unanswered.");

  if (tgt->query_effect("supplication"))
    FAIL( (tgt == tp ? "You have " : capitalize(tgt->query_subjective())+" has ")+
        "already been granted supplication.");

  if (tp->query_mp() < 50)
    FAIL("Your magic is too low.");
  
  return 1;
}

int cmd_supplication(string str) {
  object tp = this_player();
  object env = environment(tp);
  object tgt;
  int time, cost;
  int strength, dexterity, constitution, hp, sp;
  class Effect supp;
 
  if (!spell()) return 0;

  if (!str || str == "me")
    tgt = tp;
  else
    tgt = present(str, env);

  if (!can_cast(tp, tgt)) return 0;

  time = tp->query_skill("faith")/2 + tp->query_stats("wisdom")*2 + (2*60);

  cost = time*4/5;
  if (tp->query_mp() < cost)
    FAIL("Your magic is too low.");

  if (tgt->query_stat_bonus("strength") <= 0)
    strength = tgt->query_base_stats()["strength"] * 15 / 100;
  if (tgt->query_stat_bonus("dexterity") <= 0)
    dexterity = tgt->query_base_stats()["dexterity"] * 15 / 100;
  if (tgt->query_stat_bonus("constitution") <= 0)
    constitution = tgt->query_base_stats()["constitution"] * 25 / 100;
  if (tgt->query_heal_rate_bonus("hp") <= 0)
    hp = tgt->query_max_hp() * 3 / 100;
  if (tgt->query_heal_rate_bonus("sp") <= 0)
    sp = tgt->query_max_sp() * 8 / 100;

  if (! (strength || dexterity || constitution || hp || sp) )
    FAIL("Some other power has already enhanced "+
        (tgt == tp ? "you" : tgt->query_objective())+".");
  
  message("magic", COL+"You pray for divine aid."+RES, tp);
  message("magic", COL+tp->query_cap_name()+" prays for divine aid."+RES, env, tp);
  message("magic", COL2+"You feel an "+COL+"incredible boost"+COL2+
      " in your strength and stamina."+RES, tgt);
  message("magic", COL2+tgt->query_cap_name()+" suddenly looks "+
      COL+"stronger"+COL2+" and more imposing."+RES, env, tgt);

  tp->add_mp(-(cost+random(cost/7)));
  tp->set_magic_round(1);

  supp = new(class Effect);
  supp->target = tgt;
  supp->caster = tp;
  supp->castername = tp->query_name();
  supp->name = "supplication";
  supp->desc = "Your strength and stamina have been increased through supplication.";
  supp->endmessages = ({
    COL2+"The powers of supplication fade away."+RES,
    COL2+tgt->query_cap_name()+" seems to return to "+
      tgt->query_possessive()+" normal strength."+RES,
  });
  supp->misc = ({ strength, dexterity, constitution, hp, sp });
  supp->endtime = time()+time;
  supp->endfunc = function(class Effect buff) {
    object tgt = buff->target;
    int *info = buff->misc;
    int strength = info[0];
    int dexterity = info[1];
    int constitution = info[2];
    int hp = info[3];
    int sp = info[4];

    tgt->add_stat_bonus("strength", -strength);
    tgt->add_stat_bonus("dexterity", -dexterity);
    tgt->add_stat_bonus("constitution", -constitution);
    tgt->add_heal_rate_bonus("hp", -hp);
    tgt->add_heal_rate_bonus("sp", -sp);
  };

  tgt->add_stat_bonus("strength", strength);
  tgt->add_stat_bonus("dexterity", dexterity);
  tgt->add_stat_bonus("constitution", constitution);
  tgt->add_heal_rate_bonus("hp", hp);
  tgt->add_heal_rate_bonus("sp", sp);

  tgt->add_effect(supp);

  return 1;
}

