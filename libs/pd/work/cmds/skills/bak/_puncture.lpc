#include <std.h>
#include <daemons.h>

#define TYPE "knife"
#define COL "%^RED%^"
#define RES "%^RESET%^"
#define BALANCE3_D "/daemon/balance3_d"
#define FAIL(s) return notify_fail(s);

inherit DAEMON;

int abil() {
  object tp=this_player();
  if (tp && tp->query_skill(TYPE) >= 100 && tp->query_skill("attack") >= 40)
    return 1;
  return 0;
}

string type() { return "weapon"; }

int ok_cast(object tp, object tgt, object *weps) {

  if (tp->query_rest_type())
    FAIL("You must be standing to do that.\n");
  
  if (environment(tp)->query_property("no attack"))
    FAIL("You cannot do that here.\n");

  if (tp->query_disable() || tp->query_casting() || tp->query_magic_round())
    FAIL("You are busy.\n");

  if (!tgt)
    FAIL("You don't see that here.\n");

  if (!living(tgt))
    FAIL("That is not alive.\n");

  if (tp == tgt)
    FAIL("You cannot attack yourself.\n");

  if (!sizeof(weps))
    FAIL("You need to use a knife for that.\n");
  
  if (!tp->kill_ob(tgt))
    FAIL("That cannot be attacked by you yet.\n");

  return 1;
}

int cmd_puncture(string str) {
  object tp=this_player();
  object tgt;
  object *weps;
  string wep, limb;
  int cost, dmg, rank;
  int wc;

  if (!abil()) return 0;

  if (tp->query_disable()) return 1;

  if (!str) tgt=tp->query_current_attacker();
  else tgt=present(str,environment(tp));

  weps = filter(tp->query_wielded(), (: $1->query_type() == TYPE :) );
  
  if (!ok_cast(tp,tgt,weps)) return 0;

  foreach (object w in weps)
    wc += w->query_wc();
  wc = wc / sizeof(weps);
  
  if (tp->query_skill(TYPE) >= 160) rank=3;
  else rank=2;
  
  dmg=BALANCE3_D->get_damage(tp, tgt, rank,
        ({ TYPE, "attack" }),
        ({ "strength", "dexterity", "dexterity" }),
        ({ "strength", "dexterity" }) );

  dmg = dmg * 0.9;
  
  dmg += wc*6;

  if (dmg > 600) dmg=600+random(tp->query_level()*2);
  
  cost=dmg/9;
  
  if (tp->query_sp() < cost)
    FAIL("You are too tired.\n");

  tp->set_disable(1);
  tp->add_sp(-(cost+random(cost/10)));

  wep = weps[0]->query_name();
  limb = tgt->return_target_limb();
  if (dmg < 50) {
    message("combat","You lunge at "+tgt->query_cap_name()+" with "+wep+
                     ", but miss.", tp);

    message("combat",tp->query_cap_name()+" lunges at "+tgt->query_cap_name()+
                     " with "+wep+", but misses.", environment(tp), ({ tp, tgt }) );
    
    message("combat",tp->query_cap_name()+" lunges at you with "+wep+", but misses.", tgt);
  }
  else {
    message("combat","You lunge at "+tgt->query_cap_name()+" and "+
                     COL+"puncture"+RES+" "+tgt->query_possessive()+
                     " "+limb+"!", tp);
    
    message("combat",tp->query_cap_name()+" lunges at you and "+
                     COL+"punctures"+RES+" your "+limb+"!", tgt);

    message("combat",tp->query_cap_name()+" lunges at "+tgt->query_cap_name()+
                     " and "+COL+"punctures"+RES+" "+tgt->query_possessive()+
                     " "+limb+"!", environment(tp), ({ tp, tgt }) );
    
    tgt->do_damage(limb, dmg);

    if (rank == 3 && tp->query_alignment() < 0) {
      message("combat","You "+COL+"twist"+RES+" the "+wep+" maliciously!",tp);
      message("combat",tp->query_cap_name()+" "+COL+"twists"+RES+" the "+wep+
                       " maliciously!", environment(tp), tp);
      if (userp(tgt))
        tgt->heal_limb(limb, -(dmg/3));
      else
        tgt->heal_limb(limb, -(dmg/(tgt->query_level()*3)));
      tgt->do_damage(limb, dmg/10);
    }
  }
  
  return 1;
}

void help() {
  message("help","\n"
    "Syntax: <puncture [living]>\n\n"
    "Using a knife, you can lunge and puncture your opponent's skin. "
    "The quality of the knife is important.\n"
    "Anyone with sufficient skill can learn this.",
    this_player());
}

