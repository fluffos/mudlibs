
#include <std.h>
#include <daemons.h>

#define RES "%^RESET%^"
#define COL RES+"%^WHITE%^"
#define COL2 RES+"%^ORANGE%^"

#define FAIL(s) return notify_fail(s+"\n")

inherit DAEMON;

// at berserker and thug can get 40 melee at level 7, 40 blunt at level 8
int abil() {
  object tp=this_player();
  if (tp &&
      (tp->query_subclass() == "berserker" ||
       tp->query_subclass() == "thug") &&
      (tp->query_skill("melee") >= 40 ||
       tp->query_skill("blunt") >= 40) )
         return 1;
  return 0;
}

string type() { return "attack"; }

void help() {
  message("help",
    "Syntax: <pound [whom]>\n\n"
    "Brawlers can pound on their enemies using either their fists "
    "or a blunt weapon.",
    this_player() );
}

int can_cast(object tp, object tgt, object *weps) {

  if (!tp) return 0;

  if (environment(tp)->query_property("no attack"))
    FAIL("You may not attack here.");

  if (tp->query_disable() || tp->query_casting() || tp->query_magic_round())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("You flail around uselessly.");

  if (!tgt)
    FAIL("Pound whom?");

  if (!living(tgt))
    FAIL("You give it a good pounding, but it doesn't seem to care.");

  if (tgt == tp)
    FAIL("Your attempt to pound yourself leaves you looking stupid.");

  if (!sizeof(weps) &&
      (sizeof(tp->query_wielding_limbs())-sizeof(tp->query_limbs_wielded())) < 1)
        FAIL("You need a free hand or a blunt weapon to pound things!");

  if (!tp->kill_ob(tgt))
    FAIL("You cannot attack "+tgt->query_cap_name()+".");

  return 1;
}

int cmd_pound(string str) {
  object tp=this_player();
  object env=environment(tp);
  object tgt;
  object *weps;
  int dmg, rank, cost;
  int wc=0;
  int perc;
  string type, limb, what;
  string *skills=({});

  if (!abil()) return 0;

  if (str)
    tgt=present(str, env);
  else
    tgt=tp->query_current_attacker();

  weps = filter(tp->query_wielded(), (: $1->query_type() == "blunt" :) );

  if (!can_cast(tp, tgt, weps)) return 0;

  if (sizeof(weps)) {
    type = "blunt";
    if (sizeof(tp->query_wielded()) > 1)
      skills += ({"double wielding"});
    foreach (object w in weps)
      wc += w->query_wc();
    wc /= sizeof(weps);
  }
  else {
    type = "melee";
    if (sizeof(tp->query_wielded()))
      skills += ({"double wielding"});
    wc = 4+tp->query_stats("strength")/10;
  }

  skills += ({"attack", type});

  rank = 1+tp->query_skill(type)/(5.5*16);
  if (rank < 1) rank=1;
  if (rank > 4) rank=4;

  dmg = BALANCE3_D->get_damage(tp, tgt, rank,
    skills,
    ({"strength","strength","dexterity"}),
    ({"strength"}) );

  dmg *= 0.8;

  if (dmg > (2*rank-1)*170)
    dmg = (2*rank-1)*170+random(tp->query_level()*2);

  dmg += random(wc*6);
  
  cost = dmg/13;

  if (tp->query_sp() < cost)
    FAIL("You are too tired.");

  tp->add_sp(-(cost-random(cost/17)));
  tp->set_disable();

  limb = tgt->return_target_limb();
  perc = percent(tgt->query_hp(), tgt->query_max_hp());

  if ((perc >= 50 && perc <= 75) ||
      tgt->query_paralyzed() ||
      tgt->query_rest_type()) {
        dmg *= 1.5;
        message("combat", "You "+COL2+"POUND"+RES+" "+tgt->query_cap_name()+
                          "'s "+COL2+limb+RES+" "+
                          COL+"b"+COL2+"ru"+COL+"t"+COL2+"a"+COL+"lly"+RES+
                          "!", tp);
        message("combat", tp->query_cap_name()+" "+COL2+"POUNDS"+RES+" your "+
                          COL2+limb+RES+" "+
                          COL+"b"+COL2+"ru"+COL+"t"+COL2+"a"+COL+"lly"+RES+
                          "!", tgt);
        message("combat", tp->query_cap_name()+" "+COL2+"POUNDS"+RES+" "+
                          tgt->query_cap_name()+"'s "+COL2+limb+RES+" "+
                          COL+"b"+COL2+"ru"+COL+"t"+COL2+"a"+COL+"lly"+RES+
                          "!", env, ({tp, tgt}) );
  }
  else if (perc <= 15 && tgt->query_is_limb("head") &&
           tp->query_stats("strength") >=
           (tgt->query_stats("constitution")+tgt->query_stats("dexterity"))/2) {
        dmg = tgt->query_hp()*2;
        limb = "head";
        message("combat", "You "+COL2+"POUND"+RES+" "+tgt->query_cap_name()+
                          "'s "+COL2+limb+RES+" "+
                          COL+"b"+COL2+"ru"+COL+"t"+COL2+"a"+COL+"lly"+RES+
                          " until it cracks open!", tp);
        message("combat", tp->query_cap_name()+" "+COL2+"POUNDS"+RES+" your "+
                          COL2+limb+RES+" "+
                          COL+"b"+COL2+"ru"+COL+"t"+COL2+"a"+COL+"lly"+RES+
                          " until it cracks open!\n"
                          "%^BOLD%^%^WHITE%^Suddenly everything goes white."+RES,
                          tgt);
        message("combat", tp->query_cap_name()+" "+COL2+"POUNDS"+RES+" "+
                          tgt->query_cap_name()+"'s "+COL2+limb+RES+" "+
                          COL+"b"+COL2+"ru"+COL+"t"+COL2+"a"+COL+"lly"+RES+
                          " until it cracks open!", env, ({tp, tgt}) );
        
  }
  else {
    if (sizeof(weps))
      what = weps[0]->query_name();
    else
      what = "fist";
    message("combat", "You "+COL2+"pound"+RES+" on "+tgt->query_cap_name()+
                      "'s "+COL2+limb+RES+" with your "+what+".", tp);
    message("combat", tp->query_cap_name()+" "+COL2+"pounds"+RES+" on your "+
                      COL2+limb+RES+" with "+tp->query_possessive()+" "+what+
                      ".", tgt);
    message("combat", tp->query_cap_name()+" "+COL2+"pounds"+RES+" on "+
                      tgt->query_cap_name()+"'s "+
                      COL2+limb+RES+" with "+tp->query_possessive()+" "+what+
                      ".", env, ({tp, tgt}) );
  }

  tgt->do_damage(limb, dmg);
  tp->add_skill_points(type, 15+(rank-1)*10);

  return 1;
}

