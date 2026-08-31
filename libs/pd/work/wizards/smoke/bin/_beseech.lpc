#include <std.h>
#define FAIL(s) return notify_fail(s);

inherit DAEMON;

int spell() {
  object tp=this_player();
  if (tp->query_subclass() == "white")
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
    FAIL("That wouldn't be wise.\n");

  if (!tp->kill_ob(tgt))
    FAIL("That cannot be attacked by you yet.\n");

  return 1;
}

int cmd_beseech(string str) {
  object tp=this_player();
  object tgt;

  int wis,fai,ma;
  int twis,tmdef;
  int cost, dmg;
 
  if (!spell()) return 0;

  if (tp->query_disable()) return 1;

  if (!str) tgt=tp->query_current_attacker();
  else tgt=present(str,environment(tp));

  if (!ok_cast(tp,tgt)) return 0;
  
  wis=tp->query_stats("wisdom");
  fai=tp->query_skill("faith");
  ma=tp->query_skill("magic attack");
  
  twis=tgt->query_stats("wisdom");
  tmdef=tgt->query_skill("magic defense");

  dmg=wis*3/2+fai/2+ma+random(tp->query_level()+15);
  dmg-=twis/4+tmdef/4;
  cost=dmg/8;
 
  if (tp->query_mp() < cost)
    FAIL("Your prayers may not be cast right now.\n");

  tp->set_disable(1);
  tp->add_mp(-cost);
  tp->set_casting(dmg);

  message("magic","%^YELLOW%^You beseech Valor, praying for a holy blast upon "
                  +tgt->query_cap_name()+"!%^RESET%^",tp);
  message("magic","%^YELLOW%^"+tp->query_cap_name()+"'s prayers are answered "
                  "and a holy blast from the heavens rains upon you!%^RESET%^",tgt);
  message("magic",""+tp->query_cap_name()+"'s prayers are answered and a holy "
                  "blast from the heavens rains upon "+tgt->query_cap_name()+" ",environment(tp),({tp,tgt}));

  return 1;
}

void help() {
  message("help","\n"
    "Syntax: <beseech [living]>\n" 
    "A holy spell of the White Dragon. The Dragon prays to Valor, the Dragon "
	"Lord, for a holy blast from the heavens to strike down his enemies.",
    this_player());
}
