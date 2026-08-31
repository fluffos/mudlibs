
#include <std.h>
#include <daemons.h>
#include <damage_types.h>
#include <damage.h>

#define RES "%^RESET%^"
#define COL "%^YELLOW%^"
#define COL2 "%^BOLD%^%^BLACK%^"
#define COL3 RES+"%^RED%^"

#define FAIL(s) return notify_fail(s+"\n");

inherit DAEMON;

void dakzhul_hit(mixed *args);
string hit_msg(float perc, string what);

int abil() {
  object tp=this_player();
  if (tp && tp->query_subclass() == "kataan" &&
      tp->query_skill("projectile") >= 40*6 &&
      tp->query_skill("attack") >= 40*4 &&
      tp->query_skill("faith") >= 40*6 &&
      tp->query_skill("summoning") >= 40*6)
        return 1;
  return 0;
}

string type() { return "attack"; }

void help() {
  message("help",
    "Syntax: <dakzhul [whom]>\n\n"
    "The dakzhul is a powerful opening attack that focuses "
    "demonic energy into the user and his spear. The user then "
    "flies forward to unleash the power in a devastating blast.\n"
    "This move is a mark of the kataan masters.",
    this_player() );
}

int can_cast(object tp, object tgt, object *weps) {
  
  if (!tp) return 0;

  if (environment(tp)->query_property("no attack"))
    FAIL("You cannot use that here.");

  if (tp->query_disable() || tp->query_casting() || tp->query_magic_round())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("You're dead.");

  if (!alignment_ok(tp))
    FAIL("The power does not come.");

  if (!tgt)
    FAIL("Dakzhul whom?");
  
  if (!living(tgt))
    FAIL("You can't kill objects.");

  if (tp == tgt)
    FAIL("If you killed yourself, you'd be too dead to kill anybody else.");
  
  if (!sizeof(weps))
    FAIL("You need a spear to perform the dakzhul!");

  if (sizeof(tp->query_attackers()))
    FAIL("You are too busy fighting!");
  
  return 1;
}

int cmd_dakzhul(string str) {
  object tp=this_player();
  object env=environment(tp);
  object tgt;
  object *weps;
  int pdmg, mdmg, spcost, mpcost, rank;
  int pike;

  if (!abil()) return 0;

  if (str && str != "") tgt=present(str, env);

  weps=filter(tp->query_wielded(), (: $1->query_type() == "projectile" :) );

  tp->clean_up_attackers();
  
  if (!can_cast(tp, tgt, weps)) return 0;

  weps->set_property("no steal",1);

  if (tp->query_skill("faith")+tp->query_skill("projectile") >= 12*53)
    rank=4;
  else
    rank=3;

  pdmg = BALANCE3_D->get_damage(tp, tgt, rank,
    ({"projectile","attack"}),
    ({"strength","dexterity"}),
    ({"strength"}) );

  pdmg *= 1.4;

  spcost = BALANCE3_D->get_cost(pdmg, rank, "sp")*120/100;

  if (tp->query_invis())
    pdmg *= 1.2;

  mdmg = BALANCE3_D->get_damage(tp, tgt, rank,
    ({"faith", "faith", "summoning"}),
    ({"wisdom"}),
    ({"faith"}) );

  mdmg *= 0.4;

  foreach (object wep in weps) {
    if (wep->id("kataan warpike")) {
      mdmg *= 1.35;
      pike=1;
    }
  }
  
  mpcost = BALANCE3_D->get_cost(mdmg, rank, "mp") * 3;

  if (tp->query_sp() < spcost)
    FAIL("You are too tired.");
  if (tp->query_mp() < mpcost)
    FAIL("You need more magic.");

  tp->add_sp(-(spcost/2));
  tp->add_mp(-(mpcost/2));
  tp->set_disable();
  
  message("magic", COL+"You summon "+COL2+"demonic energy"+COL+
                   " into yourself."+RES, tp);
  if (pike) message("magic", COL3+"You draw on the warpike's power."+RES, tp);
  if (!tp->query_invis())
    message("magic", tp->query_cap_name()+" summons "+COL2+"demonic energy"+
                     COL+" into "+tp->query_objective()+"self.", env, tp);

  call_out("dakzhul_hit", 1, ({tp, tgt, weps, pdmg, spcost, mdmg, mpcost}) );

  return 1;
}

void dakzhul_hit(mixed *args) {
  object tp=args[0];
  object tgt=args[1];
  object *weps=args[2];
  int pdmg=args[3];
  int spcost=args[4];
  int mdmg=args[5];
  int mpcost=args[6];
  object env;
  int dmg;
  float perc;
  string verb, adverb, limb;

  if (sizeof(weps))
    weps->set_property("no steal", 0);

  if (!tp || !tgt || !sizeof(weps) ||
      !pdmg || !spcost || !mdmg || !mpcost)
        return;

  env=environment(tp);

  if (environment(tgt) != env) {
    message("info", "Your opponent is gone.", tp);
    return;
  }

  if (!tp->kill_ob(tgt)) {
    message("info", "You cannot attack "+tgt->query_cap_name()+".", tp);
    return;
  }
  
  dmg=pdmg+mdmg;
  perc = to_float(dmg)/to_float(tgt->query_hp());
  verb = hit_msg(perc, "verb");
  adverb = hit_msg(perc, "adverb");
  limb=tgt->return_target_limb();

  tp->add_sp(-(spcost/2));
  tp->add_mp(-(mpcost/2));

  message("combat", "You "+COL+"fly"+RES+" at "+tgt->query_cap_name()+
                    " with a "+COL2+"des"+COL3+"truct"+COL2+"ive"+RES+
                    " "+COL+"blast"+RES+"!", tp);
  message("combat", tp->query_cap_name()+" "+COL+"flies"+RES+" at you "
                    "with a "+COL2+"des"+COL3+"truct"+COL2+"ive"+RES+
                    " "+COL+"blast"+RES+"!", tgt);
  message("combat", tp->query_cap_name()+" "+COL+"flies"+RES+" at "+
                    tgt->query_cap_name()+
                    " with a "+COL2+"des"+COL3+"truct"+COL2+"ive"+RES+
                    " "+COL+"blast"+RES+"!", env, ({tp, tgt}) );

  if (tp->query_invis())
    tp->set_invis();

  message("combat", "You "+COL+verb+RES+" "+tgt->query_cap_name()+
                    " "+COL3+adverb+RES+" in the "+COL2+limb+RES+"!", tp);
  message("combat", tp->query_cap_name()+" "+COL+verb+RES+" you "+
                    COL3+adverb+RES+" in the "+COL2+limb+RES+"!", tgt);
  message("combat", tp->query_cap_name()+" "+COL+verb+RES+" "+
                    tgt->query_cap_name()+" "+
                    COL3+adverb+RES+" in the "+COL2+limb+RES+"!", env, ({tp, tgt}) );

  tgt->do_damage(limb, pdmg, DAMAGE_PHYSICAL | DAMAGE_PIERCE, 0, tp);
  tgt->do_damage(limb, mdmg, DAMAGE_FAITH | DAMAGE_UNHOLY, 0, tp);
  
}

string hit_msg(float perc, string what) {
  switch (what) {
    case "verb":
      if (perc > 0.6) return "destroyed";
      if (perc > 0.5) return "destroyed";
      if (perc > 0.4) return "mutilated";
      if (perc > 0.3) return "sliced";
      if (perc > 0.2) return "scraped";
      return "knicked";
    break;
    case "adverb":
      if (perc > 0.6) return "utterly";
      if (perc > 0.5) return "terribly";
      if (perc > 0.4) return "horribly";
      if (perc > 0.3) return "badly";
      if (perc > 0.2) return "barely";
      return "barely";
    break;
    default:
  }
  return "";
}

