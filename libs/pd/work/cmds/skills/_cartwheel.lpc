
#include <std.h>
#include <daemons.h>
#include <rest.h>
#include <damage_types.h>
#include <damage.h>

#define RES "%^RESET%^"
#define COL "%^BOLD%^%^GREEN%^"
#define COL2 RES+"%^CYAN%^"

#define CARTWHEEL COL+"c"+COL2+"a"+COL+"r"+COL2+"t"+COL+"w"+COL2+"h"+COL+"e"+COL2+"e"+COL+"l"+RES

#define FAIL(s) return notify_fail(s+"\n");

inherit DAEMON;

string random_cartwheel_limb(object who);

int abil() {
  object tp=this_player();
  if (tp && tp->query_subclass() == "jester" &&
      tp->query_skill("entertainment") >= 6*20) return 1;
  return 0;
}

void help() {
  object tp=this_player();
  message("help","Syntax: <cartwheel [whom]>\n\n"
                 "Jesters can do cartwheels during combat to try and knock "
                 "their enemies over.",tp);
}

string type() { return "attack"; }

int can_cast(object tp, object tgt) {

  if (!tp) return 0;
  
  if (environment(tp)->query_property("no attack"))
    FAIL("You cannot attack here.");

  if (tp->query_disable() || tp->query_casting() || tp->query_magic_round())
    FAIL("You are busy.");

  if (tp->query_rest_type())
    FAIL("You have to stand up before you can do a cartwheel!");
  
  if (!tgt)
    FAIL("Cartwheel at whom?");

  if (!living(tgt))
    FAIL("You cartwheel at "+tgt->query_name()+" and bounce off.");

  if (tgt == tp)
    FAIL("You cartwheel around in a circle but can't manage to catch up to yourself.");

  if (!(tp->kill_ob(tgt)))
    FAIL("You may not attack "+tp->query_objective()+".");

  return 1;
}

int cmd_cartwheel(string str) {
  object tp=this_player();
  object env=environment(tp);
  object tgt;
  object *others;
  object prev;
  int dmg, cost, rank;
  int hit;
  
  if (!abil()) return 0;

  tp->clean_up_attackers();
  
  if (str && str != "")
    tgt=present(str, env);
  else
    tgt=tp->query_current_attacker();
  
  if (!can_cast(tp, tgt)) return 0;

  hit = tp->query_skill("entertainment")+tp->query_stats("dexterity")+tp->query_stats("strength");
  if (hit > 48*(6+2+2)) rank=4;
  else if (hit > 32*(6+2+2)) rank=3;
  else rank=2;
  
  dmg = BALANCE3_D->get_damage(tp, tgt, rank,
    ({ "entertainment", "entertainment", "attack" }),
    ({ "dexterity" }),
    ({ "dexterity", "strength" }) );

  dmg = dmg*95/100;
  
  cost = BALANCE3_D->get_cost(dmg, rank, "sp") * 110 / 100;
  
  others = tp->query_attackers() - ({tgt});

  if (tp->query_sp() < cost)
    FAIL("You are too tired.");

  tp->set_disable();

  if (tgt->query_stats("dexterity")+tgt->query_skill("agility")-random(20) >
      (tp->query_stats("dexterity")+tp->query_skill("entertainment"))*0.75) {
        tp->add_sp(-(cost/3+random(cost/15)));
        message("combat", "You turn and do a cartwheel at "+tgt->query_cap_name()+
                          ", but miss.", tp);
        message("combat", tp->query_cap_name()+" does a cartwheel at you, "
                          "but you dodge it easily.", tgt);
        message("combat", tp->query_cap_name()+" does a cartwheel at "+
                          tgt->query_cap_name()+", but misses.", env, ({tp, tgt}) );
  }

  else {

    message("combat", "You turn and "+CARTWHEEL+
                      " straight into "+tgt->query_cap_name()+"!", tp);
    message("combat", tp->query_cap_name()+" does a "+CARTWHEEL+
                      " straight into you!", tgt);
    message("combat", tp->query_cap_name()+" does a "+CARTWHEEL+
                      " straight into "+tgt->query_cap_name()+"!", env, ({tp, tgt}) );
    
    tp->add_sp(-(cost+random(cost/15)));
    tgt->do_damage(random_cartwheel_limb(tgt), dmg, DAMAGE_PHYSICAL | DAMAGE_IMPACT | DAMAGE_UNARMED, DAMAGE_NO_SEVER, tp);

    // hit is at _least_ 120
    if (hit > 300) hit = 300 + (hit - 300)/3;
    if (hit > 500) hit = 500;
    
    prev=tgt;
    foreach(object who in others) {
      int miss = who->query_skill("defense") + who->query_skill("agility") + who->query_stats("dexterity");
      if (hit > miss+random(110)-random(110)) {
        message("combat", "You fall and knock "+who->query_cap_name()+
                          " over!", prev);
        message("combat", prev->query_cap_name()+" falls and knocks "+
                          "you over!", who);
        message("combat", prev->query_cap_name()+" falls and knocks "+
                          who->query_cap_name()+" over!", env, ({prev, who}) );
        who->set_rest_type(3+random(2));
      }
      else {
        message("combat", "You stumble into "+who->query_cap_name()+"!", prev);
        message("combat", prev->query_cap_name()+" stumbles into you!", who);
        message("combat", prev->query_cap_name()+" stumbles into "+who->query_cap_name()+"!", env, ({prev, who}) );
      }
      dmg = dmg * 0.6;
      if (dmg < 10) dmg = 10;
      who->do_damage(who->query_torso(), dmg, DAMAGE_PHYSICAL | DAMAGE_IMPACT | DAMAGE_UNARMED, DAMAGE_NO_SEVER, tp);
      prev=who;
    }

    if (random(1000) < 50+hit) {
      tgt->set_rest_type(3+random(2));
      if (prev == tgt)
        message("info", "You stumble and fall over!", tgt);
    }
    
  }
  
  return 1;
}

string random_cartwheel_limb(object who) {
  string *all;
  if (!living(who)) return "";

  all=who->query_limbs();

  all = filter(all, (:
    regexp($1, "torso|abdomen|(left|right) leg|foot|foreleg|rear paw|fore hoof|front claw|front .+ (leg|claw)")
  :) );

  if (!sizeof(all))
    return "none";
  else
    return all[random(sizeof(all))];
}

