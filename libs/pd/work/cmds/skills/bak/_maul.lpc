#include <std.h>
#include <daemons.h>

#define TYPE "blunt"
#define COL "%^ORANGE%^"
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
    FAIL("You need to use a blunt weapon for that.\n");
  
  if (!tp->kill_ob(tgt))
    FAIL("That cannot be attacked by you yet.\n");

  return 1;
}

int cmd_maul(string str) {
  object tp=this_player();
  object tgt;
  object *weps;
  string wep, limb;
  int cost, dmg, rank;
  int wc=0;

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
    message("combat","You swing "+wep+" at "+tgt->query_cap_name()+
                     ", "+COL+"mauling"+RES+" "+tgt->query_objective()+
                     " badly in the "+limb+"!", tp);
    
    message("combat",tp->query_cap_name()+" swings "+wep+" at you, "+
                     COL+"mauling"+RES+" you badly in the "+limb+"!", tgt);

    message("combat",tp->query_cap_name()+" swings "+wep+" at "+
                     tgt->query_cap_name()+", "+COL+"mauling"+RES+" "+
                     tgt->query_objective()+" badly in the "+limb+"!",
                     environment(tp), ({ tp, tgt }) );
    
    tgt->do_damage(limb, dmg);

    if (tp->query_stats("strength")-random(20)+random(20) >
        (tgt->query_stats("strength")+tgt->query_stats("constitution"))/2 &&
        limb == "head" && tgt->query_paralyzed() == 0) {
          // it should be sufficiently random that you hit them in the head
          //  without checking random(100) < 25 or whatever
          if (rank == 3) {
            message("combat","You are really dazed by the blow!",tgt);
            message("combat",tgt->query_cap_name()+" looks really dazed.",
                    environment(tgt), tgt);
            tgt->set_paralyzed(2+(random(2)*2), "You feel dazed.", "You can think straight again.");
          }
          else {
            message("combat","You are dazed by the blow!",tgt);
            message("combat",tgt->query_cap_name()+" looks dazed.",
                    environment(tgt), tgt);
            tgt->set_paralyzed(2, "You feel dazed.", "You can think straight again.");
          }
    }
  }
  
  return 1;
}

void help() {
  message("help","\n"
    "Syntax: <maul [living]>\n\n"
    "This attack lets you swing a blunt weapon at your foe. "
    "It's possible to daze your foe if he takes a bad enough "
    "blow to the head.\n"
    "Anyone with sufficient skill can learn this.",
    this_player());
}

