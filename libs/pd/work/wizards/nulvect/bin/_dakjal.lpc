
#include <std.h>
#include <daemons.h>

#define COL "%^YELLOW%^"
#define MCOL "%^BOLD%^%^BLACK%^"
#define RES "%^RESET%^"

#define FAIL(s) return notify_fail(s+"\n")

inherit DAEMON;

int abil() {
  object tp=this_player();
  if (tp && tp->query_subclass() == "kataan" &&
      tp->query_skill("projectile") >= 60*6 &&
      tp->query_skill("attack") >= 60*4 &&
      tp->query_skill("magic attack") >= 60*5 &&
      tp->query_skill("faith") >= 60*6 &&
      tp->query_skill("summoning") >= 60*6)
        return 1;
  return 0;
}

string type() { return "attack"; }

void help() {
  message("help",
    "Syntax: <dakjal [whom]>\n\n"
    "Dakjal is an incredibly advanced technique for only the "
    "most powerful kataans. It involves swinging your spear in "
    "a slicing motion and simultaneously channeling energy through "
    "it to create a sizable wave of pure demonic power that rips "
    "through your foe.",
    this_player() );
}

int can_cast(object tp, object tgt, object *weps) {

  if (!tp) return 0;

  if (environment(tp)->query_property("no attack"))
    FAIL("You cannot attack here.");

  if (tp->query_disable() || tp->query_casting() || tp->query_magic_round())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("You're not alive.");

  if (!tgt)
    FAIL("Dakjal whom?");

  if (!living(tgt))
    FAIL("That would be a waste of time.");

  if (tgt == tp)
    FAIL("The demons laugh at you.");

  if (!sizeof(weps))
    FAIL("You must use a spear for that.");

  if (!tp->kill_ob(tgt))
    FAIL("You may not attack "+tgt->query_cap_name()+".");
  return 1;
}

int cmd_dakjal(string str) {
  object tp=this_player();
  object env=environment(tp);
  object tgt;
  object *weps;
  int pdmg, mdmg, pcost, mcost;
  int myatt, hisdef;

  if (!abil()) return 0;

  if (str)
    tgt=present(str, env);
  else
    tgt=tp->query_current_attacker();

  weps = filter(tp->query_wielded(), (: $1->query_type() == "projectile" :) );

  if (!can_cast(tp, tgt, weps)) return 0;

  pdmg = BALANCE3_D->get_damage(tp, tgt, 4,
    ({"attack", "projectile"}),
    ({"strength", "strength","dexterity"}),
    ({"strength","dexterity"}) );

  pdmg *= 0.3;

  pcost = pdmg/8;

  mdmg = BALANCE3_D->get_damage(tp, tgt, 4,
    ({"magic attack", "faith", "summoning"}),
    ({"wisdom","wisdom","intelligence"}),
    ({"summoning", "faith"}) );

  mdmg *= 0.8;

  mcost = mdmg/12;

  if (tp->query_sp() < pcost)
    FAIL("You are too tired.");

  tp->add_sp(-(pcost+random(pcost/12)));
  tp->set_disable();

  myatt = tp->query_stats("dexterity");
  myatt += tp->query_skill("attack");
  myatt += tp->query_skill("projectile")/6;

  hisdef = tgt->query_stats("dexterity")*5/4;
  hisdef += tgt->query_skill("defense");
  hisdef += tgt->query_skill("agility")/3;

  if (tp->query_rest_type()) {
    message("combat", "You "+COL+"sw"+MCOL+"i"+COL+"ng"+RES+" your "+
                      weps[0]->query_name()+" in "+tgt->query_cap_name()+
                      "'s direction!", tp);
    message("combat", tp->query_cap_name()+" "+COL+"sw"+MCOL+"in"+COL+"gs"+RES+
                      " "+tp->query_possessive()+" "+weps[0]->query_name()+
                      " in your direction!", tgt);
    message("combat", tp->query_cap_name()+" "+COL+"sw"+MCOL+"in"+COL+"gs"+RES+
                      " "+tp->query_possessive()+" "+weps[0]->query_name()+
                      " in "+tgt->query_cap_name()+"'s direction!",
                      env, ({tp, tgt}) );
  }
  else if (hisdef > myatt-random(25)) {
    message("combat", "You "+COL+"sw"+MCOL+"i"+COL+"ng"+RES+" your "+
                      weps[0]->query_name()+" at "+tgt->query_cap_name()+
                      " and barely miss "+tgt->query_objective()+"!", tp);
    message("combat", tp->query_cap_name()+" "+COL+"sw"+MCOL+"in"+COL+"gs"+RES+
                      " "+tp->query_possessive()+" "+weps[0]->query_name()+
                      " at you and barely misses you!", tgt);
    message("combat", tp->query_cap_name()+" "+COL+"sw"+MCOL+"in"+COL+"gs"+RES+
                      " "+tp->query_possessive()+" "+weps[0]->query_name()+
                      " at "+tgt->query_cap_name()+" and barely misses "+
                      tgt->query_objective()+"!", env, ({tp, tgt}) );
  }
  else {
    message("combat", "You "+COL+"sw"+MCOL+"i"+COL+"ng"+RES+" your "+
                      weps[0]->query_name()+" at "+tgt->query_cap_name()+
                      " and "+COL+"sl"+MCOL+"i"+COL+"ce"+RES+" "+tgt->query_objective()+
                      " with the blade!", tp);
    message("combat", tp->query_cap_name()+" "+COL+"sw"+MCOL+"in"+COL+"gs"+RES+
                      " "+tp->query_possessive()+" "+weps[0]->query_name()+
                      " at you and "+COL+"sl"+MCOL+"ic"+COL+"es"+RES+
                      " you with the blade!", tgt);
    message("combat", tp->query_cap_name()+" "+COL+"sw"+MCOL+"in"+COL+"gs"+RES+
                      " "+tp->query_possessive()+" "+weps[0]->query_name()+
                      " at "+tgt->query_cap_name()+" and "+
                      COL+"sl"+MCOL+"ic"+COL+"es"+RES+" "+
                      tgt->query_objective()+" with the blade!", env, ({tp, tgt}) );
    tgt->do_damage(tgt->return_target_limb(), pdmg);
  }

  if (tp->query_mp() < mcost) {
    message("info", "Your magic is too low.", tp);
  }
  else if (env->query_property("no magic")) {
    message("info", "Some force prevents your magic.", tp);
  }
  else {
    message("magic", MCOL+"A wave of "
                      "d"+COL+"e"+MCOL+"m"+COL+"o"+MCOL+"n"+COL+"i"+MCOL+"c"
                      " energy "+COL+"shoots"+MCOL+" out and "+COL+"rips"+MCOL+
                      " through you!", tgt);
    message("magic", MCOL+"A wave of "
                      "d"+COL+"e"+MCOL+"m"+COL+"o"+MCOL+"n"+COL+"i"+MCOL+"c"
                      " energy "+COL+"shoots"+MCOL+" out and "+COL+"rips"+MCOL+
                      " through "+tgt->query_cap_name()+"!", env, tgt);
    tp->add_mp(-(mcost+random(mcost/12)));
    tgt->do_damage(tgt->return_limb(), mdmg);
  }

  return 1;
}
      
