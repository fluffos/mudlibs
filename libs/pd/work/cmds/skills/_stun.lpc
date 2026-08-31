
#include <std.h>
#include <daemons.h>
#include <damage.h>
#include <damage_types.h>

#define RES "%^RESET%^"
#define COL RES+"%^WHITE%^"
#define COL2 "%^BOLD%^%^GREEN%^"

#define FAIL(s) return notify_fail(s+"\n")

inherit DAEMON;

int abil() {
  object tp=this_player();
  if (tp && tp->query_skill("attack") >= 14*5 &&
      tp->query_skill("melee") >= 14*6 &&
      member_array(tp->query_subclass(), ({"thug","berserker"})) != -1)
        return 1;
  return 0;
}

string type() { return "attack"; }

void help() {
  message("help",
    "Syntax: <stun [whom]>\n\n"
    "You punch your opponent in the stomach, causing him to double over "
    "and be stunned for a little while. You can only use this to start "
    "a fight.",
    this_player() );
}

int can_cast(object tp, object tgt) {

  if (!tp) return 0;

  if (environment(tp)->query_property("no attack"))
    FAIL("You cannot attack here.");

  if (tp->query_disable() || tp->query_casting() || tp->query_disable())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("Your fists can't hit anything when you're dead.");

  if (tp->query_rest_type())
    FAIL("You must stand up first.");

  if (!tgt)
    FAIL("Stun whom?");

  if (!living(tgt))
    FAIL("It wasn't going to move anyway.");

  if (tgt == tp)
    FAIL("You try to punch yourself, but just look stupid.");

  if (!tgt->query_is_limb("torso"))
    FAIL("That doesn't have a stomach to punch.");

  if (tp->query_current_attacker())
    FAIL("You are too busy fighting.");

  if (!tp->kill_ob(tgt))
    FAIL("You may not attack "+tgt->query_cap_name()+".");
  
  return 1;
}

int cmd_stun(string str) {
  object tp=this_player();
  object env=environment(tp);
  object tgt;
  int dmg, rank, cost;
  int mystr, hiscon, rounds;

  if (!abil()) return 0;

  if (str)
    tgt=present(str, env);

  if (!can_cast(tp, tgt)) return 0;

  if (tp->query_level() >= 30) rank=3;
  else rank=2;

  dmg = BALANCE3_D->get_damage(tp, tgt, rank,
    ({"attack", "melee"}),
    ({"strength"}),
    ({"strength"}) );

  dmg /= 5;

  cost = BALANCE3_D->get_cost(dmg, rank, "sp") * 110 / 100;

  if (tp->query_sp() < cost)
    FAIL("You are too tired.");

  tp->add_sp(-(cost+random(cost/8)));
  tp->set_disable();

  mystr = tp->query_stats("strength");
  hiscon = tgt->query_stats("constitution");

  if (mystr+random(15) < hiscon*4/3) {
    message("combat", "You send a punch to "+tgt->query_cap_name()+
                      "'s stomach, but "+tgt->query_subjective()+
                      " seems unphased.", tp);
    message("combat", tp->query_cap_name()+" punches you in the stomach, "
                      "but it doesn't hurt you.", tgt);
    message("combat", tp->query_cap_name()+" punches "+tgt->query_cap_name()+
                      " in the stomach, but it doesn't seem to do anything.",
                      env, ({tp, tgt}) );
  }
  else {
    message("combat", "You send a "+
                      COL2+"p"+COL+"u"+COL2+"n"+COL+"c"+COL2+"h"+RES+
                      " to "+tgt->query_cap_name()+"'s stomach, knocking the "
                      "wind out of "+tgt->query_objective()+"!", tp);
    message("combat", tp->query_cap_name()+" "+
                      COL2+"p"+COL+"u"+COL2+"n"+COL+"c"+COL2+"h"+COL+"e"+COL2+"s"+RES+
                      " you hard in the stomach, "
                      "knocking the wind out of you!", tgt);
    message("combat", tp->query_cap_name()+" "+
                      COL2+"p"+COL+"u"+COL2+"n"+COL+"c"+COL2+"h"+COL+"e"+COL2+"s"+RES+
                      " "+tgt->query_cap_name()+" hard in the stomach, "
                      "knocking the wind out of "+tgt->query_objective()+"!", tgt);
    
    rounds=1+random(2);
    if (mystr >= hiscon*2)
      rounds += mystr/(hiscon*1.2);
    if (rounds > 3)
      rounds=3;
    
    tgt->set_paralyzed(rounds*2, "You are still trying to catch your breath.");
    tgt->do_damage("torso", dmg, tp->query_unarmed_damage_type(), tp->query_unarmed_damage_flags(), tp);
    
  }
  
  return 1;
}

