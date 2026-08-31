#include <std.h>
#include <daemons.h>
#define FAIL(s) return notify_fail(s);
#define COL "%^WHITE%^"
#define MCOL "%^BOLD%^%^RED%^"
#define RES "%^RESET%^"

inherit DAEMON;

void roast(mixed *args);

int abil() {
  object tp=this_player();
  if (tp->query_subclass() == "red" &&
      tp->query_skill("melee") >= to_int(20*5.5) &&
      tp->query_skill("breath") >= 20*5)
    return 1;
  return 0;
}

int ok_cast(object tp, object tgt) {
  if (environment(tp)->query_property("no magic") ||
      environment(tp)->query_property("no attack"))
    FAIL("You cannot do that here.\n");

  if (!tgt)
    FAIL("You don't see that here.\n");

  if (!living(tgt))
    FAIL("That is not alive.\n");

  if (tp == tgt)
    FAIL("You can't attack yourself.\n");

  if (!tp->kill_ob(tgt))
    FAIL("That cannot be attacked by you yet.\n");

  return 1;
}

int cmd_pyrestrike(string str) {
  object tp=this_player();
  object tgt;

  int cost, dmg, bdmg;

  if (!abil()) return 0;

  if (tp->query_disable()) return 1;

  if (!str) tgt=tp->query_current_attacker();
  else tgt=present(str,environment(tp));

  if (!ok_cast(tp,tgt)) return 0;
  
  if (tp->query_level() >= 40) {
    dmg=BALANCE_D->get_damage(tp, tgt, 3,
          ({"melee", "melee", "attack", "claw"}),
          ({"strength", "strength", "dexterity"}),
          ({"strength"}) );
    bdmg=BALANCE_D->get_damage(tp, tgt, 3,

          ({"breath", "breath", "attack"}),
          ({"strength", "strength", "intelligence"}),
          ({"strength"}) );
  }
  else {
    dmg=BALANCE_D->get_damage(tp, tgt, 2,
          ({"melee","melee","attack","claw"}),
          ({"strength", "strength", "dexterity"}) );
    bdmg=BALANCE_D->get_damage(tp, tgt, 2,
          ({"breath","breath","attack"}),
          ({"strength", "strength", "intelligence"}) );
  }

  dmg=dmg/2;
  bdmg=bdmg*3/2;
  
  cost=dmg/20;
  
  if (tp->query_sp() < cost)
    FAIL("Not enough stamina.\n");

  tp->add_sp(-(cost+random(cost/15)));

  if (tp->query_skill("melee")/2 < tgt->query_stats("dexterity")) {
    message("info",COL+"You try to knock "+tgt->query_cap_name()+
                        " down, but "+tgt->query_subjective()+
                        " is too fast!"+RES,tp);
    message("info",COL+tp->query_cap_name()+" rushes at you, "
                    "but misses!"+RES, tgt);
    message("info",COL+tp->query_cap_name()+" rushes at "+tgt->query_cap_name()+
                    ", but misses!"+RES, environment(tgt), ({tp,tgt}) );
    return 1;
  }
  
  message("info",COL+"You rush at "+tgt->query_cap_name()+" and knock "+
                  tgt->query_objective()+" down!"+RES,tp);
  message("info",COL+tp->query_cap_name()+" rushes at you and knocks "
                  "you down!"+RES,tgt);
  message("info",COL+tp->query_cap_name()+" rushes at "+tgt->query_cap_name()+
                  " and knocks "+tgt->query_objective()+" down!"+RES,
                  environment(tp), ({tp,tgt}) );

  tgt->set_paralyzed(2, "You are being held down.");
  tp->set_paralyzed(4, "You are busy holding someone down.");

  tgt->do_damage(tgt->return_target_limb(),dmg);

  call_out("roast",2,({tp,tgt,bdmg}));
  
  return 1;
}

void roast(mixed *args) {
  object tp=args[0];
  object tgt=args[1];
  int bdmg=args[2];
  int cost;

  if (!tp || !tgt) return;
  
  cost=bdmg/15;

  if (tp->query_sp() < cost) {
    message("info","You try to roast "+tgt->query_cap_name()+", but don't "
                   "have enough energy.",tp);
    return;
  }
  
  message("info",MCOL+"You roast "+tgt->query_cap_name()+" to a "
                  "%^RESET%^ORANGE%^crisp "+MCOL+"with a gout of flame!"+RES, tp);
  message("info",MCOL+tp->query_cap_name()+" roasts you to a "
                  "%^RESET%^%^ORANGE%^crisp "+MCOL+"with "
                  "a gout of flame!"+RES, tgt);
  message("info",MCOL+tp->query_cap_name()+" roasts "+tgt->query_cap_name()+
                  " to a %^RESET%^%^ORANGE%^crisp "+MCOL+"with "
                  "a gout of flame!"+RES, environment(tgt), ({tp,tgt}) );

  tgt->do_damage(tgt->return_limb(), bdmg);
  tp->add_sp(-(cost+random(cost/16)));

}

void help() {
  message("help","\n"
    "Syntax: <pyrestrike [living]>\n"
    "Red dragons can knock down an opponent, then roast him with their "
    "fiery hot breath.",
    this_player());
}

