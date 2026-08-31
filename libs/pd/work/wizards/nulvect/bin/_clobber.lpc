#include <std.h>
#include <daemons.h>
#include <rest.h>

#define COL "%^WHITE%^"
#define RES "%^RESET%^"

#define FAIL(s) return notify_fail(s+"\n")

inherit DAEMON;

int abil() {
    object o = this_player();
    if (o && o->query_subclass() == "thug" && o->query_skill("melee") >= 15*6)
      return 1;
    return 0;
}

string type() { return "attack"; }

void help() {
  message("help",
    "Syntax: <clobber [victim]>\n\n"
    "A thug ability where the thug will punch his opponent "
    "as hard as possible, sometimes causing the victim to be "
    "knocked to the ground.",
    this_player() );
}

int can_cast(object tp, object tgt) {

  if (!tp) return 0;

  if (environment(tp)->query_property("no attack"))
    FAIL("Some force prevents your violence.");

  if (tp->query_busy())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("You appear to be dead.");

  if (!tgt)
    FAIL("Clobber who?");

  if (!living(tgt))
    FAIL("Pointless.");

  if (tgt == tp)
    FAIL("Not a very bright idea.");

  if (tp->query_rest_type())
    FAIL("You cannot do that while on the ground!");

  if (tgt->query_rest_type())
    FAIL(tgt->query_cap_name()+" is not in a position to be punched!");

  if (sizeof(tp->query_wielding_limbs()) - sizeof(tp->query_limbs_wielded()) < 1)
    FAIL("You need at least one free hand to clobber.");

  if (!tp->ok_to_kill(tgt))
    FAIL("You cannot attack "+tgt->query_cap_name()+".");

  return 1;
}

int cmd_clobber(string str) {
  object tp = this_player();
  object env = environment(tp);
  object tgt;
  int rank, dmg, cost;
  string limb;

  if (!abil()) return 0;

  if (str)
    tgt = present(str, env);
  else
    tgt = tp->query_current_attacker();

  if (!can_cast(tp, tgt)) return 0;

  if (tp->query_level() < 20)
    rank = 1;
  else if (tp->query_level() < 36)
    rank = 2;
  else
    rank = 3;

  dmg = BALANCE3_D->get_damage(tp, tgt, rank,
    ({ "attack", "melee", "melee" }),
    ({ "strength", "strength", "dexterity" }),
    ({ "strength", "dexterity" }) );

  dmg *= 1.1;

  cost = 2.5*log(25*dmg*dmg) - 13;
  if (cost < 10) cost = 10;

  if (tp->query_sp() < cost)
    FAIL("You are too tired.");

  if (!tp->kill_ob(tgt))
    FAIL("You cannot attack "+tgt->query_cap_name()+".");

  if (dmg < 10) {
    message("combat", "Your punch misses completely.", tp);
    message("combat", tp->query_cap_name()+" misses a punch.", env, tp);
    cost = cost / 5;
  }
  else {

    if (random(100) < 50 || !tgt->query_is_limb("head")) {
      dmg = dmg * 5 / 4;  
      limb = "torso";
      message("combat", "You punch "+tgt->query_cap_name()+" hard in the stomach!", tp);
      message("combat", tp->query_cap_name()+" punches you in the stomach!\n"
                        "You cough up some %^RED%^%^BOLD%^blood"+RES+"!", tgt);
      message("combat", tp->query_cap_name()+" punches "+tgt->query_cap_name()+
                        " hard in the stomach!", env, ({ tp, tgt }));   
      message("combat", tgt->query_cap_name()+ " coughs up some "
                        "%^RED%^%^BOLD%^blood"+RES+"!", env, tgt);
    }
    else {
      dmg = dmg * 4 / 5;  
      limb = "head";
      message("combat", "You punch "+tgt->query_cap_name()+" hard in the face!", tp);
      message("combat", tp->query_cap_name()+" punches you in the face!", tgt);            
      message("combat", tp->query_cap_name()+" punches "+tgt->query_cap_name()+
                        " hard in the face!", env, ({ tp, tgt }));   

      if (random(100) > 50 &&
          tp->query_stats("strength") > tgt->query_stats("constitution")*3/2 ) {

            message("combat", tgt->query_cap_name()+ "'s eyes roll back and "+
                              tgt->query_subjective()+" falls to the ground!", env, tgt);
            message("combat", "You feel light in the head and fall back on to the ground!", tgt);
            tgt->set_rest_type(LAY);
            tgt->set_paralyzed(2, "You are dazed from the hit!");

      }

    }

    tgt->do_damage(limb, dmg);

  }        

  tp->set_disable();
  tp->add_sp(-(cost+random(cost/10)));
  
  return 1;
    
}
