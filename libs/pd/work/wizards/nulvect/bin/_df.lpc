#include <std.h>
#include <daemons.h>

#define COL "%^BOLD%^%^RED%^"
#define COL2 "%^BOLD%^%^BLACK%^"
#define RES "%^RESET%^"

#define FAIL(s) return notify_fail(s+"\n");

inherit DAEMON;

int spell() {
  object tp=this_player();
  if (tp && tp->query_subclass() == "kataan" &&
      tp->query_skill("faith") >= 35*6 &&
      tp->query_skill("summoning") >= 35*6)
        return 1;
  return 0;
}

string type() { return "attack"; }

void help() {
  message("help",
    "Syntax: <demonfire>\n\n"
    "Those of great demonic faith can summon raw power from hell "
    "and send it outward in the form of flames. These flames work "
    "to destroy any living thing they encounter.",
    this_player() );
}

int can_cast(object tp) {
  object env;

  if (!tp) return 0;

  env=environment(tp);

  if (env->query_property("no magic") || env->query_property("no attack"))
    FAIL("You may not cast that here.");

  if (tp->query_disable() || tp->query_casting() || tp->query_magic_round())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("The demons laugh at you.");

  if (!alignment_ok(tp))
    FAIL("You have betrayed the source of your powers.");

  return 1;
}

int cmd_df(string str) {
  object tp=this_player();
  object env=environment(tp);
  object *tgts;
  int cost=400;

  if (!spell()) return 0;

  if (!can_cast(tp)) return 0;
  
  if (tp->query_mp() < cost)
    FAIL("You need more magic.");
  
  tp->add_mp(-(cost+random(cost/3)));
  tp->set_magic_round(1);
  tp->set_paralyzed(2, "The raw power holds you.");

  message("magic", COL+"Dark "+
                   COL2+"fl"+COL+"a"+COL2+"m"+COL+"e"+COL2+"s"+COL+
                   " gather around you."+RES, tp);
  message("magic", COL+"Dark "+
                   COL2+"fl"+COL+"a"+COL2+"m"+COL+"e"+COL2+"s"+COL+
                   " gather around "+tp->query_cap_name()+"."+RES, env, tp);
  
  call_out("demonfire_hit", 1, ({tp}) );

  return 1;
}

void demonfire_hit(mixed *args) {
  object tp=args[0];
  object *tgts;
  object env;

  if (!tp) return;

  env=environment(tp);
  
  tgts = filter(all_inventory(env), (: $1->is_living() :) ) - ({tp});

  message("magic", COL2+"The power "+
                   COL+"r"+COL2+"ad"+COL+"ia"+COL2+"te"+COL+"s"+COL2+
                   " out from your body!"+RES, tp);
  message("magic", COL2+"Power "+
                   COL+"r"+COL2+"ad"+COL+"ia"+COL2+"te"+COL+"s"+COL2+
                   " out from "+
                   tp->query_cap_name()+"!"+RES, env, tp);

  foreach (object tgt in tgts) {
    int dmg;
    
    if (userp(tgt) && !interactive(tgt)) {
      message("info", "You may not attack link-dead players.", tp);
      continue;
    }
    if (!tp->kill_ob(tgt)) {
      message("info", "You may not attack "+tgt->query_cap_name()+".", tp);
      continue;
    }

    dmg = BALANCE3_D->get_damage(tp, tgt, 3,
      ({"summoning", "summoning", "faith"}),
      ({"wisdom", "intelligence"}),
      ({"summoning", "faith"}) );

    dmg = dmg*1.65;

    if (dmg < 70) {
      message("magic", COL2+"Flames engulf your body, "
                       "but don't seem to hurt you.", tgt);
      message("magic", COL2+"Flames engulf "+tgt->query_cap_name()+
                       ", but don't seem to hurt "+
                       tgt->query_objective()+"."+RES, env, tgt);
      continue;
    }
    
    message("magic", COL+"You are engulfed by horrific burning fire!"+RES, tgt);
    message("magic", COL+tgt->query_cap_name()+" is engulfed by horrific "
                     "burning fire!", env, tgt);

    tgt->do_damage(tgt->return_limb(), dmg);

  }
  
}

