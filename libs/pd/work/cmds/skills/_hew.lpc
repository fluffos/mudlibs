#include <std.h>
#include <daemons.h>
#include <damage_types.h>
#include <damage.h>

#define TYPE "axe"
#define COL "%^BOLD%^%^RED%^"
#define RES "%^RESET%^"
#define FAIL(s) return notify_fail(s);

inherit DAEMON;

int abil() {
  object tp=this_player();
  if (tp && tp->query_subclass() == "berserker" &&
      tp->query_skill(TYPE) >= 35*5 &&
      tp->query_skill("ferocity") >= 35*5 &&
      tp->query_skill("attack") >= 35*6)
        return 1;
  return 0;
}

string type() { return "attack"; }

int ok_cast(object tp, object tgt, object *weps) {

  if (tp->query_rest_type())
    FAIL("You must be standing to do that.\n");
  
  if (environment(tp)->query_property("no attack"))
    FAIL("You cannot do that here.\n");

  if (!tgt)
    FAIL("You don't see that here.\n");

  if (!living(tgt))
    FAIL("That is not alive.\n");

  if (tp == tgt)
    FAIL("You cannot attack yourself.\n");

  if (!sizeof(weps))
    FAIL("You need to use an axe for that.\n");
  
  if (!tp->kill_ob(tgt))
    FAIL("That cannot be attacked by you yet.\n");

  return 1;
}

int cmd_hew(string str) {
  object tp=this_player();
  object tgt;
  object *weps;
  string wep, limb;
  int cost, dmg, rank;
  int wc;
  int bodydam;

  if (!abil()) return 0;

  if (tp->query_disable()) return 1;

  if (!str) tgt=tp->query_current_attacker();
  else tgt=present(str,environment(tp));

  weps = filter(tp->query_wielded(), (: $1->query_type() == TYPE :) );
  
  if (!ok_cast(tp,tgt,weps)) return 0;

  foreach (object w in weps)
    wc += w->query_wc();
  wc = wc / sizeof(weps);

  if (tp->query_skill(TYPE) >= 250) rank=4;
  else rank=3;
  
  dmg=BALANCE3_D->get_damage(tp, tgt, rank,
        ({ TYPE, TYPE, "attack", "ferocity", "rage" }),
        ({ "strength", "strength", "strength", "dexterity" }),
        ({ "strength", "dexterity" }) );
  
  dmg = dmg * 0.95;
  
  dmg += wc*8;

  cost = BALANCE3_D->get_cost(dmg, rank, "sp") * 85 / 100;
  
  if (tp->query_sp() < cost)
    FAIL("You are too tired.\n");

  tp->set_disable(1);
  tp->add_sp(-(cost+random(cost/10)));

  wep = weps[0]->query_name();
  limb = tgt->return_target_limb();
  if (tp->query_stats("dexterity")+random(40) < tgt->query_stats("dexterity")) {
    message("combat","You swing "+wep+" at "+tgt->query_cap_name()+
                     " and miss "+tgt->query_objective()+" completely.", tp);

    message("combat",tp->query_cap_name()+" swings "+wep+" at "+tgt->query_cap_name()+
                     " and misses "+tgt->query_objective()+" completely.",
                     environment(tp), ({ tp, tgt }) );
    
    message("combat",tp->query_cap_name()+" swings "+wep+" at you and "
                     "misses completely.", tgt);
  }
  else {
    message("combat","You swing your "+COL+"axe"+RES+" at "+tgt->query_cap_name()+" and "+
                     COL+"HEW"+RES+" "+tgt->query_possessive()+" "+limb+"!", tp);
    
    message("combat",tp->query_cap_name()+" swings "+tp->query_possessive()+
                     " "+COL+"axe"+RES+" at you and "+COL+"HEWS"+RES+" your "+
                     limb+"!", tgt);
    
    message("combat",tp->query_cap_name()+" swings "+tp->query_possessive()+
                     " "+COL+"axe"+RES+" at "+tgt->query_cap_name()+" and "+
                     COL+"HEWS"+RES+" "+tgt->query_cap_name()+"'s "+limb+"!",
                     environment(tp), ({ tp, tgt }) );
    
    bodydam = dmg * (250+random(180)-(tgt->query_stats("constitution")*7/10))/100;
    tgt->do_damage(limb, bodydam, DAMAGE_PHYSICAL | DAMAGE_IMPACT | DAMAGE_SLASH, DAMAGE_NO_HP, tp);
    tgt->do_damage(limb, dmg, DAMAGE_PHYSICAL | DAMAGE_IMPACT | DAMAGE_SLASH, 0, tp);

    if (tgt->query_hp() < tgt->query_max_hp()/2) {
      message("combat", "The sight of "+COL+"blood"+RES+" from "+
                        tgt->query_cap_name()+"'s wound sends you "
                        "into a frenzy!", tp);
      message("combat", tp->query_cap_name()+" goes into a frenzy at the sight "
                        "of "+COL+"blood"+RES+"!", environment(tp), tp);

      for (int i=((tp->query_skill("rage")-250)/60)+1; i > 0; i--) {
        message("combat", "You "+COL+"slam"+RES+" your axe into "+
                          tgt->query_cap_name()+" again!", tp);
        message("combat", tp->query_cap_name()+" "+COL+"slams"+RES+" "+
                          tp->query_possessive()+" axe into you again!", tgt);
        message("combat", tp->query_cap_name()+" "+COL+"slams"+RES+" "+
                          tp->query_possessive()+" axe into "+tgt->query_cap_name()+
                          " again!", environment(tp), ({ tp, tgt}) );
        tgt->do_damage("target", dmg/5, DAMAGE_PHYSICAL | DAMAGE_IMPACT | DAMAGE_SLASH, 0, tp);
      }
    }

  }
  
  return 1;
}

void help() {
  message("help","\n"
    "Syntax: <hew [living]>\n\n"
    "This is a seasoned berserker's ability to attack with an axe, "
    "causing a lot of damage to his foe's body.",
    this_player());
}

