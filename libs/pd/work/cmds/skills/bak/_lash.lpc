#include <std.h>
#include <daemons.h>
#include <rest.h>

#define TYPE "flail"
#define COL "%^MAGENTA%^"
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
    FAIL("You need to use a whip for that.\n");
  
  if (!tp->kill_ob(tgt))
    FAIL("That cannot be attacked by you yet.\n");

  return 1;
}

int cmd_lash(string str) {
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

  dmg = dmg * 1.1;
  
  dmg += wc*2;

  if (dmg > 600) dmg=600+random(tp->query_level()*2);
  
  cost=dmg/12;
  
  if (tp->query_sp() < cost)
    FAIL("You are too tired.\n");

  tp->set_disable(1);
  tp->add_sp(-(cost+random(cost/10)));

  wep = weps[0]->query_name();
  limb = tgt->return_limb();
  if (dmg < 50) {
    message("combat","You crack "+wep+" at "+tgt->query_cap_name()+
                     " but miss.", tp);

    message("combat",tp->query_cap_name()+" cracks "+wep+" at "+
                     tgt->query_cap_name()+" but misses.",
                     environment(tp), ({ tp, tgt }) );
    
    message("combat",tp->query_cap_name()+" cracks "+wep+" at you but misses.", tgt);
  }
  else {
    message("combat","You crack "+wep+" at "+tgt->query_cap_name()+", "+
                     COL+"lashing"+RES+" "+tgt->query_objective()+
                     " painfully!", tp);
    
    message("combat",tp->query_cap_name()+" cracks "+wep+" at you, "+
                     COL+"lashing"+RES+" you painfully!", tgt);

    message("combat",tp->query_cap_name()+" cracks "+wep+" at "+
                     tgt->query_cap_name()+", "+COL+"lashing"+RES+" "+
                     tgt->query_objective()+" painfully!", environment(tp), ({tp, tgt}));
    
    tgt->do_damage(limb, dmg);

    if (rank == 3 && strsrch(limb,"leg") != -1 &&
        tp->query_stats("strength")+random(10)-random(10) > tgt->query_stats("dexterity")) {
      message("combat","The "+wep+" wraps around "+tgt->query_possessive()+" "+
                       limb+" and you pull back, "+COL+"wrenching"+RES+" it out "
                       "from under "+tgt->query_objective()+"!", tp);
      message("combat","The "+wep+" wraps around "+tgt->query_possessive()+" "+
                       limb+" and "+tp->query_cap_name()+" pulls back, "+COL+
                       "wrenching"+RES+" it out from under "+tgt->query_objective()+"!",
                       environment(tp), ({ tp, tgt }) );
      message("combat","The "+wep+" wraps around your "+limb+" and "+
                       tp->query_cap_name()+" pulls back, "+COL+"wrenching"+RES+
                       " it out from under you!", tgt);
      message("combat","You fall over!", tgt);
      message("combat",tgt->query_cap_name()+" falls over!", environment(tp), tgt);
      tgt->do_damage(tgt->return_limb(), dmg/10);
      tgt->set_rest_type(LAY);
    }
  }
  
  return 1;
}

void help() {
  message("help","\n"
    "Syntax: <lash [living]>\n\n"
    "This flail move lets you lash your opponent painfully, and, "
    "if you're strong enough, even catch his limbs with your whip.\n"
    "Anyone with sufficient skill can learn this.",
    this_player());
}

