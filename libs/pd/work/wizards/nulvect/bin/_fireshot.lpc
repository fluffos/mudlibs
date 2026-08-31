#include <std.h>
#include <daemons.h>
#define FAIL(s) return notify_fail(s);
#define COL "%^WHITE%^"
#define MCOL "%^BOLD%^%^RED%^"
#define RES "%^RESET%^"

inherit DAEMON;

int abil() {
  object tp=this_player();
  if (tp->query_subclass() == "red" &&
      tp->query_skill("flying") >= to_int(32*3.5) &&
      tp->query_skill("breath") >= 32*5)
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

int cmd_fireshot(string str) {
  object tp=this_player();
  object tgt;
  string howbig;
  int cost, dmg;

  if (!abil()) return 0;

  if (tp->query_disable()) return 1;

  if (!str) tgt=tp->query_current_attacker();
  else tgt=present(str,environment(tp));

  if (!ok_cast(tp,tgt)) return 0;
  
  if (tp->query_level() >= 60) {
    dmg=BALANCE_D->get_damage(tp, tgt, 4,
          ({"attack", "breath", "breath", "flying"}),
          ({"strength", "strength", "dexterity"}),
          ({"intelligence"}) );
  }
  else {
    dmg=BALANCE_D->get_damage(tp, tgt, 3,
          ({"attack", "breath", "breath", "flying"}),
          ({"strength", "strength", "dexterity"}) );
  }

  cost=dmg/11;
  
  if (tp->query_sp() < cost)
    FAIL("Not enough stamina.\n");

  tp->add_sp(-(cost+random(cost/15)));

  message("info", COL+"You leap into the sky!", tp);
  message("info", COL+tp->query_cap_name()+" leaps into the sky!",
                  environment(tp), tp);

  if (tp->query_skill("flying")*4/5 < tgt->query_stats("dexterity")-random(30)) {
    message("info",MCOL+"You spit a ball of flame at "+tgt->query_cap_name()+
                   ", but "+tgt->query_subjective()+" dodges it!"+RES,tp);
    message("info",MCOL+tp->query_cap_name()+" spits a ball of flame at you, "
                    "but you dodge it!"+RES, tgt);
    message("info",MCOL+tp->query_cap_name()+" spits a ball of flame at "+
                   tgt->query_cap_name()+", but misses!"+RES,
                   environment(tgt), ({tp,tgt}) );
    return 1;
  }

  if (tp->query_skill("breath") > 300)
    howbig="a %^YELLOW%^GIANT ball of flame"+RES+MCOL;
  else
    howbig="a %^YELLOW%^large ball of flame"+RES+MCOL;
  
  message("info",MCOL+"You spit "+howbig+" at "+tgt->query_cap_name()+
                 " that engulfs "+tgt->query_objective()+"!"+RES,tp);
  message("info",MCOL+tp->query_cap_name()+" spits "+howbig+" at you "
                  "that engulfs you!"+RES,tgt);
  message("info",MCOL+tp->query_cap_name()+" spits "+howbig+" at "+
                  tgt->query_cap_name()+" that engulfs "+
                  tgt->query_objective()+"!"+RES,
                  environment(tgt), ({tp, tgt}) );

  tgt->do_damage(tgt->return_limb(),dmg);

  return 1;
}

void help() {
  message("help","\n"
    "Syntax: <fireshot [living]>\n"
    "The red dragon using this ability leaps into the air and spews "
    "balls of fire down at his opponent.",
    this_player());
}

