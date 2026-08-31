
#include <std.h>
#include <daemons.h>
#include <damage_types.h>
#include <damage.h>

#define COL "%^BOLD%^%^RED%^"
#define COL2 "%^BOLD%^%^BLACK%^"
#define RES "%^RESET%^"

#define FAIL(s) return notify_fail(s+"\n");

inherit DAEMON;

int spell() {
  object tp=this_player();
  if (tp && tp->query_subclass() == "kataan" &&
      tp->query_skill("summoning") >= 20*6)
        return 1;
  return 0;
}

string type() { return "attack"; }

void help() {
  message("help",
    "Syntax: <hellfire>\n\n"
    "Through this evil spell, the caster summons forth great flames "
    "from hell to incinerate his opponents.",
    this_player() );
}

int can_cast(object tp) {
  object env;

  if (!tp) return 0;

  env=environment(tp);

  if (env->query_property("no magic") || env->query_property("no attack"))
    FAIL("Some force prevents your magic.");

  if (tp->query_disable() || tp->query_magic_round() || tp->query_casting())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("You can't cast that until you're alive again.");

  if (!alignment_ok(tp))
    FAIL("Nothing happens.");

  return 1;
}

int cmd_hellfire(string str) {
  object tp=this_player();
  object env=environment(tp);
  object *tgts;

  if (!spell()) return 0;

  if (!can_cast(tp)) return 0;

  tgts = filter(all_inventory(env), (: ($1->is_living() && strlen($1->query_long())) :) ) - ({tp});

  message("magic", COL2+"Your hatred "+COL+"burns"+COL2+" as you call forth "+
                   COL+"flames"+COL2+" from hell!", tp);
  message("magic", COL2+tp->query_cap_name()+" calls forth "+COL+"flames"+COL2+
                   " of hell!", env, tp);

  tp->add_mp(-random(55));
  tp->set_magic_round(1);
  tp->set_paralyzed(1, "You are concentrating on the hellfire!");

  foreach (object tgt in tgts) {
    int dmg, cost;

    if (tgt->query_ghost() || !tp->kill_ob(tgt)) {
      message("info", "You cannot attack "+tgt->query_cap_name()+".",tp);
      continue;
    }

    dmg = BALANCE3_D->get_damage(tp, tgt, 2,
      ({"summoning"}),
      ({"wisdom", "intelligence"}) );

    cost = BALANCE3_D->get_cost(dmg, 2, "mp") * 130 / 100;
    
    if (tp->query_mp() < 100 ||
        tp->query_mp() < cost) {
          if (tgt == tgts[0]) {
            FAIL("You need more magic to cast that.");
          }
          else {
            message("magic", COL2+"The hellfire burns out, "
                             "lacking power to feed it."+RES, tp);
            return 1;
          }
    }

    tp->add_mp(-cost);

    if (tgt->query_skill("magic defense")+tgt->query_stats("wisdom") > dmg) {
      message("magic", COL+"The flames engulf "+tgt->query_cap_name()+
                       " and dissipate harmlessly."+RES, env, tgt);
      message("magic", COL+"The flames engulf you and dissipate harmlessly."+RES, tgt);
      continue;
    }

    message("magic", COL+"Great tongues of hell's flame engulf you!"+RES, tgt);
    message("magic", COL+"Great tongues of hell's flame engulf "+
                     tgt->query_cap_name()+"!"+RES, env, tgt);

    tgt->do_damage("random", dmg, DAMAGE_FAITH | DAMAGE_UNHOLY | DAMAGE_FIRE, 0, tp);

    if (tgt->query_hp() < 1)
      tgt->heart_beat();

  }

  tp->add_alignment(-2);

  return 1;
}

