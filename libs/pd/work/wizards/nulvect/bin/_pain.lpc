
#include <std.h>
#include <daemons.h>

#define FAIL(s) return notify_fail(s);

#define COL "%^BOLD%^%^GREEN%^"
#define RES "%^RESET%^"

inherit DAEMON;

int spell() {
  object tp=this_player();
  if ((tp->query_subclass() == "cleric" ||
      tp->query_subclass() == "monk") &&
      tp->query_skill("healing") >= 10)
        return 1;
  return 0;
}

string type() { return "attack"; }

void help() {
  message("help",
    "Syntax: <pain [living]>\n\n"
    "This spell uses the powers of healing in reverse to cause "
    "sharp pain in the body of the target.",
    this_player());
}

int can_cast(object tp, object tgt) {
  object env;

  if (!tp) return 0;

  env = environment(tp);

  if (env->query_property("no attack") || env->query_property("no magic"))
    FAIL("You cannot cast that here.\n");

  if (tp->query_disable() || tp->query_casting() || tp->query_magic_round())
    FAIL("You are busy.\n");

  if (!tgt)
    FAIL("Cause pain in whom?\n");

  if (!living(tgt))
    FAIL("That cannot feel pain.\n");

  if (tp == tgt)
    FAIL("Ouch.\n");

  if (userp(tgt) && !interactive(tgt))
    FAIL("You may not attack link-dead players.\n");

  if (!(tp->kill_ob(tgt)))
    FAIL("You cannot attack "+tgt->query_cap_name()+".\n");
  
  return 1;
}

int cmd_pain(string str) {
  object tp=this_player();
  object env=environment(tp);
  object tgt;
  int i;
  int dmg, cost;

  if (!spell()) return 0;

  if (str)
    tgt = present(str, env);
  else
    tgt = tp->query_current_attacker();

  if (!can_cast(tp, tgt)) return 0;

  dmg = BALANCE3_D->get_damage(tp, tgt, 1,
    ({"healing"}),
    ({"wisdom"}) );

  dmg = dmg/2;

  cost = dmg/7;

  if (tp->query_mp() < cost)
    FAIL("Too low on magic.\n");

  tp->add_mp(-(cost+random(cost/7)));
  tp->set_casting(dmg);
  tp->set_disable();

  message("magic", "You point at "+tgt->query_cap_name()+".", tp);
  message("magic", tp->query_cap_name()+" points at you.", tgt);
  message("magic", tp->query_cap_name()+" points at "+
                   tgt->query_cap_name()+".", env, ({tp, tgt}) );
  
  message("magic", COL+"You send a sharp pain through "+
                   tgt->query_cap_name()+"'s body!"+RES, tp);
  message("magic", COL+tp->query_cap_name()+" sends a sharp pain through "
                   "your body!", tgt);
  message("magic", COL+tp->query_cap_name()+" sends a sharp pain through "+
                   tgt->query_cap_name()+"'s body!", env, ({tp, tgt}) );
  
  return 1;
}

