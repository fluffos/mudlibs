
#include <std.h>
#include <daemons.h>
#include <effect_cl.h>

#define FAIL(s) return notify_fail(s+"\n")

#define RES "%^RESET%^"
#define COL "%^BOLD%^%^BLACK%^"
#define COL2 "%^BOLD%^%^RED%^"
#define COL3 RES+"%^RED%^"
#define COL4 RES+"%^BLACK%^%^B_RED%^"

inherit DAEMON;

void continue_spell(object tp, object env, object *tgts);
void do_damnation(object tgt, int div);
void end_damnation(class Effect damn);

int spell() {
  object tp = this_player();
  if (tp && tp->query_subclass() == "antipaladin" &&
      tp->query_skill("magic attack") >= 50*4 &&
      tp->query_skill("faith") >= 50*4)
        return 1;
  return 0;
}

string type() { return "faith"; }

void help() {
  message("help",
    "Syntax: <damnation (victim)>\n\n"
    "Calling on vast powers from his demonic masters in the Abyss, "
    "an antipaladin can weaken the followers of good considerably.\n"
    "This spell will affect everyone in the room unless directed at "
    "one target.",
    this_player() );
}

int can_cast(object tp, object tgt) {

  if (!tp) return 0;

  if (environment(tp)->query_property("no magic") ||
      environment(tp)->query_property("no attack"))
        FAIL("Some force prevents your magic.");

  if (tp->query_busy())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("A chilling demonic laughter fills your mind.");

  if (!tgt)
    FAIL("Weaken who?");

  if (!tgt->is_living())
    FAIL("Surely there is better use for such a power.");

  if (tgt->query_effect("damnation"))
    FAIL(tgt->query_cap_name()+" is already weakened by damnation!");

  if (!tp->ok_to_kill(tgt))
    FAIL("You cannot attack "+tgt->query_cap_name()+".");

  return 1;
}

int cmd_damnation(string str) {
  object tp = this_player();
  object env = environment(tp);
  object *tgts;
  int cost;

  if (!spell()) return 0;

  if (str)
    tgts = ({ present(str, env) });
  else
    tgts = filter(all_inventory(env), (:
      $1 != $2 && !PARTY_D->same_party($1, $2)
    :), tp);

  tgts = filter(tgts, (: can_cast($2, $1) :), tp);

  if (!sizeof(tgts)) return 0;

  if (tp->query_mp() < 400)
    FAIL("Too low on magic.");

  tp->add_mp(-(100+random(20)-random(20)));
  tp->set_magic_round(2);

  message("magic", COL+"You call to the "+COL2+"demons"+COL+
    " of the "+COL3+"Abyss"+COL+" for "+
    COL2+"p"+COL3+"o"+COL2+"w"+COL3+"e"+COL2+"r"+COL+"!", tp);
  message("magic", COL+tp->query_cap_name()+" calls to the "+COL2+"demons"+COL+
    " of the "+COL3+"Abyss"+COL+" for "+
    COL2+"p"+COL3+"o"+COL2+"w"+COL3+"e"+COL2+"r"+COL+"!", env, tp);

  call_out("continue_spell", 4, tp, env, tgts);

  return 1;
}

void continue_spell(object tp, object env, object *tgts) {
  int cost;

  if (!tp || !env) return;
  if (!env || environment(tp) != env) {
    message("info", "Your spell is interrupted!", tp);
    return;
  }
  tgts = filter(tgts, (: $1 && environment($1) == $2 :), env);
  if (!tgts || !sizeof(tgts)) {
    message("info", "Your targets are not here!", tp);
    return;
  }

  cost = 200 + (50 * sizeof(tgts));

  tp->add_mp(-(cost+random(cost/9)-random(cost/9)));
  tp->set_magic_round(1);


  foreach (object tgt in tgts) {
    message("magic", COL2+"The scalding dark heat of damnation sears through "+tgt->query_cap_name()+"!"+RES, env, tgt);
    message("magic", COL4+"The scalding dark heat of damnation sears through your body and soul!", tgt);
    do_damnation(tgt, sizeof(tgts));
  }
}

void do_damnation(object tgt, int div) {
  object tp = this_player();
  class Effect damn;
  int *data;
  int perc, secs;

  perc = 10;
  // += 30 % more at 1500 (godly), 0% more at -1500 satanic
  perc += (tgt->query_alignment() + 1500) / 100;
  perc += tp->query_skill("magic attack")/15;
  perc -= tgt->query_skill("magic defense")/10;

  switch (div) {
    case 0: /* should never happen */ break;
    case 1: /* good as is */ break;
    case 2: perc = perc * 70 / 100; break;
    case 3: perc = perc * 50 / 100; break;
    case 4:
    default: perc = perc * 30 / 100; break;
  }

  secs = tp->query_stats("wisdom") * 40 / 100;

  data = ({
    tgt->query_stats("strength")*perc/100,
    tgt->query_stats("dexterity")*perc/100,
    tgt->query_stats("constitution")*perc/100,
    tgt->query_stats("intelligence")*perc/100,
    tgt->query_skill("attack")*perc/100,
    tgt->query_skill("defense")*perc/100,
  });

  if (tgt->query_stat_bonus("strength") >= 0)
    tgt->add_stat_bonus("strength", -data[0]);
  else
    data[0] = 0;

  if (tgt->query_stat_bonus("dexterity") >= 0)
    tgt->add_stat_bonus("dexterity", -data[1]);
  else
    data[1] = 0;

  if (tgt->query_stat_bonus("constitution") >= 0)
    tgt->add_stat_bonus("constitution", -data[2]);
  else
    data[2] = 0;

  if (tgt->query_stat_bonus("intelligence") >= 0)
    tgt->add_stat_bonus("intelligence", -data[3]);
  else
    data[3] = 0;

  if (tgt->query_skill_bonus("attack") >= 0)
    tgt->add_skill_bonus("attack", -data[4]);
  else
    data[4] = 0;

  if (tgt->query_skill_bonus("defense") >= 0)
    tgt->add_skill_bonus("defense", -data[5]);
  else
    data[5] = 0;

  damn = new(class Effect);
  damn->name = "damnation";
  damn->castername = tp->query_name();
  damn->caster = tp;
  damn->target = tgt;
  damn->desc = "A dark heat has scalded through you, weakening your body.";
  damn->endtime = time() + secs;
  damn->endfunc = (: end_damnation :);
  damn->endmessages = ({
    "Your scalded soul finally recovers.",
  });
  damn->misc = data;

  tgt->add_effect(damn);

  tp->add_skill_points("faith", perc);
  tp->add_skill_points("magic attack", perc);
}

void end_damnation(class Effect damn) {
  object tgt = damn->target;
  int *data = damn->misc;

  tgt->add_stat_bonus("strength", data[0]);
  tgt->add_stat_bonus("dexterity", data[1]);
  tgt->add_stat_bonus("constitution", data[2]);
  tgt->add_stat_bonus("intelligence", data[3]);
  tgt->add_skill_bonus("attack", data[4]);
  tgt->add_skill_bonus("defense", data[5]);
}

