#include <std.h>
#include <daemons.h>

#define TYPE "flail"
#define COL "%^MAGENTA%^"
#define RES "%^RESET%^"
#define BALANCE3_D "/daemon/balance3_d"
#define FAIL(s) return notify_fail(s);

inherit DAEMON;

int abil() {
  object tp=this_player();
  if (tp && tp->query_skill(TYPE) >= 20)
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
    FAIL("You need to use a whip for that.\n");
  
  if (!tp->kill_ob(tgt))
    FAIL("That cannot be attacked by you yet.\n");

  return 1;
}

int cmd_whip(string str) {
  object tp=this_player();
  object tgt;
  object *weps;
  string wep;
  int cost, dmg, rank;

  if (!abil()) return 0;

  if (tp->query_disable()) return 1;

  if (!str) tgt=tp->query_current_attacker();
  else tgt=present(str,environment(tp));

  weps = filter(tp->query_wielded(), (: $1->query_type() == TYPE :) );
  
  if (!ok_cast(tp,tgt,weps)) return 0;

  if (tp->query_skill(TYPE) >= 75) rank=2;
  else rank=1;
  
  dmg=BALANCE3_D->get_damage(tp, tgt, rank,
        ({ TYPE, "attack" }),
        ({ "dexterity" }) );
  
  dmg = dmg*3/4;

  if (dmg > 300) dmg=300+random(tp->query_level()*2);
  
  cost=dmg/9;
  
  if (tp->query_sp() < cost)
    FAIL("You are too tired.\n");

  tp->set_disable(1);
  tp->add_sp(-(cost+random(cost/10)));

  if (dmg < 15) {
    message("combat","You try to whip "+tgt->query_cap_name()+
                     ", but miss.", tp);

    message("combat",tp->query_cap_name()+" tries to whip "+tgt->query_cap_name()+
                     ", but misses.", environment(tp), ({ tp, tgt }) );
    
    message("combat",tp->query_cap_name()+" tries to whip you, but misses.", tgt);
  }
  else {
    wep = weps[0]->query_name();
    message("combat","You "+COL+"whip"+RES+" "+tgt->query_cap_name()+" with "+wep+"!", tp);
    
    message("combat",tp->query_cap_name()+" "+COL+"whips"+RES+" you with "+wep+"!", tgt);

    message("combat",tp->query_cap_name()+" "+COL+"whips"+RES+" "+tgt->query_cap_name()+
                     "with "+wep+"!", environment(tp), ({ tp, tgt }) );
    
    tgt->do_damage(tgt->return_target_limb(), dmg);
  }
  
  return 1;
}

void help() {
  message("help","\n"
    "Syntax: <whip [living]>\n\n"
    "A basic attack with a whip.\n"
    "Anyone with sufficient skill can learn this.",
    this_player());
}

