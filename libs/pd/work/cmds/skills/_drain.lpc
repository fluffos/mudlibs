#include <std.h>
#include <daemons.h>

#define FAIL(s) return notify_fail(s);
#define RES "%^RESET%^"
#define COL RES+"%^RED%^"
#define COL2 "%^BOLD%^%^WHITE%^"

inherit DAEMON;

int spell() {
  object tp=this_player();
  if (tp->query_subclass() == "kataan" &&
      tp->query_skill("faith") >= 16*6 &&
      tp->query_skill("magic attack") >= 16*5)
        return 1;
  return 0;
}

string type() { return "healing"; }

void help() {
  message("help",
    "Syntax: <drain [living]>\n\n"
    "This evil spell sucks the stamina out of an opponent and gives it to the caster.",
    this_player());
}

int ok_cast(object tp, object tgt) {
  object env;

  if (!tp) return 0;

  env = environment(tp);
  
  if (env->query_property("no magic") || env->query_property("no attack"))
    FAIL("You cannot do that here.\n");

  if (tp->query_disable() || tp->query_casting() || tp->query_magic_round())
    FAIL("You are busy.\n");

  if (tp->query_ghost())
    FAIL("You are dead.\n");
  
  if (!tgt)
    FAIL("You don't see that here.\n");

  if (!living(tgt))
    FAIL("That is not alive.\n");

  if (tp == tgt)
    FAIL("How foolish.\n");

  if (userp(tgt) && !interactive(tgt))
    FAIL("You may not attack link-dead players.\n");

  if (tgt->query_sp() < 5)
    FAIL(tgt->query_subjective()+" is already completely drained.\n");
  
  if (!tp->kill_ob(tgt))
    FAIL("That cannot be attacked by you yet.\n");

  return 1;
}

int cmd_drain(string str) {
  object tp=this_player();
  object env=environment(tp);
  object tgt;
  int cost, dmg;

  if (!spell()) return 0;

  tp->clean_up_attackers();

  if (!str) tgt=tp->query_current_attacker();
  else tgt=present(str,environment(tp));

  if (!ok_cast(tp,tgt)) return 0;

  dmg = BALANCE3_D->get_damage(tp, tgt, 2,
    ({"faith", "magic attack", "magic attack"}),
    ({"wisdom", "wisdom", "intelligence"}),
    ({"magic attack"}) );

  dmg /= 4;

  if (dmg > 80) dmg=80+(dmg-80)/2;

  if (tgt->query_sp() < dmg)
    dmg = tgt->query_sp();
  
  cost = BALANCE3_D->get_cost(dmg, 2, "mp") * 60 / 100;
  
  if (tp->query_mp() < cost)
    FAIL("Too low on magic.\n");

  tp->set_magic_round(1);
  tp->add_mp(-(cost+random(cost/5)));

  message("magic",COL+"You r"+COL2+"eac"+COL+"h a hand out towards "+
                  tgt->query_cap_name()+
                  " and "+COL2+"drain"+COL+" some "+
                  COL2+"en"+COL+"er"+COL2+"gy"+COL+
                  " from "+tgt->query_objective()+"!"+RES,tp);
  message("magic",COL+tp->query_cap_name()+" r"+COL2+"eache"+COL+"s a hand "
                  "out towards you and "+
                  COL2+"drains"+COL+" some of your "+
                  COL2+"en"+COL+"er"+COL2+"gy"+COL+"!"+RES,tgt);
  message("magic",COL+tp->query_cap_name()+" r"+COL2+"eache"+COL+"s a hand "
                  "out towards "+tgt->query_cap_name()+" and "+
                  COL2+"drains"+COL+" some of "+tgt->query_possessive()+" "+
                  COL2+"en"+COL+"er"+COL2+"gy"+COL+"!"+RES,
                  environment(tp), ({tp,tgt}) );

  tp->add_sp(dmg);
  tgt->add_sp(-dmg);
  tp->add_alignment(-5);

  return 1;
}

