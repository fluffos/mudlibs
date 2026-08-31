#include <std.h>
#include <daemons.h>
#include <damage_types.h>
#include <damage.h>

#define TYPE "projectile"
#define COL "%^YELLOW%^"
#define RES "%^RESET%^"
#define FAIL(s) return notify_fail(s);

inherit DAEMON;

int abil() {
  object tp=this_player();
  if (tp && tp->query_subclass() == "ranger" &&
      tp->query_skill(TYPE) >= 14*5)
        return 1;
  return 0;
}

string type() { return "attack"; }

int ok_cast(object tp, object tgt, object *weps) {

  if (tp->query_rest_type())
    FAIL("You must be standing to do that.\n");
  
  if (environment(tp)->query_property("no attack"))
    FAIL("You cannot do that here.\n");

  if (tp->query_busy())
    FAIL("You are busy.");

  if (!tgt)
    FAIL("You don't see that here.\n");

  if (!living(tgt))
    FAIL("That is not alive.\n");

  if (tp == tgt)
    FAIL("You cannot attack yourself.\n");

  if (!sizeof(weps))
    FAIL("You need to use a spear for that.\n");
  
  if (!tp->kill_ob(tgt))
    FAIL("That cannot be attacked by you yet.\n");

  return 1;
}

int cmd_spear(string str) {
  object tp=this_player();
  object tgt;
  object *weps;
  string wep, limb;
  int cost, dmg, rank;
  int wc;
  int x;
  int s;

  if (!abil()) return 0;

  if (!str) tgt=tp->query_current_attacker();
  else tgt=present(str,environment(tp));

  weps = filter(tp->query_wielded(), (: $1->query_type() == TYPE :) );
  
  tp->clean_up_attackers();

  s=sizeof(tp->query_attackers());

  if (!ok_cast(tp,tgt,weps)) return 0;

  foreach (object w in weps)
    wc += w->query_wc();
  wc = wc / sizeof(weps);
  
  if (tp->query_skill(TYPE) >= 45*5) rank=4;
  else if (tp->query_skill(TYPE) >= 30*5) rank=3;
  else rank=2;
  
  dmg=BALANCE3_D->get_damage(tp, tgt, rank,
        ({ TYPE, TYPE, "attack", "discipline" }),
        ({ "strength", "dexterity" }),
        ({ "strength", "dexterity" }) );
  
  dmg = dmg*0.9;
  
  if (!s) {
    x = BALANCE3_D->get_damage(tp, tgt, rank,
          ({TYPE, "discipline", "stealth"}),
          ({"dexterity", "dexterity", "strength"}),
          ({"dexterity", "strength"}) );

    if (tp->query_skill("stealth")*5/3 > random(tgt->query_skill("perception")))
      dmg += x/2;
    if (tp->query_stealth())
      dmg += x/4;
    if (tp->query_invis())
      dmg += x/4;

    message("combat","You "+COL+"catch"+RES+" "+tgt->query_cap_name()+
                     " off guard!",tp);
    dmg += wc*7;

  }

  cost = BALANCE3_D->get_cost(dmg, rank, "sp") * 92 / 100;
  
  if (tp->query_sp() < cost)
    FAIL("You are too tired.\n");

  tp->set_disable(1);
  tp->add_sp(-(cost+random(cost/10)));

  wep = weps[0]->query_name();
  limb = tgt->return_target_limb();

  if (dmg < 20) {
    message("combat","You try to spear "+tgt->query_cap_name()+
                     ", but miss.", tp);

    message("combat",tp->query_cap_name()+" tries to spear "+tgt->query_cap_name()+
                     ", but misses.", environment(tp), ({ tp, tgt }) );
    
    message("combat",tp->query_cap_name()+" misses an attempt to spear you.", tgt);
  }
  else {
    message("combat","You "+COL+"heft"+RES+" your "+wep+" and "+COL+"spear"+RES+
                     " "+tgt->query_cap_name()+" with a downward blow!", tp);
    
    message("combat",tp->query_cap_name()+" "+COL+"hefts"+RES+" "+
                     tp->query_possessive()+" "+wep+" and "+COL+"spears"+RES+
                     " you with a downward blow!", tgt);

    message("combat",tp->query_cap_name()+" "+COL+"hefts"+RES+" "+
                     tp->query_possessive()+" "+wep+" and "+COL+"spears"+RES+
                     " "+tgt->query_cap_name()+" with a downward blow!",
                     environment(tp), ({ tp, tgt }) );
    
    tgt->do_damage(limb, dmg, DAMAGE_PHYSICAL | DAMAGE_PIERCE, 0, tp);
  }
  
  return 1;
}

void help() {
  message("help",
    "Syntax: <spear [living]>\n\n"
    "A hunting ability that rangers use. Surprise attacks can be "
    "especially damaging.",
    this_player());
}

