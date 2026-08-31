#include <std.h>
#include <daemons.h>

#define TYPE "axe"
#define COL "%^BOLD%^%^RED%^"
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

int cmd_hack(string str) {
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

  if (tp->query_skill(TYPE) >= 160) rank=3;
  else rank=2;
  
  dmg=BALANCE3_D->get_damage(tp, tgt, rank,
        ({ TYPE, "attack" }),
        ({ "strength", "strength", "dexterity" }),
        ({ "strength", "dexterity" }) );
  
  dmg += wc*4;

  if (dmg > 600) dmg=600+random(tp->query_level()*2);
  
  cost=dmg/10;
  
  if (tp->query_sp() < cost)
    FAIL("You are too tired.\n");

  tp->set_disable(1);
  tp->add_sp(-(cost+random(cost/10)));

  wep = weps[0]->query_name();
  limb = tgt->return_target_limb();
  if (dmg < 50) {
    message("combat","You swing "+wep+" at "+tgt->query_cap_name()+
                     " and miss.", tp);

    message("combat",tp->query_cap_name()+" swings "+wep+" at "+tgt->query_cap_name()+
                     " and misses.", environment(tp), ({ tp, tgt }) );
    
    message("combat",tp->query_cap_name()+" swings "+wep+" at you and misses.", tgt);
  }
  else {
    message("combat","You take a swing and "+COL+"hack"+RES+" "+wep+
                     " deeply into "+tgt->query_cap_name()+
                     "'s "+limb+"!", tp);
    
    message("combat",tp->query_cap_name()+" takes a swing and "+COL+"hacks"+
                     RES+" "+wep+" deeply into your "+limb+"!", tgt);
    
    message("combat",tp->query_cap_name()+" takes a swing and "+COL+"hacks"+
                     RES+" "+wep+" deeply into "+tgt->query_cap_name()+
                     "'s "+limb+"!", environment(tp), ({ tp, tgt }) );
    
    if (userp(tgt))
      bodydam=dmg/4;
    else
      bodydam=dmg/(tgt->query_level()*4);
    
    tgt->heal_limb(limb, -(2*bodydam));
    
    tgt->do_damage(limb, dmg);

    if (rank == 3) {
      message("combat","The wound bleeds badly.",environment(tp));
      tgt->do_damage(limb, dmg/10);
    }

  }
  
  return 1;
}

void help() {
  message("help","\n"
    "Syntax: <hack [living]>\n\n"
    "Using this ability, you hack into your foe's limbs using an axe."
    "This causes a lot of damage to the limb it hits.\n"
    "Anyone with sufficient skill can learn this.",
    this_player());
}

