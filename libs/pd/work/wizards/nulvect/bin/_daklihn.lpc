
#include <std.h>
#include <daemons.h>

#define COL "%^YELLOW%^"
#define COL2 "%^BOLD%^%^BLACK%^"
#define RES "%^RESET%^"

#define FAIL(s) return notify_fail(s+"\n");

inherit DAEMON;

int abil() {
  object tp=this_player();
  if (tp->query_subclass() == "kataan" &&
      tp->query_skill("attack") >= 26*4 &&
      tp->query_skill("summoning") >= 26*6 &&
      tp->query_skill("projectile") >= 26*6) return 1;
  return 0;
}

string type() { return "attack"; }

void help() {
  message("help",
    "Syntax: <daklihn [whom]>\n\n"
    "A kataan technique, the daklihn hits the victim first with "
    "a quick spear thrust, then the user channels dark energy into "
    "his victim to eat away at the soul.",
    this_player() );
}

int can_cast(object tp, object tgt, object *weps) {
  
  if (!tp) return 0;

  if (environment(tp)->query_property("no attack"))
    FAIL("You cannot attack here.");

  if (tp->query_disable() || tp->query_casting() || tp->query_magic_round())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("You are dead.");

  if (!sizeof(weps))
    FAIL("You must use a spear for that.");

  if (tp->query_rest_type())
    FAIL("You have to stand up to do that.");
  
  if (!tgt)
    FAIL("Daklihn whom?");

  if (!living(tgt))
    FAIL("That is not alive.");

  if (tgt == tp)
    FAIL("The demons laugh at you.");

  if (!tp->kill_ob(tgt))
    FAIL("You may not attack "+tgt->query_cap_name()+".");
  
  return 1;
}

int cmd_daklihn(string str) {
  object tp=this_player();
  object env=environment(tp);
  object tgt;
  object *weps;
  string limb;
  int pdmg, mdmg, spcost, mpcost, rank;

  if (!abil()) return 0;

  if (!str) tgt=tp->query_current_attacker();
  else tgt=present(str,environment(tp));

  weps = filter(tp->query_wielded(), (: $1->query_type() == "projectile" :) );

  if (!can_cast(tp, tgt, weps)) return 0;

  if (tp->query_skill("projectile")+tp->query_skill("summoning") > 40*12)
    rank=4;
  else if (tp->query_skill("projectile")+tp->query_skill("summoning") > 32*12)
    rank=3;
  else
    rank=2;

  pdmg = BALANCE3_D->get_damage(tp, tgt, rank-1,
    ({"projectile","projectile","attack"}),
    ({"strength","dexterity"}),
    ({"strength"}) );

  pdmg *= 0.4;

  pdmg += weps[0]->query_wc()*9;

  mdmg = BALANCE3_D->get_damage(tp, tgt, rank,
    ({"summoning", "summoning", "summoning", "faith"}),
    ({"wisdom", "wisdom", "wisdom", "intelligence"}),
    ({"summoning", "magic attack"}) );

  mdmg *= 0.6;

  if (mdmg > 300) mdmg=300+(mdmg-300)*3/4;
  if (mdmg > 500) mdmg=500+(mdmg-500)*2/3;

  spcost=pdmg/12.5;
  mpcost=mdmg/5.75;
  
  if (tp->query_sp() < spcost)
    FAIL("You are too tired.");

  if (tp->query_mp() < mpcost)
    FAIL("Too low on magic.");

  tp->set_disable(1);

  limb=tgt->return_target_limb();

  if (tgt->query_stats("dexterity")*3/2+tgt->query_skill("defense")/2-random(30) >
      tp->query_stats("dexterity")+tp->query_skill("attack")/3+tp->query_skill("projectile")/2) {

    message("info","You lunge at "+tgt->query_cap_name()+" with your spear, but miss!",tp);
    message("info",tp->query_cap_name()+" lunges at you, but you are too fast for "+
      tp->query_objective()+".",tgt);
    message("info",tp->query_cap_name()+" lunges at "+tgt->query_cap_name()+", but misses.",
      environment(tp),({tp,tgt}));
    tp->add_sp(-(spcost/2));
    return 1;
  }

  tp->add_sp(-spcost);
  tp->add_mp(-mpcost);

  message("info","You "+COL+"lunge"+RES+" at "+tgt->query_cap_name()+
                 " and "+COL+"sp"+COL2+"e"+COL+"ar"+RES+" "+
                 tgt->query_objective()+" badly!", tp);
  message("info",tp->query_cap_name()+" "+COL+"lunges"+RES+" with "+
                 tp->query_possessive()+" "+COL+"sp"+COL2+"e"+COL+"ar"+RES+
                 " and wounds you badly!", tgt);
  message("info",tp->query_cap_name()+" "+COL+"lunges"+RES+" with "+
                 tp->query_possessive()+" "+COL+"sp"+COL2+"e"+COL+"ar"+RES+
                 " and wounds "+tgt->query_cap_name()+" badly!", env, ({tp, tgt}) );
  tgt->do_damage(limb, pdmg);

  if (alignment_ok(tp) && !env->query_property("no magic")) {
    message("info", COL2+"Dark tendrils flow into your wound!"+RES,tgt);
    message("info", COL2+"Dark tendrils flow into "
      +tgt->query_cap_name()+"'s wound!"+RES, env, tgt );
    tgt->do_damage(limb, mdmg);
    ({tp,tgt})->add_alignment(-5);
  }

  return 1;
}

