
#include <std.h>
#include <daemons.h>
#include <damage_types.h>
#include <damage.h>

#define COL "%^YELLOW%^"
#define RES "%^RESET%^"

#define FAIL(s) return notify_fail(s+"\n")

inherit DAEMON;

int abil() {
  object tp=this_player();
  if (tp && tp->query_skill("projectile") >= 200 &&
      member_array(tp->query_subclass(), ({"kataan"})) != -1)
        return 1;
  return 0;
}

string type() { return "attack"; }

void help() {
  message("help",
    "Syntax: <skewer [whom]>\n\n"
    "An advanced spear technique. The user tries to run his spear "
    "right through his opponent. Fully skewering a moving target is "
    "very hard to do, but even grazing hits will cause a lot of "
    "pain and internal damage.",
    this_player() );
}

int can_cast(object tp, object tgt, object *weps) {

  if (!tp) return 0;

  if (environment(tp)->query_property("no attack"))
    FAIL("You may not attack here.");

  if (tp->query_disable() || tp->query_casting() || tp->query_magic_round())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("You jab your spear into... hey, wait, you're dead.");

  if (!sizeof(weps))
    FAIL("You must use a spear for that.");

  if (tp->query_rest_type())
    FAIL("You have to stand up to do that.");

  if (!tgt)
    FAIL("Skewer whom?");

  if (!living(tgt))
    FAIL("Trying to make some shishkebabs?");

  if (tgt == tp)
    FAIL("That would be really difficult to do.");

  if (!tp->kill_ob(tgt))
    FAIL("You may not attack "+tgt->query_cap_name()+".");
  
  return 1;
}

int cmd_skewer(string str) {
  object tp=this_player();
  object env=environment(tp);
  object tgt;
  object *weps;
  int dmg, cost, rank;
  int hisdodge, myhit;
  int extradmg;
  string wepname;

  if (!abil()) return 0;

  if (str)
    tgt = present(str, env);
  else
    tgt = tp->query_current_attacker();
  
  weps = filter(tp->query_wielded(), (: $1->query_type() == "projectile" :) );

  if (!can_cast(tp, tgt, weps)) return 0;
  
  if (tp->query_skill("attack")+tp->query_skill("projectile") >= 45*(4+6))
    rank=4;
  else
    rank=3;
  
  dmg = BALANCE3_D->get_damage(tp, tgt, rank,
    ({"projectile", "projectile", "attack"}),
    ({"strength", "dexterity"}),
    ({"strength", "strength", "dexterity"}) );

  cost = BALANCE3_D->get_cost(dmg, rank, "sp") * 115 / 100;

  if (tp->query_sp() < cost)
    FAIL("You are too tired.");

  tp->add_sp(-(cost-random(cost/12)));
  tp->set_disable();

  hisdodge = tgt->query_stats("dexterity")*2+tgt->query_skill("defense");
  myhit = tp->query_stats("dexterity")+tp->query_skill("attack");
  wepname = weps[0]->query_name();
  
  extradmg = BALANCE3_D->get_damage(tp, tgt, rank,
    ({"projectile"}), ({"strength"}), ({"strength"}) );
  extradmg /= 5;

  if (hisdodge > myhit+random(35)) {
    message("combat", "You try to stab your "+wepname+" into "+
                      tgt->query_cap_name()+", but "+tgt->query_subjective()+
                      " dodges out of the way!", tp);
    message("combat", tp->query_cap_name()+" tries to stab "+
                      tp->query_possessive()+" "+wepname+" into you, "
                      "but you dodge out of the way!", tgt);
    message("combat", tp->query_cap_name()+" tries to stab "+
                      tp->query_possessive()+" "+wepname+" into "+
                      tgt->query_cap_name()+", but "+tgt->query_cap_name()+
                      " dodges out of the way!", env, ({tp, tgt}) );
  }
  else {
    if (hisdodge+30 < myhit+random(30) || tgt->query_hp() < dmg+extradmg) {
      message("combat", "You "+COL+"stab"+RES+" your "+wepname+" "+
                        COL+"deeply"+RES+" into "+tgt->query_cap_name()+
                        " and "+COL+"SKEWER"+RES+" "+tgt->query_objective()+
                        " gruesomely!", tp);
      message("combat", tp->query_cap_name()+" "+COL+"stabs"+RES+" "+
                        tp->query_possessive()+" "+wepname+" "+
                        COL+"deeply"+RES+" into you and "+COL+"SKEWERS"+RES+
                        " you gruesomely!", tgt);
      message("combat", tp->query_cap_name()+" "+COL+"stabs"+RES+" "+
                        tp->query_possessive()+" "+wepname+" "+
                        COL+"deeply"+RES+" into "+tgt->query_cap_name()+
                        " and "+COL+"SKEWERS"+RES+" "+tgt->query_objective()+
                        " gruesomely!", env, ({tp, tgt}) );
      dmg += extradmg;
    }
    else {
      message("combat", "You "+COL+"graze"+RES+" "+tgt->query_cap_name()+
                        " "+COL+"painfully"+RES+" with your "+wepname+"!", tp);
      message("combat", tp->query_cap_name()+" "+COL+"grazes"+RES+" you "+
                        COL+"painfully"+RES+" with "+tp->query_possessive()+
                        " "+wepname+"!", tgt);
      message("combat", tp->query_cap_name()+" "+COL+"grazes"+RES+" "+
                        tgt->query_cap_name()+" "+
                        COL+"painfully"+RES+" with "+tp->query_possessive()+
                        " "+wepname+"!", env, ({tp, tgt}) );
      dmg *= 0.85;
    }
    tgt->do_damage("target", dmg, DAMAGE_PHYSICAL | DAMAGE_PIERCE, 0, tp);
  }
  
  return 1;
}
