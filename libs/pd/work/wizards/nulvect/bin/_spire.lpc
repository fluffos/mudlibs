#include <std.h>
#include <daemons.h>
#define FAIL(s) return notify_fail(s);
#define COL "%^BOLD%^%^CYAN%^"
#define RES "%^RESET%^"

inherit DAEMON;

int spell() {
  object tp=this_player();
  if (tp->query_subclass() == "blue" &&
      tp->query_skill("faith") >= 28*5 &&
      tp->query_skill("conjuring") >= 28*3)
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
    FAIL("Not very smart.\n");

  if (!tp->kill_ob(tgt))
    FAIL("That cannot be attacked by you yet.\n");

  return 1;
}

int cmd_spire(string str) {
  object tp=this_player();
  object tgt;

  int cost, dmg;

  if (!spell()) return 0;

  if (tp->query_disable()) return 1;

  if (!str) tgt=tp->query_current_attacker();
  else tgt=present(str,environment(tp));

  if (!ok_cast(tp,tgt)) return 0;
  
  dmg=BALANCE_D->get_damage(tp, tgt, 3,
      ({ "faith", "faith", "conjuring" }),
      ({ "wisdom", "intelligence" }),
      ({ "wisdom" }) );
  
  dmg=dmg*1.15;
  
  cost=dmg/9;
  
  if (tp->query_mp() < cost)
    FAIL("Your magic is too low.\n");
  
  tp->add_mp(-(cost+random(cost/20)));

  message("magic",COL+"A large ice spire suddenly shoots up from the ground "
                  "and stabs into you!"+RES, tgt);
  message("magic",COL+"A large ice spire suddenly shoots up from the ground "
                  "and stabs into "+tgt->query_cap_name()+"!"+RES,
                  environment(tgt), tgt);

  tp->set_casting(dmg);
  
  return 1;
}

void help() {
  message("help","\n"
    "Syntax: <spire [living]>\n"
    "This spell creates a sharp spire of ice to come up from the ground "
    "at an angle and stab into your foe.",
    this_player());
}

