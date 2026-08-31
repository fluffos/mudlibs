#include <std.h>
#include <daemons.h>

#define TYPE "blade"
#define COL "%^BOLD%^%^WHITE%^"
#define RES "%^RESET%^"
#define FAIL(s) return notify_fail(s);

inherit DAEMON;

int abil() {
  object tp=this_player();
  if (tp && tp->query_class() == "fighter" &&
      tp->query_skill(TYPE) >= 30*5 &&
      tp->query_skill("attack") >= 30*6)
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
    FAIL("You need to use a sword for that.\n");
  
  if (!tp->kill_ob(tgt))
    FAIL("That cannot be attacked by you yet.\n");

  return 1;
}

int cmd_warblade(string str) {
  object tp=this_player();
  object tgt;
  object *weps;
  string wep, limb;
  string *adverbs;
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

  if (tp->query_skill("attack") >= 50*6) rank=4;
  else rank=3;

  adverbs = ({ "terribly", "severely" });
  
  dmg=BALANCE3_D->get_damage(tp, tgt, rank,
        ({ TYPE, TYPE, "attack" }),
        ({ "strength", "dexterity" }),
        ({ "strength", "dexterity" }) );

  dmg = dmg * 0.9;
  
  dmg += tp->query_skill("ferocity")/5;
  dmg += tp->query_skill("discipline")/6;
  
  dmg += wc*3;

  cost=dmg/12;
  
  if (tp->query_sp() < cost)
    FAIL("You are too tired.\n");

  tp->set_disable(1);
  tp->add_sp(-(cost+random(cost/10)));

  wep = weps[0]->query_name();
  limb = tgt->return_target_limb();

  if (tp->query_stats("dexterity")*2/3+tp->query_skill("discipline")/6+random(20) < tgt->query_stats("dexterity")) {
    message("combat","You miss "+tgt->query_cap_name()+" with your war slash.", tp);

    message("combat",tp->query_cap_name()+" misses "+tp->query_cap_name()+
                     " with a war slash.", environment(tp), ({ tp, tgt }) );
    
    message("combat",tp->query_cap_name()+" misses you with a war slash.", tgt);
  }
  else {
    message("combat","You "+COL+"SLASH"+RES+" "+tgt->query_cap_name()+
                     " "+COL+adverbs[rank-3]+RES+" with your sword!", tp);
    
    message("combat",tp->query_cap_name()+" "+COL+"SLASHES"+RES+" you "+COL+
                     adverbs[rank-3]+RES+" with "+tp->query_possessive()+" sword!", tgt);
    
    message("combat",tp->query_cap_name()+" "+COL+"SLASHES"+RES+" "+
                     tgt->query_cap_name()+" "+COL+adverbs[rank-3]+RES+" with "+
                     tp->query_possessive()+" sword!",
                     environment(tp), ({ tp, tgt }) );
    
    tgt->do_damage(limb, dmg);

    if (rank == 4) {
      // for every 25 dex over 100, give another hit
      for (int i=(tp->query_stats("dexterity")-100+random(30))/25; i>0; i--) {
        message("combat", "You swing around and "+COL+"SLASH"+RES+" "+
                          tgt->query_objective()+" again!", tp);
        message("combat", tp->query_cap_name()+" swings around and "+COL+
                          "SLASHES"+RES+" you again!", tgt);
        message("combat", tp->query_cap_name()+" swings around and "+COL+
                          "SLASHES"+RES+" "+tgt->query_objective()+" again!",
                          environment(tp), ({ tp, tgt}) );
        tgt->do_damage(tgt->return_target_limb(), dmg/7);
      }
    }

  }
  
  return 1;
}

void help() {
  message("help","\n"
    "Syntax: <warblade [living]>\n\n"
    "This is one of the most powerful sword strikes known, learned only "
    "by skilled fighters.",
    this_player());
}

